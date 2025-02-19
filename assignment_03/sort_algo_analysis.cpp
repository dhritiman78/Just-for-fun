#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

int write_input() {
    ofstream output("input.txt");
    if (!output) {
        cerr << "Error: Could not create input.txt" << endl;
        return 1;
    }

    int sizes[] = {100, 500, 1000, 2000, 5000, 10000, 50000, 75000, 100000, 200000, 500000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    output << num_sizes << endl;
    srand(time(0)); // Seed for randomness

    for (int i = 0; i < num_sizes; i++) {
        output << sizes[i] << endl;
        for (int j = 0; j < sizes[i]; j++) {
            output << (rand() % 1000000) + 1 << " "; // Generate random numbers
        }
        output << endl;
    }

    output.close();
    return 0;
}

void readInput(int &test_cases, int **&test_data, int *&sizes) {
    ifstream input("input.txt");
    if (!input) {
        cerr << "Error: Could not open input.txt" << endl;
        exit(1);
    }

    input >> test_cases;
    sizes = new int[test_cases];
    test_data = new int *[test_cases];

    for (int t = 0; t < test_cases; t++) {
        input >> sizes[t];
        test_data[t] = new int[sizes[t]];
        for (int i = 0; i < sizes[t]; i++) {
            input >> test_data[t][i];
        }
    }

    input.close();
}

// Bubble Sort
void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertion_sort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selection_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}

// Heap Sort Helpers
void heapify(int *arr, int size, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heap_sort(int *arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Merge Sort Helpers
void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int *L = new int[n1], *R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L, R;
}

void merge_sort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int display_menu() {
    int choice;
    cout << "Choose any: " << endl;
    cout << "1. Change the inputs." << endl;
    cout << "2. Bubble Sort." << endl;
    cout << "3. Insertion Sort." << endl;
    cout << "4. Selection Sort." << endl;
    cout << "5. Heap Sort." << endl;
    cout << "6. Merge Sort." << endl;
    cout << "What's your choice: ";
    cin >> choice;
    return choice;
}

void apply_sorting_algo(int choice, int **test_data, int *sizes, int test_cases) {
    for (int t = 0; t < test_cases; t++) {
        int *arr = new int[sizes[t]];
        for (int i = 0; i < sizes[t]; i++)
            arr[i] = test_data[t][i];

        auto start = high_resolution_clock::now();

        switch (choice) {
            case 2: bubble_sort(arr, sizes[t]); break;
            case 3: insertion_sort(arr, sizes[t]); break;
            case 4: selection_sort(arr, sizes[t]); break;
            case 5: heap_sort(arr, sizes[t]); break;
            case 6: merge_sort(arr, 0, sizes[t] - 1); break;
            default: cout << "Invalid choice!" << endl; return;
        }

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout<<endl;
        cout << "Testcase #" << t + 1 <<endl;
        cout << "No. of elements: " << sizes[t] <<endl;
        cout << "Time taken: " << duration.count() << " ms" <<endl;
        cout<<endl;
        delete[] arr;
    }
}

int main() {
  int test_cases, **test_data, *sizes;
        readInput(test_cases, test_data, sizes);
    int choice = display_menu();
    if (choice == 1) write_input();
    else {
    apply_sorting_algo(choice, test_data, sizes, test_cases);
    }
    for (int t = 0; t < test_cases; t++) delete[] test_data[t];
    delete[] test_data;
    delete[] sizes;
    return 0;
}

