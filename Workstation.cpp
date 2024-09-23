/*******************************************************
 * Pouya Shakiba
 * Pooya.shakiba5@gmail.com
 * https://github.com/pouyashakiba
 * 2024/09/23
 *******************************************************/

#include"Workstation.h"

namespace seneca {
	std::deque<CustomerOrder> g_incomplete; 
	std::deque<CustomerOrder> g_completed; 
	std::deque<CustomerOrder> g_pending;


	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty())
			m_orders.front().fillItem(*this, os);
	}

	bool Workstation::attemptToMoveOrder()
	{
		bool move = false;
		if (!m_orders.empty()) {
			if (m_orders.front().isItemFilled(getItemName())) {
				if (m_pNextStation) {
					*m_pNextStation += std::move(m_orders.front());
				}
				else if (!m_orders.front().isOrderFilled()) {
					g_incomplete.push_back(std::move(m_orders.front()));
				}
				else {
					g_completed.push_back(std::move(m_orders.front()));
				}

				move = true;
				m_orders.pop_front();
			}
			else if (this->getQuantity() <= 0) {
				if (m_pNextStation)
					*m_pNextStation += std::move(m_orders.front());
				else
					g_incomplete.push_back(std::move(m_orders.front()));
				move = true;
				m_orders.pop_front();
			}
		}
		return move;
	}

	void Workstation::setNextStation(Workstation* station)
	{	
		if (station)
			m_pNextStation = station;
		else
			m_pNextStation = nullptr;
	}

	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const
	{
		if (m_pNextStation)
			os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
		else
			os << getItemName() << " --> " << "End of Line" << std::endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}

}
