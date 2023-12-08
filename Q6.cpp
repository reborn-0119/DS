#include <iostream>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    TreeNode* root;

    // Helper functions for various operations
    TreeNode* insertRec(TreeNode* root, int x);
    TreeNode* deleteRec(TreeNode* root, int x);
    TreeNode* findMin(TreeNode* root);
    TreeNode* searchRec(TreeNode* root, int x);
    void displayPreorder(TreeNode* root);
    void displayInorder(TreeNode* root);
    void displayPostorder(TreeNode* root);

public:
    BST() {
        root = NULL;
    }

    // Public methods for operations
    void insert(int x);
    void remove(int x);
    bool search(int x);
    void displayPreorder();
    void displayInorder();
    void displayPostorder();
};

// Insert an element x into the BST
void BST::insert(int x) {
    cout << "Inserting " << x << " into the BST" << endl;
    root = insertRec(root, x);
}

// Helper function for inserting recursively
TreeNode* BST::insertRec(TreeNode* root, int x) {
    if (root == NULL) {
        return new TreeNode(x);
    }

    if (x < root->data) {
        root->left = insertRec(root->left, x);
    } else if (x > root->data) {
        root->right = insertRec(root->right, x);
    }

    return root;
}

// Delete an element x from the BST
void BST::remove(int x) {
    cout << "Deleting " << x << " from the BST" << endl;
    root = deleteRec(root, x);
}

// Helper function for deleting recursively
TreeNode* BST::deleteRec(TreeNode* root, int x) {
    if (root == NULL) {
        return root;
    }

    if (x < root->data) {
        root->left = deleteRec(root->left, x);
    } else if (x > root->data) {
        root->right = deleteRec(root->right, x);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children, get the inorder successor (smallest in the right subtree)
        TreeNode* temp = findMin(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteRec(root->right, temp->data);
    }
    return root;
}

// Helper function to find the node with the minimum value in a BST
TreeNode* BST::findMin(TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Search for an element x in the BST
bool BST::search(int x) {
    return searchRec(root, x) != NULL;
}

// Helper function for searching recursively
TreeNode* BST::searchRec(TreeNode* root, int x) {
    if (root == NULL || root->data == x) {
        return root;
    }

    if (x < root->data) {
        return searchRec(root->left, x);
    }

    return searchRec(root->right, x);
}

// Display the elements of the BST in preorder
void BST::displayPreorder() {
    displayPreorder(root);
    cout << endl;
}

// Helper function for preorder traversal
void BST::displayPreorder(TreeNode* root) {
    if (root != NULL) {
        cout << root->data << " ";
        displayPreorder(root->left);
        displayPreorder(root->right);
    }
}

// Display the elements of the BST in inorder
void BST::displayInorder() {
    displayInorder(root);
    cout << endl;
}

// Helper function for inorder traversal
void BST::displayInorder(TreeNode* root) {
    if (root != NULL) {
        displayInorder(root->left);
        cout << root->data << " ";
        displayInorder(root->right);
    }
}

// Display the elements of the BST in postorder
void BST::displayPostorder() {
    displayPostorder(root);
    cout << endl;
}

// Helper function for postorder traversal
void BST::displayPostorder(TreeNode* root) {
    if (root != NULL) {
        displayPostorder(root->left);
        displayPostorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder Traversal: ";
    bst.displayInorder();

    cout << "Preorder Traversal: ";
    bst.displayPreorder();

    cout << "Postorder Traversal: ";
    bst.displayPostorder();

    int searchKey = 40;
    if (bst.search(searchKey)) {
        cout << searchKey << " found in the BST" << endl;
    } else {
        cout << searchKey << " not found in the BST" << endl;
    }

    cout << "Deleting " << searchKey << " from the BST" << endl;
    bst.remove(searchKey);

    cout << "Inorder Traversal after deletion: ";
    bst.displayInorder();

    return 0;
}
