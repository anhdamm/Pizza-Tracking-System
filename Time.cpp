#include "Time.h"

using namespace std;

/* Pre: none
 Post: Creates a time with default values for data members.
*/
Time::Time(){
    
    minute = 0;
    hour = 0;
}

/*Pre: 0 <= hour <= 23 and 0 <= min <= 59.
 Post: Creates a time with the given hour and minute.
 */
Time::Time(int hr, int min) throw (logic_error){
    
    if ((hr >= 0) && (hr <= 23) && (min >= 0) && (min <= 59)) {
        hour = hr;
        minute = min;
    }
    else{
        throw logic_error("hour and/or minutes are invalid times");
    }
}

/*Pre: none
 Post: Returns the difference in minutes between t1 and t2. Assumes t2 is between 00:00 and 23:59 hours after t1.
*/
int Time::elapseMin(Time t1, Time t2){
    
    int t1TotalMinutes;
    int t2TotalMinutes;
    int t1HoursinMinutes;
    int t2HoursinMinutes;
    
    t1HoursinMinutes = (t1.hour * 60);
    t2HoursinMinutes =(t2.hour * 60);
    
    t1TotalMinutes =  t1HoursinMinutes + t1.minute;
    t2TotalMinutes =  t2HoursinMinutes + t2.minute;
    
    return t2TotalMinutes - t1TotalMinutes;
}

/*Pre: none
 Post: Returns a string containing the hour and minute (e.g., “13:01”).   
 */
string Time::toString() const{
    
    string timeToString;
    if(minute < 10)
    {
        timeToString = to_string(hour) + ":" + "0" + to_string(minute);
    }
    else
    {
        timeToString = to_string(hour) + ":" + to_string(minute);
    }
    
    return timeToString;
}
