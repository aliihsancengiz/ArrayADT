#include "Array.h"



int main()
{
    
    Array Arr;
    InitArray(&Arr,0,10);
    setArrayZero(&Arr);
    dispArray(&Arr);
    destroyArray(&Arr);
}