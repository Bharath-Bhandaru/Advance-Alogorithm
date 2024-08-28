#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

pair<int, int> twoSum(vector<int>& numbers, int sum) {
    auto m = map<int, int>();

    for (size_t i = 0; i < numbers.size(); ++i) {
        auto key = sum - numbers[i];
        if (m.find(key) != m.end()) {
            return make_pair(m[key], i);
        }
        m[numbers[i]] = i;
    }

    return make_pair(-1, -1);
}

vector<int> getInputArray(int size) {
    vector<int> numbers;
    cout << "Please enter " << size << " integer values separated by spaces: ";
    string line;
    getline(cin, line);
    stringstream ss(line);
    int value;
    while (ss >> value) {
        if (value < -1000000000 || value > 1000000000) {
            throw runtime_error("Value out of constraints. Please enter values between -10^9 and 10^9.");
        }
        numbers.push_back(value);
    }

    if (numbers.size() != size) {
        throw runtime_error("Incorrect number of values entered.");
    }

    return numbers;
}

int getTargetValue() {
    int target;
    string line;
    cout << "Please enter the target value (integer): ";
    getline(cin, line);
    stringstream ss(line);

    if (!(ss >> target)) {
        throw runtime_error("Invalid input. Please enter an integer.");
    }

    
    if (target < -1000000000 || target > 1000000000) {
        throw runtime_error("Target value out of constraints. Please enter a value between -10^9 and 10^9.");
    }

    return target;
}

int main() {
    try {
        int size;
        cout << "Enter the size of the array: ";
        cin >> size;
        cin.ignore(); // Ignore the remaining newline character

        
        if (size < 2 || size > 10000) {
            throw runtime_error("Array size must be between 2 and 10,000.");
        }

        vector<int> numbers = getInputArray(size);
        int target = getTargetValue();

        auto ts = twoSum(numbers, target);

        if (-1000000000 <= target && target <= 1000000000 && ts.first != -1) {
            cout << "Output: {" << ts.first << ", " << ts.second << "}" << endl;
        } else {
            cout << "no result" << endl;
        }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
