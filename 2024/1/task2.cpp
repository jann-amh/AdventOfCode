#include <algorithm>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

int main()
{
    ifstream input_file("input.txt");
    string text;
    string delimiter = "   ";
    list<int> left, right;

    while (getline(input_file, text))
    {
        unsigned int pos = text.find(delimiter);
        left.push_front(stoi(text.substr(0, pos)));
        right.push_front(stoi(text.substr(pos + delimiter.length(), std::string::npos)));
    }

    auto it_left = left.begin(); // 🏎️ auto
    auto it_right = right.begin(); // 🏎️ auto
    int result = 0;

    for (auto left_value : left) {
        int counter = 0;

        for (auto right_value : right) {
            if (left_value == right_value) {
                counter++;
            }
        }

        result += left_value * counter ;
    }

    cout << "Gesamtanzahl der Übereinstimmungen: " << result << endl;

    input_file.close();
    return 0;
}
