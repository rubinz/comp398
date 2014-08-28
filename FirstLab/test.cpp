
#include <iostream>
#include <fstream>


using namespace std;

int main(){
	ifstream inFile;
	inFile.open("data.csv");
	string line;
	while( getline(inFile,line))
	{

		cout<<line<<endl;

	}
	
	return 0;
}
