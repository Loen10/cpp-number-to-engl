#pragma once
#include <cstddef>
#include <string>
#include <optional>

void starts_digit(const char *number, std::size_t len, std::string& engl);
void convert_digits(const char* const digits, const std::size_t len,
    std::string& engl);

size_t find_last_non_zero_digit(const char* const number,
    const std::size_t start, const std::size_t end);

std::optional<std::size_t> find_first_non_zero(const char* const number,
    const std::size_t len);