#ifndef RECIPE_H
#define RECIPE_H

#include <tuple>
#include <vector>
#include <map>
#include <string>

class Recipe
{
public:
    Recipe(std::string id,
           std::string description,
           std::vector<std::tuple<std::string, size_t>> input,
           std::vector<std::tuple<std::string, size_t>> output,
           size_t processing_time);

    std::string getId();
private:
    std::string id;
    std::string description;
    std::vector<std::tuple<std::string, size_t>> input;
    std::vector<std::tuple<std::string, size_t>> output;
    size_t processing_time;
};

class RecipeList
{
    RecipeList();

    void insert(Recipe *recipe, std::string id="")
    {
        if(id=="") this->list.insert(std::pair<std::string, Recipe*>(recipe->getId(), recipe));
        else this->list.insert(std::pair<std::string, Recipe*>(id, recipe));
    }

    void remove(std::string id)
    {
        this->list.erase(this->list.find(id));
    }

    void remove(Recipe *recipe)
    {
        this->remove(recipe->getId());
    }

    std::map<std::string, Recipe*> list;
};

#endif // RECIPE_H
