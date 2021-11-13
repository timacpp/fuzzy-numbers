#include "fuzzy_num.h"


TriFuzzyNum TriFuzzyNum::rank() const {
    return {rank_lower(), rank_modal(), rank_upper()};
}

real_t TriFuzzyNum::rank_lower() const {
    return 0;
}

real_t TriFuzzyNum::rank_modal() const {
    return 0;
}

real_t TriFuzzyNum::rank_upper() const {
    return 0;
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

/*
 * x = ((u - l) * m + sqrt(1 + (u - m) * (u - m)) * l + sqrt(1 + (m - l) * (m - l)) * u) / z,
 * y = (u - l) / z,
 * z = (u - l) + sqrt(1 + (u - m) * (u - m)) + sqrt(1 + (m - l) * (m - l)).
 */

//auto TriFuzzyNum::operator<=>(const TriFuzzyNum& other) const {
//    return false;
//}

std::ostream& operator<<(std::ostream& out, const TriFuzzyNum& num) {
    out << '(' << num.lower << ", " << num.modal << ", " << num.upper << ')';
    return out;
}
