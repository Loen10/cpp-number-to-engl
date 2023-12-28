#include "digit_conversions.hpp"
#include "decimal_conversions.hpp"
#include <iostream>

void starts_negative(const std::string& number, std::string& engl) {
    if (number.length() == 1) {
        engl = "Invalid numeral!";
        return;
    }

    if (std::isdigit(number[1])) {
        engl = "negative ";
        starts_digit(number.data() + 1, number.length() - 1, engl);
        return;
    }
    
    if (number[1] == '.') {
        engl = "negative ";
        starts_digit(number.data() + 1, number.length() - 1, engl);
        return;
    }

    engl = "Invalid numeral!";
}

int main() {
    while (true) {
        std::cout << "Enter a number: ";
        std::string number, engl;
        std::getline(std::cin, number);

        if (number.length() == 0) {
            std::cout << "Invalid number!" << std::endl;
            continue;
        }

        if (number[0] == '-') {
            starts_negative(number, engl);
        } else if (std::isdigit(number[0])) {
            starts_digit(number.data(), number.length(), engl);
        } else if (number[0] == '.') {
            starts_decimal(number.data(), number.length(), engl, "");
        } else {
            engl = "Invalid number!";
        }

        std::cout << engl << std::endl;
    }
}