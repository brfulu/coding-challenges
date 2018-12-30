#include <bits/stdc++.h>

using namespace std;

int current_index = 0;
vector<int> tree_data;

int get_metadata_sum()
{
    if (current_index >= tree_data.size())
    {
        return 0;
    }

    int child_count = tree_data[current_index];
    int metadata_count = tree_data[current_index + 1];

    int result = 0;

    current_index += 2;
    int child_start = current_index;
    for (int i = child_start; i < child_start + child_count; i++)
    {
        result += get_metadata_sum();
    }

    int metadata_start = current_index;
    for (current_index = metadata_start; current_index < metadata_start + metadata_count; current_index++)
    {
        result += tree_data[current_index];
    }
    return result;
}

int main()
{
    fstream file;
    file.open("input.txt");
    int value;
    while (file >> value)
    {
        tree_data.push_back(value);
    }
    cout << get_metadata_sum() << "\n";
}