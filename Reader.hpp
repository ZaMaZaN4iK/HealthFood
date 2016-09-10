//
// Created by zamazan4ik on 09.09.16.
//

#ifndef COOKER_READER_HPP
#define COOKER_READER_HPP

#include <fstream>
#include <string>
#include <vector>

#include "Recipe.hpp"
#include "Composition.hpp"

class Reader
{
private:
    std::string name_;
    std::ifstream in_;
public:
    Reader(const std::string& name) : name_(name)
    {
    }

    std::vector<Recipe> readRecipes()
    {
        std::vector<Recipe> result;
        in_.open(name_);

        size_t allCount;
        in_ >> allCount;
        for(size_t i = 0; i < allCount; ++i)
        {
            std::string name;
            double energy, health;
            Composition comp;
            size_t countIngred, countAddIngred;
            std::vector<Ingredient> ingred, addIngred;

            in_ >> name >> energy >> health >> comp.prot_ >> comp.fat_ >> comp.carbohydr_
                >> countIngred;
            for(size_t j = 0; j < countIngred; ++j)
            {
                std::string nameIng;
                double health;
                in_ >> nameIng >> health;
                ingred.push_back(Ingredient(nameIng, health));
            }
            in_ >> countAddIngred;
            for(size_t j = 0; j < countAddIngred; ++j)
            {
                std::string nameIng;
                double health;
                in_ >> nameIng >> health;
                addIngred.push_back(Ingredient(nameIng, health));
            }

            result.push_back(Recipe(name, energy, comp, ingred, addIngred));
        }
        return result;
    }

    ~Reader()
    {
        in_.close();
    }
};


#endif //COOKER_READER_HPP
