#ifndef Order_h
#define Order_h

#include <stdio.h>
#include <iostream>
#include <string>
#include "Time.h"

using namespace std;

class Order
{
public:
    string atRestaurant = "atRestaurant";
    string toBeDelivered = "toBeDelivered";
    string delivered = "delivered";
    
    /*Pre: none
     Post: Creates an order with default values for data members.
    */
    Order();
    
    /*Pre: none
     Post: Creates an order with the given order time and information.
     */
    Order(Time time, string info);
    
    /*Pre: Order is at the restaurant.
     Post: Order is out for delivery.
     */
    void depart(Time time) throw (logic_error);
    
    /*Pre: Order is out for delivery.
     Post: Order is delivered. Time to delivery is recorded.
     */
    void deliver(Time time) throw (logic_error);
    
    /*Pre: Order is delivered.
     Post: Returns the minutes until the order is delivered (i.e., between “order” and “deliver” commands).
     */
    int getMinToDelivery() throw (logic_error);
    
    /*Pre: none
     Post: Returns a string containing the order time and info.
     */
    string toString();
    
    
    /*Pre: none
     Post: Returns the difference in minutes between 2 other times.
     */
    int getTimeElapsed();
    
    
private:
    Time departedTime;
    Time arrivedTime;
    Time orderedTime;
    Time deliveredTime;
    string orderInfo;
    string orderState;
};

#endif 
