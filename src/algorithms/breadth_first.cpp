#include "breadth_first.h"
#include <queue>
#include <tuple>
#include <iomanip>

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

    std::vector<size_t> came_from(map.size(), PathAlgorithm::PATH_NOT_VISITED);
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
    std::vector<size_t> points;

    std::queue<size_t> frontier;
    frontier.push(start);

    std::tuple<size_t, float> def = std::make_tuple(PATH_NOT_VISITED, 0.0f);
    std::vector<std::tuple<size_t, float>> came_from(map.size(), def);
    std::get<0>(came_from[start]) = 0.0f;

    size_t cycles = 0;

    while(!frontier.empty())
    {
        cycles++;
        size_t current = frontier.front();
        float travel_time = std::get<1>(came_from[current]) + map.getData(current);
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
                if(map.getData(next) >= 0.0f)
                {
                    if((std::get<0>(came_from[next]) == PATH_NOT_VISITED) || (std::get<1>(came_from[next]) > travel_time))
                    {
                        std::get<1>(came_from[next]) = travel_time;
                        std::get<0>(came_from[next]) = current;
                        frontier.push(next);
                    }
                }
            }
        }
    }



    for(std::tuple<size_t, float> p : came_from)
    {
        points.push_back(std::get<0>(p));
    }

    std::vector<size_t> result = buildWeightedPath(start, goal, points);

    //Debug
    /*
    for(size_t y=0; y<map.height(); y++)
    {
        for(size_t x=0; x<map.width(); x++)
        {
            std::cout << std::setw(3) << map.getData(x,y,0);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Processed in " << cycles << " cycles" << std::endl;
    float steps = 0.0f;
    for(size_t p : result) steps += map.getData(p);
    std::cout << "Time : " << steps << " steps" << std::endl << std::endl;
    */

    return result;
}

std::vector<size_t> BreadthFirst::buildWeightedPath(size_t start, size_t goal, std::vector<size_t> points)
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
