#ifndef BREADTH_FIRST_H
#define BREADTH_FIRST_H

#include "path_algorithm.h"
#include "utils/vector3D.h"

class BreadthFirst : public PathAlgorithm
{
public:
    BreadthFirst();

    std::vector<size_t> findPath(Point3D start, Point3D goal, Vector3D<bool> map);
    std::vector<size_t> findPath(size_t start, size_t goal, Vector3D<bool> map);

    std::vector<size_t> findWeightedPath(Point3D start, Point3D goal, Vector3D<float> map);
    std::vector<size_t> findWeightedPath(size_t start, size_t goal, Vector3D<float> map);


protected:
    std::vector<size_t> buildPath(size_t start, size_t goal, std::vector<size_t> points);
    std::vector<size_t> buildWeightedPath(size_t start, size_t goal, std::vector<std::tuple<size_t, float>> points);
};
#endif //BREADTH_FIRST_H
