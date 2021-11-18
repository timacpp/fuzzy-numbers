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

    const auto sum = std::accumulate(elements.begin(),elements.end(), crisp_zero());
    const auto avg([this](real_t val) -> real_t {
        return val / static_cast<real_t>(elements.size());
    });

    return {avg(sum.lower_value()), avg(sum.modal_value()), avg(sum.upper_value())};
}

TriFuzzyNumSet& TriFuzzyNumSet::operator=(TriFuzzyNumSet&& other) noexcept {
    this->elements = std::move(other.elements);
    return *this;
}
