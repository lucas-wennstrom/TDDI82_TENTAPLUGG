#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> nums{};

    
    copy(istream_iterator<int>{cin}, 
             istream_iterator<int>{}, 
             back_inserter(nums));

    int sum = accumulate(nums.begin(), nums.end(), 0);

    auto it = remove_if(nums.begin(), nums.end(), [&sum](int& number){
        return sum % number == 0;
    });

    nums.erase(nums.begin(), it);

    sort(nums.begin(), nums.end(), greater<int>());


    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
}