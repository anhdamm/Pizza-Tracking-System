#include "Order.h"
#include <string>

/*Pre: none
 Post: Creates an order with default values for data members.
 */
Order::Order(){
    
    Time time;
    orderedTime = time;
    orderState = "atRestaurant";
    orderInfo = "";
    
}


/*Pre: none
 Post: Creates an order with the given order time and information.
 */
Order::Order(Time time, string info)
: orderedTime(time), orderInfo(info), orderState("atRestaurant")
{
}



/*Pre: Order is at the restaurant.
 Post: Order is out for delivery.
 */
void Order::depart(Time time) throw(logic_error){
    departedTime = time;
    
    if (orderState == "atRestaurant") {
        orderState = "toBeDelivered";
    }
    else{
        throw logic_error("Order not at restaurant");
    }
    
}


/*Pre: Order is out for delivery.
 Post: Order is delivered. Time to delivery is recorded.
 */
void Order::deliver(Time time) throw(logic_error){
    
    if (orderState == "toBeDelivered") {
        orderState = "delivered";
        deliveredTime = time;
    }
    else {
        throw logic_error("Order not being delivered");
    }
}


/*Pre: Order is delivered.
 Post: Returns the minutes until the order is delivered (i.e., between “order” and “deliver” commands). 
 */
int Order::getMinToDelivery() throw(logic_error){

    int minutesUntil = Time::elapseMin(orderedTime, deliveredTime);

    if (orderState == "delivered") {
        return minutesUntil;
    }

    else
    {
        throw logic_error("Order not delivered");
    }
}


/*Pre: none
 Post: Returns a string containing the order time and info.
 */
string Order::toString(){
    
    string timeAndInfo = orderedTime.toString() + " " + orderInfo ;
    return timeAndInfo;
}

/*Pre: none
 Post: Returns the difference in minutes between 2 other times.
 */
int Order::getTimeElapsed()
{
    return Time::elapseMin(orderedTime, deliveredTime);
}


