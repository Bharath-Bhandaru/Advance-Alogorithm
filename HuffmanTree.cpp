#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <limits>
#include <algorithm>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void printCodes(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (!root)
        return;

    if (root->ch != '#')
        huffmanCode[root->ch] = str;

    printCodes(root->left, str + "0", huffmanCode);
    printCodes(root->right, str + "1", huffmanCode);
}

unordered_map<char, string> buildHuffmanTree(string S, vector<int> f) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < S.size(); ++i) {
        pq.push(new Node(S[i], f[i]));
    }

    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *top = new Node('#', left->freq + right->freq);
        top->left = left;
        top->right = right;
        pq.push(top);
    }

    unordered_map<char, string> huffmanCode;
    printCodes(pq.top(), "", huffmanCode);
    return huffmanCode;
}

bool isValidString(const string& input) {
    for (char c : input) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

bool isValidFrequencies(const string& input, vector<int>& frequencies, int length) {
    frequencies.clear();
    istringstream iss(input);
    int num;
    while (iss >> num) {
        frequencies.push_back(num);
    }
    return frequencies.size() == length;
}

int main() {
    string S;
    vector<int> f;
    int N;

    while (true) {
        cout << "Enter the characters (distinct letters): ";
        cin >> S;
        if (isValidString(S) && S.size() <= 26) { // Allowing only distinct letters (up to 26)
            break;
        } else {
            cout << "Invalid input. Please enter distinct letters only." << endl;
        }
    }

    N = S.size();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    while (true) {
        string freqInput;
        cout << "Enter the frequencies (space-separated): ";
        getline(cin, freqInput);
        if (isValidFrequencies(freqInput, f, N)) {
            break;
        } else {
            cout << "Invalid input. Please enter exactly " << N << " frequencies." << endl;
        }
    }

    unordered_map<char, string> huffmanCode = buildHuffmanTree(S, f);

    cout << "Huffman codes will be:" << endl;
    
    
    vector<string> codes;
    for (char c : S) {
        codes.push_back(huffmanCode[c]);
    }
    

    sort(codes.begin(), codes.end());
    for (const auto& code : codes) {
        cout << code << " ";
    }
    cout << endl;

    for (const auto& pair : huffmanCode) {
        cout << "  " << pair.first << " : " << pair.second << endl;
    }

    return 0;
}
