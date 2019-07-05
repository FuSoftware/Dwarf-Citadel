#include "tests.h"

#include <stddef.h>
#include "utils/vector3D.h"
#include "algorithms/breadth_first.h"
#include <iostream>
#include <chrono>

Tests::Tests()
{

}

void Tests::simpleVectorTest(size_t w, size_t h, size_t d)
{
    Vector3D<size_t> vec(w, h, d);
    std::vector<size_t> data(vec.size());

    for(size_t i=0; i< data.size(); i++)
    {
        data[i] = i;
    }

    vec.setData(data);

    for(size_t z=0; z < vec.depth(); z++)
    {
        for(size_t y=0; y < vec.height(); y++)
        {
            for(size_t x=0; x < vec.width(); x++)
            {
                std::cout << x << ":" << y << ":" << z << " : " << vec.getData(x, y, z) << std::endl;
            }
        }
    }
}

void Tests::booleanVectorTest(Vector3D<bool> vec)
{
    size_t h = vec.height();
    size_t w = vec.width();

    auto time_init = std::chrono::steady_clock::now();

    BreadthFirst algorithm;
    std::vector<size_t> path = algorithm.findPath(Point3D(0, 0, 0), Point3D(w-1, h-1, 0), vec);

    auto time_search = std::chrono::steady_clock::now();

    Vector3D<bool> result(w, h, 1);

    for(size_t point : path)
    {
        result.setData(point, true);
    }

    for(size_t y=0; y < vec.height(); y++)
    {
        for(size_t x=0; x < vec.width(); x++)
        {
            if(vec.getData(x,y,0))
            {
                std::cout << (result.getData(x, y, 0) ? "X" : "\u2591");
            }
            else
            {
                std::cout << "\u2588";
            }

        }
        std::cout << std::endl;
    }

    auto time_rendering = std::chrono::steady_clock::now();

    std::cout << "   Search : " << std::chrono::duration_cast<std::chrono::microseconds>(time_search - time_init).count()       << "us" << std::endl;
    std::cout << "Rendering : " << std::chrono::duration_cast<std::chrono::microseconds>(time_rendering - time_search).count()  << "us" << std::endl;
    std::cout << "    Total : " << std::chrono::duration_cast<std::chrono::microseconds>(time_rendering - time_init).count()   << "us" << std::endl << std::endl;
}

void Tests::booleanVectorTest()
{
    Vector3D<bool> vec(30, 15, 1);
    vec.setData(std::vector<bool>(vec.size(), true));
    vec.setArea(3,2,20,1,false);
    vec.setArea(3,3,2,8,false);
    vec.setArea(13,4,2,10, false);
    vec.setArea(20,0,2,6,false);
    vec.setArea(20,5,6,2,false);

    booleanVectorTest(vec);

    vec.setData(std::vector<bool>(vec.size(), true));
    vec.setArea(0,1,29,1,false);
    vec.setArea(1,4,29,1, false);
    vec.setArea(0,7,29,1,false);
    vec.setArea(1,10,29,1,false);
    vec.setArea(0,13,29,1,false);

    booleanVectorTest(vec);
}

void Tests::weightedVectorTest()
{
    Vector3D<float> vec(6,6,1);
    vec.setData({
        1.0f, 0.5f, 0.5f, 1.0f, 0.8f, 1.0f,
        1.0f, 0.5f, 1.0f, 1.0f, 0.5f, 1.0f,
        1.0f, 0.5f, 1.0f, 0.3f, 0.2f, 1.0f,
        1.0f, 0.5f, 0.2f, 0.7f, 0.0f, 1.0f,
        1.0f, 0.5f, 1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
    });

    size_t h = vec.height();
    size_t w = vec.width();

    BreadthFirst algorithm;
    std::vector<size_t> path = algorithm.findWeightedPath(Point3D(0, 0, 0), Point3D(w-1, h-1, 0), vec);

    Vector3D<bool> result(w, h, 1);

    for(size_t point : path)
    {
        result.setData(point, true);
    }

    for(size_t y=0; y < vec.height(); y++)
    {
        for(size_t x=0; x < vec.width(); x++)
        {
            if(vec.getData(x,y,0) > 0.0f)
            {
                std::cout << (result.getData(x, y, 0) ? "X" : "\u2591");
            }
            else
            {
                std::cout << "\u2588";
            }

        }
        std::cout << std::endl;
    }
}
