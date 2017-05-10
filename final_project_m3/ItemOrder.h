#pragma once
// CustomerOrder Milestone - ItemOrder Interface
// ItemOrder.h
// Chris Szalwinski
// v1.0 - 9/11/2015
#include <iostream>
#include <string>

class Item;

class ItemOrder 
{
    std::string name;
    bool filled;
    unsigned int code;

public:

    /**
     *  Upon instantiation, an ItemOrder object either receives nothing or a reference 
     *  to an unmodifiable std::string. This string contains the name of the ordered item.
     *
     *  The constructor initializes the name identifying the item ordered to the name received
     *  or to an empty state if no name was received, initializes filled to false and initializes
     *  the item code to 0.
     */
    ItemOrder(const std::string& name = std::string()); 

    bool asksFor(const Item& item) const;

    /**
     *  returns true if the current order has been filled
     */
    bool isFilled() const;

    /**
     *  sets the item code for the current object to the value received and switches the status 
     *  of the current object to filled
     */
    void fill(const unsigned int c);

    /**
     *  resets the item code for the current object to 0 and resets the status of the current 
     *  object to not filled
     */
    void clear();

    const std::string& getName() const;

    /**
     *  inserts into the referenced ostream object a description of the item order as shown in
     *  the sample output listed below. The description consists of
     *      - the symbol + or – identifying the status of the item order
     *      - the code printed on the item if filled or 0 if not filled in a field width of 
     *        CODE_WIDTH padded with 0s and enclosed within brackets
     *      - the name of the ordered item
     **/
    void display(std::ostream& os) const;
};
