#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "price.hpp"
using namespace std;

void add(Price &sum, Price price, int qnt)
{
    mult(price, qnt);
    sum.uah += price.uah;
    sum.kop += price.kop;
    sum.uah += sum.kop / 100;
    sum.kop %= 100;
}

void mult(Price &price, int quant)
{
    price.uah = price.uah * quant;
    price.kop = price.kop * quant;
    price.uah += price.kop / 100;
    price.kop %= 100;
}

void roundto10(Price &sum)
{
    if (sum.kop % 10 >= 5)
        sum.kop -= sum.kop % 10 - 10;
    else
        sum.kop -= sum.kop % 10;
    sum.uah += sum.kop / 100;
    sum.kop %= 100;
}

void out(Price sum)
{
    printf("Сума: %d.%d\n", sum.uah, sum.kop);
    roundto10(sum);
    printf("До оплати: %d.%d\n", sum.uah, sum.kop);
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
            add(sum, price, qnt);
        }
        out(sum);     
        fclose(input_file);
    }
}