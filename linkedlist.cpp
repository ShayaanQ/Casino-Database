#include <iostream>
#include <fstream>
using namespace std;
#include <algorithm>
#include <string>
#include "linkedlist.h"


void list::insertAtEnd(string tempName, int tempAge, int tempDeposit, int tempDrinks){

    node* temp = new node();
    temp->name = tempName;
    temp->age = tempAge;
    temp->deposit = tempDeposit;
    temp->drinks = tempDrinks;
    temp->next = nullptr;

    if(head == nullptr){
        head = temp;
        size++;
        return;
    }

    node* temp2 = head;

    while(temp2->next != nullptr){
        temp2 = temp2->next;
    }

    temp2->next = temp;
    size++;


}

void list::insertAtPosition(string tempName, int tempAge, int tempDeposit, int tempDrinks, int index){

  node* temp = new node();
  temp->name = tempName;
  temp->age = tempAge;
  temp->deposit = tempDeposit;
  temp->drinks = tempDrinks;
  temp->next = nullptr;

  node* curr = head;
  node* prev = nullptr;
  

  while(curr != nullptr){
    if((curr->name == temp->name) && (curr->age == temp->age)){
        
        curr->deposit = temp->deposit;
        curr->drinks = temp->drinks;
        delete temp;
        return;
    }
    curr = curr->next;
  }

  if(index <= 0){
    if(head == nullptr){
        head = temp;
        size++;
        return;
    }
    else{
        temp->next = head;
        head = temp;
        size++;
        return;
    }
  }
    
    if(index >= size){
        curr = head;
        if(curr == nullptr){
        head = temp;
        size++;
        return;
        }

        while(curr->next != nullptr){
            if(curr == nullptr){
                return;
            }
            curr = curr->next;
        }

        if(curr == nullptr){
            return;
        }

        curr->next = temp;
        size++;
        return;
    }

   curr = head;
  for(int i = 0; i < index; i++){
    if(curr == nullptr){
        delete temp;
        return;
    }
    prev = curr;
    curr = curr->next;
  }

  if(curr == nullptr){
    delete temp;
    return;
  }

  

  prev->next = temp; 
  temp->next = curr; 
  size++;
  return;

}



void list::remove(string attribute, string attributeVal){

    if(head == nullptr){
        return;
    }

    int val;
    node* curr = head;
    node* prev = nullptr;

    if(attribute == "drinks"){
        val = stoi(attributeVal);
        while(curr != nullptr){
            if(curr->drinks == val){
               if(curr == nullptr){
                   return;
                }
                if(prev == nullptr){
                    node* temp = curr->next;
                    delete curr;
                    head = temp;
                    size--;
                    curr = head;
                    return;
                }

                prev->next = curr->next;
                delete curr;
                size--;
                
            }

            prev = curr;
            curr = curr->next;

        }

    }
    else if(attribute == "age"){
        val = stoi(attributeVal);
        while(curr != nullptr){
            if(curr->age == val){
               if(curr == nullptr){
                   return;
                }

                if(prev == nullptr){
                    node* temp = curr->next;
                    delete curr;
                    head = temp;
                    size--;
                    curr = head;
                    return;
                }

                prev->next = curr->next;
                delete curr;
                size--;
                
            }

            prev = curr;
            curr = curr->next;

        }
        
    }
    else if(attribute == "deposit"){
        val = stoi(attributeVal);
        while(curr != nullptr){
            if(curr->deposit == val){
               if(curr == nullptr){
                   return;
                }

                if(prev == nullptr){
                    node* temp = curr->next;
                    delete curr;
                    head = temp;
                    size--;
                    curr = head;
                    return;
                }

                prev->next = curr->next;
                delete curr;
                size--;
                
            }

            prev = curr;
            curr = curr->next;

        }
    }
    else if(attribute == "name"){
        while(curr != nullptr){
            if(curr->name == attributeVal){
               if(curr == nullptr){
                   return;
                }

                if(prev == nullptr){
                    node* temp = curr->next;
                    delete curr;
                    head = temp;
                    size--;
                    curr = head;
                    return;
                }

                prev->next = curr->next;
                delete curr;
                size--;
                
            }

            prev = curr;
            curr = curr->next;
        
        }
    }


}

void list::sortDeposit(){

   if (head == nullptr || head->next == nullptr) {
        return; 
    }

    bool swapped;
    node* temp;
    node* finish = nullptr;

    do {
        swapped = false;
        temp = head;

        while (temp->next != finish) {
            if (temp->deposit > temp->next->deposit) {
                swap(temp, temp->next);
                swapped = true;
            }
            temp = temp->next;
        }
        finish = temp;
    } while (swapped);
    
}

void list::swap(node* a, node* b) {

    string tempName = a->name;
    int tempAge = a->age;
    int tempDeposit = a->deposit;
    int tempDrinks = a->drinks;


    a->name = b->name;
    a->age = b->age;
    a->deposit = b->deposit;
    a->drinks = b->drinks;

    b->name = tempName;
    b->age = tempAge;
    b->deposit = tempDeposit;
    b->drinks = tempDrinks;
}



void list::sortAge(){

    if (head == nullptr || head->next == nullptr) {
        return; 
    }

    bool swapped;
    node* temp;
    node* finish = nullptr;

    do {
        swapped = false;
        temp = head;

        while (temp->next != finish) {
            if (temp->age > temp->next->age) {
                swap(temp, temp->next);
                swapped = true;
            }
            temp = temp->next;
        }
        finish = temp;
    } while (swapped);

}

void list::sortName(){

    if (head == nullptr || head->next == nullptr) {
        return; 
    }

    bool swapped;
    node* temp;
    node* finish = nullptr;

    do {
        swapped = false;
        temp = head;

        while (temp->next != finish) {
            if (temp->name > temp->next->name) {
                swap(temp, temp->next);
                swapped = true;
            }
            temp = temp->next;
        }
        finish = temp;
    } while (swapped);
}

void list::sortDrinks(){

    if (head == nullptr || head->next == nullptr) {
        return; 
    }

    bool swapped;
    node* temp;
    node* finish = nullptr;

    do {
        swapped = false;
        temp = head;

        while (temp->next != finish) {
            if (temp->drinks > temp->next->drinks) {
                swap(temp, temp->next);
                swapped = true;
            }
            temp = temp->next;
        }
        finish = temp;
    } while (swapped);

}

void list::print(ofstream& fout){

    node* temp = head;

    if(temp == nullptr){
        return;
    }

    while(temp != nullptr){
        fout << "[name: " << temp->name << "; age: " <<  temp->age << "; deposit: " << temp->deposit << "; number of drinks: " << temp->drinks << "]" << endl;
        temp = temp->next;
    }
    fout << endl;
}

void list::print2(){

    node* temp = head;

    if(temp == nullptr){
        return;
    }

    while(temp != nullptr){
        cout << "[name: " << temp->name << "; age: " <<  temp->age << "; deposit: " << temp->deposit << "; number of drinks: " << temp->drinks << "]" << endl;
        temp = temp->next;
    }
    cout << endl;
}