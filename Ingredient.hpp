//
// Created by zamazan4ik on 09.09.16.
//

#ifndef COOKER_INGREDIENT_HPP
#define COOKER_INGREDIENT_HPP

#include <string>

class Ingredient
{
private:
    std::string name_;
    double health_;
public:
    Ingredient() = default;
    Ingredient(const std::string& name, const double health = 100.0) :
            name_(name), health_(health)
    {}

    std::string getName() const { return name_; }
    double getHealth() const { return health_; }

    void setName(const std::string& name) { name_ = name; }
    void setHealth(const double health) { health_ = health; }

    bool operator==(const Ingredient& val) const
    {
        return name_ == val.name_;
    }
};



#endif //COOKER_INGREDIENT_HPP
