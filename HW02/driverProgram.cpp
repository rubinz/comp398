#include "StatesLinkList.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

states::states() //constructor
{

// ifstream inFile;
// inFile.open("States.csv");

//head = NULL;
head = new Node;
headPtr = head;

const string END_OF_FILE_DELIMITER = "$$$$$";

ifstream inFile("States.csv");
string line;
while( getline(inFile,line) ){
   cout << "line = " << line << endl;
   if(line == END_OF_FILE_DELIMITER){
      break;
   }
   else{
       head->next = NULL;
    	head->next = new Node;
    	head = head->next;
   }
}

head->next = NULL;

//inFile.close();
}

// void states::displayStates(string state, string abv)
// {

// for (Node *cur = headPtr; cur != NULL; cur = cur->next)
// {
//     cout << cur->state << " " << cur->abv << " \n" << endl;
    
// }
//}