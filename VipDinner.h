#pragma once
#include <iostream>
#include "OrchestraExceptions.h"
class VipDinner
{
private:
    enum Meal { chicken, steak, fish, lubster };
    enum sideDish {salad, pasta, rice};
    enum Dessert { suffle, tiramissu, cheescake };
    enum Drink { red_wine, white_wine, cocktaile, soda };
    Meal theMeal;
    sideDish theSideDish;
    Dessert theDessert;
    Drink theDrink;

public:
    VipDinner(void);
    VipDinner(const VipDinner& other);// copy
    void chooseMeal(int choice);
    const char* getMeal(void);
    void chooseSideDish(int choice);
    const char* getSideDish(void);
    void chooseDessert(int choice);
    const char* getDessert(void);
    void print(void)const;
    void chooseDrink(int choice);
    const char* getDrink(void);
    int getMealNum(const VipDinner& other);
    int getSideNum(const VipDinner& other);
    int getDessertNum(const VipDinner& other);
    int getDrinkNum(const VipDinner& other);
    VipDinner& operator=(const VipDinner& other); // assignment operator
    void setDinner(int meal, int side, int drink, int dessert);
    void printMenu(void)const ;
    const char* getMealByNum(int index)const;
    const char* getSideByNum(int index)const;
    const char* getDrinkByNum(int index)const;
    const char* getDessertByNum(int index)const;

};
