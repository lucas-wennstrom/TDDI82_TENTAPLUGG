#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <stdexcept>
#include <vector>

// Implementera Pair_Sum_Container hÃ¤r
template <typename Left_Container, typename Right_Container>
class Pair_Sum_Container
{
    public:
        Pair_Sum_Container(Left_Container const& left, Right_Container const& right)
        :left{left}, right{right}
    {

    }

    std::size_t size() const//size_t är en unsinged integer vilket betyder att den kan vara större än en int men bara inte negativ
    {
        return std::min(left.size(), right.size());
        //Utgår att de finns en size() funktion i den behållaren? men alla behållare har inte en
        //Man kan använda std::Distance då som räknar hur många steg de tar att gå från begin till end och returnar en int annars
    }
    typename Left_Container::value_type operator[](std::size_t index) const //returnar value_type som left har
    {
        if(index >= size())
        {
            throw std::out_of_range("Index är för stort");
        }
        auto leftIterator{std::next(left.begin(), index)}; //finns i bibliotek om iterator returnar en iterator som pekar på platsen index
        auto rightIterator{std::next(right.begin(), index)};

        return *leftIterator + *rightIterator; //avreferera
    }
    private:
        Left_Container const& left;
        Right_Container const& right;
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
            std::cout << "Ett lämpligt undantag kastades ej!"
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
