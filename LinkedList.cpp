#include "LinkedList.h"
#include <iostream>
#include <limits>

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(int* array, int len) {
    head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < len; i++) {
        Node* newNode = new Node(array[i]);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->link = newNode;
            tail = newNode;
        }
    }
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->link;
        delete temp;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);

    if (pos <= 1 || !head) {
        newNode->link = head;
        head = newNode;
        return;
    }

    Node* current = head;
    for (int i = 1; current && i < pos - 1; i++) {
        current = current->link;
    }

    if (!current) { 
        delete newNode; 
        return; 
    }

    newNode->link = current->link;
    current->link = newNode;
}

bool LinkedList::deletePosition(int pos) {
    if (!head || pos < 1) return false;

    if (pos == 1) {
        Node* temp = head;
        head = head->link;
        delete temp;
        return true;
    }

    Node* current = head;
    for (int i = 1; current && i < pos - 1; i++) {
        current = current->link;
    }

    if (!current || !current->link) return false;

    Node* temp = current->link;
    current->link = temp->link;
    delete temp;
    return true;
}

int LinkedList::get(int pos) {
    Node* current = head;
    for (int i = 1; current; i++) {
        if (i == pos) return current->data;
        current = current->link;
    }
    return std::numeric_limits<int>::max();
}

int LinkedList::search(int target) {
    Node* current = head;
    int index = 1;
    while (current) {
        if (current->data == target) return index;
        current = current->link;
        index++;
    }
    return -1;
}

void LinkedList::printList() {
    std::cout << "[";
    Node* current = head;
    while (current) {
        std::cout << current->data;
        if (current->link) std::cout << " ";
        current = current->link;
    }
    std::cout << "]" << std::endl;
}
