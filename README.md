## What in a world are fuzzy numbers?

[Fuzzy number](https://en.wikipedia.org/wiki/Fuzzy_number) is a generalization of a real one. The core concept lies behind the assignment of **weights** to a number. Nonetheless, basic arithmetics is still applicable to this numbers.

## Introducing: triangular fuzzy numbers
One of the simplest representatives of the fuzzy numbers are called [triangular](https://www.researchgate.net/publication/318946539_Theory_of_Triangular_Fuzzy_Number).
They are defined as a tuple (l, m, u) and the mapping from real numbers to which has the following formula:

             { (x - l) / (m - l), if l <= x <= m;
      f(x) = { (u - x) / (u - m), if m < x <= u;
             { 0,                 otherwise
             

Addition, subtraction and multiplication work the same way as in real world, but pair-wise. Comparison, however, is performed via lexicographical order of their [ranks](https://www.researchgate.net/publication/260834079_A_new_method_for_ranking_triangular_fuzzy_numbers).

## About the project

This is a library for triangular fuzzy numbers manipulations. You can create them, perform operations mentioned above, store in a custom multiset and even more.
