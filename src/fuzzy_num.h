#ifndef FUZZYNUM_H
#define FUZZYNUM_H

#include <vector>
#include <compare>
#include <iostream>

using real_t = double;

class TriFuzzyNum {
public:
    constexpr TriFuzzyNum(real_t first, real_t second, real_t third)
            : lower{first}, modal{second}, upper{third} {
        this->order_values();
    }

    TriFuzzyNum(const TriFuzzyNum&) = default;

    TriFuzzyNum(TriFuzzyNum&&) = default;

    ~TriFuzzyNum() = default;

    [[nodiscard]] constexpr inline real_t lower_value() const {
        return this->lower;
    }

    [[nodiscard]] constexpr inline real_t modal_value() const {
        return this->modal;
    }

    [[nodiscard]] constexpr inline real_t upper_value() const {
        return this->upper;
    }

    friend TriFuzzyNum operator+(const TriFuzzyNum&, const TriFuzzyNum&);

    friend TriFuzzyNum operator-(const TriFuzzyNum&, const TriFuzzyNum&);

    friend TriFuzzyNum operator*(const TriFuzzyNum&, const TriFuzzyNum&);

    TriFuzzyNum& operator=(const TriFuzzyNum&) = default;

    TriFuzzyNum& operator=(TriFuzzyNum&&) = default;

    TriFuzzyNum& operator+=(const TriFuzzyNum&);

    TriFuzzyNum& operator-=(const TriFuzzyNum&);

    TriFuzzyNum& operator*=(const TriFuzzyNum&);

    friend std::ostream& operator<<(std::ostream&, const TriFuzzyNum&);

    friend std::strong_ordering operator<=>(const TriFuzzyNum&, const TriFuzzyNum&);

    friend constexpr inline bool operator==(const TriFuzzyNum&, const TriFuzzyNum&);

    friend constexpr inline bool operator!=(const TriFuzzyNum&, const TriFuzzyNum&);

private:
    real_t lower;
    real_t modal;
    real_t upper;

    TriFuzzyNum operator-() const;

    [[nodiscard]] std::vector<real_t> rank() const;

    constexpr inline void order_values() {
        if (lower > modal)
            std::swap(lower, modal);
        if (lower > upper)
            std::swap(lower, upper);
        if (modal > upper)
            std::swap(modal, upper);
    }
};

constexpr inline bool operator==(const TriFuzzyNum& lhs, const TriFuzzyNum& rhs) {
    return lhs.lower == rhs.lower &&
           lhs.modal == rhs.modal &&
           lhs.upper == rhs.upper;
}

constexpr inline bool operator!=(const TriFuzzyNum& lhs, const TriFuzzyNum& rhs) {
    return !(lhs == rhs);
}

consteval inline TriFuzzyNum crisp_number(real_t v) {
    return {v, v, v};
}

constinit TriFuzzyNum crisp_zero{crisp_number(0)};

#endif //FUZZYNUM_H
