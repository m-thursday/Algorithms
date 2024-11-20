#include <stack.hpp>

template<class T>
StackNode<T>::StackNode(T value, StackNode<T> *next) {
    this->value = value;
    this->next = next;
}

template<class T>
StackNode<T>::~StackNode() {
    this->next = NULL;
}

template<class T>
Stack<T>::Stack() {
    this->head = NULL;
}

template<class T>
Stack<T>::~Stack() {
    StackNode<T> * temp = head; 
    while(temp != NULL){
        StackNode<T> * temp2 = temp -> next;
        delete temp;
        temp = temp2;
    }
    this->head = NULL;
}

template<class T>
bool Stack<T>::empty() {
    if(this->head == NULL){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
T Stack<T>::pop() {
    T value = this->head->value;
    StackNode<T> * temp = this->head;
    head = head->next;
    delete temp;
    return value;
}

template<class T>
void Stack<T>::push(T value) {

    head = new StackNode<T>(value, head);

}

template class Stack<int>;
