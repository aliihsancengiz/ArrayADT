#include "Array.h"


/*
*   @brief : Display array up to its curent size 
*   @param : 
*               Arr: Array which is displayed
*   @ret   :None
*/
void dispArray(Array * Arr)
{
    int i;
    for(i=0;i<Arr->size;i++)
    {
        printf("%d ",Arr->Data[i]);
    }
    printf("\n");
}

/*
*   @brief : Allocate memory for array and initialize its size and capacity 
*   @param : 
*               Arr     : Array which is initialize
*               size    : Current size of Array
*               length  : Capacity of Array
*   @ret   :None
*/
void InitArray(Array * Arr,int size,int length)
{
    Arr->Data=(int *)malloc(sizeof(int)*length);
    Arr->length=length;
    Arr->size=size;
}

/*
*   @brief : Deallocate the memory of array 
*   @param : 
*               Arr: Array which is deallocated
*   @ret   :None
*/
void destroyArray(Array *Arr)
{
    free(Arr->Data);
    Arr->Data=NULL;
    Arr->length=0;
    Arr->size=0;
}

/*
*   @brief : Clear the all elements of array by setting them to 0 
*   @param : 
*               Arr: Array which is all element is setted to be zero
*   @ret   :None
*/
void setArrayZero(Array *Arr)
{
    int i;
    for(i=0;i<Arr->length;i++)
    {
        Arr->Data[i]=0;
    }
    Arr->size=Arr->length;
}

/*
*   @brief : Append the given data to the array 
*   @param : 
*               Arr : Array which data is appended
*               data: data which is appended to array 
*   @ret   : Status of operation
*/
int appendArray(Array *Arr,int data)
{
    if(Arr->size > (Arr->length-1))
    {
        return -1;
    }
    Arr->Data[Arr->size]=data;
    Arr->size++;
    return 1;

}


/*
*   @brief : insert the given data to specific index of the array 
*   @param : 
*               Arr : Array which data is inserted
*               data: data which is inserted to array 
*               index:Index number
*   @ret   : Status of operation
*/
int insertArray(Array *Arr,int data,int index)
{
    if((index > Arr->length) || (index < 0))
    {
        return -1;
    }
    if(Arr->size < Arr->length)
    {
        int i;
        for(i=Arr->size;i>index;i--)
        {
            Arr->Data[i]=Arr->Data[i-1];
        }
        Arr->Data[index]=data;
        Arr->size++;
        return 1;
    }
    else
    {
        return -1;
    }
    
}

/*
*   @brief : delete the given index of the array 
*   @param : 
*               Arr : Array which data is inserted
*               index:Index number of deleted item
*   @ret   : deleted value on success,ARR_OUTOFBOUND in Failure
*/
int deleteindexArray(Array*Arr,int index)
{
    if((index<0) || (index > Arr->size-1) )
    {
        return -1;
    }
    int i,t=Arr->Data[index];
    for(i=index;i<Arr->size;i++)
    {
        Arr->Data[i]=Arr->Data[i+1];
    }
    Arr->size--;
    return t;
}

/*
*   @brief : Search the given key in the array 
*   @param : 
*               Arr : Array which data is searched
*               key : searched key
*   @ret   : index number in success,-1 in failure
*/
int searchArray(Array *Arr,int key)
{
    int i;
    for(i=0;i<Arr->size;i++)
    {
        if(Arr->Data[i]==key)
        {
            return i;
        }
    }
    return -1;
}

/*
*   @brief : Get value at index of Array 
*   @param : 
*               Arr   : Array which operation is performed
*               index : Index number  
*   @ret   : Value of Array at index,-1 in failure
*/
int getindexArray(Array * Arr,int index)
{
    if((index < 0) | (index > Arr->size))
    {
        return -1;
    }
    return Arr->Data[index];
}

/*
*   @brief : Set the index of Array with given Value 
*   @param : 
*               Arr : Array which data is searched
*               index : index number
*   @ret   : 1 in success,-1 in failure
*/
int setindexArray(Array * Arr,int index,int value)
{   
    if((index < 0) | (index > Arr->size))
   {
        return -1;
    }
    Arr->Data[index]=value;
    return 0;
}
void swap(int * a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void reverseArray(Array *Arr)
{
    int i;
    for(i=0;i<Arr->size/2;i++)
    {
        swap(&Arr->Data[i],&Arr->Data[Arr->size-i-1]);
    }
}