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

function calculateTotalCost(mealCost, tipPercent, taxPercent) {
  const tipCost = mealCost * (tipPercent / 100.0);
  const taxCost = mealCost * (taxPercent / 100.0);
  return Math.round(mealCost + tipCost + taxCost);
}

function main() {
  const mealCost = parseFloat(readLine());
  const tipPercent = parseInt(readLine(), 10);
  const taxPercent = parseInt(readLine(), 10);

  const result = calculateTotalCost(mealCost, tipPercent, taxPercent);
  console.log(result);
}
