#include <iostream>
#include <vector>
#include <list>

// Implementera alternate_sum() hÃ¤r

template <typename Container>
typename Container::value_type alternate_sum(const Container& container)
{
    int i{};
    typename Container::value_type sum{};
    /* for_each(container.begin(), container.end(), [&sum, &i, &container](const int& element){
    
        if(i % 2 == 0)
        {
            return sum += element;
        }
        else
        return sum -= element;
    }); */

    for(auto e : container)
    {
        if(i % 2 == 0)
        {
            sum += e;
        }
        else 
        sum -= e;

        i++;
    }
    return sum;
}




int main()
{
    {
        std::cout << "==== Testfall #1 ====" << std::endl;
        std::vector<int> v { 4, 3, 2, 1 };

        auto result = alternate_sum(v);
        auto answer = 2;

        if (result == answer)
        {
            std::cout << "RÃ¤tt!";
        }
        else
        {
            std::cout << "Fel: Fick " << result 
                      << " men fÃ¶rvÃ¤ntade sig " << answer;
        }
        std::cout << std::endl;
    }

    {
        std::cout << "==== Testfall #2 ====" << std::endl;
        std::list<double> l { 1.5, 2.25, 3.75, 4.5 };

        auto result = alternate_sum(l);
        auto answer = -1.5;

        if (result == answer)
        {
            std::cout << "RÃ¤tt!";
        }
        else
        {
            std::cout << "Fel: Fick " << result 
                      << " men fÃ¶rvÃ¤ntade sig " << answer;
        }
        std::cout << std::endl;
    }
}