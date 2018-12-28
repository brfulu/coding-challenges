#include <bits/stdc++.h>

using namespace std;

class Point
{
  public:
    int x;
    int y;

    Point(int _x, int _y) : x(_x), y(_y) {}
    Point() : x(0), y(0) {}

    bool operator<(const Point &other) const
    {
        if (this->x < other.x)
            return this->x < other.x;
        else
            return this->y < other.y;
    }
};

int get_distance(Point a, Point b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

const int LIMIT = 10000;

int main()
{
    fstream file;
    file.open("input.txt");
    string line;

    vector<Point> points;
    int max_x = 0, max_y = 0;

    while (getline(file, line))
    {
        Point p;
        sscanf(line.c_str(), "%d, %d", &p.x, &p.y);
        points.push_back(p);
        max_x = max(max_x, p.x);
        max_y = max(max_y, p.y);
    }

    int area = 0;
    for (int x = 0; x < max_x + 200; x++)
    {
        for (int y = 0; y < max_y + 200; y++)
        {
            Point p1(x, y);
            int total_dist = 0;
            for (Point p2 : points)
            {
                total_dist += get_distance(p1, p2);
            }
            area += (total_dist < LIMIT);
        }
    }
    cout << area << "\n";
}