#pragma once

#include <iostream>

struct BSTNode {
    int key;
    int height;
    int value;
    BSTNode *left;
    BSTNode *right;

    BSTNode();
    BSTNode(int key, int height = 0, int value = 0, BSTNode *left = NULL, BSTNode *right = NULL);  
    ~BSTNode();
};

class BST {
    protected:
        BSTNode *root;
    public:
        BST();
        ~BST();
        BSTNode* find(int key, int value = 0);
        BSTNode* popMaximum();
        BSTNode* popMinimum();
        BSTNode* insert(int key, int value = 0);
        BSTNode* remove(int key, int value = 0);
        int sumValue();
};

