// CustomerOrder Milestone - ItemOrder Interface
// ItemOrder.cpp
// Young-Hwan Mun
// v1.0 14/11/2015

#include "ItemOrder.h"
#include "Utilities.h"
#include <iomanip>

ItemOrder::ItemOrder(const std::string& n)
: name(n), filled(false), code(0)
{

}

bool ItemOrder::asksFor(const Item& item) const
{
	return false;
}

bool ItemOrder::isFilled() const
{
	return filled;
}

void ItemOrder::fill(const unsigned int c)
{
	code = c;
	filled = true;
}

void ItemOrder::clear()
{
	code = 0;
	filled = false;
}

const std::string& ItemOrder::getName() const
{
	return name;
}

void ItemOrder::display(std::ostream& os) const
{
	if (name.size() > 0)
	{
		os << " " << (filled ? "+" : "-");
		os << " [" << std::right << std::setw(CODE_WIDTH) << std::setfill('0') << code << std::setfill(' ') << "] ";
		os << name << std::endl;
	}
}
