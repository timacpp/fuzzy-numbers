#define BOOST_TEST_MODULE fuzzynum_suite

#include <boost/test/included/unit_test.hpp>
#include "../src/fuzzy_num.h"

#define NUM(x, y, z) TriFuzzyNum(x, y, z)
#define ADD(x, y, z) NUM(x + x, y + y, z + z)
#define MUL(x, y, z) NUM(x * x, y * y, z * z)

namespace {
    constinit real_t lower{1};
    constinit real_t modal{2};
    constinit real_t upper{3};
    constexpr real_t eps{1e-9};

    TriFuzzyNum sample() {
        return NUM(lower, modal, upper);
    }
}

BOOST_AUTO_TEST_CASE(ValuesTest) {
    TriFuzzyNum num{sample()};

    BOOST_CHECK_EQUAL(num.lower_value(), lower);
    BOOST_CHECK_EQUAL(num.modal_value(), modal);
    BOOST_CHECK_EQUAL(num.upper_value(), upper);
}

BOOST_AUTO_TEST_CASE(EqualTest) {
    TriFuzzyNum num{sample()};

    BOOST_CHECK(num == num);
    BOOST_CHECK(crisp_zero == crisp_zero);
    BOOST_CHECK(num != crisp_zero);
    BOOST_CHECK(num - crisp_zero == num + crisp_zero);
    BOOST_CHECK(num + num == ADD(lower, modal, upper));
    BOOST_CHECK(num * num == MUL(lower, modal, upper));
}

BOOST_AUTO_TEST_CASE(OrderTest) {
    std::vector<real_t> values{lower, modal, upper};
    std::vector<TriFuzzyNum> nums;

    do {
        TriFuzzyNum num{values[0], values[1], values[2]};
        nums.push_back(num);
    } while (std::next_permutation(values.begin(), values.end()));

    BOOST_CHECK(nums == std::vector<TriFuzzyNum>(nums.size(), nums[0]));
}

BOOST_AUTO_TEST_CASE(CopyConstructorTest) {
    TriFuzzyNum num1{sample()};
    const TriFuzzyNum& num2{num1};

    BOOST_CHECK_EQUAL(num1, num2);
}

BOOST_AUTO_TEST_CASE(ZeroMultiplyTest) {
    TriFuzzyNum num{sample()};

    BOOST_CHECK_EQUAL(num * crisp_zero, crisp_zero);
    BOOST_CHECK_EQUAL(crisp_zero * num, crisp_zero);
    BOOST_CHECK_EQUAL(crisp_zero * crisp_zero, crisp_zero);
    BOOST_CHECK_EQUAL((num *= crisp_zero), crisp_zero);
}

BOOST_AUTO_TEST_CASE(GeneralMultiplyTest) {
    const int runs = 10;
    TriFuzzyNum num{sample()};
    real_t l = lower, m = modal, u = upper;

    for (int i = 0; i < runs; i++) {
        num *= num;
        l *= l;
        m *= m;
        u *= u;

        BOOST_CHECK_EQUAL(num, NUM(l, m, u));
    }
}

BOOST_AUTO_TEST_CASE(AddTest) {
    TriFuzzyNum num{sample()};

    BOOST_CHECK_EQUAL(num + crisp_zero, num);
    BOOST_CHECK_EQUAL(num - crisp_zero, num);
    BOOST_CHECK_EQUAL(num + num, ADD(lower, modal, upper));
    BOOST_CHECK_EQUAL(crisp_zero + crisp_zero, crisp_zero);
    BOOST_CHECK_EQUAL(crisp_number(eps) + crisp_number(eps), ADD(eps, eps, eps));
    BOOST_CHECK(num + crisp_number(eps) != num);
    BOOST_CHECK(num - crisp_number(eps) != num);
}

BOOST_AUTO_TEST_CASE(AssignmentTest) {
    TriFuzzyNum num{sample()};

    BOOST_CHECK_EQUAL(num = num, num);
    BOOST_CHECK_EQUAL(num = crisp_zero, crisp_zero);
    BOOST_CHECK_EQUAL(num = crisp_number(1), crisp_number(1));
    BOOST_CHECK_EQUAL(num = crisp_number(eps), crisp_number(eps));
}

BOOST_AUTO_TEST_CASE(OrderAfterOperationTest) {
    TriFuzzyNum num{-1, 0, 1};
    const TriFuzzyNum res{0, 1, 1};

    BOOST_CHECK_EQUAL(num * num, res);
}
