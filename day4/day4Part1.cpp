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
    for (auto& sub_word : sub_words) {
        if (sub_word == "XMAS" || sub_word == "SAMX")
            count++;
    }

    // Count vertical
    for (int i = 0; i < sub_words[0].size(); ++i) {
        std::string vertical;
        for (int j = 0; j < sub_words.size(); ++j) {
            vertical += sub_words[j][i];
        }
        if (vertical == "XMAS" || vertical == "SAMX")
            count++;
        vertical.clear();
    }
    
}

int CountXmas(StringVector& words) {
    int count = 0;
    for (int i = 0; i < words.size() - 4; ++i) {
        // std::cout << "line: " << i << "\n";
        for (int j = 0; j < words[i].size() - 4; ++j) {
            StringVector sub_words;
            for (int k = i; k < i + 4; ++k) {
                sub_words.emplace_back(words[k], j, 4);
            }
            /* sub_words looks smth like dis:
            {   "MSAM",
                "AMXS",
                "MSAM",
                "XMAS" } */
            CountXmasSubWords(sub_words, count);

            for (const auto& s : sub_words) {
                std::cout << s << "\n";
            }
            sub_words.clear();
            std:: cout << "\n";
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