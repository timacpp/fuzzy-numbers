#ifndef FUZZYNUM_H
#define FUZZYNUM_H

using real_t = double;

class TriFuzzyNum;

constexpr TriFuzzyNum crisp_zero();

constexpr TriFuzzyNum crisp_number(real_t v);

class TriFuzzyNum {
    real_t lower;
    real_t modal;
    real_t upper;

public:
    constexpr TriFuzzyNum(real_t, real_t, real_t);

    TriFuzzyNum(const TriFuzzyNum&);

    TriFuzzyNum(TriFuzzyNum&&) noexcept;

    constexpr real_t lower_value() const;

    constexpr real_t modal_value() const;

    constexpr real_t upper_value() const;

    TriFuzzyNum rank() const;

    TriFuzzyNum operator+(const TriFuzzyNum&) const;

    TriFuzzyNum operator+=(const TriFuzzyNum&);

    TriFuzzyNum operator-(const TriFuzzyNum&) const;

    TriFuzzyNum operator-=(const TriFuzzyNum&);

    TriFuzzyNum operator*(const TriFuzzyNum&) const;

    TriFuzzyNum operator*=(const TriFuzzyNum&);

    bool operator==(const TriFuzzyNum&) const;

    bool operator!=(const TriFuzzyNum&) const;

    auto operator<=>(const TriFuzzyNum&) const;
};

#endif //FUZZYNUM_H
