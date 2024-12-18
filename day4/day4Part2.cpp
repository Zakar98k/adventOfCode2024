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
    if (words[row + 1][col + 1] != 'A') {
        return;
    }

    StringVector sub_words;
    for (int i = 0; i < 3; i++) {
        sub_words.emplace_back(words[row + i], col, 3);
    }
    if (sub_words[0][0] == 'X' || sub_words[0][0] == 'A' || sub_words[0][2] == 'X' || sub_words[0][2] == 'A')
        return;
    else if (sub_words[2][0] == 'X' || sub_words[2][0] == 'A' || sub_words[2][2] == 'X' || sub_words[2][2] == 'A')
        return;
    
    std::string diagonal;
    for (int i = 0; i < sub_words.size(); i++)
        diagonal.push_back(sub_words[i][i]);
    // std::cout << "d1: " << diagonal << '\n';
    if (diagonal != "SAM" && diagonal != "MAS")
        return;

    diagonal.clear();
    for (int i = 0; i < sub_words.size(); i++)
        diagonal.push_back(sub_words[i][sub_words.size()-1 - i]);
    if (diagonal != "SAM" && diagonal != "MAS")
        return;
    // for (auto& s : sub_words) {
    //     std::cout << s << '\n';
    // }
    // std::cout << words[row + 1][col + 1] << '\n';
    // std::cout << "\n";
    count++;
}

int CountXmas(StringVector& words) {
    int count = 0;
    for (int i = 0; i <= words.size() - 3; ++i) {
        for (int j = 0; j <= words[i].size() - 3; ++j) {
            FindXmas(i, j, words, count);
        }
    }

    return count;
    
}

int main() {
    std::string file_name = "day4Input.txt";
    StringVector words;

    ReadInputToVector(file_name, words);
    int count = CountXmas(words);

    std::cout << count << "\n";

    return 0;
}