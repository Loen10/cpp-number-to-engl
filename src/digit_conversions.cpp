#include "digit_conversions.hpp"
#include "decimal_conversions.hpp"
#include "nums.hpp"

constexpr int to_digit(const char c) {
    return c - '0';
}

constexpr bool is_non_zero_digit(const char c) {
    return c > '0' && c < 58;
}

size_t find_end_of_digits(const char* const number, const size_t len) {
    for (size_t end = 0; end < len; ++end) {
        if (!std::isdigit(number[end])) return end;
    }

    return len;
}

void handle_zeros_followed_by_non_digit(const char *start_non_digit,
    std::size_t len, std::string &engl)
{
    if (start_non_digit[0] == '.') {
        bool converted_decimals = starts_decimal(start_non_digit, len, engl);

        if (!converted_decimals) {
            engl = "zero";
        }
        
        return;
    }

    engl = "Invalid number!";
}

void starts_digit(const char* number, std::size_t len, std::string &engl) {
    auto first_non_zero = find_first_non_zero(number, len);

    if (!first_non_zero) {
        engl = "zero";
        return;
    }

    if (!isdigit(number[*first_non_zero])) {
        handle_zeros_followed_by_non_digit(number + *first_non_zero,
            len - *first_non_zero, engl);
        
        return;
    }

    number += *first_non_zero;
    len -= *first_non_zero;
    const size_t end = find_end_of_digits(number, len);
    convert_digits(number, end, engl);

    if (end < len && number[end] == '.') {
        convert_after_decimal(number + end, len - end, engl, " and ");
    }
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

void convert_group_no_leading(const char* const group, const int len,
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
    size_t third_order = (len - 1) / 3;
    int first_group_len = len - third_order * 3;
    convert_group_no_leading(digits, first_group_len, engl, third_order);

    for (size_t i = first_group_len; i < len; i += 3) {
        convert_group3(digits + i, --third_order, engl);
    }
}

size_t find_last_non_zero_digit(const char* const number, const size_t start,
    const size_t end)
{
    size_t last_non_zero_digit = start;

    for (size_t i = start + 1; i < end; ++i) {
        if (number[i] != '0') {
            if (!is_non_zero_digit(number[i])) break;
            last_non_zero_digit = i;
        }
    }

    return last_non_zero_digit;
}

std::optional<size_t> find_first_non_zero(const char *const number,
    const std::size_t len)
{
    if (len == 0) return std::nullopt;

    for (size_t i = 0; i < len; ++i) {
        if (number[i] != '0') return i;
    }

    return std::nullopt;
}