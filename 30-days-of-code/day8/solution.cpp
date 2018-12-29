#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, string> phone_book;

    for (int i = 0; i < n; i++)
    {
        string name, number;
        cin >> name >> number;
        phone_book[name] = number;
    }

    string query_name;
    while (cin >> query_name)
    {
        if (phone_book.count(query_name) > 0)
            cout << query_name << "=" << phone_book[query_name] << "\n";
        else
            cout << "Not found\n";
    }

    return 0;
}