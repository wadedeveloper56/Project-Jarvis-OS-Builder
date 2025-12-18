#include "pch.h"
#include "LinkerUtils.h"
#include "structures.h"

bool TestBit(int_8* array, unsigned num)
{
    int_8 mask = 1 << (num % 8);
    num /= 8;
    return(*(array + num) & mask);
}