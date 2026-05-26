#include <cstdlib>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>

template <typename T>
class Ping_Pong
{
public:
    
    template <typename Container>
    Ping_Pong(Container & data)
    : data{data.begin(), data.end()} // detta kopierar innehållet till en vektor så man bara behöver arbeta med den
    {}

    void append(T const& value)
    {
        data.push_back(value);
    }

    T const&  operator[](int i) const
    {
        int size{static_cast<int>(data.size())};

        i %= 2*size; //om index är 3 och size är 3 blir index = 3, om index är 7 och size är 3 blir index 1 använder den för att "wrappa" runt så man aldrig kan få större värde än index
        if (i < 0)   // negativ
        {
          i += 2*size; //i =-3, size = 4, i = -3 + 8 = 5 vilket är större än size
          i %= 2*size; //denna rad finns då för att se till att i är mindre än size eller 0
        }
        if(i >= size) //då är index en eller mer för stort
        {
            i = size -(i - size) -1;
        //t.ex i = 4 - (8 - 4) -1; == -1
        }
        return data[i];
    }
private:
   std::vector<T> data;    
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
