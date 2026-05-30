#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>

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
    int lower_dens{};
    int upper_dens{};
    int threshold{};

    std::vector<Product> products{};
    std::ifstream istrm("factory.txt");

    std::cout << "Enter the lower density tolerance: ";
    std::cin >> lower_dens;
    std::cout << "Enter the upper density tolerance: ";
    std::cin >> upper_dens; 
    std::cout << "Enter the squential fault threshold: ";
    std::cin >> threshold;

    copy(std::istream_iterator<Product>{istrm}, 
         std::istream_iterator<Product>{}, 
         back_inserter(products)); 


    auto faulty = search_n(products.begin(), products.end(), threshold, 0, [&lower_dens, &upper_dens](const Product& product, int){
        return density(product) < lower_dens || density(product) > upper_dens;
    });

    if (faulty == products.end())
    std::cout << "No faults found" << std::endl;
    else
    {
    size_t index = distance(products.begin(), faulty);
    std::cout << "Found a faulty sequence after " << index << " products: ";
    copy(faulty, faulty + threshold, std::ostream_iterator<Product>{std::cout , " "});
    }

}