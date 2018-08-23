#ifndef MAP_H
#define MAP_H

#include <iostream>

template <class T>
class Map {
    struct Node {
        T data;
        Node* rvalue;
        Node* lvalue;
    };

    Node* top;

    void add(T data, Node* node);
    void print(Node* node);
    void copy(Node *& node1, Node* node2);

public:
    Map() : top(nullptr) {}
    Map(const Map& map);
    //~Map();

    void add(T data);
    void print();

    //Map operator=(const Map& map);
};

template <class T>
Map<T>::Map(const Map& map) {
    if (map.top) {
        copy(top, map.top);
    }
    else {
        top = nullptr;
    }
}

template <class T>
void Map<T>::copy(Node *& node1, Node* node2) {
    if (node2) {
        node1 = new Node;
        node1->data = node2->data;
        copy(node1->lvalue, node2->lvalue);
        copy(node1->rvalue, node2->rvalue);
    }
    else {
        node1 = nullptr;
    }
}

template <class T>
void Map<T>::add(T data) {
    if (top) {
        add(data, top);
    }
    else {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->lvalue = nullptr;
        newNode->rvalue = nullptr;
        top = newNode;
    }
}

template <class T>
void Map<T>::add(T data, Node* node) {
    if (data >= node->data) {
        if (node->rvalue) {
            add(data, node -> rvalue);
        }
        else {
            node->rvalue = new Node;
            node->rvalue->data = data;
            node->rvalue->rvalue = nullptr;
            node->rvalue->lvalue = nullptr;
        }
    }
    else {
        if (node->lvalue) {
            add(data, node->lvalue);
        }
        else {
            node->lvalue = new Node;
            node->lvalue->data = data;
            node->lvalue->rvalue = nullptr;
            node->lvalue->lvalue = nullptr;
        }
    }
}

template <class T>
void Map<T>::print() {
    if (top) {
        print(top);
    }
    else {
        std::cout << "Empty" << std::endl;
    }
}

template <class T>
void Map<T>::print(Node* node) {
    if (node->lvalue) {
        print(node->lvalue);
    }

    std::cout << node->data << std::endl;

    if (node->rvalue) {
        print(node->rvalue);
    }
}

#endif