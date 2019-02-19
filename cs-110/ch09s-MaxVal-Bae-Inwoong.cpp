/* 

  Chapter : 9
  Program : ch09s-MaxVal-Bae-Inwoong.cpp
  Author  : Inwoong Bae
  Date    : 3/16/2015
  Purpuse : Provide sample of minimum and maximum values for several unsigned and signed integer fields

*/

#include <iostream>

using namespace std;

int main()
{
  unsigned            char u1;

  unsigned short       int u2;
  unsigned             int u3;
  unsigned long  long  int u4;

    signed            char s1;
  
    signed short       int s2;
    signed             int s3;
    signed long  long  int s4;

    signed            char s5;
  
    signed short       int s6;
    signed             int s7;
    signed long  long  int s8;

  u1 = UCHAR_MAX;
  u2 = USHRT_MAX;
  u3 = UINT_MAX;
  u4 = _UI64_MAX;

  s1 = CHAR_MIN;
  s2 = SHRT_MIN;
  s3 = INT_MIN;
  s4 = _I64_MIN;

  cout << endl;

  cout << "  int(UCHAR_MAX) = " << int(u1) << endl;

  cout << "      USHRT_MAX  = " <<     u2  << endl;
  cout << "      UINT_MAX   = " <<     u3  << endl;
  cout << "      _UI64_MAX  = " <<     u4  << endl << endl;

  cout << endl;

  cout << "  int(CHAR_MIN)  = " << int(s1) << endl;
  cout << "      SHRT_MIN   = " <<     s2  << endl;
  cout << "       INT_MIN   = " <<     s3  << endl;
  cout << "       _64_MIN   = " <<     s4  << endl << endl;

  s1 = CHAR_MAX;
  s2 = SHRT_MAX;
  s3 = INT_MAX;
  s4 = _I64_MAX;

  cout << endl;

  cout << "  int(CHAR_MAX)  = " << int(s1) << endl;
  cout << "      SHRT_MAX   = " <<     s2  << endl;
  cout << "       INT_MAX   = " <<     s3  << endl;
  cout << "       _64_MAX   = " <<     s4  << endl << endl;

  s1++;
  s2++;
  s3++;
  s4++;

  cout << "  int(CHAR_MAX) + 1  = " << int(s1) << endl;
  cout << "      SHRT_MAX  + 1  = " <<     s2  << endl;
  cout << "       INT_MAX  + 1  = " <<     s3  << endl;
  cout << "       _64_MAX  + 1  = " <<     s4  << endl << endl;
}