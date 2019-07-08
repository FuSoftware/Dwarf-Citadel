TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        algorithms/a_star.cpp \
        algorithms/breadth_first.cpp \
        algorithms/path_algorithm.cpp \
        engine/entities/entity.cpp \
        engine/tasks/task.cpp \
        main.cpp \
        map/collision_map.cpp \
        tests.cpp

HEADERS += \
    algorithms/a_star.h \
    algorithms/breadth_first.h \
    algorithms/path_algorithm.h \
    engine/entities/entity.h \
    engine/tasks/task.h \
    map/collision_map.h \
    tests.h \
    utils/point3d.h \
    utils/vector3D.h \
    utils/vectorxd.h
