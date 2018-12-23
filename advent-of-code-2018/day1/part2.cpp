#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    fstream file;
    file.open("input.txt");

    set<int> seen;
    vector<int> changes;
    int frequency = 0;
    int value;

    while (file >> value)
    {
        changes.push_back(value);
    }

    int result = -2;
    for (int i = 0;; i = (i + 1) % changes.size())
    {
        frequency += changes[i];
        if (seen.count(frequency) > 0)
        {
            result = frequency;
            break;
        }
        seen.insert(frequency);
    }

    cout << result << "\n";
}
