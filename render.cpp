#include "headers/render.hpp"
#include <vector>
#include <cstdint>

void setpixel(unsigned x, unsigned y,
              std::vector<uint8_t>& framebuffer,
              unsigned width,
              uint8_t colorIndex) {
    if (colorIndex != 0) {
        framebuffer[y * width + x] = colorIndex;
    }
}
