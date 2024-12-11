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

    int similarityScore = 0;
    // Iterate through l1
    for (int i = 0; i < l1.size(); i++) {
        int count = std::count(l2.begin(), l2.end(), l1[i]);
        similarityScore += (l1[i] * count);
    }

    cout << similarityScore;

    return 0;
}

