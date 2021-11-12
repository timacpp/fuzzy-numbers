#ifndef FUZZYNUM_H
#define FUZZYNUM_H

// TODO: merge fuzzy_num and fuzzy_set files into fuzzy.
// TODO: constexpr and explicit
// TODO: default copy constructor or not?

using real_t = double;

class TriFuzzyNum;

TriFuzzyNum crisp_zero();

TriFuzzyNum crisp_number(real_t v);

class TriFuzzyNum {
    real_t lower;
    real_t modal;
    real_t upper;

public:
    TriFuzzyNum(real_t, real_t, real_t);

    TriFuzzyNum(const TriFuzzyNum&);

    TriFuzzyNum(TriFuzzyNum&&) = default;

    real_t lower_value() const;

    real_t modal_value() const;

    real_t upper_value() const;

    TriFuzzyNum rank() const;

    TriFuzzyNum operator+(const TriFuzzyNum&) const;

    TriFuzzyNum operator+=(const TriFuzzyNum&);

    TriFuzzyNum operator-(const TriFuzzyNum&) const;

    TriFuzzyNum operator-=(const TriFuzzyNum&);

    TriFuzzyNum operator*(const TriFuzzyNum&) const;

    TriFuzzyNum operator*=(const TriFuzzyNum&);

    bool operator==(const TriFuzzyNum&) const;

    bool operator!=(const TriFuzzyNum&) const;

//    auto operator<=>(const TriFuzzyNum&) const;
};

#endif //FUZZYNUM_H
