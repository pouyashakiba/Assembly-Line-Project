/*******************************************************
 * Pouya Shakiba
 * Pooya.shakiba5@gmail.com
 * https://github.com/pouyashakiba
 * 2024/09/23
 *******************************************************/


#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H
#include"Station.h"

namespace seneca {
    struct Item {
        std::string m_itemName;
        size_t m_serialNumber{ 0 };
        bool m_isFilled{ false };
        Item(const std::string& src) : m_itemName(src) {};
    };

    class CustomerOrder
    {
        std::string m_name{ "" };      
        std::string m_product{ "" };       
        size_t m_cntItem{ 0u };      
        Item** m_lstItem{ nullptr }; 
        static size_t m_widthField;        

    public:
        //Rule of five
        CustomerOrder() = default;
        CustomerOrder(const std::string& src);
        CustomerOrder(const CustomerOrder& src); 
        CustomerOrder& operator=(const CustomerOrder& src) = delete;
        CustomerOrder(CustomerOrder&& src) noexcept;
        CustomerOrder& operator=(CustomerOrder&& src) noexcept;
        ~CustomerOrder();

        bool isOrderFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& station, std::ostream& os);
        void display(std::ostream& os) const;
    };
}
#endif // !SENECA_CUSTOMERORDER_H
