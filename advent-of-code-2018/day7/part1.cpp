#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream file;
    file.open("input.txt");
    string line;

    vector<int> graph[30];
    int in_degree[30];
    fill(in_degree, in_degree + 30, 0);

    set<int> seen;
    while (getline(file, line))
    {
        char u, v;
        sscanf(line.c_str(), "Step %c must be finished before step %c can begin.", &u, &v);
        graph[u - 'A'].push_back(v - 'A');
        in_degree[v - 'A']++;
        seen.insert(u - 'A');
        seen.insert(v - 'A');
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < 26; i++)
    {
        if (in_degree[i] == 0 && seen.count(i))
            pq.push(i);
    }

    string topo_order = "";
    while (!pq.empty())
    {
        int u = pq.top();
        topo_order += char(u + 'A');
        pq.pop();

        for (int v : graph[u])
        {
            in_degree[v]--;
            if (in_degree[v] == 0)
                pq.push(v);
        }
    }
    cout << topo_order << "\n";
}