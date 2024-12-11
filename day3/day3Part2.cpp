#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>
#include <vector>
#include <numeric>

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

void SearchInputForInstructions(
    std::string& content, 
    std::smatch& match, 
    std::regex& pattern, 
    std::vector<int>& products
) {
    while (std::regex_search (content, match, pattern)) {
        // for (auto m : match) std::cout << m << " ";
        // Calculate mul(X,Y)
        products.push_back((std::stoi(match[1]) * std::stoi(match[2]))); 
        // std::cout << '\n';
        content = match.suffix().str();
    }

}

int main() {
    std::string file_name = "day3Input.txt";
    std::string content = ReadDataFromFile(file_name);
    std::smatch match;
    std::regex pattern("mul\\((\\d{1,3}),(\\d{1,3})\\)");
    std::vector<int> products; // Will sum these up later 

    SearchInputForInstructions(content, match, pattern, products);
    std::cout << std::accumulate(products.begin(), products.end(), 0) << "\n";

    return 0;
}