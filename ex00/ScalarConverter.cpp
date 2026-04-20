/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 00:24:29 by wuabdull          #+#    #+#             */
/*   Updated: 2026/04/20 16:22:54 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <climits>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

bool isSpecialLiteral(const std::string& literal)
{
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
           return true;
    return false;
}

bool isCharLiteral(const std::string& literal)
{
    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return true;
    return false;
}

bool isIntLiteral(const std::string& literal)
{
    int i = 0;

    if (literal.empty())
        return false;

    if (literal[0] == '+' || literal[0] == '-')
    {
        if (literal.length() == 1)
            return false;
        i = 1;
    }

    while (i < static_cast<int>(literal.length()))
    {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    return true;
}

bool isFloatLiteral(const std::string& literal)
{
    int i = 0;
    int dotCount = 0;

    if (literal.empty())
        return false;

    if (literal[literal.length() - 1] != 'f')
        return false;

    if (literal[0] == '+' || literal[0] == '-')
    {
        if (literal.length() == 1)
            return false;
        i = 1;
    }

    if (!std::isdigit(literal[i]))
        return false;

    while (i < static_cast<int>(literal.length()) - 1)
    {
        if (literal[i] == '.')
            dotCount++;
        else if (!std::isdigit(literal[i]))
            return false;
        i++;
    }

    if (dotCount != 1)
        return false;

    if (literal[literal.length() - 2] == '.')
        return false;

    return true;
}

bool isDoubleLiteral(const std::string& literal)
{
    int i = 0;
    int dotCount = 0;

    if (literal.empty())
        return false;

    if (literal[0] == '+' || literal[0] == '-')
    {
        if (literal.length() == 1)
            return false;
        i = 1;
    }

    if (!std::isdigit(literal[i]))
        return false;

    while (i < static_cast<int>(literal.length()))
    {
        if (literal[i] == '.')
            dotCount++;
        else if (!std::isdigit(literal[i]))
            return false;
        i++;
    }

    if (dotCount != 1)
        return false;

    if (literal[literal.length() - 1] == '.')
        return false;

    return true;
}

void ScalarConverter::convert(const std::string& literal)
{
    std::string type;

    if (isSpecialLiteral(literal))
        type = "special";
    else if (isCharLiteral(literal))
        type = "char";
    else if (isIntLiteral(literal))
        type = "int";
    else if (isFloatLiteral(literal))
        type = "float";
    else if (isDoubleLiteral(literal))
        type = "double";
    else
        type = "invalid";
        
    if (type == "invalid")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (type == "special")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (literal == "nan" || literal == "nanf")
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (literal == "+inf" || literal == "+inff")
        {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else if (literal == "-inf" || literal == "-inff")
        {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        return;
    }
    if (type == "char")
    {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }
    if (type == "int")
    {
        long num = std::strtol(literal.c_str(), NULL, 10);

        if (num >= 0 && num <= 127)
        {
            if (std::isprint(static_cast<int>(num)))
                std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }
        else
            std::cout << "char: impossible" << std::endl;

        if (num > INT_MAX || num < INT_MIN)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(num) << std::endl;

        if (num > 999999 || num < -999999)
        {
            std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(num) << std::endl;
        }
        else
        {
            std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
        }
        return;
    }
    if (type == "float")
    {
        float num = static_cast<float>(std::atof(literal.c_str()));

        if (num < 0 || num > 127 || num != static_cast<int>(num) || num != num)
            std::cout << "char: impossible" << std::endl;
        else if (std::isprint(static_cast<int>(num)))
            std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        if (num > INT_MAX || num < INT_MIN || num != static_cast<int>(num) || num != num)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(num) << std::endl;

        if (num == static_cast<int>(num))
        {
            std::cout << "float: " << num << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
        }
        else
        {
            std::cout << "float: " << num << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(num) << std::endl;
        }
        return;
    }
    if (type == "double")
    {
        double num = std::atof(literal.c_str());

        if (num < 0 || num > 127 || num != static_cast<int>(num) || num != num)
            std::cout << "char: impossible" << std::endl;
        else if (std::isprint(static_cast<int>(num)))
            std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        if (num > INT_MAX || num < INT_MIN || num != static_cast<int>(num) || num != num)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(num) << std::endl;

        if (num == static_cast<int>(num))
        {
            std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
            std::cout << "double: " << num << ".0" << std::endl;
        }
        else
        {
            std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
            std::cout << "double: " << num << std::endl;
        }
        return;
    }
}
