#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>
#include <sstream>


std::set<std::string> readbooks(std::istream& is)
{
    std::set<std::string> result{};
    std::string line;
    getline(is, line);
    std::istringstream iss{line};
    copy(std::istream_iterator<std::string>{iss}, 
         std::istream_iterator<std::string>{}, 
         std::inserter(result, result.end()));

    return result;
}

int main()
{
    std::ifstream ifs("books.txt");
    std::set<std::string> Christoffer = readbooks(ifs);
    std::set<std::string> Eric = readbooks(ifs);

    for(auto book : Christoffer)
    {
        if(Eric.count(book))
        std::cout << book << std::endl;
    };
}