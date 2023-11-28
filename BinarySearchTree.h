//
// Created by maxdg on 11/27/2023.
//

#ifndef DOWNLOADS_BINARYTREE_H
#define DOWNLOADS_BINARYTREE_H


class BinaryTree {
private:
    struct Node {
        int val;
        Node* left;
        Node* right;

        Node(int aVal, Node* left = nullptr, Node* right = nullptr);
    };

    Node* root;

private:
    void insert(Node* &aNodePtr, Node* &aNewNodePtr);
    void deleteNode(int aVal, Node* &aNodePtr);
    void makeDeletion(Node* &aNodePtr);

public:
    BinaryTree();
    void insertNode(int aVal);
    bool searchNode(int aVal);
    void remove(int aVal);

    void displayInOrder(Node* aNodePtr){
        if (aNodePtr) {
            displayInOrder(aNodePtr->left);
            std::cout << aNodePtr->val << " ";
            displayInOrder(aNodePtr->right);
        }
    }

    void printTree(){
        displayInOrder(root);
        std::cout << std::endl;
    };
};



#endif //DOWNLOADS_BINARYTREE_H
