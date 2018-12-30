#include <bits/stdc++.h>

using namespace std;

int current_index = 0;
vector<int> tree_data;

int get_node_value()
{
    if (current_index >= tree_data.size())
    {
        return 0;
    }

    int child_count = tree_data[current_index];
    int metadata_count = tree_data[current_index + 1];

    current_index += 2;
    int child_start = current_index;
    vector<int> child_values;
    for (int i = child_start; i < child_start + child_count; i++)
    {
        child_values.push_back(get_node_value());
    }

    int result = 0;
    int metadata_start = current_index;

    if (child_count == 0)
    {
        for (current_index = metadata_start; current_index < metadata_start + metadata_count; current_index++)
        {
            result += tree_data[current_index];
        }
    }
    else
    {
        for (current_index = metadata_start; current_index < metadata_start + metadata_count; current_index++)
        {
            int child_index = tree_data[current_index] - 1;
            if (child_index >= 0 && child_index < child_count)
            {
                result += child_values[child_index];
            }
        }
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
    cout << get_node_value() << "\n";
}