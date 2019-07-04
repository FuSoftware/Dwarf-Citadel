#ifndef POINT_3D_H
#define POINT_3D_H

#include <stddef.h>

class Point3D
{
public:
    Point3D(size_t x=0, size_t y=0, size_t z=0) : x(x), y(y) , z(z) {}

    static Point3D fromOffset(Point3D p, long x=0, long y=0, long z=0)
    {
        return Point3D(p.x + x,
                       p.y + y,
                       p.z + z);
    }

    size_t x = 0;
    size_t y = 0;
    size_t z = 0;
};
#endif //POINT_3D_H
