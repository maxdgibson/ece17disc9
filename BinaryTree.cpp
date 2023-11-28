#include "BinaryTree.h"
#include <iostream>


BinaryTree::BinaryTree() { root = nullptr; }

void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
    if (nodePtr == nullptr) {
        nodePtr = newNode;				// Insert the node.
    }
    else if (newNode->value < nodePtr->value) {
        insert(nodePtr->left, newNode); // Search the left branch
    }
    else {
        insert(nodePtr->right, newNode);// Search the right branch
    }
}


void BinaryTree::insertNode(int num) {
    TreeNode *newNode = nullptr; // Pointer to a new node.

    // Create a new node and store num in it.
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;

    // Insert the node.
    insert(root, newNode);
}



void BinaryTree::destroySubTree(TreeNode *nodePtr) {
    if (nodePtr->left) {
        destroySubTree(nodePtr->left);
    }

    if (nodePtr->right) {
        destroySubTree(nodePtr->right);
    }

    delete nodePtr;
}


bool BinaryTree::searchNode(int num) {
    bool status = false;

    TreeNode *nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == num) {
            status = true;
        }
        else if (num < nodePtr->value) {
            nodePtr = nodePtr->left;
        }
        else {
            nodePtr = nodePtr->right;
        }
    }

    return status;
}


void BinaryTree::remove(int num) {
    deleteNode(num, root);
}


void BinaryTree::deleteNode(int num, TreeNode *&nodePtr) {
    if (num < nodePtr->value) {
        deleteNode(num, nodePtr->left);
    }
    else if (num > nodePtr->value) {
        deleteNode(num, nodePtr->right);
    }
    else {
        makeDeletion(nodePtr);
    }
}
void BinaryTree::makeDeletion(TreeNode *&nodePtr) {
    // Temporary pointer, used in reattaching the left subtree.
    TreeNode *tempNodePtr = nullptr;

    if (nodePtr == nullptr) {
        cout << "Cannot delete empty node.\n";
    }
    else if (nodePtr->right == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;   // Reattach the left child
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;  // Reattach the right child
        delete tempNodePtr;
    }
        // If the node has two children.
    else {
        // Move one node the right.
        tempNodePtr = nodePtr->right;

        // Go to the end left node.
        while (tempNodePtr->left) {
            tempNodePtr = tempNodePtr->left;
        }

        // Reattach the left subtree.
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;

        // Reattach the right subtree.
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}


void BinaryTree::displayInOrder(TreeNode *nodePtr) {
    if (nodePtr) {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}

void BinaryTree::displayPreOrder(TreeNode *nodePtr) {
    if (nodePtr) {
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}


void BinaryTree::displayPostOrder(TreeNode *nodePtr) {
    if (nodePtr) {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << endl;
    }
}


int BinaryTree::numNodes() {
    return countNodes(root);
}

int BinaryTree::numLeafNodes() {
    leafCount = 0;    // reset to 0 each time a count is made
    countLeaves(root);

    return leafCount;
}




int BinaryTree::treeHeight() {
    return getTreeHeight(root);
}
