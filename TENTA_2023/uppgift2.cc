
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>

struct Product
{
    std::string name;
    double weight;
    double volume;
};

std::ostream& operator<<(std::ostream& os, Product product)
{
    os << product.name << " [" << product.weight << " kg, " << product.volume << " m^3]";
    return os;
}

std::istream& operator>>(std::istream& is, Product& product)
{
    is >> product.name >> product.weight >> product.volume;
    return is;
}

double density(Product product)
{
    return product.weight / product.volume;
}

int main()
{
    int upperLim{};
    int lowerLim{};
    int threshold{};
    std::vector<Product> product;
     // Implementera uppgiften hÃ¤r

    std::ifstream ifs{"Factory.txt", std::ios::binary};
    std::cout << "Enter the lower density tolerance: ";
    std::cin >> lowerLim;
    std::cout << "Enter the upper density tolerance: ";
    std::cin >> upperLim;

    std::cout << "Enter the sequential fault threshold: ";
    std::cin >> threshold;
    
    std::copy(std::istream_iterator<Product>{ifs}, //skriver in hela ifs in i product vektorn
    std::istream_iterator<Product>{},
    std::back_inserter(product)); //lägger in allt i stats

    auto it = std::search_n(product.begin(), product.end(), threshold, lowerLim,[&upperLim](Product const& p, double lowerLimit)
    // search_n tar in 4 parametrar, början slut, hur många saker som får vara fel "threshold"
    // och i detta fall lowerlim, för att dock kunna göra en riktig jämnföring så behöver man ta med lowerlim i parameter listan
    // för lamda funktionen och fånga upperlim i lamdan

                  {
                      double D{density(p)};
                      if(D < lowerLimit || D > upperLim)
                      {
                          return true;
                      }
                      else
                      {
                         return false;
                      }
                  });

    if(it != product.end())
    {
       std::cout << "Found a faulty sequence after 5 products: ";
       std::copy_n(it, threshold, std::ostream_iterator<Product>{std::cout , " "});
       //Copy_n tar in vart den ska börja vilket i detta fall är it som är början på sekenvsen som är fel
       //ostream skriver ut
    }
    else
    {
      std::cout << "No fault found"; 
    }
}
