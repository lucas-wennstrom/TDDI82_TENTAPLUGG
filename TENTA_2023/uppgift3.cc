#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <iterator>
#include <sstream>
#include <fstream>
#include <map>


std::map<std::string, int> const products
{
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

int main()
{  
  std::string line;
  std::string name;
  std::map<std::string, std::set<std::string>> s;
  std::ifstream ifs{"customers.txt"};

  while(std::getline(ifs, line))
  {
    std::istringstream ss{line};
    ss >> name;
    std::copy(std::istream_iterator<std::string>{ss},
              std::istream_iterator<std::string>{},
              std::inserter(s[name], s[name].end())); //Detta lägger de som copy har läst in på namn platsen
  }

  std::cout << "Enter name" << "(ctrl+D to exit): ";
  while(std::getline(std::cin, name))
  {
    int totalCost{};
    std::set<std::string> cart{s[name]};
       
    std::for_each(cart.begin(), cart.end(),[&totalCost](std::string const& currentItem)
    {
      totalCost += products.at(currentItem); 
    });
    if(totalCost > 0)
    {
      std::cout << "Your cart contains: " << std::endl;
      std::copy(cart.begin(), cart.end(),
              std::ostream_iterator<std::string>{std::cout, "\n"});
      std::cout << "Your total is: ";
      std::cout << totalCost << std::endl;
    }
    else
    {
      std::cout << "This person isn't shopping" << std::endl;
    }
    std::cout << "Enter name" << "(ctrl+D to exit): ";
  }
      
}
