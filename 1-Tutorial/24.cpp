#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * TASK: Restaurant Order Management System
 * 
 * REQUIREMENTS:
 * 1. Create an enum for DishType (APPETIZER, MAIN_COURSE, DESSERT, BEVERAGE)
 * 2. Create an enum for OrderStatus (PENDING, PREPARING, READY, SERVED, CANCELLED)
 * 3. Create a Dish structure with:
 *    - name (string)
 *    - type (DishType)
 *    - price (double)
 * 4. Create an Order structure with:
 *    - orderId (int)
 *    - dishes (vector<Dish>)
 *    - status (OrderStatus)
 *    - tableNumber (int)
 * 5. Implement these functions:
 *    - void displayDish(Dish d) - prints dish info
 *    - void displayOrder(Order o) - prints full order with all dishes
 *    - double calculateTotal(Order o) - returns sum of all dish prices
 *    - void updateOrderStatus(Order& o, OrderStatus newStatus) - updates status
 *    - void addDishToOrder(Order& o, Dish d) - adds a dish to order
 * 6. In main():
 *    - Create at least 5 different dishes with varying types
 *    - Create 2-3 orders
 *    - Add dishes to each order
 *    - Display each order with total price
 *    - Update order statuses and display the changes
 *    - Track price changes as orders are modified
 * 
 * STRETCH GOALS (optional):
 * - Add a function to remove a dish from an order
 * - Add a function to filter orders by status
 * - Add timestamps to orders
 * - Implement discount for orders over $50
 */

// TODO: Define enums and structures here

// TODO: Implement all required functions here

enum DishType {
    APPETIZER, MAIN_COURSE, DESSERT, BEVERAGE
};
enum OrderStatus {
    PENDING, PREPARING, READY, SERVED, CANCELLED
};

struct Dish {
    string name;
    DishType type;
    double price;
};

struct Order{
    int orderID;
    vector<Dish> dishes;
    OrderStatus status;
    int tableNumber;
};

void displayDish(Dish d){
    cout << "Name: " << d.name << endl;
    cout << "Type: " << d.type << endl;
    cout << "Price: " << d.price << endl;
}

void displayOrder(Order o){
    cout << "order id: " << o.orderID << endl;
    cout << "Dishes: " << endl;
    for (auto i: o.dishes){
        cout << i.name << ' ';
    }
    cout << endl;
    cout << "order status: " << o.status << endl;
    cout << "Table number: " << o.tableNumber << endl;
}

double calculateTotal(Order o){
    double s = 0;
    for (auto i: o.dishes){
        s += i.price;
    };
    return s;
}

void updateOrderStatus(Order& o, OrderStatus newStatus){
    o.status = newStatus;
}

void addDishToOrder(Order& o, Dish d) {
    o.dishes.push_back(d);
}

double calculateDiscount(Order& o){
    const int tenPercentThreshold = 50;
    const int fifteenPercentThreshold = 100;
    double totalprice = calculateTotal(o);
    if (totalprice < tenPercentThreshold){
        return 0.0;
    } else if (totalprice < fifteenPercentThreshold){
        return totalprice*0.1;
    } else {
        return totalprice*0.15;
    }
}

double calculateTotalwithDiscount(Order& o){
    return calculateTotal(o) - calculateDiscount(o);
}


int main() {
    Dish d1 = {"Salad", APPETIZER, 5.99};
    Dish d2 = {"Steak", MAIN_COURSE, 19.99};
    Dish d3 = {"Ice Cream", DESSERT, 3.99};
    Dish d4 = {"Soda", BEVERAGE, 1.99};
    Dish d5 = {"Soup", APPETIZER, 4.99};

    Order o1 = {1, {}, PENDING, 5};
    Order o2 = {2, {}, PENDING, 3};
    Order o3 = {3, {}, PENDING, 10};


    addDishToOrder(o1, d1);
    addDishToOrder(o1, d2);
    addDishToOrder(o1, d3);
    addDishToOrder(o2, d3);
    addDishToOrder(o2, d4);
    addDishToOrder(o2, d5);

    addDishToOrder(o3, d2);
    addDishToOrder(o3, d2);
    addDishToOrder(o3, d2);
    addDishToOrder(o3, d2);
    addDishToOrder(o3, d2);
    addDishToOrder(o3, d4);

    displayOrder(o1);
    cout << "Total: " << calculateTotal(o1) << endl;
    displayOrder(o2);
    cout << calculateTotal(o2) << endl;
    o1.status = PREPARING;
    o2.status = READY;
    cout << "Total: " << calculateTotal(o1) << endl;
    cout << "Total: " << calculateTotal(o2) << endl;    

    cout << "Total: " << calculateTotalwithDiscount(o3) << endl;    
    return 0;
}