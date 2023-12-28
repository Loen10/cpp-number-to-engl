#include "decimal_conversions.hpp"
#include "nums.hpp"
#include "digit_conversions.hpp"

void convert_decimal_place(const size_t place, std::string& engl) {
    engl += fractional_prefixes[place % 3];
    engl += third_orders[place / 3];
    engl += "th";
}

void starts_decimal(const char* number, size_t len,
    std::string& engl, const char* const prefix)
{
    if (len == 1) return;
    number += 1;
    len -= 1;
    auto first_non_zero = get_first_non_zero(number, len);

    if (!first_non_zero.has_value() || !std::isdigit(number[*first_non_zero]))
        return;

    engl += prefix;
    len = get_last_non_zero_digit(number, *first_non_zero, len) + 1;
    convert_digits(number + *first_non_zero, len - *first_non_zero, engl);
    convert_decimal_place(len, engl);

    if (*first_non_zero + 1 != len || number[*first_non_zero] != '1') {
        engl += "s";
    }
}