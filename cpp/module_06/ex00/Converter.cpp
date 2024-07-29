/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:00:04 by daraz             #+#    #+#             */
/*   Updated: 2024/07/25 15:39:14 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

// print functions

static void printConversions(char c) {
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void printConversions(int n) {
    if (n < 0 || n > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (n < 32 || n == 127) {
        std::cout << "char: non-displayable" << std::endl;
    } else {
        std::cout << "char: " << static_cast<char>(n) << std::endl;
    }
    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

static void printConversions(float n) {
    if (n < 0 || n > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (n < 32 || n == 127) {
        std::cout << "char: non-displayable" << std::endl;
    } else {
        std::cout << "char: " << static_cast<char>(n) << std::endl;
    }
    std::cout << "int: " << static_cast<int>(n) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(2) << n << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(n) << std::endl;
}

static void printConversions(double n) {
    if (n < 0 || n > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (n < 32 || n == 127) {
        std::cout << "char: non-displayable" << std::endl;
    } else {
        std::cout << "char: " << static_cast<char>(n) << std::endl;
    }
    std::cout << "int: " << static_cast<int>(n) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(n) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(2) << n << std::endl;
}

// special values
static void printSpecialValue(const std::string &value) {
    if (value == "-inf" || value == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << INT_MIN << std::endl;
        std::cout << "float: " << FLT_MIN << std::endl;
        std::cout << "double: " << DBL_MIN << std::endl;
    } else if (value == "+inf" || value == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << INT_MAX << std::endl;
        std::cout << "float: " << FLT_MAX << std::endl;
        std::cout << "double: " << DBL_MAX << std::endl;
    } else if (value == "nan" || value == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

// validations
static bool isValidNumber(const std::string &param, bool &isFloat) {
    size_t len = param.length();
    size_t i = 0;

    if (len == 0) return false;

    isFloat = (param[len - 1] == 'f');
    if (isFloat) len--;

    while (i < len && (std::isdigit(param[i]) || param[i] == '.')) {
        i++;
    }
    return (i == len);
}

static void processInput(const std::string &param) {
    bool isFloat = false;

    if (param.length() == 1 && std::isprint(param[0]) && !std::isdigit(param[0])) {
        printConversions(param[0]);
    } else if (param == "-inf" || param == "-inff" || param == "+inf" || param == "+inff" || param == "nan" || param == "nanf") {
        printSpecialValue(param);
    } else if (isValidNumber(param, isFloat)) {
        if (isFloat) {
            float f = std::atof(param.c_str());
            printConversions(f);
        } else if (param.find('.') != std::string::npos) {
            double d = std::atof(param.c_str());
            printConversions(d);
        } else {
            int n = std::atoi(param.c_str());
            printConversions(n);
        }
    } else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: 0" << std::endl;
        std::cout << "float: 0" << std::endl;
        std::cout << "double: 0" << std::endl;
    }
}

void Converter::convert(const std::string &param) {
    processInput(param);
}
