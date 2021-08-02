/* 
 * File: main.cpp
 * Author: Nitish Mallueu
 * 
 * This file will be use to test my FIFO stack
 */

#include "main.h"

int main() {

    FifoStack stack; string a = "hello"; 
    stack.push(1, &a);
    stack.push(2, &a);
    stack.push(3, &a);
    stack.push(4, &a);
    stack.push(5, &a); 
    
    Data* d = new Data;
    stack.printList(); 
    stack.pull(d); 
    stack.printList(); 
    stack.pull(d); 
    stack.printList(); 




    // srand(time(NULL));


    // const int testdatasize = BASE + (rand() % OFFSET + 1);
    // int ids[testdatasize];
    // string strs[testdatasize];
    
    // char buffer[BUFFERSIZE];
    // for (int i = 0; i < testdatasize; i++) {
    //     ids[i] = rand() % MAXID + 1;
    //     for (int j = 0; j < BUFFERSIZE - 1; j++) {
    //         buffer[j] = 'a' + i;
    //     }
    //     buffer[BUFFERSIZE - 1] = '\0';
    //     strs[i] = buffer;
    // }
    // ids[testdatasize-2] = ids[testdatasize-3];
    // strs[testdatasize-2] = "known duplicate";
    // ids[testdatasize-1] = - 1;
    // strs[testdatasize-1] = "known bad";
    

    // cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    // for (int i = 0; i < testdatasize; i++) {
    //     cout << ids[i] << " : " << strs[i] << endl;
    // }
    // cout << endl;
    
    // FifoStack stack;

    // cout << "Randomly testing the FIFO Stack"<< endl;
    // cout << endl;

    // for(int i = 0; i < SIZE*10; i++){
    //     int random = rand()%6;
    //     int randId = rand()%testdatasize;
    //     int randInfo = rand()%testdatasize;
    //     if (random <=6 && random > 2){
    //         if(stack.push(ids[randId], &strs[randInfo])){
    //             cout << "PUSH:    " << strs[randInfo] << " with id of "<< ids[randId] << " was pushed onto the Stack" <<endl;
    //         }else{
    //             cout << "PUSH:    " << strs[randInfo] << " with id of " << ids[randId] << " could not be pushed onto the Stack" << endl;
    //         }
    //     }else if(random == 2){
    //         Data *emptyStruct = new Data;
    //         if(stack.pull(emptyStruct)){
    //             cout << "PULL:    The bottom node with an id of "<< emptyStruct->id << " and the data of " << emptyStruct->data << " was pulled from the stack" <<endl;
    //         }else{
    //             cout << "PULL:    The Stack is empty, so nothing can be pulled" << endl;
    //             delete emptyStruct;
    //             emptyStruct = nullptr;
    //         }
    //     }
    //     else if(random == 1){
    //         Data *emptyStruct = new Data;
    //         if(stack.peek(emptyStruct)){
    //             cout << "PEEK:    The bottom node has an id of "<< emptyStruct->id << " and the data of " << emptyStruct->data <<endl;
    //         }else{
    //             cout << "PEEK:    The Stack is empty, so there is nothing to peek at" << endl;
    //             delete emptyStruct;
    //             emptyStruct = nullptr;
    //         }
    //     }else{
    //         if(stack.isEmpty()){
    //             cout << "ISEMPTY: The Stack is empty" << endl; 
    //         }else{
    //             cout << "ISEMPTY: The Stack is NOT empty" << endl; 
    //         }
    //     }
    // }
}