#ifndef PANTRY_H
#define PANTRY_H

#include <iostream>
#include "Storage.h"
#include "Ingredient.h"

class Pantry : public Storage {
public:
    void addIngredient(const Ingredient& ingredient) override;

    void runningLow() const;
};

#endif
