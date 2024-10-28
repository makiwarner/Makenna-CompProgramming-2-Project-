#ifndef RECIPEMANAGER_H
#define RECIPEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>
#include "Fridge.h"
#include "Pantry.h"
#include "Recipe.h"
#include "json.hpp"
#include "Ingredient.h"

using json = nlohmann::json;

class RecipeManager {
private:
    Fridge fridge;
    Pantry pantry;
    std::vector<Recipe> recipes;

    void saveHistory(const Recipe& recipe);
    void displayFullRecipe(const Recipe& recipe);
    void saveIngredientsToFile(const std::string& filename);

public:
    // Getter functions for accessing fridge and pantry
    const Fridge& getFridge() {
        return fridge;
    }

    const Pantry& getPantry() {
        return pantry;
    }

    // Constructor
    RecipeManager(const std::string& recipeFilename);
    // Member functions
    void loadIngredientsFromFile(const std::string& filename);
    void collectIngredients();
    void generateGroceryList(const std::vector<std::string>& missingIngredients);
    void matchRecipes();
    void viewRecipeHistory();
    void clearGroceryList();
    void menu();
};

#endif
