/*
 * sudo apt install libboost-all-dev
 * sudo apt install aptitude
 * aptitude search boost
 */

#define BOOST_TEST_MODULE fuzzy_suite
#include <boost/test/included/unit_test.hpp>

#include "../src/fuzzy_num.h"

BOOST_AUTO_TEST_CASE(ValuesTest) {
    const real_t lower{1}, modal{2}, upper{3};

    TriFuzzyNum num{lower, modal, upper};

    BOOST_CHECK_EQUAL(num.lower_value(), lower);
    BOOST_CHECK_EQUAL(num.modal_value(), modal);
    BOOST_CHECK_EQUAL(num.upper_value(), upper);
}

BOOST_AUTO_TEST_CASE(OrderTest) {
    TriFuzzyNum num1{1, 2, 3};
    TriFuzzyNum num2{3, 2, 1};

    BOOST_CHECK_EQUAL(num1.lower_value(), num2.lower_value());
    BOOST_CHECK_EQUAL(num1.modal_value(), num2.modal_value());
    BOOST_CHECK_EQUAL(num1.upper_value(), num2.upper_value());
}

BOOST_AUTO_TEST_CASE(CopyConstructorTest) {
    TriFuzzyNum num1{1, 2, 3};
    const TriFuzzyNum& num2{num1};

    BOOST_CHECK_EQUAL(num1.lower_value(), num2.lower_value());
    BOOST_CHECK_EQUAL(num1.modal_value(), num2.modal_value());
    BOOST_CHECK_EQUAL(num1.upper_value(), num2.upper_value());
}
