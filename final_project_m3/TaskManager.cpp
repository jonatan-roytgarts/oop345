// Manager Milestone - TaskManager Interface
// TaskManager.cpp
// v1.0 - 22/11/2015

#include "Task.h"
#include "Item.h"
#include "ItemManager.h"
#include "TaskManager.h"
#include <algorithm>

void TaskManager::push_back(Task&& task)
{
    tasks.push_back(std::move(task));
}

std::vector<Task>::iterator TaskManager::begin()
{
    return tasks.begin();
}

std::vector<Task>::iterator TaskManager::end()
{
    return tasks.end();
}

const std::vector<Task>::const_iterator TaskManager::cbegin() const
{
    return tasks.cbegin();
}

const std::vector<Task>::const_iterator TaskManager::cend() const
{
    return tasks.cend();
}

void TaskManager::validate(std::ostream& os)
{
    bool valid = true;
    for (auto i = 0u; i < tasks.size() && valid; i++) 
    {
        bool invalid = true;
        for (auto j = 0u; j < tasks.size() && invalid; j++) 
        {
            if (tasks[i].validate(tasks[j]))
                invalid = false;
        }
        valid = !invalid;
    }
    if (!valid)
        os << "*** Not all Tasks have been validated ***\n";
}

void TaskManager::display(std::ostream& os) const
{
    for (auto& t : tasks)
        t.display(std::cout);
}
 
void validate(const TaskManager& taskManager, const ItemManager& itemManager, std::ostream& os)
{
    for (auto it = itemManager.cbegin(); it != itemManager.cend(); it++)
    {
        const auto& item = *it;

        auto available = [&] (const Task& task) 
        {                
            return !task.getName().compare(item.getDestination());                
        };

        if (std::find_if (taskManager.cbegin(), taskManager.cend(), available) == taskManager.cend())
            os << item.getDestination() << " is unavailable\n";        
    }
}
