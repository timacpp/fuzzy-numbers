#ifndef FUZZYSET_H
#define FUZZYSET_H

#include <set>
#include <initializer_list>

#include "fuzzy_num.h"

/** Class representing a multiset of triangular fuzzy numbers **/
class TriFuzzyNumSet {
public:
    TriFuzzyNumSet() = default;

    TriFuzzyNumSet(const std::initializer_list<TriFuzzyNum>&);

    TriFuzzyNumSet(std::initializer_list<TriFuzzyNum>&&);

    TriFuzzyNumSet(const TriFuzzyNumSet&) = default;

    TriFuzzyNumSet(TriFuzzyNumSet&&) noexcept;

    ~TriFuzzyNumSet() = default;

    void insert(TriFuzzyNum&);

    void insert(TriFuzzyNum&&) noexcept;

    void remove(TriFuzzyNum);

    TriFuzzyNum arithmetic_mean();

    TriFuzzyNumSet& operator=(const TriFuzzyNumSet&) = default;

    TriFuzzyNumSet& operator=(TriFuzzyNumSet&&) noexcept;

private:
    std::multiset<TriFuzzyNum> elements;

    TriFuzzyNum sum() const;
};

#endif //FUZZYSET_H