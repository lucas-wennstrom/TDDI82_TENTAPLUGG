#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

// Implementera Pair_Sum_Container hÃ¤r

template <typename Left_Container, typename Right_Container>
class Pair_Sum_Container
{
    public:
    Pair_Sum_Container(Left_Container& left, Right_Container& right)
    : left{left}, right{right}
    {}

    auto size()
    {
      return std::min(left.size(), right.size());
    }

    typename Left_Container::value_type operator[](const size_t index)
    {
        if(index > size())
        throw std::logic_error("För stort index");

        auto left_value = std::next(left.begin(), index);
        auto right_value = std::next(right.begin(), index);

        return *left_value + *right_value;
    }



    private:
    Left_Container& left;
    Right_Container& right;
};

int main()
{
    {
        std::cout << "==== Testfall #1 ===="<< std::endl;

        using Left  = std::vector<int>;
        using Right = std::vector<int>;

        Left  left  { 1, 2, 3, 4 };
        Right right { 2, 3, 4, 5 };

        Pair_Sum_Container<Left, Right> p { left, right };

        // Testa undantag
        try 
        { 
            p[1000];
            std::cout << "Ett lÃ¤mpligt undantag kastades ej!"
                      << std::endl;
            return 0;
        }
        catch (std::exception&) { }

        for (std::size_t i { 0 }; i < p.size(); ++i)
        {
            std::cout << p[i] << " ";
        }
        std::cout << std::endl;
    }

    {
        std::cout << "==== Testfall #2 ===="<< std::endl;

        using Left  = std::set<double>;
        using Right = std::list<int>;

        Left  left  { 1.75, 2.5, 3.25, 4.0 };
        Right right { 4, 3, 2, 1 };

        Pair_Sum_Container<Left, Right> p { left, right };
        for (std::size_t i { 0 }; i < p.size(); ++i)
        {
            std::cout << p[i] << " ";
        }
        std::cout << std::endl;
    }

    {
        std::cout << "==== Testfall #3 ===="<< std::endl;

        using Left  = std::vector<std::string>;
        using Right = std::list<std::string>;

        Left  left  { "Christ", "E", "Mal", "Ni", "Pon", "T" };
        Right right { "offer", "ric", "te", "ls", "tus", "im" };

        Pair_Sum_Container<Left, Right> p { left, right };
        for (std::size_t i { 0 }; i < p.size(); ++i)
        {
            std::cout << p[i] << " ";
        }
        std::cout << std::endl;
    }
}