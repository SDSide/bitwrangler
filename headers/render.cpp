#include "render.hpp"
#include <vector>
#include <cstdint>
#include <iostream>
#include <fstream>

void setpixel(unsigned x, unsigned y,
              std::vector<uint8_t>& framebuffer,
              unsigned width,
              uint8_t colorIndex) {
    if (colorIndex != 0) {
        framebuffer[y * width + x] = colorIndex;
    }
}

void renderquad(unsigned x0, unsigned y0,
                std::vector<uint8_t>& framebuffer,
                unsigned rectW,
                unsigned rectH,
                unsigned fbW,
                unsigned fbH,
                uint8_t colorIndex) {
    for (unsigned y = y0; y < y0 + rectH; ++y) {
        for (unsigned x = x0; x < x0 + rectW; ++x) {
            if (x < fbW && y < fbH)
                setpixel(x, y, framebuffer, fbW, colorIndex);
        }
    }
}

// fix this fucking function when u get home im so fucking tired bro
void renderimage(
    unsigned x0, unsigned y0,
    std::vector<uint8_t>& framebuffer,
    unsigned rectW,
    unsigned rectH,
    int fbW,
    int fbH,
    const std::vector<uint16_t>& image,   // palette indices
    bool flipX,
    bool flipY,
    int headersize
) {
    for (unsigned iy = 0; iy < rectH; ++iy) {
        for (unsigned ix = 0; ix < rectW; ++ix) {

            unsigned fbX = x0 + ix;
            unsigned fbY = y0 + iy;

            if (fbX < fbW && fbY < fbH) {

                int rx = flipX ? (rectW - 1 - ix) : ix;  // read-from index, flipped or not

                uint16_t colorIndex = image[iy * rectW + rx + headersize];

                setpixel(fbX, fbY, framebuffer, fbW, colorIndex);
            }
        }
    }
}

float clip(float n, float lower, float upper) {
  return std::max(lower, std::min(n, upper));
}


void loadimage(const std::string& filename,
               std::vector<uint16_t>& array,
               uint16_t width,
               uint16_t height,
               int headersize)
{
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open: " << filename << "\n";
        return;
    
    }


    // allocate the space we will write into, +2 is size of image header, will make image format more elaborate at later date.
    array.resize(width * height + headersize);

    // loop header length!!!
    for (int i = 0; i < headersize; ++i) {
        file >> array[i];
    }

    for (uint16_t y = 0; y < height; ++y) {
        for (uint16_t x = 0; x < width; ++x) {
            file >> array[headersize + y * width + x];
        }
    }

    std::cout << "Image size: " << array[0] << ", " << array[1] << "\n";

    int n = array.size();

    std::cout << "Array Elements: ";
    for (int i = 0; i < n - headersize; i++)
        std::cout << array[i + headersize] << " ";
    std::cout << "\n";
    std::cout << n;
    std::cout << "\n";
}