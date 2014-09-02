//
//Created by Zevi Rubin on 9/1/2014
//

#pragma once
#include <iostream>
#include <string>
using namespace std;

//begin class states
class states
{
public:
    states(); // constructor
    
    void displayStates();


private:
struct Node

{ string state; //state name data type
  string abv; //state abreviation data type
  
   Node *next; //next node pointer
};
Node *head;
Node *headPtr;


};