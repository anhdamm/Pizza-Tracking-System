#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#include "Restaurant.h"
#include "Driver.h"
#include "Order.h"
#include <iomanip> 



// When you compile the test, it will show up the line "Enter a command: " and after this sentence, you type your input. For example: "Enter a command line: login Bev" then hit enter and enter the input again.



/*Pre: Driver is not logged in.
 Post: Driver login with the system.
 */
void login(Restaurant& inputRestaurant, string input)
{
    Driver* newDriver = new Driver(input);
    inputRestaurant.addDriver(newDriver);
}


/*Pre: Driver is logged in and at the restaurant.
 Post: Driver logout with the system.
 */
void logout(Restaurant& inputRestaurant, string input)
{
    if(!(inputRestaurant.getDriver(input) == nullptr))
    {
        if(inputRestaurant.getDriver(input)->isAtRestaurant())
        {
            inputRestaurant.logout(input);
        }
        else
        {
            cout << "That driver is currently out on a delivery, and cannot be logged out";
        }
    }
    else
    {
        cout << "There is no driver here by that name" << endl;
    }
}

/*Pre: none.
 Post: Returns a string with time ordered, order information and address.
 */
void order(Restaurant& inputRestaurant, string input)
{
    
    stringstream iss(input);
    string ordertime;
    iss >> ordertime;
    string orderInfo;
    iss >> orderInfo;
    unsigned long pos = input.find(orderInfo);
    orderInfo = input.substr(pos);

    int i = 0;
    unsigned int z = 1;
    z--;
    if(ordertime.at(1) == ':')
    {
        i = 1;
    }
    else if(ordertime.at(2) == ':')
    {
        i = 2;
    }
    else
    {
        throw logic_error("invalid time input, try again");
    }
    int hour3;
    int minute3;
    if(i == 1)
    {
        hour3 = stoi(ordertime.substr(0, 1));
        minute3 = stoi(ordertime.substr(2, ordertime.length() - 1));
    }
    else if(i == 2)
    {
        hour3 = stoi(ordertime.substr(0, 2));
        minute3 = stoi(ordertime.substr(3, ordertime.length() - 1));
    }
    else
    {
        throw logic_error("invalid time input, try again");
    }
    Time newTime(hour3, minute3);
    Order* newOrder = new Order(newTime, orderInfo);
    inputRestaurant.addOrder(newOrder);
}


/*Pre: none.
 Post: The time the order is served.
 */
void serve(Restaurant& inputRestaurant, string input)
{
    if(inputRestaurant.cookingQisEmpty())
    {
        throw logic_error("There are no orders to serve");
    }
    string orderTime = input;
    int i = 0;
    unsigned int z = 1;
    z--;
    if(orderTime.at(1) == ':')
    {
        i = 1;
    }
    else if(orderTime.at(2) == ':')
    {
        i = 2;
    }
    else
    {
        throw logic_error("invalid time input, try again");
    }
    int hour4;
    int minute4;
    if(i == 1)
    {
        hour4 = stoi(orderTime.substr(0, 1));
        minute4 = stoi(orderTime.substr(2, orderTime.length() - 1));
    }
    else if(i == 2)
    {
        hour4 = stoi(orderTime.substr(0, 2));
        minute4 = stoi(orderTime.substr(3, orderTime.length() - 1));
    }
    else
    {
        throw logic_error("invalid time input, try again");
    }
    Time newTime(hour4, minute4);
    inputRestaurant.serveNextOrder();
}


/*Pre: none.
 Post: The time a driver departs the order.
 */
void depart(Restaurant& inputRestaurant, string input)
{
    stringstream iss(input);
    string ordertime;
    iss >> ordertime;
    string driver;
    iss >> driver;
    
    if(inputRestaurant.departQisEmpty())
    {
        throw logic_error("There are no orders to depart");
    }
    if(!(inputRestaurant.getDriver(driver) == nullptr))
    {
        if(inputRestaurant.getDriver(driver)->isDelivering())
        {
            throw logic_error("That driver is currently out on a delivery, and cannot be sent on  another delivery");
        }
    }
    else
    {
        throw logic_error("There is no driver here by that name");
    }
    if(!(inputRestaurant.getDriver(driver) == nullptr))
    {
        
        {
            int i = 0;
            unsigned int z = 1;
            z--;
            if(ordertime.at(1) == ':')
            {
                i = 1;
            }
            else if(ordertime.at(2) == ':')
            {
                i = 2;
            }
            else
            {
                throw logic_error("invalid time input, try again");
            }
            int hour4;
            int minute4;
            if(i == 1)
            {
                hour4 = stoi(ordertime.substr(0, 1));
                minute4 = stoi(ordertime.substr(2, ordertime.length() - 1));
            }
            else if(i == 2)
            {
                hour4 = stoi(ordertime.substr(0, 2));
                minute4 = stoi(ordertime.substr(3, ordertime.length() - 1));
            }
            else
            {
                throw logic_error("invalid time input, try again");
            }
            Time newTime(hour4, minute4);
            inputRestaurant.departNextOrder(newTime, inputRestaurant.getDriver(driver));
        }
        
    }
    else
    {
        throw logic_error("There is no driver here by that name");
    }
}


