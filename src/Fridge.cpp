#include "Fridge.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "Storage.h"
#include "Ingredient.h"



void Fridge::addIngredient(const Ingredient& ingredient) {
   Storage::addIngredient(ingredient);
   std::cout << ingredient.getName() << " added to Fridge.\n";
}


void Fridge::expiringSoon() const {
   time_t now = time(0);
   tm *ltm = localtime(&now);


   for (const auto& ingredient : ingredients) {
       if (!ingredient.getExpirationDate().empty()) {
           tm exp = {};
           strptime(ingredient.getExpirationDate().c_str(), "%Y-%m-%d", &exp);
           time_t exp_time = mktime(&exp);


           if (difftime(exp_time, now) <= 5 * 24 * 60 * 60) {
               std::cout << ingredient.getName() << " is expiring in less than 5 days.\n";
           }
       }
   }
}


/*



// HOW TO RUN THIS CLASS ON A WINDOWS COMPUTER -- strptime() doesn't work on windows.



void Fridge::addIngredient(const Ingredient& ingredient) {
    Storage::addIngredient(ingredient);
    std::cout << ingredient.getName() << " added to Fridge.\n";
}


void Fridge::expiringSoon() const {
    time_t now= time(0);
    tm *ltm= localtime(&now);


    for (const auto& ingredient : ingredients) {
        if (!ingredient.getExpirationDate().empty()) {
            tm exp= {};
            std::istringstream ss(ingredient.getExpirationDate());
            ss >> std::get_time(&exp, "%Y-%m-%d");


            if (ss.fail()) {
                std::cerr << "Failed to parse date for ingredients: " << ingredient.getName() << " \n";
                continue;
            }


            time_t exp_time = mktime(&exp);


            if (difftime(exp_time, now) <= 5*24*60*60) {
                std::cout << ingredient.getName() << " is expiring in less than 5 days.\n";
            }
        }
    }
}
*/