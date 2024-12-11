#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

typedef std::vector<std::vector<int>> IntMatrix;

void ReadDataFromFile(std::string& file_name, IntMatrix& reports) {
    std::ifstream input_file(file_name);
    std::string line;
    int word;

    if (!input_file) {
        std::cerr << "Error: unable to open file " << file_name << '\n';
    }

    while (getline(input_file, line)) {
        std::vector<int> report;
        std::istringstream ss(line);

        while (ss >> word) {
            report.push_back(word);
        }
        reports.push_back(report);

        /* reports should look something like this:
        {
            {7, 6, 4, 2, 1},
            {1, 2, 7, 8, 9},
            {9, 7, 6, 2, 1},
        }
        */
    }

    input_file.close();
}

// Returns the safety of a given report
bool IsSafe(const std::vector<int>& report) {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 1; i < report.size(); i++) {
        int diff = abs(report[i] - report[i - 1]);

        if (diff < 1 || diff > 3)
            return false;
        if (report[i] < report[i - 1]) 
            increasing = false;
        if (report[i] > report[i - 1]) 
            decreasing = false;
    }

    return increasing || decreasing;
}

void PrintIntMatrix(std::vector<std::vector<int>>& matrix) {
    for (std::vector<int> i : matrix) {
        for (int j : i) {
            std::cout << j << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    IntMatrix reports;
    std::string file_name = "input.txt";
    ReadDataFromFile(file_name, reports);
    int safe_count = 0;

    for (const auto& report : reports) {
        if (IsSafe(report)) {
            safe_count++;
        }
    }
    std::cout << '\n' << safe_count << '\n';

    return 0;
}