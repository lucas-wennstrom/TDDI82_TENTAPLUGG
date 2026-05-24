#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>


std::set<std::string> readBook(std::istream& text) //Set är en behållare som inte kan ha dubbletter vilket gör att man tar bort felet
{                                                  //med att en person kan skriva en bok två gånger, std::stringstream ss{line}
    std::set<std::string> result{};
    std::string line{};
    std::getline(text, line);
    std::istringstream ss{line}; //skapar en ström för att kunna använda istream_iterator på den i copy

    std::copy(std::istream_iterator<std::string>{ss},
              std::istream_iterator<std::string>{},
              std::inserter(result, result.end())); //Tar behållaren den ska sätta in saker in result och vart i behållaren result.end()
    return result;
}


int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        return 1;
    }

    std::ifstream text{argv[1]}; //Vidrigt men samma skit som första uppgiften
    std::set<std::string> Christoffer{readBook(text)};
    std::set<std::string> Erik{readBook(text)};

    for(auto& a : Christoffer)
    {
        if(Erik.count(a)) //count returnar en 1 eller 0 beroende på om a finns i erik eller inte,
        {
            std::cout << a << std::endl;;
        }
    }
    return 0;

}
