#include <vector>
#include <list>
#include <iostream>

/// Implementera sum_and_max() och print_pair()
template <typename it>
std::pair<typename it::value_type, typename it::value_type> sum_and_max(it begin, it end)
{
    using valueType = typename it::value_type; // MÅSTE STÅ USING INTE AUTO ELLER LIKNADNE ANNARS KAN MAN INTE HÄMTA UT TYPEN

    valueType sum{}; //här e vrf man måste hämta ut typen
    valueType max{*begin}; //tar begins värde som första största

    for_each(begin, end,[&sum, &max](valueType& curr)
        {
            sum += curr;
            if(max < curr)
            {
                max = curr;
            }
        });
    return std::make_pair(sum, max);
}

template <typename T>
void print_pair(std::pair<T,T> const& sum_max)
{
    std::cout << "The sum is: " << sum_max.first << std::endl;
    std::cout << "The biggest(>) element is: " << sum_max.second << std::endl;
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
