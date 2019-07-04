#ifndef PATH_ALGORITHM_H
#define PATH_ALGORITHM_H

#include <vector>
#include "utils/vector3D.h"
#include "utils/point3d.h"
#include <tuple>

class PathAlgorithm
{
public:
    PathAlgorithm();

    virtual std::vector<size_t> findPath(Point3D start, Point3D goal, Vector3D<bool> map) = 0;
    virtual std::vector<size_t> findPath(size_t start, size_t goal, Vector3D<bool> map) = 0;

    virtual std::vector<size_t> findWeightedPath(Point3D start, Point3D goal, Vector3D<float> map) = 0;
    virtual std::vector<size_t> findWeightedPath(size_t start, size_t goal, Vector3D<float> map) = 0;


protected:
    static const size_t PATH_START;
    static const size_t PATH_NOT_VISITED;
};

#endif //PATH_ALGORITHM_H
