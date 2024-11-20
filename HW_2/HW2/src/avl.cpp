#include <avl.hpp>


AVL::AVL() : BST() {
    // The AVL constructor will initialize the empty AVL tree via the BST constructor
    // You do NOT need to implement this one
}

AVL::~AVL() {
    // The AVL deconstructor will deallocate memory of all nodes in AVL via the BST deconstructor
    // You do NOT need to implement this one
}

/*
 * AVL Balance Factor, Update Height, Rotations, and Balance
*/

int AVL::balanceFactor(BSTNode *node) {
    // YOUR CODE HERE
}


void AVL::update(BSTNode *node) {
    // YOUR CODE HERE
}


BSTNode* AVL::rotateRight(BSTNode *node) {
    // YOUR CODE HERE
}


BSTNode* AVL::rotateLeft(BSTNode *node) {
    // YOUR CODE HERE
}


BSTNode *AVL::balance(BSTNode *node) {
    // YOUR CODE HERE
}


/*
 * AVL Insert
*/

BSTNode* AVL::insertHelper(int key, int value, BSTNode *node) {
    // YOUR CODE HERE
}


BSTNode *AVL::insert(int key, int value) {
    // YOUR CODE HERE
    //return this->root = this->insertHelper(key, value, this->root); // Uncomment this one if you implement the insertHelper to insert a node into AVL.
}

/*
 * AVL Remove 
*/


BSTNode* AVL::findMinimum(BSTNode *node) {
   // YOUR CODE HERE
}

BSTNode* AVL::removeMinimum(BSTNode *node) {
    // YOUR CODE HERE
}

BSTNode* AVL::removeHelper(BSTNode *node, int key, int value) {
    // YOUR CODE HERE
}

BSTNode *AVL::remove(int key, int value) {
    // YOUR CODE HERE
    // return this->root = this->removeHelper(this->root, key, value); // Uncomment this one if you implement the removeHelper to remove a node out of AVL.
}


