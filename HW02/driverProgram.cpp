//
//Created by Zevi Rubin on 9/1/2014
//

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#include "StatesLinkList.h"

//Constructor
//PRE: n/a
//POST: creates a linked list which is filled from a text file
states::states() //constructor
{

head = NULL;
head = new Node; // New empty node is created
headPtr = head;

const string END_OF_FILE_DELIMITER = "$$$$$"; //create delimitter at end of file to help with reading in data

ifstream inFile("States.csv");
string line;
while( getline(inFile,line) ){
   cout << "line = " << line << endl; 	//attempt at printing read in files to console
   if(line == END_OF_FILE_DELIMITER){
      break;
   }
   else{
       head->next = NULL;
    	head->next = new Node; //the buffer node is created
    	head = head->next;
   }
}

head->next = NULL;

inFile.close();
} // End states CTOR


//displayStates function prints out all state names and abreviations to console and plaintext file
void states::displayStates(string state, string abv)
{

// for (Node *cur = headPtr; cur != NULL; cur = cur->next)
// {
//     cout << cur->state << " " << cur->abv << " \n" << endl;
    
    ifstream display("States.csv"); //creates an output file name statesPT.txt (Plain Text)
    string Line;
    ofstream output_plaintext;
    output_plaintext.open("statesPT.txt"); 

    while(!display.eof()){	//while loop writes one line of the text at a time to the output file
    	getline (display, Line);
    	output_plaintext << Line;

    }

    display.close();
    output_plaintext.close();

// }
} //end of displayStates