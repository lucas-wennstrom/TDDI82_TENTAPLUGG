#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
#include <numeric>


using namespace std;
/*
Givna produkter, ska initiseras i behÃ¥llaren sÃ¥hÃ¤r:

products {
    { "Apples", 20 },
    { "Bananas", 15 },
    { "Oranges", 25 },
    { "Grapes", 30 },
    { "Strawberries", 30 },
    { "Watermelon", 10 },
    { "Pineapple", 35 },
    { "Kiwi", 5 },
    { "Blueberries", 25 },
    { "Mango", 40 }    
};
*/

int main()
{
    map<string, int> products{
    { "Apples", 20 },
    { "Bananas", 15 },
    { "Oranges", 25 },
    { "Grapes", 30 },
    { "Strawberries", 30 },
    { "Watermelon", 10 },
    { "Pineapple", 35 },
    { "Kiwi", 5 },
    { "Blueberries", 25 },
    { "Mango", 40 }    
    };
    
    map<string, vector<string>> customers{};
    
    ifstream ifs{"customers.txt"};
    string line{};
    string name{};
    string product_list{};

    while(getline(ifs, line))
    {
        istringstream iss{line};
        iss >> name;
        copy(istream_iterator<string>{iss}, 
             istream_iterator<string>{}, 
             back_inserter(customers[name]));
    }

    string input{};
    cout << "Enter name (ctrl+D to exit): ";
    while(getline(cin, input))
    {
        if (customers.count(input))
        {
            cout << "Your cart contains: " << endl;
            copy(customers[input].begin(), 
                 customers[input].end(), 
                 ostream_iterator<string>(cout, "\n"));

            
           int total = accumulate(customers[input].begin(), customers[input].end(), 0, [&products](int total, const string& product){
                
            return total += products[product];
            });

            cout << "Your total is: " << total << endl;
            

        }
    }


};
    