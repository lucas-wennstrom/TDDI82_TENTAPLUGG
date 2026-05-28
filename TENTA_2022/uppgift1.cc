
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>

template<typename it>
std::vector<std::pair<typename std::iterator_traits<it>::value_type, typename std::iterator_traits<it>::value_type>>
get_pairs(it begin, it end)
{
  using valueType = typename std::iterator_traits<it>::value_type;
  std::vector<std::pair<valueType, valueType>> P;

  for(it curr{begin}; curr != end; ++curr)
  {
    for(it next{std::next(curr)}; next != end; ++next )
    {
      P.emplace_back(*curr,*next);
    }
  }
  return P;
}
int main()
{

    std::cout << "==== Testfall #1 ====" << std::endl;
    
    // Enkelt testfall
    std::vector<int> v1 { 1, 2, 3, 4 };
    auto v1_pairs { get_pairs(v1.begin(), v1.end()) };

    // v1_pairs innehÃ¥ller par, sÃ¥ vi loopar Ã¶ver den
    for (std::pair<int, int> p : v1_pairs)
    {
	std::cout << p.first << " + " << p.second << " = "
		  << p.first + p.second << std::endl;
    }

    std::cout << "==== Testfall #2 ====" << std::endl;

    
    // Vi vill skriva ut alla par av namn dÃ¤r ena namnet slutar pÃ¥
    // samma bokstav som andra namnet bÃ¶rjar pÃ¥.
    
    // AnvÃ¤nder std::list fÃ¶r att kolla att det fungerar fÃ¶r olika typer
    std::list<std::string> names { "PONTUS", "CHRISTOFFER",
				   "ERIC", "HANNA", "MALTE", "WILHELM" };
    auto name_pairs { get_pairs(names.begin(), names.end()) };

    // Man kan loopa Ã¶ver denna pÃ¥ samma sÃ¤tt som std::map eftersom
    // att den innehÃ¥ller std::pair objekt
    for (auto const& [a, b] : name_pairs)
    {
	// om a slutar pÃ¥ samma bokstav som b bÃ¶rjar pÃ¥...
	if (a.back() == b.front())
	{
	    std::cout << a << " " << b << std::endl;
	}

	// om b slutar pÃ¥ samma bokstav som a bÃ¶rjar pÃ¥...
	else if (a.front() == b.back())
	{
	    std::cout << b << " " << a << std::endl;
	}
    }

}
