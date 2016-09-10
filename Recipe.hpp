//
// Created by zamazan4ik on 09.09.16.
//

#ifndef COOKER_RECIPE_HPP
#define COOKER_RECIPE_HPP

#include <vector>
#include <string>

#include "Composition.hpp"
#include "Ingredient.hpp"

class Recipe
{
public:
    std::string name_;
    double energy_, health_;
    Composition comp_;
    std::vector<Ingredient> ingred_, addIngred_;

    double getHealth()
    {
        double result = 0.0;
        for(const auto& val : ingred_)
        {
            result += val.getHealth();
        }
        return result / ingred_.size();
    }
public:
    Recipe() = default;

    Recipe(const std::string& name, const double energy, const Composition& comp,
           const std::vector<Ingredient>& ingred, const std::vector<Ingredient>& addIngred) :
            name_(name), energy_(energy), comp_(comp), ingred_(ingred), addIngred_(addIngred)
    {
        health_ = getHealth();
    }


    std::string getName() const { return name_; }
    //std::vector<Ingredient>& getIngredients() const { return ingred_; }

};


#endif //COOKER_RECIPE_HPP
