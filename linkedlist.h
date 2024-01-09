#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
using namespace std;
#include <string>

struct node{
    string name;
    int age;
    int deposit;
    int drinks;
    node* next;
};

class list{
    private:
    node* head;
    int size;
    public:
    list(){
        head = nullptr;
        size = 0;
    }
    
    void insertAtEnd(string tempName, int tempAge, int tempDeposit, int tempDrinks);
    void insertAtPosition(string tempName, int tempAge, int tempDeposit, int tempDrinks, int index);
    void remove(string attribute, string attributeVal);
    void sortName();
    void sortAge();
    void sortDeposit();
    void sortDrinks();
    void print(ofstream&);
    void print2();
    int getSize(){
        return size;
    }
    void swap(node* a, node* b);

};

#endif