#include "Node.h"

Node::Node(int value) : data(value), link(nullptr) {}

int Node::getData() const { return data; }
void Node::setData(int value) { data = value; }
Node* Node::getLink() const { return link; }
void Node::setLink(Node* next) { link = next; }
