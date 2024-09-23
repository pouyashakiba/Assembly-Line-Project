/*******************************************************
 * Pouya Shakiba
 * Pooya.shakiba5@gmail.com
 * https://github.com/pouyashakiba
 * 2024/09/23
 *******************************************************/

#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include<string>

namespace seneca {
	class Station {
		int stationId{ 0 };

		std::string itemName{ "" };
		std::string m_description{ "" };

		size_t nSerialNumber{ 0u };
		size_t numOfItems{ 0u };
		static size_t m_widthField;
		static size_t id_generator;

	public:
		Station(const std::string& src);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}


#endif // !SENECA_STATION_H
