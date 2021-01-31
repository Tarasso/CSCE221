#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <math.h> // for floor
#include <algorithm>
#include "TempData.h"
using namespace std;

const bool DEBUG = false;

int main() {

	// 1. Look at data file for a pattern
	int value; float precip;
	map<int, vector<TempData>> temperature;

	// 2. open file for input
	ifstream infile;
	infile.open("tempAndPrecip.txt", ios_base::in);

	// 3. Check to see if file opened
	if (infile.fail())
	{
		cout << "The File was not successfully open." << endl;
		exit(1); // ends ENTIRE program!!!
	}

	// 4. read in the data
	//5.  Read in data from file
	while (infile >> value >> precip) // this command is IMPORTANT!
	{
		if(DEBUG) { cout << "read values: " << value << " " << precip << endl; }

		// gather value for key
		int stem = floor(value/10);
    //int leaf = value - (stem*10);

		TempData tempTemp(value,precip);

		if (temperature.find(stem) == temperature.end())
		{
			temperature.insert(pair<int, vector<TempData>>(stem, vector<TempData>()));
			temperature[stem].push_back(tempTemp);
		}
		else
		{
			temperature[stem].push_back(tempTemp);
		}

	}

	// 5. close the file
	infile.close();

	map<int,vector<TempData>>::iterator itr;


	for(itr = temperature.begin(); itr != temperature.end(); itr++)
	{
        cout<<itr->first<<" ->"<<endl;
				sort(itr->second.begin(), itr->second.end(), compVal);
        for(unsigned int i = 0; i < itr->second.size(); i++)
        { cout << itr->second[i]; }
        cout << endl << endl;
	}

	return 0;
}
