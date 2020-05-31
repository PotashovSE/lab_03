#include <iostream>
#include <vector>
#include <string>
#include "histogram.h"
#include "svg.h"

using namespace std;


vector<double> input_numbers(const size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }

    return result;
}

vector<size_t> make_histogram(const vector<double>& numbers, const size_t count) {
    vector<size_t> result(count);
    double min;
    double max;
    find_minmax(numbers, min, max);
    for (double number : numbers) {
        size_t bin = (size_t)((number - min) / (max - min) * count);
        if (bin == count) {
            bin--;
        }
        result[bin]++;
    }

    return result;
}


int main() {
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);


    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    const auto bins = make_histogram(numbers, bin_count);

    show_histogram_svg(bins);


    return 0;
}
