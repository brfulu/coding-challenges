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

  main();
});

function readLine() {
  return inputString[currentLine++];
}

function main() {
  const n = parseInt(readLine());
  const phoneBook = {};
  for (let i = 0; i < n; i++) {
    const lineSplit = readLine().split(' ');
    const name = lineSplit[0];
    const number = lineSplit[1];
    phoneBook[name] = number;
  }

  while (currentLine < inputString.length) {
    const queryName = readLine();
    if (queryName in phoneBook) {
      console.log(queryName + '=' + phoneBook[queryName]);
    } else {
      console.log('Not found');
    }
  }
}
