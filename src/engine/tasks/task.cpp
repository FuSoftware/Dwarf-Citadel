#include "task.h"

Task::Task(std::string id) : id(id)
{

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
