#ifndef RENDER_HPP
#define RENDER_HPP

#include <vector>
#include <cstdint>
#include <string>

// FOR ALL YOU PRICKS WONDERING WHY I HAVE THE FUCKIN NAMES IN HERE TOO...
// ITS SO I REMEMBER THEM :BRUH:

void setpixel(unsigned x, unsigned y,
              std::vector<uint8_t>& framebuffer,
              unsigned width,
              uint8_t colorIndex);

void renderquad(unsigned x0, unsigned y0,
                std::vector<uint8_t>& framebuffer,
                unsigned rectW,
                unsigned rectH,
                unsigned fbW,
                unsigned fbH,
                uint8_t colorIndex);

void renderimage(
    unsigned x0, unsigned y0,
    std::vector<uint8_t>& framebuffer,
    unsigned rectW,
    unsigned rectH,
    int fbW,
    int fbH,
    const std::vector<uint16_t>& image,
    bool flipX,
    bool flipY,
    int headersize
);

float clip(float n, float lower, float upper);

void loadimage(const std::string& filename,
               std::vector<uint16_t>& array,
               uint16_t width,
               uint16_t height,
               int headersize);

#endif