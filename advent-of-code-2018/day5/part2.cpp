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

string remove_unit(string polymer, int c)
{
    string result = "";
    for (char unit : polymer)
    {
        if (unit != c + 'a' && unit != c + 'A')
        {
            result += unit;
        }
    }
    return result;
}

int main()
{
    fstream file;
    file.open("input.txt");
    string polymer;
    file >> polymer;

    int result = INT_MAX;
    for (int c = 0; c < 26; c++)
    {
        string temp_polymer = remove_unit(polymer, c);
        result = min(result, react_polymer_size(temp_polymer));
    }

    cout << result << "\n";
}