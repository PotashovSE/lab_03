#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <vector>
#include <sstream>
#include <string>

using namespace std;
struct Input {
    vector<double> numbers;
    size_t bin_count;
};
void find_minmax (const vector<double>& numbers, double& min, double& max);
string information_system();

#endif // HISTOGRAM_H_INCLUDED
