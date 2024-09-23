/*******************************************************
 * Pouya Shakiba
 * Pooya.shakiba5@gmail.com
 * https://github.com/pouyashakiba
 * 2024/09/23
 *******************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include "Utilities.h"

namespace seneca {

    char Utilities::m_delimiter = ' ';

    void Utilities::setFieldWidth(size_t newWidth)
    {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const
    {
        return m_widthField;
    }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
    {
        std::string token = "";
        size_t first_pos = next_pos;

        next_pos = str.find(m_delimiter, first_pos);

        if (first_pos == next_pos)
        {
            more = false;
            throw "   ERROR: No token.\n";
        }
        else if (next_pos == std::string::npos)
        {
            token = str.substr(first_pos);
            token.erase(0, token.find_first_not_of(" "));
            token.erase(token.find_last_not_of(" ") + 1);
            m_widthField = std::max(token.length(), m_widthField);
            more = false;
        }
        else
        {
            token = str.substr(first_pos, next_pos - first_pos);
            token.erase(0, token.find_first_not_of(" "));
            token.erase(token.find_last_not_of(" ") + 1);
            m_widthField = std::max(token.length(), m_widthField);
            more = true;
        }

        next_pos++;

        return token;
    }

    void Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter() {
        return m_delimiter;
    }
}


