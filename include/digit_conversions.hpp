#pragma once
#include <cstddef>
#include <string>
#include <optional>

void starts_digit(const char* number, size_t len, std::string& engl);
void convert_digits(const char* const digits, const size_t len,
    std::string& engl);

size_t find_last_non_zero_digit(const char* const number, const size_t start,
    const size_t end);

std::optional<size_t> find_first_non_zero(const char* const number,
    const size_t len);