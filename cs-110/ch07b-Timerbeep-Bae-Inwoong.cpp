/*
 Chapter: 7
 program: ch07b-TimerBeep-Bae-Inwoong
 Author : Inwoong Bae
 Date   : 3/2/2015

 Purpose: Provide sample of nested loops, using good indentation

 Program: Display timer

          output hours, minites and seconds that have elapsed since start of program

          Same as sample program ch07s-Timer, but also:

          -- every minute,
               sound beep at 880 hertz for half second
               (use "beep" function from windows header file)
          -- every 10 seconds BETWEEN minutes,
               (use cout command with escapre and control characters for "alert")

          At start of minute, do not issue both sounds	
*/
//Specify preprocessor directives

#include <iomanip>
#include <iostream>

using namespace std;

#include <cstdlib>
#include <windows.h> // WinApi header

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
        Beep(880,500); // 880 hertz for half of seconds           

        for (sec = 0; sec < 60; sec++)
        {
                    
          cout << setw(2) << hr  << ":";
          cout << setw(2) << min << ":";
          cout << setw(2) << sec << " ";
          
          cout.flush();


          if(sec % 10 == 0 && sec != 0)
          cout << '\a';

          _sleep(1000);
  
          cout << '\r';        
          
        }
     }
  }

}