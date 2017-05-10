#pragma once
// Manager Milestone - OrderManager Interface
// OrderManager.h
// v1.0 - 16/11/2015
#include <iostream>
#include <string>
 
class ItemManager;
class CustomerOrder;
 
class OrderManager 
{
    std::vector<CustomerOrder> customerOrders;

public:

	/**
	 *	moves customerOrder to the back of customerOrders
	 */
    void push_back(CustomerOrder&& customerOrder);

    /**
     *	returns the iterator to the beginning of customerOrders
     */
    std::vector<CustomerOrder>::iterator begin();

    /**
     *	returns the iterator to the end of customerOrders
     */
    std::vector<CustomerOrder>::iterator end();

    /**
     *	returns the iterator to the beginning of read-only customerOrders
     */
    const std::vector<CustomerOrder>::const_iterator cbegin() const;

    /**
     *	returns the iterator to the end of read-only customerOrders
     */
    const std::vector<CustomerOrder>::const_iterator cend() const;

    /**
     *	inserts into the referenced ostream object descriptions of the customer 
     *	orders stored in customerOrders
     */
    void display(std::ostream& os) const;
};
 
/**
 *	checks that the items in the customer orders are available, reporting any 
 *	requested items that are not available on the ostream object.
 */
void validate(const OrderManager& orderManager, const ItemManager& itemManager, std::ostream& os);
