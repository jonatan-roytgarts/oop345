#pragma once
// Manager Milestone - TaskManager Interface
// TaskManager.h
// Chris Szalwinski
// v1.0 - 16/11/2015
#include <iostream>
#include <vector>
 
class Task;
class ItemManager;
 
class TaskManager 
{
    std::vector<Task> tasks;

public:

	/**
	 *	moves task to the back of tasks
	 */
    void push_back(Task&& task);

    /**
     *	returns the iterator to the beginning of tasks
     */
    std::vector<Task>::iterator begin();

    /**
     *	returns the iterator to the end of tasks
     */
    std::vector<Task>::iterator end();

    /**
     *	returns the iterator to the beginning of read-only tasks
     */
    const std::vector<Task>::const_iterator cbegin() const;

    /**
     *	returns the iterator to the end of read-only tasks
     */
    const std::vector<Task>::const_iterator cend() const;

    /**
     *	validates all of the follow on tasks against the tasks stored in tasks
     */
    void validate(std::ostream& os);

    /**
     *	inserts into the referenced ostream object descriptions of the tasks stored in tasks
     */
    void display(std::ostream& os) const;
};
 
/**
 *	checks that the tasks attached to each item are available, reporting any requested tasks 
 *	that are unavailable on the ostream object.
 */
void validate(const TaskManager& taskManager, const ItemManager& itemManager, std::ostream& os);
