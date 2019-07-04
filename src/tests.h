#ifndef TESTS_H
#define TESTS_H

#include <stddef.h>
#include "utils/vector3D.h"

class Tests
{
public:
    Tests();

    static void simpleVectorTest(size_t w, size_t h, size_t d);
    static void booleanVectorTest();
    static void booleanVectorTest(Vector3D<bool> vec);

    static void weightedVectorTest();

private:
};

#endif // TESTS_H
