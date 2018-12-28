#include <bits/stdc++.h>

using namespace std;

#define WORKER_COUNT 5
#define JOB_TIME 60

class Compare
{
  public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first != b.first)
            return a.first > b.first;
        else
            return a.second > b.second;
    }
};

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
        u -= 'A';
        v -= 'A';
        graph[u].push_back(v);
        in_degree[v]++;
        seen.insert(u);
        seen.insert(v);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    vector<int> workers(WORKER_COUNT, 0);
    for (int i = 0; i < 26; i++)
    {
        if (in_degree[i] == 0 && seen.count(i) > 0)
        {
            int min_available_worker = min_element(workers.begin(), workers.end()) - workers.begin();
            pq.push(make_pair(workers[min_available_worker], i));
            workers[min_available_worker] += JOB_TIME + i + 1;
        }
    }

    int max_time = 0;
    while (!pq.empty())
    {
        int t = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        int job_finish_time = t + JOB_TIME + u + 1;
        max_time = max(max_time, job_finish_time);

        for (int v : graph[u])
        {
            in_degree[v]--;
            if (in_degree[v] == 0)
            {
                int min_available_worker = min_element(workers.begin(), workers.end()) - workers.begin();
                int start_time = max(job_finish_time, workers[min_available_worker]);
                pq.push(make_pair(start_time, v));
                workers[min_available_worker] = start_time + JOB_TIME + v + 1;
            }
        }
    }
    cout << max_time << "\n";
}