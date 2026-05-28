#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
#include <exception>


int main(int argc, char* argv[]) // För att ta in fler argument direkt efter ./a.out
{
  std::vector<std::string> text;
  std::map<std::string, std::string> arguments;
  
  std::ifstream ifs{argv[1]};
  std::copy(std::istream_iterator<std::string>{ifs},
            std::istream_iterator<std::string>{},
            std::back_inserter(text));

  for (int i{2}; i < argc; ++i) {
    arguments.insert({"#" + std::to_string(i-2), argv[i]});
  }

  for(std::string& currWord : text)
  {
      auto found{arguments.find(currWord)}; //found kommer bli en pekare till den platsen i mappen

      if(currWord[0] == '#')
      {
        if(found != arguments.end()) //ordet har hittats!
        {
          currWord = found -> second;
        }
        else
        {
          std::cout << ("This parameter is not set:: " + currWord);
          return 1;     
        }

      }
  };
  
  for(auto e: text)
  {
    std::cout << e << " ";  
  }
}
