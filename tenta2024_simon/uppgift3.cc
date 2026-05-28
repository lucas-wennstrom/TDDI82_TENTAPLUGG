#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Ping_Pong
{
    public:
    template <typename Container>
    Ping_Pong(const Container& data)
    : data{data.begin(), data.end()}
    {}

    T operator[](const int& index)
    {
        
        int period = 2 * data.size();
        int pos = index % period;

        if ( pos<0 )
        pos+=period;
        
        if (pos < static_cast<int>(data.size()))
        return data[pos];
        else
        return data[2*static_cast<int>(data.size()) - 1 - pos];
    }

    void append(const T& value) 
    {
        data.push_back(value);
    }




    private:
    vector<T> data{};

};



int main()
{
    {
        std::vector<int> v { 0, 1, 2, 3 } ;
        Ping_Pong<int> p { v };

        for (int i { -10 }; i <= 10; ++i)
            std::cout << p[i] << " ";
        std::cout << std::endl;

        p.append(4);
        for (int i { -10 }; i <= 10; ++i)
            std::cout << p[i] << " ";

        std::cout << std::endl;
    }

    {
        std::list<std::string> v { "PONTUS", "ERIC", "MALTE", "NILS", "EDVIN" };
        Ping_Pong<std::string> p { v };

        for (int i { -4 }; i <= 5; ++i)
            std::cout << p[i] << " ";
        std::cout << std::endl;

        p.append("CHRISTOFFER");
        for (int i { -4 }; i <= 5; ++i)
            std::cout << p[i] << " ";

        std::cout << std::endl;
    }

    {
        std::vector<int> v { 0, 1 };
        std::set<int> s { 0, 1 };
        Ping_Pong<int> p { v };

        // se till att behÃ¥llaren inte Ã¤r en mallparameter till Ping_Pong.
        p = Ping_Pong<int>{ s };

        for (int i { -9 }; i <= 10; ++i)
            std::cout << p[i] << " ";
        std::cout << std::endl;
    }
}