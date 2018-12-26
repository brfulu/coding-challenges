#include <bits/stdc++.h>

using namespace std;

enum event_type
{
    SHIFT_CHANGE,
    FALLS_ASLEEP,
    WAKES_UP
};

class Event
{
  public:
    string date;
    int hour, minute;
    event_type type;
    int guard_id;

    Event(string date, int hour, int minute, event_type type, int guard_id)
    {
        this->date = date;
        this->hour = hour;
        this->minute = minute;
        this->type = type;
        this->guard_id = guard_id;
    }
};

bool cmp(Event a, Event b)
{
    if (a.date != b.date)
        return a.date < b.date;
    else if (a.hour != b.hour)
        return a.hour < b.hour;
    else
        return a.minute < b.minute;
}

int solve(vector<Event> &events)
{
    map<int, vector<int>> guard_counter;
    int guard_id = -1;

    for (Event e : events)
    {
        if (e.type == SHIFT_CHANGE)
        {
            guard_id = e.guard_id;
            if (guard_counter.find(guard_id) == guard_counter.end())
            {
                vector<int> counter(60);
                guard_counter[guard_id] = counter;
            }
        }
        else if (e.type == FALLS_ASLEEP)
        {
            int minute_start = e.minute;
            guard_counter[guard_id][minute_start]++;
        }
        else if (e.type == WAKES_UP)
        {
            int minute_end = e.minute;
            guard_counter[guard_id][minute_end]--;
        }
    }

    int guard_max_asleep_id = -1;
    int max_asleep = -1;
    int minute_max_asleep = -1;

    for (auto guard : guard_counter)
    {
        int count_asleep = 0;
        int current_max_minute = 0;

        for (int i = 1; i < 60; i++)
        {
            guard.second[i] += guard.second[i - 1];
            count_asleep += guard.second[i];
            if (guard.second[i] > guard.second[current_max_minute])
            {
                current_max_minute = i;
            }
        }

        if (count_asleep > max_asleep)
        {
            guard_max_asleep_id = guard.first;
            max_asleep = count_asleep;
            minute_max_asleep = current_max_minute;
        }
    }

    return guard_max_asleep_id * minute_max_asleep;
}

int main()
{
    fstream file;
    file.open("input.txt");

    vector<Event> events;
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string date, time_str, type_str, guard_str;
        string temp;

        ss >> date;
        ss >> time_str;
        ss >> type_str;
        ss >> guard_str;

        date = date.substr(1);
        time_str = time_str.substr(0, time_str.size() - 1);

        event_type type = SHIFT_CHANGE;
        if (type_str == "falls")
        {
            type = FALLS_ASLEEP;
        }
        else if (type_str == "wakes")
        {
            type = WAKES_UP;
        }

        int hour, minute;
        sscanf(time_str.c_str(), "%d:%d", &hour, &minute);

        int guard_id = -1;
        if (type == SHIFT_CHANGE)
        {
            sscanf(guard_str.c_str(), "#%d", &guard_id);
        }

        Event event(date, hour, minute, type, guard_id);
        events.push_back(event);
    }

    sort(events.begin(), events.end(), cmp);
    int result = solve(events);
    cout << result << "\n";
}