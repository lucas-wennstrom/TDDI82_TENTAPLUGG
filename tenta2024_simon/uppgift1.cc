#include <vector>
#include <list>
#include <iostream>
#include <cctype>
#include <iterator>
#include <utility>
#include <numeric>

/// Implementera sum_and_max() och print_pair()

template <typename It>
std::pair<typename std::iterator_traits<It>::value_type, typename std::iterator_traits<It>::value_type> sum_and_max(const It& begin, const It& end)
{
   typename std::iterator_traits<It>::value_type sum = std::accumulate(begin, end, typename std::iterator_traits<It>::value_type{});
   typename std::iterator_traits<It>::value_type max = *std::max_element(begin, end);

   return std::make_pair(sum, max);
}

template <typename T>
void print_pair(const std::pair< T, T>& Pair)
{
    std::cout << "the sum is: " << Pair.first << std::endl;
    std::cout << "The biggest(>) element is: " << Pair.second << std::endl;
}

int main()
{
    std::cout << "==== Testfall #1 ====" << std::endl;

    // Enkelt testfall
    std::vector<int> v1 { 1, 2, 4, 3};
    auto v1_pair { sum_and_max(v1.begin(), v1.end()) };

    print_pair(v1_pair);

    std::cout << "==== Testfall #2 ====" << std::endl;

    // Testa std::list (en annan behÃ¥llare Ã¤n std::vector)
    std::list<std::string> names {
        "PONTUS ", "CHRISTOFFER ", "ERIC ", "MALTE ", "NILS ", "EDVIN" };
    auto names_pair { sum_and_max(names.begin(), names.end()) };

    print_pair(names_pair);
}