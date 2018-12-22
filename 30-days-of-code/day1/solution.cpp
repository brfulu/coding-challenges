#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    int input_int;
    double input_double;
    string input_string, blank;

    cin >> input_int;
    cin >> input_double;
    getline(cin, blank);
    getline(cin, input_string);

    cout << i + input_int << endl;
    cout << fixed << setprecision(1) << d + input_double << endl;
    cout << s + input_string << endl;
    return 0;
}