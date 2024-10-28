#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "Ingredient.h"

using json = nlohmann::json;
using std::string;
using std::vector;
using std::pair;

class Recipe {
private:
    std::string recipeName;
    std::vector<std::pair<std::string, std::string>> requiredIngredients;
    std::vector<std::pair<std::string, std::string>> condiments;
    std::vector<std::string> steps;
    std::string category;

public:
    Recipe(std::string name, 
           std::vector<std::pair<std::string, std::string>> ingredients, 
           std::vector<std::pair<std::string, std::string>> condiments, 
           std::vector<std::string> steps, std::string type);

    std::string getRecipeName() const;
    std::string getType() const;
    bool canMakeRecipe(const std::vector<Ingredient>& userIngredients, std::vector<std::string>& missingIngredients) const;
    std::vector<std::pair<std::string, std::string>> getRequiredIngredients() const;
    std::vector<std::pair<std::string, std::string>> getCondiments() const;
    std::vector<std::string> getSteps() const;
};

std::vector<Recipe> loadRecipesFromJSON(const std::string& filename);

#endif
