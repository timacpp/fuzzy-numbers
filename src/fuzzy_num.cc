#include <cmath>
#include "fuzzy_num.h"

TriFuzzyNum TriFuzzyNum::rank() const {
    const real_t sqrt_um{sqrt(1 + (upper - modal) * (upper - modal))};
    const real_t sqrt_ml{sqrt(1 + (modal - lower) * (modal - lower))};

    real_t z = (upper - lower) + sqrt_um + sqrt_ml;
    real_t y = (upper - lower) / z;
    real_t x = ((upper - lower) * modal + sqrt_um * lower + sqrt_ml * upper) / z;

    return {x, y, z};
}

TriFuzzyNum TriFuzzyNum::operator+(const TriFuzzyNum& other) const {
    return {
        this->lower + other.lower,
        this->modal + other.modal,
        this->upper + other.upper
    };
}

TriFuzzyNum& TriFuzzyNum::operator+=(const TriFuzzyNum& other) {
    return (*this = *this + other);
}

TriFuzzyNum TriFuzzyNum::operator*(const TriFuzzyNum& other) const {
    return {
        this->lower * other.lower,
        this->modal * other.modal,
        this->upper * other.upper
    };
}

TriFuzzyNum& TriFuzzyNum::operator*=(const TriFuzzyNum& other) {
    return (*this = *this * other);
}

TriFuzzyNum TriFuzzyNum::operator-() const {
    return (*this * crisp_number(-1));
}

TriFuzzyNum TriFuzzyNum::operator-(const TriFuzzyNum& other) const {
    return (*this + (-other));
}

TriFuzzyNum& TriFuzzyNum::operator-=(const TriFuzzyNum& other) {
    return (*this = *this - other);
}

bool TriFuzzyNum::operator==(const TriFuzzyNum& other) const {
    return this->lower == other.lower &&
           this->modal == other.modal &&
           this->upper == other.upper;
}

bool TriFuzzyNum::operator!=(const TriFuzzyNum& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const TriFuzzyNum& num) {
    out << '(' << num.lower << ", " << num.modal << ", " << num.upper << ')';
    return out;
}


