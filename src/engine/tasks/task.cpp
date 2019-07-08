#include "task.h"

#include <iomanip>
#include <iostream>

Task::Task(std::string id, Task* parent) : id(id)
{
    if(parent != nullptr) parent->addSubtask(this);
}


void Task::addSubtask(Task* t)
{
    this->subtasks.push_back(t);
}

bool Task::isCompleted()
{
    if(this->subtasks.size() > 0)
    {
        for (Task*t : this->subtasks) if(!t->isCompleted()) return false;
        return true;
    }
    else
    {
        return this->completed;
    }
}

void Task::complete()
{
    this->completed = true;
}

void Task::update()
{
    if(!this->completed)
    {
        this->current_completion++;
        if(this->current_completion >= this->completion_time) this->completed = true;
    }
}

void Task::printTree(int level)
{
    std::cout << std::setw(level*4) << " " << "-" << this->id << "(" << (this->isCompleted() ? "Complete" : "Pending") << ")" << std::endl;
    for (Task*t : this->subtasks) t->printTree(level + 1);
}
