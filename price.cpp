#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "price.hpp"
using namespace std;

Price add(Price sum, Price price, int qnt)
{
    price = mult(price, qnt);
    sum.uah += price.uah;
    sum.kop += price.kop;
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

void out(Price sum)
{
    printf("Сума: %d.%d\nДо оплати: %d.%d\n", sum.uah, sum.kop, roundto10(sum).uah, roundto10(sum).kop);
}

void parseFile(const char*)
{
    FILE* input_file;
    errno_t err;
    char c;
    
    if ((err = fopen_s(&input_file, "input.txt", "r")) != 0) 
        fprintf(stderr, "cannot open file '%s': %s\n", "input.txt", strerror(err));
    else 
    {
        Price sum = {};
        Price price = {};
        int qnt = 0;
        while(fscanf(input_file, "%*[^,], %d %*[грн] %d %*[коп,] %d", &price.uah, &price.kop, &qnt) == 3)
        {
            sum = add(sum, price, qnt);
        }
        out(sum);     
        fclose(input_file);
    }
}