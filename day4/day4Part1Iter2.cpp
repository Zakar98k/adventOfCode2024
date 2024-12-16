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

    // Right
    int i = 0;
    const std::string XMAS = "XMAS";
    std::string current_word = "";
    while (col + i < words[row].size() && i < 4) {
        if (words[row][col + i] == XMAS[i]) {
            current_word.push_back(words[row][col + i]);
        } else 
            break;
        i++;
    } if (current_word == XMAS) {
        std::cout << "right found at r" << row << " c" << col << "\n";
        count++;
    }

    // Left
    i = 0;
    current_word.clear();
    while (col - i > 0 && i < 4) {
        if (words[row][col - i] == XMAS[i]) {
            current_word.push_back(words[row][col - i]);
        } else 
            break;
        i++;
    } if (current_word == XMAS) {
        std::cout << "left found at r" << row << " c" << col << "\n";
        count++;
    }
}

int CountXmas(StringVector& words) {
    int count = 0;
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < words[i].size(); ++j) {
            FindXmas(i, j, words, count);
        }
    }

    return count;
    
}

int main() {
    std::string file_name = "day4TestInput.txt";
    StringVector words;

    ReadInputToVector(file_name, words);
    int count = CountXmas(words);

    std::cout << count << "\n";

    return 0;
}