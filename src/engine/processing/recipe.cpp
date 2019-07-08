#include "recipe.h"

Recipe::Recipe(std::string id,
               std::string description,
               std::vector<std::tuple<std::string, size_t>> input,
               std::vector<std::tuple<std::string, size_t>> output,
               size_t processing_time) : id(id), description(description), input(input), output(output), processing_time(processing_time)
{

}
