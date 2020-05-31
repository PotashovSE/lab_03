#include "histogram.h"
#include "svg.h"
#include <cassert>

void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}
void test_negative() {
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}

void test_same() {
    double min = 0;
    double max = 0;
    find_minmax({1, 1, 1}, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_one() {
    double min = 0;
    double max = 0;
    find_minmax({2}, min, max);
    assert(min == 2);
    assert(max == 2);
}

void test_empty() {
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

void test_findmax() {
    //TEST1
    double max = find_max({2, 5, 3});
    assert(max == 5);

    //TEST2
    vector<size_t> bins = {100, 4, 0, 25};
    assert (find_max(bins) == 100);

}
void test_empty2(){
    double max ;
    max = find_max({});

    assert (max == 0);

}

int
main() {
    test_positive();
    test_negative();
    test_same();
    test_one();
    test_empty();
    test_findmax();
    test_empty2();
}
