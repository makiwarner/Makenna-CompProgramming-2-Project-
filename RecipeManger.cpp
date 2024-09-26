#include <iostream> 
#include <vector>
#include <string>
#include "json.hpp"
#include <fstream> //for json functionality

//note: to get "json.hpp" run 
//curl -LO https://github.com/nlohmann/json/releases/download/v3.11.2/json.hpp 
//in your terminal.

using json = nlohmann::json; //to use this library, you must update c++ with: 
//g++ -std=c++11 RecipeManger.cpp -o RecipeManger
//VERY IMPORTANT (see above)

using namespace std;

//notice use of Encapsulation and Ingredient() constructor to allocate resources
class Ingredient {
    private:
        string name;
        int quantity;
    public:
        Ingredient(){
            cout << "Please enter the ingredient name (or type 'done' to finish): "; 
            cin >> name;
            if (name != "done"){
                cout << "Enter the quantity you have of " << name << ": ";
                cin >> quantity;
                }
            else {
                quantity = -1; // i set this to -1 bc if quantity == 0, "ingredient is running low will print"
            }
        }

        string getName() const {   //this will be used in the getRecipes class
            return name;
        }

        int getQuantity() const {   //this will be used in the getRecipes class
            return quantity;
        }

        //decreaseQuantity() will be called when the user confirms they will make a certain recipe
        //in the RecipeManger class
        void decreaseQuantity() {
            quantity--;
        }

        //isLowQuantity() will print a "notification" if the quantity of an ingredient is running low
        //function will be called when -1 < quantity < 2
        void isLowQuantity() const {
            cout << "The quantity of " << name << " is running low!";
        }


};

class Recipe {
    private:
        string recipeName;
        vector<pair<string, int>> requiredIngredients; //this vector will store "ingredient, quantity" pairs

    public:
        Recipe(string name, vector<pair<string, int>> ingredients) {
            recipeName = name;
            requiredIngredients = ingredients;
        }
    string getRecipeName() const {
        return recipeName;
    }

    //the function below compares the recipe ingredients with the 
    //required ingredients and returns T/F depending if that recipe is viable. 
    //In main, canMakeRecipe will be called. For each recipe that returns T, 
    //it will be displayed to the user as a valid option.
    bool canMakeRecipe(const vector<Ingredient>& userIngredients) const {
    for (const auto& reqIngredient : requiredIngredients) {
        bool found = false; //currently, each required ingredient is set to false
        for (const auto& userIngredient : userIngredients) {
            //for each required ingredient, we have to see if the user has that ingredient with sufficient quantity
            if (userIngredient.getName() == reqIngredient.first &&
                userIngredient.getQuantity() >= reqIngredient.second) {
                found = true; //if yes, found = true (which returns true)
                break;  
            }
        }

        if (!found) {
            return false;
        }
    }

    return true;
}

//Function to load recipes from a JSON file
//I had no idea how to do this. Thank you Chat:
vector<Recipe> loadRecipesFromJSON(const string& filename) {
    vector<Recipe> recipes;
    
    ifstream inputFile("recipes.json");
    if (!inputFile.is_open()) {
        cerr << "Could not open the file: " << filename << endl;
        return recipes;
    }

    json j;
    inputFile >> j;

    for (const auto& recipeData : j["recipes"]) {
        string recipeName = recipeData["name"];
        vector<pair<string, int>> ingredients;

        for (auto& ingredient : recipeData["ingredients"].items()) {
            ingredients.push_back({ ingredient.key(), ingredient.value() });
        }

        recipes.emplace_back(recipeName, ingredients);
    }

    return recipes;
} //end of chatgpt generated section




};
