#ifndef FUZZYSET_H
#define FUZZYSET_H

#include <set>
#include <compare>
#include <initializer_list>
#include "fuzzy_num.h"

class TriFuzzyNumSet {
public:
    TriFuzzyNumSet(const std::initializer_list<TriFuzzyNum>&);

    TriFuzzyNumSet(std::initializer_list<TriFuzzyNum>&&);

    TriFuzzyNumSet(const TriFuzzyNumSet&) = default;

    TriFuzzyNumSet(TriFuzzyNumSet&&) noexcept;

    ~TriFuzzyNumSet() = default;

    void insert(TriFuzzyNum&);

    void insert(TriFuzzyNum&&) noexcept;

    void remove(TriFuzzyNum&);

    TriFuzzyNum arithmetic_mean();

    TriFuzzyNumSet& operator=(const TriFuzzyNumSet&) = default;

    TriFuzzyNumSet& operator=(TriFuzzyNumSet&&) noexcept;

private:
    std::multiset<TriFuzzyNum> elements;
};

#endif //FUZZYSET_H