
#ifndef Driver_h
#define Driver_h

#include <stdio.h>
#include <string>
#include <random>
#include <math.h>

#include "Order.h"
#include "Time.h"

using namespace std;


class Driver {
public:
    /*Pre: none
     Post: Creates a logged-in driver with the given name.
     */
    Driver(string chosenName);
    
    /*Pre: Driver is not logged in.
     Post: Logs the driver in.
     */
    void login() throw (logic_error);
    
    /*Pre: Driver is logged in and at the restaurant.
     Post: Logs the driver out.
     */
    void logout() throw (logic_error);
    
    /*Pre: Driver is logged in and at the restaurant.
     Post: Driver is delivering. Departure time is recorded.
     */
    void depart(Time time, Order* o) throw (logic_error);
    
    /*Pre: Driver is delivering, tip >= 0.
     Post: Driver is not delivering. Driver’s stats are updated.
     */
    void deliver(Time time, float tip) throw (logic_error);
    
    /*Pre: Driver is driving but not delivering.
     Post: Driver is at the restaurant. Driver’s stats are updated.
     */
    void arrive(Time time) throw (logic_error);
    
    /*Pre: none
     Post: Returns the driver’s name.
     */
    string getName();
    
    /*Pre: none
     Post: Returns true if and only if the driver is logged in.
     */
    bool isLoggedIn();
    
    /*Pre: none
     Post: Returns true if and only if the driver is in the restaurant.
     */
    bool isAtRestaurant();
    
    /*Pre: Driver is logged in. Driver is not at the restaurant.
     Post: Returns true if the driver is delivering an order.
     */
    bool isDelivering();
    
    /*Pre: none
     Post: Returns the total number of deliveries.
     */
    int getTotalDeliveries();
    
    /*Pre: none
     Post: Returns the total minutes spent delivering (i.e., between “depart” and “deliver” commands).
     */
    int getTotalMinDelivering();
    
    
    /*Pre: none
     Post: Returns the total minutes spent driving (i.e., between “depart” and “arrive” commands).
     */
    int getTotalMinDriving();
    
    /*Pre: none
     Post: Returns the total tips received in dollars.
     */
    float getTotalTips();
    
    /*Pre: none
     Post: Returns the order being delivered.
     */
    Order* getOrder() throw (logic_error);
    
    /*Pre: none
     Post: Prints status of orders and logged-in drivers, as specified by the “status” command description.
     */
    void status();
    
private:
    
    string name;
    int deliveries;
    float tips;
    bool loggedIn,
    atRestaurant,
    delivering,
    driving;
    int minDelivering;
    int minDriving;
    Time deliveredTime;
    Time orderedTime;
    Time departedTime;
    Time arrivedTime;
    Order* currentOrder;
    
};

#endif
