#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

data *list;
data *d, *q;

int main()
{
    ifstream inputFile;
    list = NULL;
    d = new NODE;
    inputFile.open("data.csv");


    while (! inputFile.eof())
    {
        d = new NODE;
        inputFile >> d->data;
        cout << d->data << endl;
    }

    if (list == NULL){
    list = d;
      }
      else
      {
         q = list;
         while (q->next != NULL)
            q = q->next;
         q->next = d;
      }
    
   inputFile.close(); 


    // int i,j=0;
    // NODE *start=NULL,*ptr,*temp;
    // for (i=1;i<=10;i++)
    // {
    //     ptr = new NODE;
    //     ptr->data=i;
    //     ptr->next=NULL;
    //     if(start==NULL)
    //         start=ptr;
    //     else
    //     {
    //         temp=start;
    //         while(temp->next!=NULL)
    //             temp=temp->next;
    //         temp->next=ptr;
    //     }
    // }
    // temp=start;
    // while(temp->next!=NULL)
    // {
    //     cout<<temp->data<<"  ";
    //     temp=temp->next;
    // }
    // return 0;
}