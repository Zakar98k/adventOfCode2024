#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

typedef std::vector<std::string> StringVector;

void ReadInputToVector(std::string& file_name, StringVector& words) {
    std::ifstream input_file(file_name);

    if (!input_file) {
        std::cerr << "Error: unable to open file " << file_name << '\n';
        return;
    }

    std::string line;
    while (getline(input_file, line)) {
        words.push_back(line);
    }
}

void FindXmas(int& row, int& col, StringVector& words, int& count) {
    // Start with X
    if (words[row][col] != 'X') 
        return;
    
    
}

int CountXmas(StringVector& words) {
    int count = 0;
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < words[i].size(); ++j) {
            FindXmas(i, j, words, count);
        }
    }
    
}

int main() {
    std::string file_name = "day4TestInput.txt";
    StringVector words;

    ReadInputToVector(file_name, words);
    int count = CountXmas(words);

    std::cout << count << "\n";

    return 0;
}