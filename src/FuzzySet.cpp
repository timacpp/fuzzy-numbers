#include "FuzzySet.h"

TriFuzzyNumSet::TriFuzzyNumSet(const std::initializer_list<TriFuzzyNum>& list) {
    // TODO
}

TriFuzzyNumSet::TriFuzzyNumSet(const TriFuzzyNumSet& src) {
    // TODO
}

TriFuzzyNumSet::TriFuzzyNumSet(TriFuzzyNumSet &&) noexcept {
    // TODO
}

void TriFuzzyNumSet::insert(TriFuzzyNum &) {
    // TODO
}

void TriFuzzyNumSet::insert(TriFuzzyNum &&) noexcept {
    // TODO
}

void TriFuzzyNumSet::remove(TriFuzzyNum &) {
    // TODO
}

TriFuzzyNum TriFuzzyNumSet::arithmetic_mean() {
    return crisp_zero();
}

TriFuzzyNumSet& TriFuzzyNumSet::operator=(const TriFuzzyNumSet& other) {
    return *this;
}

TriFuzzyNumSet& TriFuzzyNumSet::operator=(TriFuzzyNumSet&& other) noexcept {
    return *this;
}