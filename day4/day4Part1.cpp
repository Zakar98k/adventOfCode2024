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

int CountXmas(StringVector& words) {
    int count = 0;
    for (int i = 0; i < words.size() - 4; ++i) {
        std::cout << "line: " << i << "\n";
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
            for (const auto& s : sub_words) {
                std::cout << s << "\n";
            }
            sub_words.clear();
            std:: cout << "\n";
        }
    }

    return count;
}

void IterateStringVector(StringVector& vec) {

}

int main() {
    std::string file_name = "day4TestInput.txt";
    StringVector words;

    ReadInputToVector(file_name, words);
    int count = CountXmas(words);

    return 0;
}