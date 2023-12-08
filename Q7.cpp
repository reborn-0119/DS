#include <iostream>
#include <algorithm>

using namespace std;

class AVLNode {
public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int k) : key(k), left(NULL), right(NULL), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node);
    int balanceFactor(AVLNode* node);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* balance(AVLNode* node);
    AVLNode* insert(AVLNode* node, int key);
    bool search(AVLNode* node, int key);
    void displayTree(AVLNode* root, int level);

public:
    AVLTree() : root(NULL) {}

    void insert(int key);
    bool search(int key);
    void displayTree();
};

int AVLTree::height(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int AVLTree::balanceFactor(AVLNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

AVLNode* AVLTree::balance(AVLNode* node) {
    if (node == NULL)
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int bf = balanceFactor(node);

    // Left Heavy
    if (bf > 1) {
        if (balanceFactor(node->left) < 0) {
            // Left-Right Case
            node->left = rotateLeft(node->left);
        }
        // Left-Left Case
        return rotateRight(node);
    }
    // Right Heavy
    if (bf < -1) {
        if (balanceFactor(node->right) > 0) {
            // Right-Left Case
            node->right = rotateRight(node->right);
        }
        // Right-Right Case
        return rotateLeft(node);
    }

    return node;
}

AVLNode* AVLTree::insert(AVLNode* node, int key) {
    if (node == NULL)
        return new AVLNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys not allowed

    return balance(node);
}

bool AVLTree::search(AVLNode* node, int key) {
    if (node == NULL)
        return false;

    if (key < node->key)
        return search(node->left, key);
    else if (key > node->key)
        return search(node->right, key);
    else
        return true; // Key found
}

void AVLTree::displayTree(AVLNode* root, int level) {
    if (root != NULL) {
        displayTree(root->right, level + 1);
        for (int i = 0; i < level; i++) cout << "    ";
        cout << root->key << endl;
        displayTree(root->left, level + 1);
    }
}

void AVLTree::insert(int key) {
    root = insert(root, key);
    cout << "Inserted " << key << " into the AVL Tree" << endl;
    displayTree();
}

bool AVLTree::search(int key) {
    return search(root, key);
}

void AVLTree::displayTree() {
    cout << "AVL Tree:" << endl;
    displayTree(root, 0);
    cout << endl;
}

int main() {
    AVLTree avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);

    avl.displayTree();

    int searchKey1 = 20;
    cout << "Search for key " << searchKey1 << ": " << (avl.search(searchKey1) ? "Found" : "Not Found") << endl;

    int searchKey2 = 15;
    cout << "Search for key " << searchKey2 << ": " << (avl.search(searchKey2) ? "Found" : "Not Found") << endl;

    return 0;
}

