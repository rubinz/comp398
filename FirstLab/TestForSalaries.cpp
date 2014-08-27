#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	string inFile;
	ifstream fin;

	inFile = "data.csv";

	fin.clear();
	fin.open( inFile.c_str());
	if (fin.fail())
	{
		cout << "ERROR: File Called " << inFile << " Could not be found " << endl;
		exit(-1); 
	}

	string outFile = inFile + ".xls";
	ofstream fout;
	fout.open( outFile.c_str() );

	if ( fout.fail())
	{
		cout << " ERROR: File called " << outFile << " failed to open " << endl;
		exit(-1);
	}


	int i = 0;
	while (i<100)
	{
		cout << "insideWhile loop" << endl;
	    if (!fin.good()) break;
	    
	    string lineFromFile;
	    getline(fin, lineFromFile);
	    cout << lineFromFile << endl;
		i++;
	} 

	cout << "Got Here" << endl;



	fin.close();
	fout.close();
	return 1;

}