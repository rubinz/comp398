//#pragma once
#include <iostream>
#include <string>
using namespace std;

class states
{
public:
    states(); // constructor
    
    //void displayStates();


private:
struct Node

{ string state; //state name 
  string abv; //state abreviation
  
   Node *next; //next node pointer
};
Node *head;
Node *headPtr;


};