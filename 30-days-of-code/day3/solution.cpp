#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n % 2 == 1)
        cout << "Weird\n";
    else if (n <= 5)
        cout << "Not Weird\n";
    else if (n <= 20)
        cout << "Weird\n";
    else
        cout << "Not Weird\n";
}