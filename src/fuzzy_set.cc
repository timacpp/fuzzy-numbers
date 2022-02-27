#include <numeric>

#include "fuzzy_set.h"

TriFuzzyNumSet::TriFuzzyNumSet(const std::initializer_list<TriFuzzyNum>& list)
        : elements{list} {}

TriFuzzyNumSet::TriFuzzyNumSet(std::initializer_list<TriFuzzyNum>&& list)
        : elements{list} {}

TriFuzzyNumSet::TriFuzzyNumSet(TriFuzzyNumSet&& src) noexcept
        : elements{std::move(src.elements)} {}

void TriFuzzyNumSet::insert(TriFuzzyNum& number) {
    elements.insert(number);
}

void TriFuzzyNumSet::insert(TriFuzzyNum&& number) noexcept {
    elements.insert(number);
}

void TriFuzzyNumSet::remove(TriFuzzyNum number) {
    elements.erase(number);
}

TriFuzzyNum TriFuzzyNumSet::arithmetic_mean() {
    return this->sum() / static_cast<real_t>(elements.size());
}

TriFuzzyNumSet& TriFuzzyNumSet::operator=(TriFuzzyNumSet&& other) noexcept {
    this->elements = std::move(other.elements);
    return *this;
}

TriFuzzyNum TriFuzzyNumSet::sum() const {
    return std::accumulate(elements.begin(), elements.end(), crisp_zero);
}
