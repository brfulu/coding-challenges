#include <bits/stdc++.h>

using namespace std;

int string_to_int(string s)
{
    int result;
    stringstream ss;
    ss << s;
    ss >> result;
    return result;
}

vector<string> split(string text, string delimeters)
{
    text += delimeters;
    vector<string> tokens;
    string current = "";
    for (char c : text)
    {
        if (delimeters.find(c) != string::npos)
        {
            tokens.push_back(current);
            current = "";
        }
        else
        {
            current += c;
        }
    }
    return tokens;
}

void extract_line(string line, int &x, int &y, int &width, int &height)
{
    vector<string> tokens = split(line, " ");

    vector<string> position_tokens = split(tokens[2], ",:");
    x = string_to_int(position_tokens[0]);
    y = string_to_int(position_tokens[1]);

    vector<string> size_tokens = split(tokens[3], "x");
    width = string_to_int(size_tokens[0]);
    height = string_to_int(size_tokens[1]);
}

map<pair<int, int>, int> counter;
int result = 0;

void fill_rectangle(int x, int y, int width, int height)
{
    for (int i = y; i < y + height; i++)
    {
        for (int j = x; j < x + width; j++)
        {
            counter[make_pair(i, j)]++;
            if (counter[make_pair(i, j)] == 2)
            {
                result++;
            }
        }
    }
}

int main()
{
    fstream file;
    file.open("input.txt");

    string claim;
    while (getline(file, claim))
    {
        int x, y, width, height;
        extract_line(claim, x, y, width, height);
        fill_rectangle(x, y, width, height);
    }

    cout << result << "\n";
}