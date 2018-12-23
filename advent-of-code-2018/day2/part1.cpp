#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file;
    file.open("input.txt");

    string box_id;
    int checksum = 0;
    int count2 = 0;
    int count3 = 0;
    int letter_counter[26];

    while (file >> box_id)
    {
        fill(letter_counter, letter_counter + 26, 0);
        for (char letter : box_id)
        {
            letter_counter[letter - 'a']++;
        }

        bool has2 = false;
        bool has3 = false;
        for (int i = 0; i < 26; i++)
        {
            if (letter_counter[i] == 2)
                has2 = true;
            if (letter_counter[i] == 3)
                has3 = true;
        }

        count2 += has2;
        count3 += has3;
    }

    checksum = count2 * count3;
    cout << checksum << "\n";
    return 0;
}