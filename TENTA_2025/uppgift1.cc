#include <iostream>
#include <vector>
#include <list>

// Implementera alternate_sum() hÃ¤r

template <typename Container>
auto alternate_sum(Container const& a) //istället för auto kan man göra typename Container::value_type
{
    using valueType = typename Container::value_type; // SKRIV NER DENNA PÅ PAPPRET TILL TENTAN HÄMTAR UT TYPEN SOM SKICKADES MED I BEHÅLLARE
    valueType altSum{};
    int counter{}; //denna kan göras som int sign{1};

    for(auto const& v : a )
    {
        if(counter % 2 == 0)
        {
            altSum += v;
        }
        else
        {
            altSum -= v;
        }
        // isåfall blir de inte ++counter man gångrar bara med sign till altSum sen här nere gör man sign *= -1
        // så altSum = altsum + v*sign;
        // sign *= 1;
        ++counter;
    }
    return altSum;
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
            std::cout << "Rätt!";
        }
        else
        {
            std::cout << "Fel: Fick " << result
                      << " men förväntade sig " << answer;
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
            std::cout << "Rätt!";
        }
        else
        {
            std::cout << "Fel: Fick " << result
                      << " men förväntade sig " << answer;
        }
        std::cout << std::endl;
    }
}
