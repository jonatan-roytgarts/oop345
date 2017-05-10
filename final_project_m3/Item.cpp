// CustomerOrder Milestone - Item Interface
// Item.cpp
// Young-Hwan Mun
// v1.0 14/11/2015

#include "Item.h"
#include "Utilities.h"
#include <iomanip>

char Item::delimiter = '\0';
size_t Item::field_width = 1;

Item::Item(const std::string& record)
: name(""), source(""), destination(""), details("no detailed description"), code(1)
{
	size_t pos = 0;
	bool more = true;	

	Utilities util(field_width);
	name = util.nextToken(record, pos, more);
	if (!name.empty())
	{	
		if (more)
			source = util.nextToken(record, pos, more);

		field_width = util.getFieldWidth();	

		if (more)
			destination = util.nextToken(record, pos, more);

		if (more)
			code = std::stoi(util.nextToken(record, pos, more));

		if (more)
			details = util.nextToken(record, pos, more);

		if (details.empty())
			details = "no detailed description";
	}
}

bool Item::empty() const
{
    return name.empty();
}

void Item::operator++(int i)
{
	code++;
}

unsigned int Item::getCode() const
{
    return code;
}

const std::string& Item::getName() const
{
    return name;
}

const std::string& Item::getSource() const
{
    return source;
}

const std::string& Item::getDestination() const
{
    return destination;
}

void Item::display(std::ostream& os, bool full) const
{
	os << std::left << std::setw(field_width) << name;
	os << " [" << std::right << std::setw(CODE_WIDTH) << std::setfill('0') << code << "]";
	os << std::left << std::setfill(' ');

	if (full)
	{
		os << " From " << std::setw(field_width) << source;
		os << " To " << std::setw(field_width) << destination << std::endl;
		os << std::right << std::setw(field_width + CODE_WIDTH + 4) << " : " << details;		
	}

	os << std::left << std::endl;
}

void Item::setDelimiter(const char c)
{
	delimiter = c;
}
    
size_t Item::getFieldWidth()
{
    return field_width;
}
