#include <iostream>
#include <iterator>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::map<std::string, int> movies;
    std::vector<std::string> people;
    std::string line;

    std::cout << "On each line, enter a person's name followed by their movie preferences." << std::endl;
    std::cout << "To exit, press ctrl+D." << std::endl;

    while(std::getline(std::cin, line)) //while stämmer medans input e igång alltså tills CTRL-D trycks
    {
       std::string name;
       std::istringstream ss{line};

       if(ss >> name) //om det finns något på raden så är det namnet först, då läser denna in namnet annars failar den
       {
           people.push_back(name);
       }
       for_each(std::istream_iterator<std::string>{ss}, //bara filmerna ska läsas in till mappen
           std::istream_iterator<std::string>{},
           [&movies](std::string const& movie)
        {
            movies[movie]++;
        });
    }

    std::cout << std::endl;
    std::cout << "The candidates for watching: " << std::endl;

    int amountOfPeople{static_cast<int>(people.size())}; //slippa göra static_cast inuti for loop people.size e unsinged int så static_castar till int för inte få varning
    for(auto const& m: movies)
    {
       if(amountOfPeople == m.second)
       {
           std::cout <<"- " << m.first << std::endl;
       }
    }
}
