#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include "json.hpp"

using json = nlohmann::json;

class Ingredient {
private:
    std::string name;
    int quantity;
    std::string expirationDate;
public:
    Ingredient();
    Ingredient(std::string name, int quantity, std::string exp);

    std::string getName() const;
    int getQuantity() const;
    std::string getExpirationDate() const;
    void setQuantity(int q);
    void setExpirationDate(const std::string& expDate);

    json toJSON() const;
    static Ingredient fromJSON(const json& j);
};

#endif