/*Pre: Driver is delivering.
 Post: The time the order is delivered.
 */
void deliver(Restaurant& inputRestaurant, string input)
{
    stringstream iss(input);
    string ordertime;
    iss >> ordertime;
    string driver;
    iss >> driver;
    string tip;
    iss >> tip;
    
    int i = 0;
    //for(i; ordertime.at(i) == ':'; i++);
    int hour2;
    int minute2;
    if(ordertime.at(1) == ':')
    {
        i = 1;
    }
    else if(ordertime.at(2) == ':')
    {
        i = 2;
    }
    if(i == 1)
    {
        hour2 = stoi(ordertime.substr(0, 1));
        minute2 = stoi(ordertime.substr(2, ordertime.length() - 1));
    }
    else {
        hour2 = stoi(ordertime.substr(0, 2));
        minute2 = stoi(ordertime.substr(3, ordertime.length() - 1));
    }
    Time newTime(hour2, minute2);
    
    float newtip = stof(tip.substr(0));

    if(!(inputRestaurant.getDriver(driver) == nullptr))
    {
        inputRestaurant.deliver(inputRestaurant.getDriver(driver), newTime, newtip);
    }
    else
    {
        throw logic_error("There is no driver here by that name");
    }
}


/*Pre: none
 Post: Driver arrives to the restaurant.
 */
void arrive(Restaurant& inputRestaurant, string input)
{
    stringstream iss(input);
    string ordertime;
    iss >> ordertime;
    string driver;
    iss >> driver;
    if((inputRestaurant.getDriver(driver) == nullptr))
    {
        throw logic_error("There is no driver here by that name");
    }
    inputRestaurant.getDriver(driver);
    int i = 0;
    
    //for(i; ordertime.at(i) == ':'; i++);
    
    if(ordertime.at(1) == ':')
    {
        i = 1;
    }
    else if(ordertime.at(2) == ':')
    {
        i = 2;
    }
    else
    {
        throw logic_error("invalid time input, try again");
    }
    int hour;
    int minute;
    
    if(i == 1)
    {
        hour = stoi(ordertime.substr(0, 1));
        minute = stoi(ordertime.substr(2, ordertime.length() - 1));
    }
    
    else {
        hour = stoi(ordertime.substr(0, 2));
        minute = stoi(ordertime.substr(3, ordertime.length() - 1));
    }{
        hour = stoi(ordertime.substr(0, 2));
        minute = stoi(ordertime.substr(3, ordertime.length() - 1));
    }
    Time newTime(hour, minute);
    inputRestaurant.getDriver(driver)->arrive(newTime);
}


/*Pre: none.
 Post: Returns a string with the status of the order.
 */
void status(Restaurant& inputRestaurant)
{
    inputRestaurant.status();
}

/*Pre: none.
 Post: Returns a string with summary statistics on orders and drivers.
 */
void summary(Restaurant& inputRestaurant)
{
    inputRestaurant.summary();
}


/*Pre: none
 Post: Runs the functions that listed in this file( login, logout, order, serve, depart, deliver, arrive, status, summary,quit)
 */
bool Parser(Restaurant& inputRestaurant)
{
    while (true) {
        cout << "Enter a command: ";
        string command;
        string argument;
        getline(cin, command);
        string temp;
        
        if((command.substr(0,5)).compare("login") == 0)
        {
            string argument = command.substr(6);
            login(inputRestaurant, argument);
        }
        
        else if((command.substr(0,6)).compare("logout") == 0)
        {
            string argument = command.substr(7);
            logout(inputRestaurant, argument);
        }
        
        else if((command.substr(0,5)).compare("order") == 0)
        {
            string argument = command.substr(6);
            order(inputRestaurant, argument);
        }
        
        else if((command.substr(0,5)).compare("serve") == 0)
        {
            string argument = command.substr(6);
            serve(inputRestaurant, argument);
        }
        
        else if((command.substr(0,6)).compare("depart") == 0)
        {
            string argument = command.substr(7);
            depart(inputRestaurant, argument);
        }
        
        else if((command.substr(0,7)).compare("deliver") == 0)
        {
            string argument = command.substr(8);
            deliver(inputRestaurant, argument);
        }
        
        else if((command.substr(0,6)).compare("arrive") == 0)
        {
            string argument = command.substr(7);
            arrive(inputRestaurant, argument);
        }
        
        else if((command.substr(0,6)).compare("status") == 0)
        {
            status(inputRestaurant);
        }
        
        else if((command.substr(0,7)).compare("summary") == 0)
        {
            summary(inputRestaurant);
        }
        
        else if((command.substr(0,4)).compare("quit") == 0)
        {
            return false;
        }
        else
        {
            cout << "Unknown command entered. Please try again" << endl;
        }
    }
}


int main()
{
    Restaurant dominatos;
    bool parse = true;
    while (parse) {
        parse = Parser(dominatos);
    }
    return 0;
}

