#ifndef Time_h
#define Time_h

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Time {
public:
    
    /* Pre: none
     Post: Creates a time with default values for data members.
     */
    Time();
    
    /*Pre: 0 <= hour <= 23 and 0 <= min <= 59.
     Post: Creates a time with the given hour and minute.
     */
    Time(int hr, int min) throw (logic_error);
    
    /*Pre: none
     Post: Returns the difference in minutes between t1 and t2. Assumes t2 is between 00:00 and 23:59 hours after t1.
     */
    static int elapseMin(Time t1, Time t2);
    
    /*Pre: none
     Post: Returns a string containing the hour and minute (e.g., “13:01”).
     */
    string toString() const;
    
private:
    int hour;
    int minute;
    
};

#endif 
