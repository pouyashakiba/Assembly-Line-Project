/*******************************************************
 * Pouya Shakiba
 * Pooya.shakiba5@gmail.com
 * https://github.com/pouyashakiba
 * 2024/09/23
 *******************************************************/

#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H


#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"


namespace seneca {
	extern std::deque<CustomerOrder> g_pending; //hold the order at the first station
	extern std::deque<CustomerOrder> g_completed; //hold the order that have been removed and filled by last station
	extern std::deque<CustomerOrder> g_incomplete; //hold the order that have been revomed but incomplete

	class Workstation : public Station {
		std::deque<CustomerOrder>m_orders;
		Workstation* m_pNextStation{ nullptr };

	public:
		Workstation(const std::string& src) : Station(src) {};
		//fills order at the front
		void fill(std::ostream& os);
		//move the order at the front to the next station
		bool attemptToMoveOrder();
		//store the ref of workstation
		void setNextStation(Workstation* station);
		//address of next station
		Workstation* getNextStation() const;
		//display
		void display(std::ostream& os) const;
		//move operator assignment
		Workstation& operator+=(CustomerOrder&& newOrder);

		//disabling copy and move constructors
		Workstation(const Workstation& ) = delete;
		Workstation( Workstation&& ) = delete;
		Workstation& operator=(const Workstation&) = delete;
		Workstation& operator= (Workstation&&) = delete;


	};

}

#endif // !SENECA_WORKSTATION_H
