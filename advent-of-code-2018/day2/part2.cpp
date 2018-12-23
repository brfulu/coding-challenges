#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string get_matched(string a, string b)
{
    string matched = "";
    for (int k = 0; k < a.size(); k++)
    {
        if (a[k] == b[k])
            matched += a[k];
    }
    return matched;
}

int main()
{
    fstream file;
    file.open("input.txt");

    vector<string> box_ids;
    string id;
    while (file >> id)
    {
        box_ids.push_back(id);
    }

    string result = "";
    for (int i = 1; i < box_ids.size() && result.size() == 0; i++)
    {
        for (int j = 0; j < i; j++)
        {
            string matched = get_matched(box_ids[i], box_ids[j]);
            if (matched.size() == box_ids[i].size() - 1)
            {
                result = matched;
                break;
            }
        }
    }

    cout << result << "\n";
    return 0;
}