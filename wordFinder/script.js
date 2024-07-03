let wordLength;
let selectedLines = [];
const alpha = [
    ['A', 'B', 'C', 'D', 'E'],
    ['F', 'G', 'H', 'I', 'J'],
    ['K', 'L', 'M', 'N', 'O'],
    ['P', 'Q', 'R', 'S', 'T'],
    ['U', 'V', 'W', 'X', 'Y'],
    ['Z']
];

function nextStep() {
    wordLength = document.getElementById('wordLength').value;
    if (wordLength > 0) {
        document.getElementById('wordForm').classList.add('hidden');
        const lineInputsDiv = document.getElementById('lineInputs');
        lineInputsDiv.innerHTML = '';
        for (let i = 0; i < wordLength; i++) {
            lineInputsDiv.innerHTML += `
                <div>
                    <label for="line${i+1}">Enter the line number in which the letter number ${i+1} of the word is present: </label>
                    <input type="number" id="line${i+1}" name="line${i+1}" min="1" max="6" required>
                </div>
            `;
        }
        document.getElementById('lineForm').classList.remove('hidden');
    }
}

function showSelectedLines() {
    selectedLines = [];
    for (let i = 0; i < wordLength; i++) {
        const lineIndex = document.getElementById(`line${i+1}`).value - 1;
        selectedLines.push(alpha[lineIndex]);
    }
    document.getElementById('lineForm').classList.add('hidden');
    const letterInputsDiv = document.getElementById('letterInputs');
    letterInputsDiv.innerHTML = '';
    for (let i = 0; i < wordLength; i++) {
        let lineOptions = '';
        selectedLines.forEach((line, index) => {
            lineOptions += `<option value="${index+1}">${line[i] || ''}</option>`;
        });
        letterInputsDiv.innerHTML += `
            <div>
                <label for="letter${i+1}">Enter the line number of the letter number ${i+1} of the word: </label>
                <select id="letter${i+1}" name="letter${i+1}" required>
                    ${lineOptions}
                </select>
            </div>
        `;
    }
    document.getElementById('letterForm').classList.remove('hidden');
}

function revealWord() {
    let word = '';
    for (let i = 0; i < wordLength; i++) {
        const lineIndex = document.getElementById(`letter${i+1}`).value - 1;
        word += selectedLines[lineIndex][i];
    }
    document.getElementById('guessedWord').textContent = word;
    document.getElementById('result').classList.remove('hidden');
}
