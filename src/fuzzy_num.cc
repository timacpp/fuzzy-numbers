#include "fuzzy_num.h"
#include <vector>

namespace {
    constexpr void order_triplet(real_t& first, real_t& second, real_t& third) {
        if (first > second)
            std::swap(first, second);
        if (first > third)
            std::swap(first, third);
        if (second > third)
            std::swap(second, third);
    }
}

TriFuzzyNum crisp_zero() {
    return {0, 0, 0};
}

TriFuzzyNum crisp_number(real_t v) {
    return {v, v, v};
}

TriFuzzyNum::TriFuzzyNum(real_t first, real_t second, real_t third) {
    order_triplet(first, second, third);

    this->lower = first;
    this->modal = second;
    this->upper = third;
}

TriFuzzyNum::TriFuzzyNum(const TriFuzzyNum& src) {
    this->lower = src.lower_value();
    this->modal = src.modal_value();
    this->upper = src.upper_value();
}

real_t TriFuzzyNum::lower_value() const {
    return this->lower;
}

real_t TriFuzzyNum::modal_value() const {
    return this->modal;
}

real_t TriFuzzyNum::upper_value() const {
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

//auto TriFuzzyNum::operator<=>(const TriFuzzyNum& other) const {
//    return false;
//}

