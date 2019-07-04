TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        algorithms/a_star.cpp \
        algorithms/breadth_first.cpp \
        algorithms/path_algorithm.cpp \
        main.cpp \
        map/collision_map.cpp \
        tests.cpp

HEADERS += \
    algorithms/a_star.h \
    algorithms/breadth_first.h \
    algorithms/path_algorithm.h \
    map/collision_map.h \
    tests.h \
    utils/point3d.h \
    utils/vector3D.h \
    utils/vectorxd.h
