#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int main(int argc, char* argv[])
{
	// empty map container
	map<char, string> equiv;

	// insert elements in random order
	equiv.insert(pair<char, string>('A', ".-"));
	equiv.insert(pair<char, string>('B', "-..."));
	equiv.insert(pair<char, string>('C', "-.-."));
	equiv.insert(pair<char, string>('D', "-.."));
	equiv.insert(pair<char, string>('E', "."));
  equiv.insert(pair<char, string>('F', "..-."));
  equiv.insert(pair<char, string>('G', "--."));
  equiv.insert(pair<char, string>('H', "...."));
  equiv.insert(pair<char, string>('I', ".."));
  equiv.insert(pair<char, string>('J', ".---"));
  equiv.insert(pair<char, string>('K', "-.-"));
  equiv.insert(pair<char, string>('L', ".-.."));
  equiv.insert(pair<char, string>('M', "--"));
  equiv.insert(pair<char, string>('N', "-."));
  equiv.insert(pair<char, string>('O', "---"));
  equiv.insert(pair<char, string>('P', ".--."));
  equiv.insert(pair<char, string>('Q', "--.-"));
  equiv.insert(pair<char, string>('R', ".-."));
  equiv.insert(pair<char, string>('S', "..."));
  equiv.insert(pair<char, string>('T', "-"));
  equiv.insert(pair<char, string>('U', "..-"));
  equiv.insert(pair<char, string>('V', "...-"));
  equiv.insert(pair<char, string>('W', ".--"));
  equiv.insert(pair<char, string>('X', "-..-"));
  equiv.insert(pair<char, string>('Y', "-.--"));
  equiv.insert(pair<char, string>('Z', "--.."));
  equiv.insert(pair<char, string>('1', ".----"));
  equiv.insert(pair<char, string>('2', "..---"));
  equiv.insert(pair<char, string>('3', "...--"));
  equiv.insert(pair<char, string>('4', "....-"));
  equiv.insert(pair<char, string>('5', "....."));
  equiv.insert(pair<char, string>('6', "-...."));
  equiv.insert(pair<char, string>('7', "--..."));
  equiv.insert(pair<char, string>('8', "---.."));
  equiv.insert(pair<char, string>('9', "----."));
  equiv.insert(pair<char, string>('0', "-----"));


  string word = argv[1];

  for(unsigned int i = 0; i < word.size(); i++)
  {
    char letter = word.at(i);
    if(equiv.find(letter) != equiv.end())
    {
      cout << equiv.at(letter) << endl;
    }
    else
    {
      cout << "Unknown character" << endl;
    }
  }

	return 0;
}
