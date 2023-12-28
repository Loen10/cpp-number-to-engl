#pragma once
#include <string>

bool convert_after_decimal(const char *number, std::size_t len,
    std::string &engl, const char *prefix = "");

bool starts_decimal(const char *number, std::size_t len, std::string &engl);