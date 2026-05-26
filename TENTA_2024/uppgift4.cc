#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <vector>

std::vector<int> read_sequence()
{
    std::string s {};
    std::getline(std::cin,s);

    std::stringstream ss { s };

    // 1. Fyll denna med alla heltal i 'ss'
    std::vector<int> sequence {  };
    std::copy (std::istream_iterator<int>{ss},
  					 	 std::istream_iterator<int>{ },
  						 std::back_inserter(sequence));
				
    return sequence;
}

int main() {

    int lower_limit { };
    int upper_limit { };
    std::cout << "Enter your bingo number limit: ";
    std::cin >> lower_limit >> upper_limit;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter your bingo numbers: ";
    std::vector<int> numbers { read_sequence() };

    // 2. Kontrollera att alla nummer i 'numbers' Ã¤r inom grÃ¤nsen.
    auto MinMax{std::minmax_element(numbers.begin(), numbers.end())}; //kollar efter minsta och största världen och retuernar ett pair, first i pair e det minsta 
    if((*MinMax.first < lower_limit) || (* MinMax.second > upper_limit)) //minmax.first är en iterator avrefera
    {
        std::cout << "You had a bingo number ouside of the limits" << std::endl;
        return 1; //för att visa att de gick fel
    }
    
    std::cout << "Enter the winning numbers: ";
    std::vector<int> winning_numbers { read_sequence() };

    // 3. Sortera och skriv ut winning_numbers
    std::cout << "The winning numbers in descending sorted order: "<< std::endl;
    std::sort(winning_numbers.begin(), winning_numbers.end(),std::greater<int>());
    std::copy(winning_numbers.begin(), winning_numbers.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    // 4. Hitta den fÃ¶rsta fÃ¶rekomsten av nÃ¥got nummer frÃ¥n winning_numbers i
    //    numbers vektorn. Skriv ut ett felmedelande om det inte fanns nÃ¥got,
    //    annars skriv ut vilken position (index) som detta nummer fÃ¶rekom pÃ¥.
    auto match{std::find_first_of(numbers.begin(), numbers.end(),
                                  winning_numbers.begin(), winning_numbers.end())};

    if(match != numbers.end())
    {
        std::cout << "First occurrence found at postion: " << * match << std::endl;
    }
    else
    {
      std::cout << "no winning numbers were found." << std::endl;   
    }
     return 0;
}
