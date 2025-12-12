#ifndef RENDER_HPP
#define RENDER_HPP

#include <vector>
#include <cstdint>

void setpixel(unsigned, unsigned,
              std::vector<uint8_t>&,
              unsigned,
              uint8_t);

#endif