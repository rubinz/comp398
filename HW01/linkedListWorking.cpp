#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct NODE
{
    string data;
    NODE *next;
};

int main()
{
    ifstream myfile ("States.csv");

    NODE *start=NULL,*ptr,*temp;
    string line;

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