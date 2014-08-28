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
int main()
{
    ifstream myfile ("dataNumbers.csv");

    NODE *start=NULL,*ptr,*temp;
    int line;
    if (myfile.is_open()){
        while (getline(myfile,line))
        {

            cout << line << endl;
            ptr = new NODE;
            ptr->data=line;
            ptr->next=NULL;
            if(start==NULL)
                start=ptr;
            else
            {
                temp=start;
                while(temp->next!=NULL)
                    temp=temp->next;
                temp->next=ptr;
            }
        }
    }
    myfile.close();
    temp=start;
    while(temp->next!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    return 0;
}