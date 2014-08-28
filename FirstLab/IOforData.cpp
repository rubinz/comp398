#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {
    

    ifstream input( "data.csv" );
    
    for(string line; getline( input, line ); )
    {
        cout << line << endl;
    }

   
}