#include <iostream>
#include "VipDinner.h"

VipDinner::VipDinner() {
	theMeal = chicken;
	theSideDish = salad; 
	theDrink = red_wine;
	theDessert = suffle; 
	// default values, can be changed later 
}
VipDinner::VipDinner(const VipDinner& other) {
    theMeal = other.theMeal;
    theSideDish = other.theSideDish;
    theDrink = other.theDrink;
    theDessert = other.theDessert;
}
void VipDinner:: chooseMeal(int choice) {
    switch (choice) {
    case 1:
        this->theMeal= chicken;
        break;
    case 2:
        this->theMeal= steak;
        break;
    case 3:
        this->theMeal = fish;
        break;
    case 4:
        this->theMeal = lubster;
        break;
    default:
        this->theMeal = chicken;
        break;
    }
}
const char* VipDinner::getMeal(void) {
    switch (theMeal)
    {
    case chicken:
        return "Chicken";
    case steak:
        return "Steak";
    case fish:
        return "Fish";
    case lubster:
        return "Lubster";
    default:
        return "Chicken - Default";
    }
}
int VipDinner::getMealNum(const VipDinner& other){
    return other.theMeal;
}
void VipDinner::chooseSideDish(int choice) {
    switch (choice) {
    case 1:
        this->theSideDish = salad;
        break;
    case 2:
        this->theSideDish = pasta;
        break;
    case 3:
        this->theSideDish = rice;
        break;
    default:
        this->theSideDish = salad;
        break;
    }
}
const char* VipDinner::getSideDish(void){
    switch (theSideDish)
    {
    case salad:
        return "Salad";
    case pasta:
        return "Pasta";
    case rice:
        return "Rice";
    default:
        return "Salad - Default";
    }
}
int VipDinner::getSideNum(const VipDinner& other) {
    return other.theSideDish;
}
void VipDinner::chooseDessert(int choice) {
    switch (choice) {
    case 1:
        this->theDessert = suffle;
        break;
    case 2:
        this->theDessert = tiramissu;
        break;
    case 3:
        this->theDessert = cheescake;
        break;
    default:
        this->theDessert = suffle;
        break;
    }
}
const char* VipDinner::getDessert(void) {
    switch (theDessert)
    {
    case suffle:
        return "Suffle";
    case tiramissu:
        return "Tiramissu";
    case cheescake:
        return "Cheescake";
    default:
        return "Suffle - Default";
    }
}
int VipDinner::getDessertNum(const VipDinner& other) {
    return other.theDessert;
}
void VipDinner::chooseDrink(int choice) {
    switch (choice) {
    case 1:
        this->theDrink = red_wine;
        break;
    case 2:
        this->theDrink = white_wine;
        break;
    case 3:
        this->theDrink = cocktaile;
        break;
    case 4:
        this->theDrink = soda;
        break;
    default:
        this->theDrink = red_wine;
        break;
    }
}
const char* VipDinner::getDrink(void) {
    switch (theDrink)
    {
    case red_wine:
        return "Red wine";
    case white_wine:
        return "White wine";
    case cocktaile:
        return "Cocktaile";
    case soda:
        return "Soda";
    default:
        return "Red wine - Default";
    }
}
int VipDinner::getDrinkNum(const VipDinner& other) {
    return other.theDrink;
}
VipDinner& VipDinner:: operator=(const VipDinner& other) {
  
    this->chooseMeal(getMealNum(other));
    this->chooseSideDish(getSideNum(other));
    this->chooseDrink(getDrinkNum(other));
    this->chooseDessert(getDessertNum(other));
    return *this;
}
void VipDinner::print(void)const {
    cout << "Vip Dinner" << endl;
    cout << "main course is " << theMeal<<endl;
    cout << "side dish is " << theSideDish << endl;
    cout << "the drink is " << theDrink << endl;
    cout << "the Dessert is " << theDessert << endl;
}
void VipDinner::setDinner(int meal, int side, int drink, int dessert) {
    chooseMeal(meal);
    chooseSideDish(side);
    chooseDrink(drink);
    chooseDessert(dessert);
}
const char* VipDinner::getMealByNum(int index)const {
    switch (index)
    {
    case chicken:
        return "Chicken";
    case steak:
        return "Steak";
    case fish:
        return "Fish";
    case lubster:
        return "Lubster";
    default:
        return "Chicken - Default";
    }
}
const char* VipDinner::getSideByNum(int index)const {
    switch (index)
    {
    case salad:
        return "Salad";
    case pasta:
        return "Pasta";
    case rice:
        return "Rice";
    default:
        return "Salad - Default";
    }
}
const char* VipDinner::getDrinkByNum(int index)const {
    switch (index)
    {
    case suffle:
        return "Suffle";
    case tiramissu:
        return "Tiramissu";
    case cheescake:
        return "Cheescake";
    default:
        return "Suffle - Default";
    }
}
const char* VipDinner::getDessertByNum(int index)const {
    switch (index)
    {
    case suffle:
        return "Suffle";
    case tiramissu:
        return "Tiramissu";
    case cheescake:
        return "Cheescake";
    default:
        return "Suffle - Default";
    }
}
void VipDinner::printMenu(void)const {
    cout << "////////////////////// MENU /////////////////////////"<<endl;
    cout << " main courses: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << "------------------------------" << getMealByNum(i)<<endl;
    }
    cout << " side dishes: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << "------------------------------" << getSideByNum(i) << endl;
    }
    cout << " drinks: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << "------------------------------" << getDrinkByNum(i) << endl;
    }
    cout << " desserts: " << endl;

    for (int i = 0; i < 3; i++) {
        cout << "------------------------------" << getDessertByNum(i) << endl;
    }
    cout << "all side dishes and drinks can be refill freely!";
}