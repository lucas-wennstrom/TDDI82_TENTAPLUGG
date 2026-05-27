#include <iostream>
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
    
    ///nums.erase(nums.begin(), nums.end(), [&sum](int n){})
    auto it = remove_if(nums.begin(), nums.end(), [&sum](int a){
        return sum % a == 0;
    });

    nums.erase(it, nums.end());

    sort(nums.begin(), nums.end(), greater<int>());

    copy(nums.begin(), nums.end(), ostream_iterator<int>{cout, " "});

}