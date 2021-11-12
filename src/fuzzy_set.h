#ifndef FUZZYSET_H
#define FUZZYSET_H

#include "fuzzy_num.h"
#include <unordered_set>
#include <initializer_list>

class TriFuzzyNumSet {
    std::unordered_multiset<TriFuzzyNum> elements;

public:
    TriFuzzyNumSet(const std::initializer_list<TriFuzzyNum>&); // TODO: explicit or not?

    TriFuzzyNumSet(const TriFuzzyNumSet&);

    TriFuzzyNumSet(TriFuzzyNumSet&&) noexcept;

    void insert(TriFuzzyNum&);

    void insert(TriFuzzyNum&&) noexcept;

    void remove(TriFuzzyNum&);

    TriFuzzyNum arithmetic_mean();

    TriFuzzyNumSet& operator=(const TriFuzzyNumSet&);

    TriFuzzyNumSet& operator=(TriFuzzyNumSet&&) noexcept;
};

#endif //FUZZYSET_H
