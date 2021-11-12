#include "fuzzy_num.h"

constexpr TriFuzzyNum crisp_zero() {
    return {0, 0, 0};
}

constexpr TriFuzzyNum crisp_number(real_t v) {
    return {v, v, v};
}

constexpr TriFuzzyNum::TriFuzzyNum(real_t first, real_t second, real_t third) {
    std::tie(lower, modal, upper) = std
}

TriFuzzyNum::TriFuzzyNum(const TriFuzzyNum& src) {
    // TODO
}

TriFuzzyNum::TriFuzzyNum(TriFuzzyNum&& src) noexcept {
    // TODO
}

constexpr real_t TriFuzzyNum::lower_value() const {
    return this->lower;
}

constexpr real_t TriFuzzyNum::modal_value() const {
    return this->modal;
}

constexpr real_t TriFuzzyNum::upper_value() const {
    return this->upper;
}

TriFuzzyNum TriFuzzyNum::rank() const {
    return crisp_zero();
}

TriFuzzyNum TriFuzzyNum::operator+(const TriFuzzyNum& other) const {
    return {lower + other.lower, modal + other.modal, upper + other.upper};
}

TriFuzzyNum TriFuzzyNum::operator+=(const TriFuzzyNum& other) {
    return crisp_zero();
}

TriFuzzyNum TriFuzzyNum::operator-(const TriFuzzyNum& other) const {
    return {lower - other.lower, modal - other.modal, upper - other.upper};
}

TriFuzzyNum TriFuzzyNum::operator-=(const TriFuzzyNum& other) {
    return crisp_zero();
}

TriFuzzyNum TriFuzzyNum::operator*(const TriFuzzyNum& other) const {
    return {lower * other.lower, modal * other.modal, upper * other.upper};
}

TriFuzzyNum TriFuzzyNum::operator*=(const TriFuzzyNum& other) {
    return crisp_zero();
}

bool TriFuzzyNum::operator==(const TriFuzzyNum& other) const {
    return false;
}

bool TriFuzzyNum::operator!=(const TriFuzzyNum& other) const {
    return false;
}

auto TriFuzzyNum::operator<=>(const TriFuzzyNum& other) const {
    return false;
}

