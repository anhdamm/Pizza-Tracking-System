
#ifndef Restaurant_H
#define Restaurant_H
#include <cstring>
#include <string>
#include <stdexcept>
#include <list>
#include <queue>
#include "Driver.h"


using namespace std;
class Restaurant
{
public:
    /*Pre: none
      Post: Creates a restaurant in an initial state, with no drivers or orders.
     */
    Restaurant();
    
    /*Pre: none
     Post: Prints status of orders and logged-in drivers, as specified by the “status” command description.
     */
    void status();
    
    
    /*Pre: none
     Post: Prints summary statistics on orders and drivers, as specified by the “summary” command description.
     */
    void summary();
    
    
    /*Pre: none
     Post: : If a driver with the given name exists within the system (logged in or not), returns a pointer to that driver. Otherwise, returns a null pointer.
     */
    Driver * getDriver(string name);
    
    
    /*Pre: none
     Post: Adds the given driver to the system.
     */
    void addDriver(Driver * driver);
    
    /*Pre: none
     Post: Adds the given order to the system, enqueuing it for cooking.
     */
    void addOrder(Order * order);
    
    /*Pre: The cooking queue is not empty.
     Post: Removes the oldest order from the cooking queue and enqueues it for departure.
     */
    void serveNextOrder() throw(logic_error);
    
    /*Pre: The departure queue is not empty.
     Post: Removes the oldest order from the departure queue and returns it.
     */
    void departNextOrder(Time time, Driver *driver) throw(logic_error);
    
    /*Pre: none
     Post: The order carried by the driver is delivered at the given time. The driver receives the given tip.
     */
    void deliver(Driver * driver, Time time, float tip);
    
    /*Pre: Driver is logged in and at the restaurant.
     Post: Logs the driver out.
     */
    void logout(string name);
    
    /*Pre: none
     Post: Returns true if the cooking quese is empty. Otherwise, returns false.
     */
    bool cookingQisEmpty();
    
    /*Pre: none
     Post: Returns true if the depart quese is empty. Otherwise, returns false.
     */
    bool departQisEmpty();

    /*Pre: none
     Post: Returns total time of serving.
     */
    int retTimeTotal();
private:
    list<Driver*> driverListIn;
    list<Driver*> driverListOut;
    list<Order*> orderListDelivered;
    queue<Order*> cookingQueue;
    queue<Order*> departureQueue;
    float timePerOrder;
    int deliveries;
    int timeTotal;
    
};

#endif 
