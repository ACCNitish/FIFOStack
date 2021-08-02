/*
 * This is a stack that stores the Data strucure 
 * and contatins all the basic functionalities of a stack except that it pull from the bottoms rather than the top
 * 
 * File:   fifo.cpp
 * Author: Nitish Malluru
 */

#include "fifo.h"


FifoStack::FifoStack(){
    head = nullptr;
    top = -1;
}

bool FifoStack::push(int x, string* info)
{
    bool pushed = false;

    if(x>0  && !info->empty())
    {
        top++;
        addNode(x, info);
        pushed = true; 
    }
    return pushed;
}

bool FifoStack::pull(Data *emptyStruct)
{
    bool pullSucess = false;
    emptyStruct->id = -1;
    emptyStruct->data = "";

    if(top >= 0)
    {
        deleteHead(emptyStruct);

        top--;
        pullSucess = true;
    }

    return pullSucess;
}

bool FifoStack::peek(Data *value)
{
    bool peekSucess = false;
    if(top >= 0){
        peekSucess = true;
        value->id = head->data.id;
        value->data = head->data.data;
    }

    return peekSucess;
}

bool FifoStack::isEmpty()
{
    return top < 0;
}



bool FifoStack::addNode(int x, string* info){
    bool addSucces = false;
    if(x > 0 && !info->empty()){    
        if(head == nullptr){
            createHead(x, *info);
        }else{
            addAfterHead(x, *info);
        }       
        addSucces = true;
        
    }
    return addSucces;
}

void FifoStack::deleteHead(Data* returnable){
    returnable->id = head->data.id;
    returnable->data = head->data.data;
    if(head->next == nullptr){
        head = nullptr;
    }else{    
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        
        delete temp;
        temp = nullptr; 
    }
}

void FifoStack::printList(bool backward){
    if(!backward){
        Node *curr = head;
        cout << "{" ;
        while(curr){ 
            cout << "[" << curr->data.id << ", " << curr->data.data << "]";
            curr = curr->next;
        }
        cout << "}" << endl;
    }
    else{
        printBackwards();
    }
}

bool FifoStack::clearList(){
    bool clearListSucess = false;
    Node *curr = head;
    int count = top+1;
    bool tail = false; 
    if(count > 0){
        for(int i = count; i > 0; i--){
            Node *next = curr->prev;
            if(curr->prev == nullptr){
                head = nullptr;
                delete curr;
                curr = nullptr;
            }
            else{
                deleteNode(curr);
            }
            curr = next;
        }
        clearListSucess = true;
    }   
    return clearListSucess;
}

void FifoStack::createNode(Node* toCreate, Node* prev, Node* next, int x, string info){
    toCreate->prev = prev;
    toCreate->next = next;
    Data *addData = new Data;
    addData->id = x;
    addData->data = info;
    toCreate->data = *addData;
}



void FifoStack::printBackwards(){
    Node *curr = head;
    bool tail = false; 
    while(curr && !tail){ 
        if (curr->next){
                curr = curr->next;
        } else {
            tail = true; 
        }
    }
    cout << "{" ;
    while(curr){ 
        cout << "[" << curr->data.id << ", " << curr->data.data << "]";
        curr = curr->prev;
    }
    cout << "}" << endl;
}

Node* FifoStack::getLast(){
    Node *curr = head;
    bool tail = false; 
    while(curr && !tail){
        if (curr->next){
            curr = curr->next;
        }else{
            tail = true; 
        }
    }
    return curr;
}

void FifoStack::createHead(int x, string info){
    Node *firstNode = new Node; 
    createNode(firstNode, nullptr, nullptr, x, info);
    head = firstNode;
}

void FifoStack::addAfterHead(int x, string info){
    Node *addNode = new Node();
    Node *last = getLast();

    createNode(addNode, last, nullptr, x, info);
    last->next = addNode;
}

void FifoStack::deleteNode(Node* curr){
    curr->prev->next = curr->next;
    if(curr->next != nullptr){
        curr->next->prev = curr->prev;    
    }
    delete curr;
    curr = nullptr;
}

FifoStack::~FifoStack(){
    clearList();
}