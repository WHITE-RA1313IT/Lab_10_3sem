#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left_branch;
    Node* right_branch;
};

void BuildTree(Node*& root, vector<int> const& vec, int const& input) {
    if (root == 0 && input - 1 < vec.size()) {
        root = new Node;
        root->data = vec[input - 1];
        root->left_branch = 0;
        root->right_branch = 0;

        BuildTree(root->left_branch, vec, input * 2);
        BuildTree(root->right_branch, vec, input * 2 + 1);
    }
}

void InvertTree(Node*& root) {
    if (root == 0) return;
    else {
        Node* temp = root->left_branch;
        root->left_branch = root->right_branch;
        root->right_branch = temp;

        InvertTree(root->left_branch);
        InvertTree(root->right_branch);
    }
}

void PrintTree(Node*& root, int level, string& tree) {
    if (root == 0) return;
    else {
        PrintTree(root->left_branch, level + 1, tree);
        if (root->left_branch != 0) {
            for (int i = 0; i < level; i++) tree += "   ";
            tree += "  /\n";
        }
        for (int i = 0; i < level; i++) tree += "   ";
        tree += to_string(root->data) + "\n";
        if (root->right_branch != 0) {
            for (int i = 0; i < level; i++) tree += "   ";
            tree += "  ";
            tree += char(92);
            tree += "\n";
        }
        PrintTree(root->right_branch, level + 1, tree);
    }
}

int main() {
    ofstream outf("C://Users//nikit//Desktop//BinaryTree.txt");
    if (!outf) {
        cout << "Error";
        exit(0);
    }

    Node* root = 0;
    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

    BuildTree(root, vec, 1);

    string tree;
    PrintTree(root, 0, tree);
    cout << tree << endl;
    outf << tree << "\n";

    InvertTree(root);
    tree = "";
    PrintTree(root, 0, tree);
    cout << tree;
    outf << tree;

    outf.close();
}