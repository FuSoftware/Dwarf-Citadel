#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>

class Entity
{
public:
    Entity(std::string tag, Entity *parent = nullptr);

    void setParent(Entity* parent);
    void addChild(Entity* child);
    void removeChild(Entity* child);

    void update();
    virtual void updateSelf() = 0;
    void updateChildren();
    std::string getTag();


protected:
    std::string tag;
    Entity* parent = nullptr;
    std::vector<Entity*> children;
    bool updateRequired = false;
};

#endif // ENTITY_H
