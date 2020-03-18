#include <gtest/gtest.h>
#include <iostream>
using namespace std;
extern "C"
{
    #include "../Array.h"
    #include "../Array.c"
}
TEST(ArrayAdtTest,getindextest)
{
    Array a1;
    InitArray(&a1,0,10);
    appendArray(&a1,45);
    appendArray(&a1,12);
    appendArray(&a1,27);
    EXPECT_EQ(getindexArray(&a1,1),12);
    EXPECT_EQ(getindexArray(&a1,4),-1);
    EXPECT_EQ(getindexArray(&a1,-1),-1);
    destroyArray(&a1);

}
TEST(ArrayAdtTest,InitArrayTest)
{
    Array temp_array;
    InitArray(&temp_array,0,5);
    EXPECT_EQ(temp_array.size,0);
    EXPECT_EQ(temp_array.length,5);
    destroyArray(&temp_array);
}
TEST(ArrayAdtTest,destroyArrayTest)
{
    Array temp_array;
    InitArray(&temp_array,0,5);
    destroyArray(&temp_array);
    EXPECT_EQ(temp_array.length,0);
    EXPECT_EQ(temp_array.size,0);
}
TEST(ArrayAdtTest,setArrayZeroTest)
{
    Array temp_array;
    InitArray(&temp_array,0,5);
    setArrayZero(&temp_array);
    EXPECT_EQ(getindexArray(&temp_array,0),0);
    EXPECT_EQ(getindexArray(&temp_array,9),-1);
    destroyArray(&temp_array);
}
TEST(ArrayAdtTest,appendArrayTest)
{
    Array temp_array;
    InitArray(&temp_array,0,8);
    int i;
    for(i=0;i<temp_array.length;i++)
    {
        appendArray(&temp_array,i*5);
        EXPECT_EQ(getindexArray(&temp_array,i),i*5);
    }
    destroyArray(&temp_array);
}
TEST(ArrayAdtTest,insertArrayTest)
{
    Array temp_array;
    InitArray(&temp_array,0,10);
    int RandomIndex[]={0,2,6},i;
    for(i=0;i<4;i++)
    {
        appendArray(&temp_array,i*8);
    }
    for(i=0;i<3;i++)
    {
        insertArray(&temp_array,5,RandomIndex[i]);
        EXPECT_EQ(getindexArray(&temp_array,RandomIndex[i]),5);
    }
    destroyArray(&temp_array);

}
TEST(ArrayAdtTest,deleteindexArrayTest)
{
    Array temp_array,temp_copy;
    InitArray(&temp_array,0,10);
    int i;
    for(i=0;i<temp_array.length;i++)
    {
        appendArray(&temp_array,i*i);
    }
    temp_copy=temp_array;
    deleteindexArray(&temp_array,4);
    EXPECT_NE(16,getindexArray(&temp_copy,4));
    EXPECT_EQ(deleteindexArray(&temp_array,-4),-1);
    EXPECT_EQ(deleteindexArray(&temp_array,15),-1);
    destroyArray(&temp_array);
}
TEST(ArrayAdtTest,searchArrayTest)
{
    Array temp_array,temp_copy;
    InitArray(&temp_array,0,10);
    int i;
    for(i=0;i<temp_array.length;i++)
    {
        appendArray(&temp_array,i*i);
    }
    EXPECT_EQ(searchArray(&temp_array,25),5);
    EXPECT_EQ(searchArray(&temp_array,64),8);
    EXPECT_EQ(searchArray(&temp_array,45),-1);

}
TEST(ArrayAdtTest,setindexArrayTest)
{
    Array temp_array;
    InitArray(&temp_array,0,10);
    
    //Set array to zero in order to access all element
    setArrayZero(&temp_array);
    //Set first index then get it test they are equal
    setindexArray(&temp_array,0,52);
    EXPECT_EQ(getindexArray(&temp_array,0),52);
    
    //Get middle element test it to be zero
    EXPECT_EQ(getindexArray(&temp_array,5),0);

    //Set last index then get it test they are equal
    setindexArray(&temp_array,9,63);
    EXPECT_EQ(getindexArray(&temp_array,9),63);

    destroyArray(&temp_array);
}
TEST(ArrayAdtTest,reverseArrayTest)
{
    Array temp_array,temp_copy;
    InitArray(&temp_array,0,10);
    InitArray(&temp_copy,0,10);
    int i;
    for(i=0;i<temp_array.length;i++)
    {
        appendArray(&temp_array,i*i);
        appendArray(&temp_copy,i*i);

    }
    reverseArray(&temp_array);
    for(i=0;i<temp_array.size;i++)
    {
        EXPECT_EQ(getindexArray(&temp_array,i),getindexArray(&temp_copy,temp_copy.size-i-1))<<"Array reversed is ok"<<endl;
    }
    destroyArray(&temp_array);
}
int main(int argc,char **argv)
{
    
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
    
}