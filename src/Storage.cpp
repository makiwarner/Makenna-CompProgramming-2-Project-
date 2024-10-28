#include "Storage.h"

void Storage::addIngredient(const Ingredient& ingredient) {
    for (auto& ing : ingredients) {
        if (ing.getName() == ingredient.getName()) {
            ing.setQuantity(ing.getQuantity() + ingredient.getQuantity());
            if (!ingredient.getExpirationDate().empty()) {
                ing.setExpirationDate(ingredient.getExpirationDate());
            }
            return;
        }
    }
    ingredients.push_back(ingredient);
}

const std::vector<Ingredient>& Storage::getIngredients() const {
    return ingredients;
}

json Storage::toJSON() const {
    json ingredientArray = json::array();
    for (const auto& ingredient : ingredients) {
        ingredientArray.push_back(ingredient.toJSON());
    }
    return ingredientArray;
}

void Storage::fromJSON(const json& j) {
    for (const auto& item : j) {
        ingredients.push_back(Ingredient::fromJSON(item));
    }
}
