#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include "price.hpp"
using namespace std;

Price add(std::vector<Price> prices, std::vector<int> quants)
{
    Price sum;
    sum.uah = 0;
    sum.kop = 0;
    int i = 0;
    for (Price price : prices)
    {
        sum.uah += mult(prices[i], quants[i]).uah;
        sum.kop += mult(prices[i], quants[i]).kop;
        i++;

    }

    sum.uah += sum.kop / 100;
    sum.kop %= 100;
        
    return sum;
}

Price mult(Price price, int quant)
{
    Price result;
    result.uah = price.uah * quant;
    result.kop = price.kop * quant;
    result.uah += result.kop / 100;
    result.kop %= 100;
    return result;
}

Price roundto10(Price sum)
{
    if (sum.kop % 10 >= 5)
        sum.kop -= sum.kop % 10 - 10;
    else
        sum.kop -= sum.kop % 10;
    sum.uah += sum.kop / 100;
    sum.kop %= 100;
    return sum;
}

void out(std::vector<Price> prices, std::vector<int> quants)
{
    Price sum = add(prices, quants);
    printf("Сума: %d.%d\nДо оплати: %d.%d\n", sum.uah, sum.kop, roundto10(sum).uah, roundto10(sum).kop);
}