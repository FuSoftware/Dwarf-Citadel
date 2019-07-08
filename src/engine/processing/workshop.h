#ifndef WORKSHOP_H
#define WORKSHOP_H

#include "recipe.h"


class Workshop
{
public:
    Workshop();

    std::tuple<std::string, size_t> requiredIngredient();
    std::vector<std::tuple<std::string, size_t>> requiredIngredients();

private:
    RecipeList *recipes;
};

#endif // WORKSHOP_H
