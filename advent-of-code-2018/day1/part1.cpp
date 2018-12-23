#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file;
    file.open("input.txt");

    int frequency = 0;
    int value;
    while (file >> value)
    {
        frequency += value;
    }

    cout << frequency << "\n";
}
