#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>
#include <vector>

typedef std::vector<std::string> StringVector;

std::string ReadDataFromFile(std::string& file_name) {
    std::ifstream input_file(file_name);

    if (!input_file) {
        std::cerr << "Error: cannot open file " << file_name << '\n';
        std::exit(0);
    }

    std::ostringstream buffer;
    buffer << input_file.rdbuf();
    return buffer.str();
}

void SearchForInstructions(
    std::string& content, 
    std::smatch& match, 
    std::regex& pattern, 
    StringVector& instructions
) {
    while (std::regex_search (content, match, pattern)) {
        for (auto m : match) std::cout << m << " ";
        std::cout << '\n';
        content = match.suffix().str();
    }

}

int main() {
    std::string file_name = "day3TestInput.txt";
    std::string content = ReadDataFromFile(file_name);
    std::smatch match;
    std::regex pattern("mul\\((\\d{1,3}),(\\d{1,3})\\)");
    StringVector instructions; // Will sum these up later 

    SearchForInstructions(content, match, pattern, instructions);

    return 0;
}