#include <iomanip>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <sstream>

using namespace std;

int main()
{
    string line;
    map<string, int> movies{};
    map<string, set<string>> personer;

    while(getline(cin, line))
    {
        istringstream iss{line};
        string name;
        iss >> name;

        for_each(istream_iterator<string>{iss}, istream_iterator<string>{}, [&movies, &name, &personer](const string& iss)
        {


        });




    }


}