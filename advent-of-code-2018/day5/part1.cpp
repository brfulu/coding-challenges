#include <bits/stdc++.h>

using namespace std;

int react_polymer_size(string polymer)
{
    string result = "";
    for (char unit : polymer)
    {
        result += unit;
        while (result.size() > 1 && abs(result[result.size() - 1] - result[result.size() - 2]) == 'a' - 'A')
        {
            result.pop_back();
            result.pop_back();
        }
    }
    return result.size();
}

int main()
{
    fstream file;
    file.open("input.txt");
    string polymer;
    file >> polymer;

    cout << react_polymer_size(polymer) << "\n";
}