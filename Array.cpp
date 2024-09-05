#include <iostream>
#include <sstream>
#include <limits> 
using namespace std;

bool validateInput(int& value) {
    if (!(cin >> value)) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Sorry, you have given wrong input. Can you re-try or to quit enter 'quit'." << endl;
        return false;
    }
    return true;
}

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    while (!validateInput(rows)) {}

    cout << "Enter the number of columns: ";
    while (!validateInput(cols)) {}

    int matrix[rows][cols] = {0};  

    cout << "Enter the elements of the matrix row by row (use spaces between numbers): " << endl;

    
    for (int i = 0; i < rows; i++) {
        string inputLine;
        bool validInput = false;
        while (!validInput) {
            validInput = true; 
            getline(cin >> ws, inputLine); 

            stringstream ss(inputLine); 
            int element;
            for (int j = 0; j < cols; j++) {
                if (!(ss >> element)) {
                    cout << "Sorry, you have given wrong input. Can you re-try or to quit enter 'quit'." << endl;
                    validInput = false;
                    break;
                }
                matrix[i][j] = element;
            }
        }
    }

    int nonZeroCount = 0;
    int compactMatrix[3][rows * cols];  // Assuming worst case, no zeroes

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                compactMatrix[0][nonZeroCount] = i;
                compactMatrix[1][nonZeroCount] = j;
                compactMatrix[2][nonZeroCount] = matrix[i][j];
                nonZeroCount++;
            }
        }
    }

    
    cout << "Representation of sparse matrix is: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < nonZeroCount; j++) {
            cout << compactMatrix[i][j] << " ";
        }
        cout << endl;
    }

    
    int zeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
            }
        }
    }

    
    cout << "Number of zeros = " << zeroCount << endl;
    if (zeroCount > (rows * cols) / 2) {
        cout << "The matrix is a sparse matrix." << endl;
    } else {
        cout << "The matrix is not a sparse matrix." << endl;
    }

    return 0;
}
