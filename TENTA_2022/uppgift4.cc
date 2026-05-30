#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

std::string const vowles{"aeiouy"};

//Accumulate är lite skum men den bygger en ny sträng utifrån den gamla typ
std::string convert(std::string const& word)
{
  std::string convertedWord = std::accumulate(word.cbegin(), word.cend(), std::string(""),[](std::string & word, char letter)
  {
    if(std::isalpha(letter) != 0)
    {
      auto it = std::find(vowles.begin(), vowles.end(), letter);
      if (it == vowles.end()) // Bokstaven finns i vowles!
      {
        return word + letter + 'o' + letter;    
      }
    }
    return word + letter;
  });
  
  return convertedWord;
}

int main()
{
  std::vector<std::string> words;
  std::cout << "Mata in din text: "; 

  std::copy(std::istream_iterator<std::string>{std::cin},
            std::istream_iterator<std::string>{},
            std::back_inserter(words));

  std::transform(words.begin(), words.end(), words.begin(),  convert);
  std::copy(words.begin(), words.end(),
            std::ostream_iterator<std::string>{std::cout, " "});  
 }
