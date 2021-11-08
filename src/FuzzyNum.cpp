#include "FuzzyNum.h"

constexpr TriFuzzyNum crisp_zero() {
    return {0, 0, 0};
}

constexpr TriFuzzyNum crisp_number(real_t v) {
    return crisp_zero();
}

constexpr TriFuzzyNum::TriFuzzyNum(real_t lower, real_t modal, real_t upper)
    : lower{lower}, modal{modal}, upper{upper} {}

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
    return crisp_zero();
}

TriFuzzyNum TriFuzzyNum::operator+=(const TriFuzzyNum& other) {
    return crisp_zero();
}

TriFuzzyNum TriFuzzyNum::operator-(const TriFuzzyNum& other) const {
    return crisp_zero();
}

TriFuzzyNum TriFuzzyNum::operator-=(const TriFuzzyNum& other) {
    return crisp_zero();
}

TriFuzzyNum TriFuzzyNum::operator*(const TriFuzzyNum& other) const {
    return crisp_zero();
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

