#include <iostream>
#include <optional>
#include <cstring>
#include <string>
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

constexpr uint8_t to_digit(const char c) {
    return c - '0';
}

void convert_double_digit(const char* const double_digit, std::string& engl) {
    if (double_digit[0] == '1') {
        engl += small_nums[10 + to_digit(double_digit[1])];
        return;
    }

    engl += prefixes[to_digit(double_digit[0]) - 2];

    if (double_digit[1] != '0') {
        engl += '-';
        engl += small_nums[to_digit(double_digit[1])];
    }
}

void convert_triple_digit(const char* const triple_digit, std::string& engl) {
    engl += small_nums[to_digit(triple_digit[0])];
    engl += " hundred";

    if (triple_digit[1] == '0') {
        if (triple_digit[2] != '0') {
            engl += ' ';
            engl += small_nums[to_digit(triple_digit[2])];
        }
    } else {
        engl += ' ';
        convert_double_digit(triple_digit + 1, engl);
    }
}

void convert_group3(const char* const group, const size_t third_order,
    std::string& engl)
{
    if (group[0] == '0') {
        if (group[1] == '0') {
            if (group[2] == '0') return;
            engl += ' ';
            engl += small_nums[to_digit(group[2])];
        } else {
            engl += ' ';
            convert_double_digit(group + 1, engl);
        }
    } else {
        engl += ' ';
        convert_triple_digit(group, engl);
    }

    engl += third_orders[third_order];
}

void convert_group_no_leading(const char* const group, const uint8_t len,
    std::string& engl, const size_t third_order)
{
    if (len == 1) {
        engl += small_nums[to_digit(group[0])];
    } else if (len == 2) {
        convert_double_digit(group, engl);
    } else {
        convert_triple_digit(group, engl);
    }

    engl += third_orders[third_order];
}

void convert_digits(const char* const digits, const size_t len,
    std::string& engl)
{
    size_t third_order = len / 3;
    const uint8_t first_group_len = len - third_order * 3;
    convert_group_no_leading(digits, first_group_len, engl, third_order);

    // 12345
    for (size_t i = first_group_len; i < len; i += 3) {
        convert_group3(digits + i, --third_order, engl);
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
    convert_digits(number, end, engl);

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
        starts_digit(number.data() + 1, number.length() - 1, engl);
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