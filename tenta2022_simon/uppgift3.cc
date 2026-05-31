#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, char* argv[])
{
    vector<string> text{};
    map<string, string> arguments{};
    ifstream ifs{argv[1]};

    string arg{};
    string line{};
    while(getline(ifs, line))
    {

    istringstream iss{line};

    copy(istream_iterator<string>{iss}, 
         istream_iterator<string>{}, 
         back_inserter(text));
    };
    
    for(int i{2}; i < argc; ++i)
    {
        arguments.insert({"#"+to_string(i-2), argv[i]});
        //arguments["#" + to_string(i - 2)] = argv[i]; eller denna
    };

    for(string word : text)
    {
        if(word[0] == '#')
        {
            if(arguments.count(word))
            {
                cout << arguments[word] << " ";
            }
            else 
            {
                cout << "Parameter " << word << " has no value" << endl;
                return 1;
            }
        }
        else 
        {
            cout << word << " ";
        }
        
    }
    cout << endl;
    

}
