#include <iostream>
#include <string>
#include <vector>
#define all(x) x.begin(), x.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;
};

Node *createNode(char data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void postorder(Node *root){
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
}

Node *recoverTree(int ini_pre, int fim_pre, int ini_in, int fim_in, string pre, string in){
    //ini_pre, fim_pre, ini_in, fim_in, pre, in
    if(ini_in > fim_in){
        return nullptr;
    }

    char letter_root = pre[ini_pre];
    //daria para precomputar em um hash table os indices de cada root no inorder e consultar em O(1)
    auto it = find(all(in), letter_root); // find the index in the inorder to divide
    int idx = distance(in.begin(), it); //tranform to int
    Node *root = createNode(letter_root);

    int size = idx - ini_in;

    root->left = recoverTree(ini_pre + 1, ini_pre + size, ini_in, idx - 1, pre, in);
    root->right = recoverTree(ini_pre + size + 1, fim_pre, idx + 1, fim_in, pre, in);
    return root;
}

Node *recoverTree(string preorder, string inorder){
    Node *root = recoverTree(0, preorder.length() - 1, 0, inorder.length() - 1, preorder, inorder);
    return root;
}

int main(){
    //recover a binary tree using only preorder and inorder traversal.
    string preorder, inorder;
    Node *root = nullptr;
    while (cin >> preorder >> inorder) {
        root = recoverTree(preorder, inorder);
        postorder(root);
        cout << endl;
    }
}
