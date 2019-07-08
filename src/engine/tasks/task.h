#ifndef TASK_H
#define TASK_H

#include <vector>
#include <string>

enum TaskType
{
    DEFAULT=0,
    MOVE,
    CRAFT,
    USE
};

class Task
{
public:
    Task(std::string id, Task* parent = nullptr);
    void addSubtask(Task* t);
    bool isCompleted();
    void complete();
    void update();
    void printTree(int level = 0);

protected:
    std::string id;
    size_t completion_time = 0; //Number of cycles to complete the task
    size_t current_completion = 0;
    bool completed = false;
    std::vector<Task*> subtasks;
};

#endif // TASK_H
