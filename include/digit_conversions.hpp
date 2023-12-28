#pragma once
#include <stdint.h>
#include <string>
#include <optional>

constexpr uint8_t to_digit(const char c);
constexpr bool is_non_zero_digit(const char c);
void convert_double_digit(const char* const double_digit, std::string& engl);
void convert_triple_digit(const char* const triple_digit, std::string& engl);
void starts_digit(const char* number, size_t len, std::string& engl);
void convert_group3(const char* const group, const size_t third_order,
    std::string& engl);

void convert_group_no_leading(const char* const group, const uint8_t len,
    std::string& engl, const size_t third_order);

void convert_digits(const char* const digits, const size_t len,
    std::string& engl);

size_t get_end_of_digits(const char* const number, const size_t len);
size_t get_last_non_zero_digit(const char* const number, const size_t start,
    const size_t end);

std::optional<size_t> get_first_non_zero(const char* const number,
    const size_t len);