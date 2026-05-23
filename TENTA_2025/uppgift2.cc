#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> nums;
    std::copy(std::istream_iterator<int> {std::cin}, //SKRIV NER PÅ PAPPAER
        std::istream_iterator<int>{},
        std::back_inserter(nums));

    int sum {std::accumulate(nums.begin(), nums.end(), 0)}; //Går igenom hela vectorn och adderar alla element, 0 skrivs då det är standardvärdet

    nums.erase(std::remove_if(nums.begin(), nums.end(), [sum](int a)
    {
       return sum%a == 0;
    }), nums.end());

    std::sort(nums.begin(), nums.end(), std::greater<int>()); //sorterar, std::greater e inbyggt i c++ och använder bara < operator för att kolla
    std::cout << "Output" << std::endl;
    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " ")); //skriver ut allt

}
