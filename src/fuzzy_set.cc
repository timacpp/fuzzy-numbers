#include "fuzzy_set.h"
#include <numeric>

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
    if (elements.empty()) {
        throw std::length_error("TriFuzzyNumSet::arithmetic_mean - the set is empty.");
    }

    const auto tri_div([](const TriFuzzyNum& num, size_t divisor) -> TriFuzzyNum {
        return {num.lower_value() / divisor,
                num.modal_value() / divisor,
                num.upper_value() / divisor};
    });

    return tri_div(this->sum(), elements.size());
}

TriFuzzyNumSet& TriFuzzyNumSet::operator=(TriFuzzyNumSet&& other) noexcept {
    this->elements = std::move(other.elements);
    return *this;
}

TriFuzzyNum TriFuzzyNumSet::sum() const {
    return std::accumulate(elements.begin(),elements.end(), crisp_zero);
}
