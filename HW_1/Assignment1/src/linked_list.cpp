#include <linked_list.hpp>

template<class T>
LinkedListNode<T>::LinkedListNode(T value, LinkedListNode<T>* next, LinkedListNode<T>* prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
LinkedListNode<T>::~LinkedListNode() {
    this->next = nullptr;
}


template<class T>
LinkedList<T>::LinkedList() {
     this->root = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList() {
    LinkedListNode<T>* current  = this-> root; // creates temporary node set equal to the head of the list
    while (current != nullptr) { //checks to see if the current node is nullptr
    	LinkedListNode<T>* next = current-> next; // creates a temporary node equal to the value of the current next pointer
    	delete current; // deletes the current Node
    	current = next; // sets current equal to next
    }
    root = nullptr; // sets the head to nullptr
}


template<class T>
LinkedListNode<T>* LinkedList<T>::insert(T value) {
    LinkedListNode<T>* p = find(value);
    if (p != NULL){ // checks if the node you want to insert is already in the linked list
        return p;
    }
    else{
        LinkedListNode<T>* p = new LinkedListNode<T>(value, NULL, NULL); // creates a new node in the list
        p-> next = this-> root; // sets the next pointer of p to the root
        this-> root = p; // makes p the root of the list
        return p;
    }
}

template<class T>
LinkedListNode<T>* LinkedList<T>::find(T value) {

    LinkedListNode<T>* current = this-> root; // creates a reference to the root pointer of the list

    while ((current != NULL) && (current -> value != value)){ // iterates through the list while checking to see if the value matches
        current = current-> next;
    }
    return current; // returns the pointer with the matching value
}

template<class T>
LinkedListNode<T>* LinkedList<T>::getRoot() {
    return this-> root;
}



template<class T>
LinkedListNode<T>* LinkedList<T>::remove(T value) {
    LinkedListNode<T>* current = this-> root;

    if(find(value) == this-> root){
        LinkedListNode<T>* q = this-> root;
        this-> root = q -> next;
        delete q;
        return this-> root;
    }

    while(current != nullptr){
        LinkedListNode<T>* q = current-> next;
        if(q-> value == value){
            current-> next = q-> next;
            delete q;
        }
        else{
            current = current-> next;
        }
    }

    return this-> root;
}


template<class T>
int LinkedList<T>::size() {
    int count = 0;
    LinkedListNode<T>* temp = this-> root;
    while(temp != nullptr){
        count++;
        temp = temp-> next;
    } 
    return count;

}

template class LinkedListNode<int>;
template class LinkedList<int>;

