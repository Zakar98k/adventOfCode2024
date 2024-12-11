#include <iostream>
#include <string>
#include <sstream>
#include <vector> // Dynamic arrays
#include <fstream> // File input handling
#include <algorithm> // provides sorting
#include <cmath> // provides abs()

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stringstream;
using std::getline;

// Returns a vector of strings split by a delimiter
vector<string> splitString(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;

    // getline returns false once it hits end of line
    // an str is extracted to token once a delimiter has been hit
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

int main()
{
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Error: Could not open file.\n";
        return 1;
    }

    string line;

    vector<int> l1;
    vector<int> l2;

    while (std::getline(file, line)) {
        vector v = splitString(line, ' ');

        // index 3, because the input is separated by 3 spaces for some reason
        l1.push_back(std::stoi(v[0]));
        l2.push_back(std::stoi(v[3]));
    }

    file.close();

    std::stable_sort(l1.begin(), l1.end());
    std::stable_sort(l2.begin(), l2.end());

    // for (int i: l1) {
    //     cout << "l1: " << i << ' ';
    // }
    // for (int i: l2) {
    //     cout << "l2: " << i << ' ';
    // }

    int totalLength = 0;

    // l1 and l2 have same size
    for (int i = 0; i < l1.size(); i++) {
        totalLength += (abs(l1[i] - l2[i]));
    }

    cout << totalLength;

    return 0;
}

