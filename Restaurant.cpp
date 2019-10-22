
#include "Restaurant.h"
#include <iomanip>

/*Pre: none
 Post: Creates a restaurant in an initial state, with no drivers or orders.
 */
Restaurant :: Restaurant()
{
    list<Driver*> driverListIn;
    list<Driver*> driverListOut;
    list<Order*> orderListDelivered;
    queue<Order*> cookingQueue;
    queue<Order*> departureQueue;
    deliveries = 0;
    timePerOrder = 0;
}


/*Pre: none
 Post: Prints status of orders and logged-in drivers, as specified by the “status” command description.
 */
void Restaurant :: status()
{
    cout << "Orders waiting to cook: ";
    if (cookingQueue.empty())
        cout << endl;
    else
    {
        for (int i = 0; i < cookingQueue.size(); i++) {
            Order* temporaryOrder = cookingQueue.front();
            cout << endl << "\t" << temporaryOrder->toString();
            cookingQueue.pop();
            cookingQueue.push(temporaryOrder);
        }
        cout << endl;
    }
    
    cout << "Orders waiting to depart: ";
    if (departureQueue.empty())
        cout << endl;
    else
    {
        for (int i = 0; i < departureQueue.size(); i++) {
            
            
            Order* temporaryOrder = departureQueue.front();
            cout << endl << "\t" << temporaryOrder->toString();
            departureQueue.pop();
            departureQueue.push(temporaryOrder);
        }
        cout << endl;
    }
    
    cout << "Drivers: " << endl;
    if (driverListIn.empty())
        cout << "empty" << endl;
    else {
        for (Driver* driverEx : driverListIn)
        {
            driverEx->status();
        }
    }
}


/*Pre: none
 Post: Prints summary statistics on orders and drivers, as specified by the “summary” command description.
 */
void Restaurant :: summary()
{
    cout << "Number of orders completed: " << orderListDelivered.size() << endl;
    cout << "Average time per order: " << timePerOrder << endl;
    
    for (Driver* exDriver : driverListIn) {
        cout << "Driver " << exDriver->getName() << ":" << endl;
        cout << "\tNumber of deliveries completed: " << exDriver->getTotalDeliveries() << endl;
        if (exDriver->getTotalDeliveries() == 0)
        {
        cout << "\tAverage time per delivery: N/A" << endl;
        }
        else
        {
            cout << "\tAverage time per delivery: " << ((exDriver->getTotalMinDriving()) / (exDriver->getTotalDeliveries())) << endl;
        }
        cout << "\tTotal driving time: " << exDriver->getTotalMinDelivering() << endl;
        
        cout << "\tTotal tips: " << exDriver->getTotalTips() << endl;
    }
    
    for (Driver* exDriver : driverListOut) {
        cout << "Driver " << exDriver->getName() << ":" << endl;
        cout << "\tNumber of deliveries completed: " << exDriver->getTotalDeliveries() << endl;
        if (exDriver->getTotalDeliveries() == 0)
        {
            cout << "\tAverage time per delivery: N/A" << endl;
        }
        else
        {
            cout << "\tAverage time per delivery: " << ((exDriver->getTotalMinDelivering()) / (exDriver->getTotalDeliveries())) << endl;

        }
        
        cout << "\tTotal driving time: " << exDriver->getTotalMinDriving() << endl;
        cout << "\tTotal tips: " << exDriver->getTotalTips() << endl;
    }
}


/*Pre: none
 Post: : If a driver with the given name exists within the system (logged in or not), returns a pointer to that driver. Otherwise, returns a null pointer.
 */
Driver* Restaurant :: getDriver(string name)
{
    for(Driver* exDriver : driverListIn)
    {
        if(exDriver->getName() == name)
        {
            return exDriver;
        }
    }
    return nullptr;
}


/*Pre: none
 Post: Adds the given driver to the system.
 */
void Restaurant :: addDriver(Driver *driver)
{
    driverListIn.push_back(driver);
    driver->login();
}


/*Pre: none
 Post: Adds the given order to the system, enqueuing it for cooking.
 */
void Restaurant :: addOrder(Order *order)
{
    cookingQueue.push(order);
}


/*Pre: The cooking queue is not empty.
 Post: Removes the oldest order from the cooking queue and enqueues it for departure.
 */
void Restaurant :: serveNextOrder() throw(logic_error)
{
    if(cookingQueue.empty())
    {
        logic_error("There are no orders to serve");
    }
    else
    {
        departureQueue.push(cookingQueue.front());
        cookingQueue.pop();
    }
}


/*Pre: The departure queue is not empty.
 Post: Removes the oldest order from the departure queue and returns it.
 */
void Restaurant::departNextOrder(Time time, Driver *driver) throw(logic_error)
{
    if (departureQueue.empty())
    {
        logic_error("There are no pizzas to deliver");
    }
    else
    {
        for (int i = 0; i < 100; i++)
        {
            if (!(driver->isDelivering()))
            {
                driver->depart(time, departureQueue.back());
                departureQueue.pop();
                return void();
            }
        }
        logic_error("There are no drivers available to depart with this order.");
    }
}


/*Pre: none
 Post: The order carried by the driver is delivered at the given time. The driver receives the given tip.
 */
void Restaurant :: deliver(Driver *driver, Time time, float tip)
{
    driver->deliver(time, tip);
    float tempTimeTool = deliveries * timePerOrder;
    tempTimeTool += driver->getOrder()->getTimeElapsed();
    deliveries ++;
    orderListDelivered.push_back(driver->getOrder());
    timePerOrder = (tempTimeTool / deliveries);
    
}


/*Pre: Driver is logged in and at the restaurant.
 Post: Logs the driver out.
 */
void Restaurant :: logout(string name)
{
    bool isFound = false;
    for(Driver* exDriver : driverListIn)
    {
        if(exDriver->getName() == name)
        {
            driverListOut.push_front(exDriver);
            driverListIn.remove(exDriver);
            exDriver->logout();
            isFound = true;
            break; break;
        }
    }
    if(!isFound)
    {
        cout << "Logout unsuccessful" << endl;
    }
}


/*Pre: none
 Post: Returns true if the cooking quese is empty. Otherwise, returns false.
 */
bool Restaurant:: cookingQisEmpty()
{
    return cookingQueue.empty();
}


/*Pre: none
 Post: Returns true if the depart quese is empty. Otherwise, returns false.
 */
bool Restaurant:: departQisEmpty()
{
    return departureQueue.empty();
}


/*Pre: none
 Post: Returns total time of serving.
 */
int Restaurant:: retTimeTotal()
{
    return (deliveries * timePerOrder * 2);
}
