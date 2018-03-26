#include<iostream>
using namespace std;
#include <stdio.h>

//网络字节序是大端 java虚拟机也是大端
//一般的intel X86都是小端  ARM是大端
//一般要将PC端的网络地址转化为大端(网络字节序)之后再从网络字节序中国转换为PC端的小端模式


void byteorder()
{
	union
	{
		short value;
		char union_bytes[ sizeof( short ) ];
	} test;
	test.value = 0x0102;
	if (  ( test.union_bytes[ 0 ] == 1 ) && ( test.union_bytes[ 1 ] == 2 ) )
	{
		printf( "big endian\n" );
	}
	else if ( ( test.union_bytes[ 0 ] == 2 ) && ( test.union_bytes[ 1 ] == 1 ) )
	{
		printf( "little endian\n" );
	}
	else
	{
		printf( "unknown...\n" );
	}
}

void My_test_byteorder()
{
  unsigned int a=1;
  unsigned char*p = (unsigned char*)&a;
  if(*p == 1)
	{
      printf( "little endian\n" );
    }
   else if(*p == 0)
	{
      printf( "big endian\n" );
    }
   else
	{
      printf( "unknown...\n" );
    }
}

int main()
{
  byteorder();
  My_test_byteorder();
  return 0;
}
