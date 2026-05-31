#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string const vowels{"aeiouy"};

void convert(const string& word)
    {
        if(word == vowels)
        {
            
        }
       
    }

int main()
{
    vector<string> text{};
    string line{};

    cout << "Mata in din text: ";

    while(getline(cin, line))
    {
        istringstream iss{line};
        copy(istream_iterator<string>{iss}, 
             istream_iterator<string>{}, 
             back_inserter(text));
    };







}