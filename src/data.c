
#include "data.h"



uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    uint8_t n[16] = "0123456789ABCDEF";

    uint8_t * ptrDigit = ptr;
    uint8_t lastPos = 0;
    uint8_t isNegative = 0;
    
    if(base < 1)
       base = 1;
    else if (base > 16)
       base = 16;
    
    if(data<0)
    {
        isNegative = 1;
        data = -data;
    }
    
    while(data != 0)
    {
        *ptrDigit = n[data % base];
        data /= base;
        ptrDigit++;
        lastPos++;
    }
    
    if(isNegative == 1)
    {
        *ptrDigit = '-';
        ptrDigit++;
        lastPos++;
    }
    *ptrDigit = 0;
    
    my_reverse(ptr, lastPos);

    return (lastPos);
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
    uint8_t isNegative = 0;
    int32_t number = 0;
    uint8_t index = 0;
    
    if(ptr == NULL)
    {
        return 0;
    }
    
    if(base < 2)
       base = 2;
       
    if(base > 16)
       base = 16;
    
    if(*ptr == '-')
    {
        isNegative = 1;
        ptr++;
        index++;
    }
    
    while(index < digits)
    {
        number = number*base + (*ptr - '0');
        ptr++;
        index++;
    }

    if(isNegative == 1)
    {
        number = -number;
    }
    
    return number;
}
