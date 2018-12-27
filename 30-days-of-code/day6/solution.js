'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
  inputString += inputStdin;
});

process.stdin.on('end', _ => {
  inputString = inputString.replace(/\s*$/, '')
    .split('\n')
    .map(str => str.replace(/\s*$/, ''));

  main(inputString);
});

function readLine() {
  return inputString[currentLine++];
}

function main(input) {
  const testCount = parseInt(input[0]);
  for (let t = 1; t <= testCount; t++) {
    const word = input[t];
    const evenLetters = word.split('').filter((letter, i) => i % 2 == 0).join('');
    const oddLetters = word.split('').filter((letter, i) => i % 2 == 1).join('');
    console.log(evenLetters + ' ' + oddLetters);
  }
}

