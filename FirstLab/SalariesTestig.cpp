#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	string inFile;
	ifstream fin;

	inFile = "SalariesCleaned.csv";

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

	string line, charecters;
	short lineNumber = 1;


	getline(fin, line);

	cout << "Lines:" << endl;

	fin.close();
	fout.close();
	return 1;

}