#ifndef WEEK9_BINARYTREE_H
#define WEEK9_BINARYTREE_H

// A class template for a binary tree

#include <iostream>
using namespace std;


class BinaryTree {
private:
    struct TreeNode {
        int value;
        TreeNode *left;
        TreeNode *right;
    };

    int leafCount;
    TreeNode *root;
    void insert(TreeNode *&nodePtr, TreeNode *&newNode);

    void deleteNode(int num, TreeNode *&nodePtr);
    void makeDeletion(TreeNode *&nodePtr);
    void displayInOrder(TreeNode *nodePtr);
    void displayPreOrder(TreeNode *nodePtr);
    void displayPostOrder(TreeNode *nodePtr);


public:
    BinaryTree();
    ~BinaryTree()		// Destructor
    { destroySubTree(root); }
    void insertNode(int num);
    bool searchNode(int num);
    void remove(int num);
    void displayInOrder()
    {	displayInOrder(root); }
    void displayPreOrder()
    {	displayPreOrder(root); }
    void displayPostOrder()
    {	displayPostOrder(root); }

    int numNodes();
    int numLeafNodes();
    int treeHeight();
};
#endif //WEEK9_BINARYTREE_H