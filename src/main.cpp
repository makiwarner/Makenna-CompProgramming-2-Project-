#include <iostream>
#include <vector>
#include <string>
#include "json.hpp"
#include <fstream>
#include <ctime> // for date functionality
#include <algorithm>
#include <sstream>

using json = nlohmann::json;
using namespace std;

#include "RecipeManager.h"  

int main() {
    std::string recipeFilename = "recipes.json";
    RecipeManager manager(recipeFilename);

    // Start the main menu for interaction
    manager.menu();

    return 0;
}
