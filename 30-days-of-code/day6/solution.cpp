#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test_count;
    cin >> test_count;

    while (test_count--)
    {
        string S;
        cin >> S;

        string odd_letters = "";
        string even_letters = "";

        for (int i = 0; i < S.size(); i++)
        {
            if (i % 2 == 0)
                even_letters += S[i];
            else
                odd_letters += S[i];
        }

        cout << even_letters << " " << odd_letters << "\n";
    }
}