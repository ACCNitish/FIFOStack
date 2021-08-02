/*
 * header file for fifo.cpp
 *
 * File:   stack.h
 * Author: Nitish Malluru
 */

#ifndef FIFO_H
#define FIFO_H

#include <iostream>
#include "data.h"

using std::cout;
using std::endl;

class FifoStack {

public:
    FifoStack();
    bool push(int, string*);
    bool pull(Data*);
    bool peek(Data*);
    bool isEmpty();
    ~FifoStack();
    void printList(bool = false);

private:

    int top;
    Node *head;

    bool addNode(int, string*);
    void deleteHead(Data*);
    bool clearList();
    void createNode(Node*, Node*, Node*, int, string);
    void printBackwards();
    Node* getLast();
    void createHead(int, string);
    void addAfterHead(int, string);
    void deleteNode(Node*);
};

#endif //FIFO_H