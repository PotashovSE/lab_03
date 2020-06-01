#include "svg.h"
#include <vector>
#include <string>
#include <iostream>
#include "histogram.h"
using namespace std;

void svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='Windows-1251'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text <<"</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill) {
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "' />";
}

double find_max(const vector<size_t>& bins) {
    if (bins.size() != 0)
    {

    size_t max = bins[0];
    for (const auto& bin : bins)
    {

            if (bin > max)
            {
                max = bin;
            }
    }
    return max;
    }
    else
        return 0;
}


void show_histogram_svg(const vector<size_t>& bins) {
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 10;
    const auto TEXT_BASELINE = 20;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    const auto BLOCK_HEIGHT = 100;
    double TEXT_WIDTH = 10;
    const auto TEXT_HEIGHT = 75;
    const size_t MAX_ASTERISK = IMAGE_WIDTH - TEXT_LEFT - TEXT_WIDTH;

    const auto BAR_HEIGHT = IMAGE_HEIGHT - TEXT_HEIGHT;

    size_t max_count = 0;
    for (size_t count : bins) {
        if (count > max_count) {
            max_count = count;
        }
    }

    const bool scaling_needed = max_count * BLOCK_HEIGHT > BAR_HEIGHT;
    double factor=1;
    if (scaling_needed){
       factor = (double)BLOCK_HEIGHT / (max_count * BLOCK_HEIGHT);

    }



    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    double height_max = find_max(bins)*BLOCK_HEIGHT*factor+10 ;
    for (size_t bin : bins) {

        size_t height = bin*BLOCK_HEIGHT*factor;

        svg_text(top + TEXT_LEFT,height_max+TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, height_max - height, BIN_HEIGHT, height,"red","#aab5ff");
        top += BIN_HEIGHT;
        TEXT_WIDTH+= BIN_HEIGHT;
    }

    svg_text(TEXT_LEFT,top+BIN_HEIGHT+height_max, information_system());
    svg_end();
}
