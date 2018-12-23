#include <bits/stdc++.h>

using namespace std;

int calculate_total_cost(double meal_cost, int tip_percent, int tax_percent)
{
    double tip_cost = meal_cost * (tip_percent / 100.0);
    double tax_cost = meal_cost * (tax_percent / 100.0);
    return round(meal_cost + tip_cost + tax_cost);
}

int main()
{
    double meal_cost;
    int tip_percent;
    int tax_percent;
    cin >> meal_cost >> tip_percent >> tax_percent;

    int result = calculate_total_cost(meal_cost, tip_percent, tax_percent);
    cout << result << "\n";
}