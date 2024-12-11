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

void GetProducts(
    std::string& content, 
    std::smatch& match, 
    std::regex& pattern, 
    std::vector<int>& products
) {
    bool can_continue = true;
    while (std::regex_search(content, match, pattern)) {
        // Calculate mul(X,Y)

        std::string prefix = match.prefix().str();
        std::smatch continue_match;
        std::regex continue_pattern("do\\(\\)|don\\'t\\(\\)");

        std::sregex_iterator iter(prefix.begin(), prefix.end(), continue_pattern);
        std::sregex_iterator end;

        std::smatch last_match;
        bool found_match = false;

        // Iterate through all matches in the prefix
        while (iter != end) {
            last_match = *iter;  // Capture the current match
            ++iter;              // Move to the next match
            found_match = true;  // We found at least one match
        }

        if (found_match) {
            // If we found a match, print the last one

            // Logic to decide if we continue
            if (last_match.str() == "do()") {
                can_continue = true;
            } else if (last_match.str() == "don't()") {
                can_continue = false;
            }
        } 
        // If we can continue, calculate the product and push to products
        if (can_continue) {
            products.push_back((std::stoi(match[1]) * std::stoi(match[2])));
        }

        // Update content for the next iteration
        content = match.suffix().str();
    }
}

int main() {
    std::string file_name = "day3Input.txt";
    std::string content = ReadDataFromFile(file_name);
    std::smatch match;
    std::regex pattern("mul\\((\\d{1,3}),(\\d{1,3})\\)"); // Matches mul(x,y)
    std::vector<int> products; // Will sum these up later 

    GetProducts(content, match, pattern, products);

    std::cout << std::accumulate(products.begin(), products.end(), 0) << "\n";

    return 0;
}