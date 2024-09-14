#include <iostream>
#include <string>
#include <algorithm>  
using namespace std;

struct MatrixNode {
    int rowIndex;
    int colIndex;
    int dataValue;
    MatrixNode* nextNode;
};


MatrixNode* createMatrixNode(int row, int col, int value) {
    MatrixNode* newNode = new MatrixNode();
    newNode->rowIndex = row;
    newNode->colIndex = col;
    newNode->dataValue = value;
    newNode->nextNode = nullptr;
    return newNode;
}

MatrixNode* matrixToLinkedList(int** matrix, int rows, int cols) {
    MatrixNode* head = nullptr;
    MatrixNode* tail = nullptr;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                MatrixNode* newNode = createMatrixNode(i, j, matrix[i][j]);
                if (head == nullptr) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->nextNode = newNode;
                    tail = newNode;
                }
            }
        }
    }
    return head;
}

void printLinkedList(MatrixNode* head) {
    MatrixNode* temp = head;
    while (temp != nullptr) {
        cout << "(" << temp->rowIndex << ", " << temp->colIndex << ", " << temp->dataValue << ") -> ";
        temp = temp->nextNode;
    }
    cout << "NULL" << endl;
}

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns of the matrix: ";
    cin >> rows >> cols;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    cout << "Enter elements of the sparse matrix (0 for empty): " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    MatrixNode* head = matrixToLinkedList(matrix, rows, cols);
    cout << "Linked list representation of the sparse matrix is: " << endl;
    printLinkedList(head);

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
