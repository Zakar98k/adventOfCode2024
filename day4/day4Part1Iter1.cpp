// This iteration don't damn work lol... I thought I could do some wacky 4x4 stuff
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

void CountXmasSubWords(StringVector& sub_words, int& count) {
    // Count horizontal
    std::cout << "Horizontal: "; 
    for (auto& sub_word : sub_words) {
        std::cout << sub_word << " ";
        if (sub_word == "XMAS" || sub_word == "SAMX")
            count++;
    }
    std::cout << "\n"; 

    // Count vertical
    std::cout << "Vertical: ";
    for (int i = 0; i < sub_words[0].size(); ++i) {
        std::string vertical;
        for (int j = 0; j < sub_words.size(); ++j) {
            vertical += sub_words[j][i];
        }
        if (vertical == "XMAS" || vertical == "SAMX")
            count++;
        std::cout << vertical << " ";
        vertical.clear();
    }
    std::cout << "\n";

    // Count diagonal
    std::string diagonal;
    for (int i = 0; i < sub_words.size(); i++) {
        diagonal += sub_words[i][i];
    }
    if (diagonal == "XMAS" || diagonal == "SAMX")
        count++;
    std::cout << "diagonal 1: " << diagonal << "\n";
    diagonal.clear();

    diagonal += sub_words[0][3];
    diagonal += sub_words[1][2];
    diagonal += sub_words[2][1];
    diagonal += sub_words[3][0];
    if (diagonal == "XMAS" || diagonal == "SAMX")
        count++;
    std::cout << "diagonal 2: " << diagonal << "\n";
    diagonal.clear();
}

int CountXmas(StringVector& words) {
    int count = 0;
    for (int i = 0; i < words.size() - 3; i++) {
        // std::cout << "line: " << i << "\n";
        for (int j = 0; j < words[i].size() - 3; ++j) {
            StringVector sub_words;
            for (int k = i; k < i + 4; ++k) {
                sub_words.emplace_back(words[k], j, 4);
            }
            /* sub_words looks smth like dis:
            {   "MSAM",
                "AMXS",
                "MSAM",
                "XMAS" } */

            for (const auto& s : sub_words) {
                std::cout << s << "\n";
            }

            CountXmasSubWords(sub_words, count);
            std:: cout << "\n";

            sub_words.clear();
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