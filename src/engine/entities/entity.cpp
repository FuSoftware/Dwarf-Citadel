#include "entity.h"
#include <algorithm>

Entity::Entity(std::string tag, Entity* parent)
{
    this->tag = tag;
    this->setParent(parent);
}

void Entity::setParent(Entity* parent)
{
    this->parent = parent;
}

void Entity::addChild(Entity* child)
{
    this->children.push_back(child);
}

void Entity::removeChild(Entity* child)
{
    this->children.erase(std::remove(this->children.begin(), this->children.end(), child), this->children.end());
}

void Entity::update()
{
    if(this->updateRequired) this->updateSelf();
    this->updateChildren();

    this->updateRequired = false;
}

void Entity::updateChildren()
{
    for(Entity* child : this->children)
    {
        child->update();
    }
}
std::string Entity::getTag()
{
    return this->tag;
}
