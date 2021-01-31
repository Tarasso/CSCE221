#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int main()
{
	// empty map container
	map<string, string> md_counties;

	// insert elements in random order
	md_counties.insert(pair<string, string>("Cecil", "Elkton"));
	md_counties.insert(pair<string, string>("Frederick", "Frederick"));
	md_counties.insert(pair<string, string>("Caroline", "Denton"));
	md_counties.insert(pair<string, string>("Dorchester", "Cambridge"));
	md_counties.insert(pair<string, string>("Kent", "Chestertown"));

	// printing map md_counties
	map<string, string>::iterator itr;
	cout << "\nThe map md_counties is : \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = md_counties.begin(); itr != md_counties.end(); ++itr)
	{
		cout << '\t' << itr->first << '\t' << itr->second << '\n';
	}
	cout << endl;

	// assigning the elements from md_counties to md_copies
	map<string, string> md_copies(md_counties.begin(), md_counties.end());

	// print all elements of the map md_copies
	cout << "\nThe map md_copies after"
		<< " assign from md_counties is : \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = md_copies.begin(); itr != md_copies.end(); ++itr)
	{
		cout << '\t' << itr->first << '\t' << itr->second << '\n';
	}
	cout << endl;

	// remove all elements with key = Cecil
	int num;
	num = md_copies.erase("Cecil");
	cout << "\nmd_copies.erase(Cecil) : ";
	cout << num << " removed \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = md_copies.begin(); itr != md_copies.end(); ++itr)
	{
		cout << '\t' << itr->first << '\t' << itr->second << '\n';
	}

	cout << endl;

	// retreive valye Caroline

	cout << "md_countries.at(\"Caroline\"): " << md_counties.at("Caroline") << endl;

	return 0;
}
