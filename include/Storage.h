#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include "Ingredient.h"
#include "json.hpp"

using json = nlohmann::json;

class Storage {
protected:
    std::vector<Ingredient> ingredients;

public:
    virtual void addIngredient(const Ingredient& ingredient);

    const std::vector<Ingredient>& getIngredients() const;

    json toJSON() const;

    void fromJSON(const json& j);
};

#endif
