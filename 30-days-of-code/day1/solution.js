process.stdin.resume();
process.stdin.setEncoding('ascii');

var inputStdin = "";
var inputStdinArray = "";
var inputCurrentLine = 0;

process.stdin.on('data', function (data) {
  inputStdin += data;
});

process.stdin.on('end', function () {
  inputStdinArray = inputStdin.split("\n");
  main();
});

// Reads complete line from STDIN
function readLine() {
  return inputStdinArray[inputCurrentLine++];
}

function main() {
  var i = 4;
  var d = 4.0;
  var s = "HackerRank ";

  var input_int = parseInt(readLine());
  var input_double = parseFloat(readLine());
  var input_string = readLine();

  console.log(i + input_int);
  console.log(parseFloat(d + input_double).toFixed(1));
  console.log(s + input_string);
}