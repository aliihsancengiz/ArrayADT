#ifndef _myARRLIB
#define _myARRLIB

#include<stdio.h>
#include<stdlib.h>

struct A
{
    int * Data;
    int size,length;
};
typedef struct A Array;

//Protype of functions
void dispArray(Array * t);
void InitArray(Array * Arr,int size,int length);
void destroyArray(Array *Arr);
void setArrayZero(Array *Arr);
int appendArray(Array *Arr,int data);
int insertArray(Array *Arr,int data,int index);
int deleteindexArray(Array*Arr,int index);
int searchArray(Array *Arr,int key);
int getindexArray(Array * Arr,int index);
int setindexArray(Array * Arr,int index,int value);
void reverseArray(Array *Arr);

#endif
