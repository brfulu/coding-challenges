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

void extract_line(string line, int &id, int &x, int &y, int &width, int &height)
{
    vector<string> tokens = split(line, " ");

    id = string_to_int(tokens[0].substr(1));

    vector<string> position_tokens = split(tokens[2], ",:");
    x = string_to_int(position_tokens[0]);
    y = string_to_int(position_tokens[1]);

    vector<string> size_tokens = split(tokens[3], "x");
    width = string_to_int(size_tokens[0]);
    height = string_to_int(size_tokens[1]);
}

map<pair<int, int>, int> visited;
set<int> unique_claims;

void fill_rectangle(int id, int x, int y, int width, int height)
{
    int free_area = 0;
    for (int i = y; i < y + height; i++)
    {
        for (int j = x; j < x + width; j++)
        {
            if (visited[make_pair(i, j)] == 0)
            {
                visited[make_pair(i, j)] = id;
                free_area++;
            }
            else
            {
                int prev_id = visited[make_pair(i, j)];
                if (unique_claims.count(prev_id))
                {
                    unique_claims.erase(prev_id);
                }
            }
        }
    }
    if (free_area == width * height)
    {
        unique_claims.insert(id);
    }
}

int main()
{
    fstream file;
    file.open("input.txt");

    string claim;
    while (getline(file, claim))
    {
        int id, x, y, width, height;
        extract_line(claim, id, x, y, width, height);
        fill_rectangle(id, x, y, width, height);
    }

    cout << *unique_claims.begin() << "\n";
}