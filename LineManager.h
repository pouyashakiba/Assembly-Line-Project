/*******************************************************
 * Pouya Shakiba
 * Pooya.shakiba5@gmail.com
 * https://github.com/pouyashakiba
 * 2024/09/23
 *******************************************************/

#ifndef SENECA_LINEMANAGER_H
#define SENECA_LINEMANAGER_H

#include<iostream>
#include<vector>
#include<string>
#include"Workstation.h"

namespace seneca {

	class LineManager {
		std::vector<Workstation*> m_activeLine;
		size_t m_cntCustomerOrder; 
		Workstation* m_firstStation;

	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void reorderStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif // !SENECA_LINEMANAGER_H
