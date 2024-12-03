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
    left.sort();
    right.sort();

    unsigned int total_distance = 0;
    auto it_left = left.begin(); // 🏎️ auto
    auto it_right = right.begin(); // 🏎️ auto

    while (it_left != left.end() && it_right != right.end())
    {
        total_distance += abs(*it_left - *it_right);
        ++it_left;
        ++it_right;
    }

    cout << "Total distance: " << total_distance << endl;


    input_file.close();
    return 0;
}
