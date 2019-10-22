#include "Driver.h"

/*Pre: none
 Post: Creates a logged-in driver with the given name.
 */
Driver:: Driver(string chosenName) //Done
{
    name = chosenName;
    deliveries = 0;
    tips = 0;
    loggedIn = false;
    atRestaurant = true;
    delivering = false;
    driving = false;
    currentOrder = nullptr;
    minDelivering = 0;
    minDriving = 0;
}

/*Pre: Driver is not logged in.
 Post: Logs the driver in.
 */
void Driver:: login() throw (logic_error) //Done
{
    if (isLoggedIn())
        throw logic_error ("Driver is already logged in!");
    
    loggedIn = true;
}


/*Pre: Driver is logged in and at the restaurant.
 Post: Logs the driver out.
 */
void Driver:: logout() throw (logic_error) //Done
{
    if (!isLoggedIn())
        throw logic_error ("Driver is not logged in!");
    if (!isAtRestaurant())
        throw logic_error ("Driver is not at the restaurant");
    
    loggedIn = false;
}


/*Pre: Driver is logged in and at the restaurant.
 Post: Driver is delivering. Departure time is recorded.
 */
void Driver:: depart(Time time, Order* o) throw (logic_error)
{
    if (!isLoggedIn())
        throw logic_error ("Driver is not logged in!");
    if (!isAtRestaurant())
        throw logic_error ("Driver is not at the restaurant");
    
    delivering = true;
    atRestaurant = false;
    driving = false;
    departedTime = time;
    currentOrder = o;
    o->depart(time);
}


/*Pre: Driver is delivering, tip >= 0.
 Post: Driver is not delivering. Driver’s stats are updated.
 */
void Driver:: deliver(Time time, float tip) throw (logic_error)
{
    if(!isDelivering())
        throw logic_error ("Driver is not delivering!");
    
    delivering = false;
    driving = true;
    
    tips += tip;
    currentOrder->deliver(time);
    deliveredTime = time;
    deliveries++;
    minDelivering = Time::elapseMin(departedTime, deliveredTime);

}


/*Pre: Driver is driving but not delivering.
 Post: Driver is at the restaurant. Driver’s stats are updated.
 */
void Driver:: arrive(Time time) throw (logic_error)
{
    if(isDelivering())
        throw logic_error ("Driver is delivering but not driving!");
    
    arrivedTime = time;
    driving = false;
    atRestaurant = true;
    minDriving = Time::elapseMin(departedTime, arrivedTime);

}

/*Pre: none
 Post: Returns the driver’s name.
 */
string Driver:: getName() //Done
{
    return name;
}


/*Pre: none
 Post: Returns true if and only if the driver is logged in.
 */
bool Driver:: isLoggedIn() //Done
{
    return loggedIn;
}


/*Pre: none
 Post: Returns true if and only if the driver is in the restaurant.
 */
bool Driver :: isAtRestaurant()
{
    return atRestaurant;
}


/*Pre: Driver is logged in. Driver is not at the restaurant.
 Post: Returns true if the driver is delivering an order.
 */
bool Driver :: isDelivering()
{
    return delivering;
}


/*Pre: none
 Post: Returns the total number of deliveries.
 */
int Driver:: getTotalDeliveries()
{
    return deliveries;
}


/*Pre: none
 Post: Returns the total minutes spent delivering in a string.
 */
int Driver::getTotalMinDelivering()
{
    return minDelivering;
}


/*Pre: none
 Post: Returns the total minutes spent driving (i.e., between “depart” and “arrive” commands).
 */
int Driver::getTotalMinDriving()
{
    return minDriving;
}

/*Pre: none
 Post: Returns the total tips received in dollars.
 */
float Driver:: getTotalTips()
{
    return tips;
}


/*Pre: none
 Post: Returns the order being delivered.
 */
Order* Driver:: getOrder() throw (logic_error)
{
    return currentOrder;
}

/*Pre: none
 Post: Prints status of orders and logged-in drivers, as specified by the “status” command description.
 */
void Driver :: status()
{
    cout << "\t" << "\t" << name << " ";
    if (currentOrder != nullptr)
    {
        cout << currentOrder->toString() <<endl;
    }
    else
    {
        cout << endl;
    }
    
}
