#include <iostream>
#include <vector>
#include <string>
#include <set>

std::set<std::string> findLongestCommonSubstrings(const std::string& str1, const std::string& str2, int& maxLength) {
    int len1 = str1.size();
    int len2 = str2.size();

    std::vector<std::vector<int>> dpTable(len1 + 1, std::vector<int>(len2 + 1, 0));
    maxLength = 0;
    std::set<std::string> longestSubstrings;
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dpTable[i][j] = dpTable[i - 1][j - 1] + 1;
                if (dpTable[i][j] > maxLength) {
                    maxLength = dpTable[i][j];
                    longestSubstrings.clear();  
                    longestSubstrings.insert(str1.substr(i - maxLength, maxLength));
                } else if (dpTable[i][j] == maxLength) {
                    longestSubstrings.insert(str1.substr(i - maxLength, maxLength));
                }
            }
        }
    }

    std::cout << "\nDP Table:\n";
    for (const auto& row : dpTable) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }

    return longestSubstrings;
}

int main() {
    std::string str1, str2;
    std::cout << "Enter the first string: ";
    std::cin >> str1;
    std::cout << "Enter the second string: ";
    std::cin >> str2;

    int length = 0;
    std::set<std::string> longestSubstrings = findLongestCommonSubstrings(str1, str2, length);

    std::cout << "\nLongest Common Substring(s):\n";
    for (const auto& substr : longestSubstrings) {
        std::cout << substr << " (Length: " << length << ")\n";
    }

    return 0;
}
