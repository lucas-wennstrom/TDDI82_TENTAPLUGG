
#include <vector>
#include <set>
#include <iostream>
#include <iterator>
/* 

FÃ¶rvÃ¤ntad utmatning:

Group #1: 1 2 3 4 
Group #2: 5 6 7 8 
Group #3: 9 10 11 12 

Group #1: 1 2 3 
Group #2: 4 5 6 
Group #3: 7 8 9 
Group #4: 10 11 12 

Group #1: Mango Pineapple Papaya 
Group #2: Blueberries Blackberries Raspberries 
Group #3: Pear Plum Peach 
Group #4: Kiwi Passion fruit Lychee 

*/

template <typename Container>
class Split_Container
{
public:
  Split_Container(Container const& container, size_t groups)
    :container{container}, groups{groups}
    {}

  void set_groups(int amount)
  {
    groups = amount;
  }

 std::vector<typename Container::value_type> get_group(size_t index)
  {
    size_t group_size{container.size() / groups};
    size_t begin{index*group_size};
    size_t end{begin + group_size};

    auto group_begin{std::next(container.begin(), begin)}; // denna kommer då skapa en iterator vid begin på den gruppen som önskas
    auto group_end{std::next(container.begin(), end)}; //denna gör end iteratorn till container.begin till end same shi

    return std::vector<typename Container::value_type>(group_begin, group_end);
 }
  size_t size()
  {
    return groups;
  }
 private:
    Container container;
    size_t groups; 
};

template<typename Container>
void print_groups(Split_Container<Container>& sv)
{
    for (std::size_t i { 0 }; i < sv.size(); ++i)
    {
        std::cout << "Group #" << (i + 1) << ": ";
        auto group { sv.get_group(i) };
        for (auto e : group)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::set<int> v { 9, 8, 6, 1, 4, 7, 12, 2, 11, 3, 10, 5 };
    Split_Container<std::set<int>> sv { v, 3 };
    print_groups(sv);

    std::cout << std::endl;
    
    sv.set_groups(4);
    print_groups(sv);

    std::cout << std::endl;
    
    std::vector<std::string> fruits {
        "Mango", "Pineapple", "Papaya",
        "Blueberries", "Blackberries", "Raspberries",
        "Pear", "Plum", "Peach",
        "Kiwi", "Passion fruit", "Lychee"
    };

    Split_Container<std::vector<std::string>> sfruits { fruits, 4 };
    print_groups(sfruits);
}
