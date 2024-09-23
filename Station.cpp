/*******************************************************
 * Pouya Shakiba
 * Pooya.shakiba5@gmail.com
 * https://github.com/pouyashakiba
 * 2024/09/23
 *******************************************************/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Station.h"
#include "Utilities.h"

namespace seneca {

	size_t Station::m_widthField = 0u;
	size_t Station::id_generator = 0u;

	Station::Station(const std::string& src)
	{
		Utilities util;
		bool more = true;
		size_t next_pos = 0u;

		stationId = ++id_generator;

		try {
			itemName = util.extractToken(src, next_pos, more);
			nSerialNumber = std::stoi(util.extractToken(src, next_pos, more));
			numOfItems = std::stoi(util.extractToken(src, next_pos, more));
			Station::m_widthField = std::max(Station::m_widthField, util.getFieldWidth());
			m_description = util.extractToken(src, next_pos, more);
		}
		catch (std::string err) {
			std::cout << err;
		}
	}

	const std::string& Station::getItemName() const
	{
		return itemName;
	}

	size_t Station::getNextSerialNumber()
	{
		++nSerialNumber;
		return nSerialNumber - 1;
	}

	size_t Station::getQuantity() const
	{
		return numOfItems;
	}

	void Station::updateQuantity()
	{
		numOfItems == 0 ? numOfItems = 0 : --numOfItems;
	}

	void Station::display(std::ostream& os, bool full) const
	{

		os << std::setw(3) << std::setfill('0')<<std::right << stationId << " | ";
		os << std::left << std::setw(m_widthField) << std::setfill(' ') << itemName << " | ";
		os << std::right << std::setw(6) << std::setfill('0') << nSerialNumber << " | ";
		if (!full) {
			 os<< std::endl;
		}
		else if (full) {
			os << std::right << std::setw(4)<< std::setfill(' ') << numOfItems << " | ";
			os << m_description << std::endl;
		}
	}

}


