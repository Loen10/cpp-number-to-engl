#include <iostream>
#include <optional>
#include <cstring>
#include <stdint.h>

constexpr const char* small_nums[] = {
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"
}, *prefixes[] = {
    "twenty",
    "thirty",
    "fourty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
}, *third_orders[] = {
    "",
    " thousand",
    " million",
    " billion",
    " trillion",
    " quadrillion",
    " quintillion",
    " sextillion",
    " septillion",
    " octillion",
    " nonillion",
    " decillion"
}, *fractional_prefixes[] = {
    "",
    "ten",
    "hundred"
};

void convert_group(const char* const group) {

}

void convert_digits(const char* const last_digit, const size_t len,
    std::string& engl)
{
    // 12345
    for (size_t i = 2; i < len; i += 3) {
        convert_group(last_digit - i);
    }
}

size_t get_end_of_digits(const char* const number, const size_t len) {
    for (size_t end = 0; end < len; ++end) {
        if (!std::isdigit(number[end])) return end;
    }

    return len;
}

void starts_decimal(const char* const number,
    const size_t len, std::string& engl)
{
}

void starts_digit(const char* const number, const size_t len,
    std::string& engl)
{
    const size_t end = get_end_of_digits(number, len);
    convert_digits(&number[end - 1], end, engl);

    if (end < len && number[end] == '.') {
        
    }

    
}

void starts_negative(const std::string& number) {
    if (number.length() == 1) {
        std::cout << "Invalid numeral!" << std::endl;
        return;
    }

    if (std::isdigit(number[1])) {
        std::string engl = "negative ";
        starts_digit(number.data() + 2, number.length() - 2, engl);
        return;
    }
    
    if (number[1] == '.') {
        std::string engl = "negative ";
        starts_digit(number.data() + 1, number.length() - 1, engl);
        return;
    }

    std::cout << "Invalid numeral!" << std::endl;
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
            starts_negative(number);
        } else if (std::isdigit(number[0])) {
            std::string engl;
            starts_digit(number.data(), number.length(), engl);
            std::cout << engl << std::endl;
        } else if (number[0] == '.') {
            std::string engl;
            starts_decimal(number.data(), number.length(), engl);
            std::cout << engl << std::endl;
        } else {
            std::cout << "Invalid number!" << std::endl;
        }
    }
}