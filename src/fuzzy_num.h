#ifndef FUZZYNUM_H
#define FUZZYNUM_H

#include <iostream>

using real_t = double;

class TriFuzzyNum;

constexpr inline TriFuzzyNum crisp_number(real_t v);

constexpr inline TriFuzzyNum crisp_zero();

class TriFuzzyNum {
public:
    constexpr inline TriFuzzyNum(real_t first, real_t second, real_t third)
            : lower{first}, modal{second}, upper{third} {
        this->order_values();
    }

    TriFuzzyNum(const TriFuzzyNum&) = default;

    TriFuzzyNum(TriFuzzyNum&&) = default;

    ~TriFuzzyNum() = default;

    constexpr inline real_t lower_value() const {
        return this->lower;
    }

    constexpr inline real_t modal_value() const {
        return this->modal;
    }

    constexpr inline real_t upper_value() const {
        return this->upper;
    }

    TriFuzzyNum rank() const;

    TriFuzzyNum operator+(const TriFuzzyNum&) const;

    TriFuzzyNum& operator+=(const TriFuzzyNum&);

    TriFuzzyNum operator-(const TriFuzzyNum&) const;

    TriFuzzyNum& operator-=(const TriFuzzyNum&);

    TriFuzzyNum operator*(const TriFuzzyNum&) const;

    TriFuzzyNum& operator*=(const TriFuzzyNum&);

    bool operator==(const TriFuzzyNum&) const;

    bool operator!=(const TriFuzzyNum&) const;

    TriFuzzyNum& operator=(const TriFuzzyNum&) = default;

    TriFuzzyNum& operator=(TriFuzzyNum&&) = default;

//    auto operator<=>(const TriFuzzyNum&) const;

    friend std::ostream& operator<<(std::ostream&, const TriFuzzyNum&);

private:
    real_t lower;
    real_t modal;
    real_t upper;

    real_t rank_lower() const;

    real_t rank_modal() const;

    real_t rank_upper() const;

    TriFuzzyNum operator-() const;

    constexpr inline void order_values() {
        if (lower > modal)
            std::swap(lower, modal);
        if (lower > upper)
            std::swap(lower, upper);
        if (modal > upper)
            std::swap(modal, upper);
    }
};

constexpr inline TriFuzzyNum crisp_number(real_t v) {
    return {v, v, v};
}

constexpr inline TriFuzzyNum crisp_zero() {
    return crisp_number(0);
}

#endif //FUZZYNUM_H
