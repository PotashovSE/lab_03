#include <vector>
#include <iostream>
#include "histogram.h"
#include <windows.h>
#include <sstream>
#include <string>

using namespace std;

void find_minmax (const vector<double>& numbers, double& min, double& max) {
    if (numbers.size() != 0)
    {
        min = numbers[0];
        max = numbers[0];
        for (double number : numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
        }
    }

}



string information_system()
{
    stringstream buffer;
    DWORD mask = 0x0000ffff;
    DWORD mask_major = 0x000000ff;
    DWORD info = GetVersion();
    DWORD platform = info >> 16;
    DWORD version = info & mask;
    DWORD version_major = version & mask_major;
    DWORD version_minor = version >> 8;
    /*printf("Windows decimal-version is %u.\n", version);
    printf("Windows 16-x version is %x.\n", version);
    printf("Platform is %u.\n", platform);
    printf("Windows major version is %u.\n", version_major);
    printf("Windows minor version is %u.\n", version_minor);*/
    if ((info & 0x40000000) == 0)
    {
        DWORD build = platform;
        buffer << "Windows:" << version_major << "." << version_minor << " (build" << build << ")\n";
    }
    char get_computer_name[MAX_COMPUTERNAME_LENGTH+1];
    DWORD size = sizeof(get_computer_name);
    GetComputerNameA(get_computer_name, &size);
    buffer << "Computer name:" << get_computer_name << "\n";
    return buffer.str();

}


void show_histogram_text(vector<size_t> bins) {
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;

    size_t max_count = 0;
    for (size_t count : bins) {
        if (count > max_count) {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > MAX_ASTERISK;

    for (size_t bin : bins) {
        if (bin < 100) {
            cout << ' ';
        }
        if (bin < 10) {
            cout << ' ';
        }
        cout << bin << "|";

        size_t height = bin;
        if (scaling_needed) {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
            height = (size_t)(bin * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }

}
