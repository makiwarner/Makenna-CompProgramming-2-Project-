#include "Pantry.h"

void Pantry::addIngredient(const Ingredient& ingredient) {
    Storage::addIngredient(ingredient);
    std::cout << ingredient.getName() << " added to Pantry.\n";
}

void Pantry::runningLow() const {
    for (const auto& ingredient : ingredients) {
        if (ingredient.getQuantity() < 2) {
            std::cout << ingredient.getName() << " is running low.\n";
        }
    }
}
