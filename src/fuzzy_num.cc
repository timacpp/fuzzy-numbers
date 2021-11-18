#include "fuzzy_num.h"
#include <cmath>

TriFuzzyNum TriFuzzyNum::rank() const {
    const real_t sqrt_um{sqrt(1 + (upper - modal) * (upper - modal))};
    const real_t sqrt_ml{sqrt(1 + (modal - lower) * (modal - lower))};

    real_t z = (upper - lower) + sqrt_um + sqrt_ml;
    real_t y = (upper - lower) / z;
    real_t x = ((upper - lower) * modal + sqrt_um * lower + sqrt_ml * upper) / z;

    return {x, y, z};
}

TriFuzzyNum operator+(const TriFuzzyNum& lhs, const TriFuzzyNum& rhs) {
    return {
        lhs.lower + rhs.lower,
        lhs.modal + rhs.modal,
        lhs.upper + rhs.upper
    };
}

TriFuzzyNum operator*(const TriFuzzyNum& lhs, const TriFuzzyNum& rhs) {
    return {
            lhs.lower * rhs.lower,
            lhs.modal * rhs.modal,
            lhs.upper * rhs.upper
    };
}

TriFuzzyNum TriFuzzyNum::operator-() const {
    return (*this * crisp_number(-1));
}

TriFuzzyNum operator-(const TriFuzzyNum& lhs, const TriFuzzyNum& rhs) {
    return (lhs + (-rhs));
}

TriFuzzyNum& TriFuzzyNum::operator+=(const TriFuzzyNum& other) {
    return (*this = *this + other);
}

TriFuzzyNum& TriFuzzyNum::operator*=(const TriFuzzyNum& other) {
    return (*this = *this * other);
}

TriFuzzyNum& TriFuzzyNum::operator-=(const TriFuzzyNum& other) {
    return (*this = *this - other);
}

std::ostream& operator<<(std::ostream& out, const TriFuzzyNum& num) {
    out << '(' << num.lower << ", " << num.modal << ", " << num.upper << ')';
    return out;
}

std::strong_ordering operator<=>(const TriFuzzyNum& lhs, const TriFuzzyNum& rhs) {
    const auto lhs_values{lhs.rank().to_vector()};
    const auto rhs_values{rhs.rank().to_vector()};

    if (lhs_values < rhs_values)
        return std::strong_ordering::less;
    else if (lhs_values > rhs_values)
        return std::strong_ordering::greater;
    return std::strong_ordering::equal;
}

std::vector<real_t> TriFuzzyNum::to_vector() const {
    return {this->lower, this->modal, this->upper};
}

