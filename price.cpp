#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include "price.hpp"
using namespace std;

int add(std::vector<Price> prices, std::vector<int> quants)
{
    int sum = 0;
    int i = 0;
    for (Price price : prices)
    {
        sum += mult(prices[i], quants[i]);
        i++;
    }
        
    return sum;
}

int mult(Price price, int quant)
{
    return (price.uah * 100 + price.kop) * quant;
}

int roun(int sum)
{
    if (sum % 10 >= 5)
        return sum - sum % 10 + 10;
    else
        return sum - sum % 10;
}

void out(int sum)
{
    printf("Сума : %.2f\nДо оплати: %.1f\n", (float)sum / 100, (float)roun(sum) / 100);
}