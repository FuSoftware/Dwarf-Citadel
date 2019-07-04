#include "breadth_first.h"
#include <queue>
#include <tuple>

BreadthFirst::BreadthFirst()
{

}

std::vector<size_t> BreadthFirst::findPath(Point3D start, Point3D goal, Vector3D<bool> map)
{
    return findPath(map.XYZtoA(start), map.XYZtoA(goal), map);
}

std::vector<size_t> BreadthFirst::findWeightedPath(Point3D start, Point3D goal, Vector3D<float> map)
{
    return findWeightedPath(map.XYZtoA(start), map.XYZtoA(goal), map);
}


std::vector<size_t> BreadthFirst::findPath(size_t start, size_t goal, Vector3D<bool> map)
{
    std::queue<size_t> frontier;
    frontier.push(start);

    std::vector<size_t> came_from(map.size(), PATH_NOT_VISITED);
    came_from[start] = PATH_START;

    while(!frontier.empty())
    {
        size_t current = frontier.front();
        frontier.pop();

        if(current == goal)
        {
            break;
        }
        else
        {
            std::vector<size_t> n = map.neighbors(current);

            for(size_t i=0; i<n.size(); i++)
            {
                size_t next = n[i];
                if(came_from[next] == PATH_NOT_VISITED && map.getData(next) == true)
                {
                    frontier.push(next);
                    came_from[next] = current;
                }
            }
        }
    }

    return buildPath(start, goal, came_from);
}

std::vector<size_t> BreadthFirst::buildPath(size_t start, size_t goal, std::vector<size_t> points)
{
    size_t c = goal;

    std::vector<size_t> results;

    if(points[c] == PATH_NOT_VISITED)
    {
        //Couldn't reach the goal
        return std::vector<size_t>(0);
    }
    else
    {
        do{
          c = points[c];
          results.push_back(c);
        }while(c != start);

        return results;
    }
}

//TODO: Implement
std::vector<size_t> BreadthFirst::findWeightedPath(size_t start, size_t goal, Vector3D<float> map)
{
    typedef std::tuple<size_t, float> WeightedPoint;
    std::vector<size_t> results;

    std::queue<size_t> frontier;
    frontier.push(start);

    WeightedPoint def = std::make_tuple(PATH_NOT_VISITED, 0.0f);
    std::vector<WeightedPoint> came_from(map.size(), def);

    while(!frontier.empty())
    {
        size_t current = frontier.front();
        frontier.pop();

        if(current == goal)
        {
            break;
        }
        else
        {
            std::vector<size_t> n = map.neighbors(current);

            for(size_t i=0; i<n.size(); i++)
            {
                size_t next = n[i];
                if(std::get<0>(came_from[next]) == PATH_NOT_VISITED && map.getData(next) > 0.0f)
                {
                    frontier.push(next);

                    std::get<0>(came_from[next]) = current;
                }
            }
        }
    }



    return buildWeightedPath(start, goal, came_from);
}

std::vector<size_t> BreadthFirst::buildWeightedPath(size_t start, size_t goal, std::vector<std::tuple<size_t, float>> points)
{
    size_t c = goal;

    std::vector<size_t> results;

    if(std::get<0>(points[c]) == PATH_NOT_VISITED)
    {
        //Couldn't reach the goal
        return std::vector<size_t>(0);
    }
    else
    {
        do{
          c = std::get<0>(points[c]);
          results.push_back(c);
        }while(c != start);

        return results;
    }
}
