#pragma once
#include <string>

void convert_decimal_place(const size_t place, std::string& engl);
void starts_decimal(const char* number, size_t len,
    std::string& engl, const char* const prefix);