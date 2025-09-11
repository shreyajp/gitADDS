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
            tail->setLink(newNode);
            tail = newNode;
        }
    }
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->getLink();
        delete temp;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);

    if (pos <= 1 || !head) {
        newNode->setLink(head);
        head = newNode;
        return;
    }

    Node* current = head;
    for (int i = 1; current && i < pos - 1; i++) {
        current = current->getLink();
    }

    if (!current) { 
        delete newNode; 
        return; 
    }

    newNode->setLink(current->getLink());
    current->setLink(newNode);
}

bool LinkedList::deletePosition(int pos) {
    if (!head || pos < 1) return false;

    if (pos == 1) {
        Node* temp = head;
        head = head->getLink();
        delete temp;
        return true;
    }

    Node* current = head;
    for (int i = 1; current && i < pos - 1; i++) {
        current = current->getLink();
    }

    if (!current || !current->getLink()) return false;

    Node* temp = current->getLink();
    current->setLink(temp->getLink());
    delete temp;
    return true;
}

int LinkedList::get(int pos) {
    Node* current = head;
    for (int i = 1; current; i++) {
        if (i == pos) return current->getData();
        current = current->getLink();
    }
    return std::numeric_limits<int>::max();
}

int LinkedList::search(int target) {
    Node* current = head;
    int index = 1;
    while (current) {
        if (current->getData() == target) return index;
        current = current->getLink();
        index++;
    }
    return -1;
}

void LinkedList::printList() {
    std::cout << "[";
    Node* current = head;
    while (current) {
        std::cout << current->getData();
        if (current->getLink()) std::cout << " ";
        current = current->getLink();
    }
    std::cout << "]" << std::endl;
}
