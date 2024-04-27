#include<stdio.h>
int main()
{
    int size, index, count, wordIndex;
    char alpha [6][5] = {{'A','B','C','D','E'},{'F','G','H','I','J'},{'K','L','M','N','O'},{'P','Q','R','S','T'},{'U','V','W','X'},{'Y','Z'}};
    printf("Think a word and I will try to guess it\n");
    printf("Just answer the following questions with reference to this lines \n");
    printf("\n");
    for (int i = 0; i < 6; i++)
    {
        printf("Line no. %d: ",i+1);
        for (int j = 0; j < 5; j++)
        {
            printf("%c ",alpha[i][j]);
        }
        printf("\n");
    }
    printf("Enter the number of letters in the word: ");
    scanf("%d",&size);
    printf("\n");
    char selectedAlpha[5][size];
    char word[size];
    for (int k = 0; k < size; k++)
    {
       printf("Enter the line number in which the letter number %d  of the word is present: ",k+1);
       scanf("%d",&index);
       count = sizeof(alpha[index-1])/sizeof(alpha[index-1][0]);
       for (int l = 0; l < count; l++)
       {
           selectedAlpha[l][k] = alpha[index-1][l];
       }
    }
    printf("\n");
    printf("Answer the following questions with reference to this lines \n");
    printf("\n");
    for (int m = 0; m < 5; m++)
    {
        printf("Line no. %d: ",m+1);
        for (int n = 0; n < size; n++)
        {
            if (selectedAlpha[m][n]!='\0')
            {
               printf("%c ",selectedAlpha[m][n]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
    for (int o = 0; o < size; o++)
    {
        printf("Enter the line number of the letter number %d of the word: ",o+1);
        scanf("%d",&wordIndex);
        word[o] = selectedAlpha[wordIndex-1][o];
    }
    printf("\n");
    printf("The word is: ");
    for (int p = 0; p < size; p++)
    {
        printf("%c",word[p]);
    }
    
    return 0;
}