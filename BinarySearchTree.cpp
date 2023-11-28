//
// Created by maxdg on 11/27/2023.
//
#include <iostream>
#include "BinarySearchTree.h"

bool BinaryTree::searchNode(int aVal) {
    Node* currentNode = root;

    while(currentNode){
        if(currentNode->val = aVal){
            return true;
        }
        else if(aVal < currentNode->val){
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }
    }
    return false;
}

void BinaryTree::insert(BinaryTree::Node *&aNodePtr, BinaryTree::Node *&aNewNodePtr) {
    if (aNodePtr == nullptr){
        aNodePtr = aNewNodePtr;
    }
    else if(aNodePtr->val < aNodePtr->val){
        insert(aNodePtr->left, aNewNodePtr);
    }
    else{
        insert(aNewNodePtr->right, aNewNodePtr);
    }

}

void BinaryTree::deleteNode(int aVal, BinaryTree::Node *&aNodePtr) {

    if(aVal < aNodePtr->val){
        deleteNode(aVal, aNodePtr->left);
    }
    else if(aVal > aNodePtr->val){
        deleteNode(aVal, aNodePtr->right);
    }
    else{ //value is correct
        makeDeletion(aNodePtr);
    }
}

void BinaryTree::makeDeletion(BinaryTree::Node *&aNodePtr) {

    //wow you can really dance

    Node* tempNodePtr = nullptr;

    if(aNodePtr == nullptr){
        std::cout << "Cannot remove empty Node" << std::endl;
    }
    else if(aNodePtr->right == nullptr){
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete tempNodePtr;

    }
    else if(aNodePtr->left == nullptr){
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->left;
        delete tempNodePtr;
    }
    else {
        tempNodePtr = aNodePtr->right;

        while(tempNodePtr->left){
            tempNodePtr = tempNodePtr->left;

        }

        tempNodePtr-> left = aNodePtr->left;
        tempNodePtr = aNodePtr;
        aNodePtr = tempNodePtr->right;

        delete tempNodePtr;
    }
}

BinaryTree::BinaryTree() {

}

void BinaryTree::insertNode(int aVal) {
    Node* newNode = new Node(aVal);
    insert(root, newNode);


}

void BinaryTree::remove(int aVal) {
    deleteNode(aVal, root);
}
