#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Reader.hpp"
#include "Ingredient.hpp"

std::vector<Ingredient> getIngredient()
{
    std::vector<Ingredient> result;

    size_t countAll;
    std::cin >> countAll;
    for(size_t i = 0; i < countAll; ++i)
    {
        std::string nameIng;
        std::cin >> nameIng;
        result.push_back(Ingredient(nameIng));
    }
    return result;
}

std::vector<std::string> getGoodRecipes(const std::vector<Ingredient>& ingred,
                                        const std::vector<Recipe>& recipes)
{
    std::vector<std::string> result;

    for(const auto& recipe : recipes)
    {
        size_t founded = 0;
        for(const auto& ing : ingred)
        {
            if(std::find(recipe.ingred_.begin(), recipe.ingred_.end(), ing)
               != recipe.ingred_.end())
            {
                ++founded;
            }
        }

        if(founded == recipe.ingred_.size())
        {
            result.push_back(recipe.getName());
        }
    }

    return result;
}


int main()
{
    Reader reader("//media//zamazan4ik//For_Linux//Projects//C++//CLion//Cooker//input.txt");
    auto recipes = reader.readRecipes();

    std::cout << recipes.size() << std::endl;

    auto ingred = getIngredient();

    auto ready = getGoodRecipes(ingred, recipes);

    for(const auto& val : ready)
    {
        std::cout << val << std::endl;
    }

    return 0;

}