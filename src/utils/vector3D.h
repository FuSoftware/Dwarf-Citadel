#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include <stddef.h>
#include <iostream>
#include <vector>
#include "point3d.h"

template <class T>
class Vector3D
{
public:
    Vector3D(size_t w=1, size_t h=1, size_t d=1) : w(w), h(h), d(d)
    {
        this->data = std::vector<T>(h*w*d);
    }

    T getData(size_t x, size_t y, size_t z)
    {
        return this->getData(XYZtoA(x,y,z));
    }

    T getData(size_t a)
    {
        return this->data[a];
    }

    void setArea(size_t x, size_t y, size_t w, size_t h, T value)
    {
        for(size_t i=0;i<w;i++)
        {
            for(size_t j=0;j<h;j++)
            {
                this->setData(x+i, y+j, 0, value);
            }
        }
    }

    void setVolume(size_t x, size_t y, size_t z, size_t w, size_t h, size_t d, T value)
    {
        for(size_t i=0;i<w;i++)
        {
            for(size_t j=0;j<h;j++)
            {
                for(size_t k=0;k<d;k++)
                {
                    this->setData(x+i, y+j, z+k, value);
                }
            }
        }
    }

    void setData(std::vector<T> data)
    {
        if(data.size() <= this->data.size())
        {
            size_t s = this->data.size();
            this->data.assign(data.begin(), data.end());
            this->data.resize(s);
        }
        else
        {
            std::cerr << "Trying to initialize Vector3D with too much data : " << data.size() << ", while vector has " << this->data.size() << std::endl;
        }

    }

    void setData(size_t x, size_t y, size_t z, T data)
    {
        this->setData(XYZtoA(x,y,z), data);
    }

    void setData(size_t a, T data)
    {
        this->data[a] = data;
    }

    size_t XYZtoA(Point3D p)
    {
        return XYZtoA(p.x, p.y, p.z);
    }

    size_t XYZtoA(size_t x, size_t y, size_t z)
    {
        return z * this->h * this->w + y * this->w + x;
    }

    Point3D AtoXYZ(size_t a)
    {
        unsigned long b = this->w * this->h;
        unsigned long z = a/b;

        return Point3D(a % this->w,(a-(z*b))/this->w,z);
    }

    bool isValidPoint(Point3D p)
    {
        return this->isValidPoint(p.x, p.y, p.z);
    }

    bool isValidPoint(size_t x, size_t y, size_t z)
    {
        return (x < this->w) && (y < this->h) && (z < this->d) && (x >= 0) && (y >= 0) && (z >= 0);
    }

    std::vector<size_t> neighbors(size_t x, size_t y, size_t z)
    {
        return neighbors(Point3D(x,y,z));
    }

    std::vector<size_t> neighbors(size_t a)
    {
        return neighbors(AtoXYZ(a));
    }

    std::vector<size_t> neighbors(Point3D vec)
    {
        std::vector<Point3D> points;
        for(long i=-1;i<=1;i++)
        {
            for(long j=-1;j<=1;j++)
            {
                for(long k=-1;k<=1;k++)
                {
                    if(!(i == j && j == k && k == 0))
                    {
                        Point3D p = Point3D::fromOffset(vec, i, j, k);
                        if(isValidPoint(p))
                        {
                            points.push_back(p);
                        }
                    }
                }
            }
        }

        std::vector<size_t> ids(points.size());
        for(size_t i=0; i<points.size(); i++) ids[i] = XYZtoA(points[i]);
        return ids;
    }

    size_t size()
    {
        return this->data.size();
    }

    size_t height()
    {
        return this->h;
    }

    size_t width()
    {
        return this->w;
    }

    size_t depth()
    {
        return this->d;
    }

private:
    size_t h = 1;
    size_t w = 1;
    size_t d = 1;
    std::vector<T> data;
};
#endif //VECTOR_3D_H
