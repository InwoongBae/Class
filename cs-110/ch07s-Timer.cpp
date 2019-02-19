/*
 Chapter: 7
 program: ch07s-Timer
 Author : Inwoong Bae
 Date   : 3/2/2015

 Purpose: Provide sample of nested loops, using good indentation

 Program: Display timer

          output hours, minites and seconds that have elapsed since start of program	
*/
//Specify preprocessor directives

#include <iomanip>
#include <iostream>

using namespace std;

#include <cstdlib>

int main()
{
  
//Declare variables

  int hr;   //hours
  int min;  //minites
  int sec;  //seconds

//Output title and instructions

  cout << "Timer Program" << endl;
  cout << "--------------------------" << endl << endl;
  cout << "To exit, press Ctrl C keys" << endl << endl;;
  cout.fill('0'); 
//Output elapsed time since start of program

  for (hr = 0; hr < 24; hr++)
  {
     for (min = 0; min < 60; min++)
     {
        for (sec = 0; sec < 60; sec++)
        {
                    
          cout << setw(2) << hr  << ":";
          cout << setw(2) << min << ":";
          cout << setw(2) << sec << " ";
          
          cout.flush();
          _sleep(1000);
  
          cout << "\r";        
          
        }
     }
  }

}