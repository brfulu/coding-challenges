#include <bits/stdc++.h>

using namespace std;

class Point
{
  public:
    int x;
    int y;

    Point(int _x, int _y) : x(_x), y(_y) {}
    Point() : x(0), y(0) {}
};

int get_distance(Point a, Point b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool is_in_rectangle(Point upper_left, Point lower_right, Point p)
{
    return p.x > upper_left.x && p.x < lower_right.x && p.y > upper_left.y && p.y < lower_right.y;
}

int get_closest_point(vector<Point> points, Point p)
{
    int min_distance = INT_MAX;
    int closest_point = -1;
    for (int i = 0; i < points.size(); i++)
    {
        if (get_distance(points[i], p) == min_distance)
        {
            closest_point = -1;
        }
        if (get_distance(points[i], p) < min_distance)
        {
            min_distance = get_distance(points[i], p);
            closest_point = i;
        }
    }
    return closest_point;
}

set<int> get_infnite_points(vector<Point> points, vector<Point> border_points)
{
    set<int> infinte_points;
    for (Point p : border_points)
    {
        int closest_point = get_closest_point(points, p);
        if (closest_point >= 0)
        {
            infinte_points.insert(closest_point);
        }
    }
    return infinte_points;
}

int main()
{
    fstream file;
    file.open("input.txt");
    string line;
    vector<Point> points;
    Point upper_left(INT_MAX, INT_MAX);
    Point lower_right(-INT_MAX, -INT_MAX);

    while (getline(file, line))
    {
        Point p;
        sscanf(line.c_str(), "%d, %d", &p.x, &p.y);
        points.push_back(p);

        upper_left.x = min(upper_left.x, p.x);
        upper_left.y = min(upper_left.y, p.y);

        lower_right.x = max(lower_right.x, p.x);
        lower_right.y = max(lower_right.y, p.y);
    }

    vector<Point> border_points;
    for (int x = upper_left.x; x <= lower_right.x; x++)
    {
        border_points.push_back(Point(x, upper_left.y));
        border_points.push_back(Point(x, lower_right.y));
    }
    for (int y = upper_left.y; y <= lower_right.y; y++)
    {
        border_points.push_back(Point(upper_left.x, y));
        border_points.push_back(Point(lower_right.x, y));
    }

    set<int> infinte_points = get_infnite_points(points, border_points);
    vector<int> area_counter(points.size());

    for (int x = upper_left.x; x <= lower_right.x; x++)
    {
        for (int y = upper_left.y; y <= lower_right.y; y++)
        {
            Point p(x, y);
            int closest_point = get_closest_point(points, p);
            if (closest_point >= 0)
            {
                area_counter[closest_point]++;
            }
        }
    }

    int max_area = 0;
    for (int i = 0; i < area_counter.size(); i++)
    {
        if (area_counter[i] > max_area && infinte_points.count(i) == 0)
        {
            max_area = max(max_area, area_counter[i]);
        }
    }
    cout << max_area << "\n";
}