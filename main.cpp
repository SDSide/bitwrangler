#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdint>

struct Color {
    uint8_t r, g, b; // refactoring begins oh god
};


int setpixel(unsigned int x, unsigned int y, std::vector<std::uint8_t>& pixels, unsigned int width, const Color color) {
            std::size_t i = (y * width + x) * 4;    // index = (row offset * width + x offset) * 4 bytes.
            pixels[i + 0] = color.r;                // R
            pixels[i + 1] = color.g;                // G
            pixels[i + 2] = color.b;                // B
            pixels[i + 3] = 255;                    // A, no param leave default or die
    return 0;
}

int main() {

    // boilerplate window size shit. i really should pick a widescreen resolution.
    // const unsigned width = 320;
    // const unsigned height = 240;

    // 640*360 should be adequate for most displays. maybe ill make a 480*360 mode for 4:3 compat.
    const unsigned width = 640;
    const unsigned height = 360;

    sf::RenderWindow window(sf::VideoMode({width, height}), "bitwrangler window", sf::Style::Default);
    window.setVerticalSyncEnabled(true);

    // why the fuck does it need an alpha im this close to killing someone
    // yes we know the size of the array beforehand, its w * h * 4 bytes
    std::vector<std::uint8_t> pixels(width * height * 4);

    // lowkey an actually interesting loop. time to explain to myself so i dont forget. lmao.
    // -----------------------------
    // This iterates over every single pixel in the texture. for this texture, it's 320x240 by default.
    // y and x are defined as unsigned integers here, as they are never used outside the scope.
    // this is essentially the same principle as i used to use in turbowarp to make 2d arrays sooo
    // i + 0 is the red component of the pixel
    // i + 1 is green
    // i + 2 is blue
    // i + 3 is irrelevant. keep at 255 please. genuinely fuckin evil if u dont.
    //
    // basically whatever you define y and x as, you can edit the individual rgb(a) values :D
    // -----------------------------

    for (unsigned y = 0; y < height; ++y) {         // ITERATE OVER COLUMNS
        for (unsigned x = 0; x < width; ++x) {      // ITERATE OVER ROWS
            std::size_t i = (y * width + x) * 4;    // index = (row offset * width + x offset) * 4 bytes.
            pixels[i + 0] = x*4 % 256;              // R, btw mod 256 because it is 256 EXCLUSIVE, not 255 as that causes artifacts
            pixels[i + 1] = y*4 % 256;              // G
            pixels[i + 2] = x*8 % 128;              // B
            pixels[i + 3] = 255;                    // A
        }
    }

    setpixel(2, 2, pixels, width, Color{127, 0, 0}); // structs are very cool!
    setpixel(3, 2, pixels, width, Color{127, 0, 0}); // structs are very cool!
    setpixel(2, 3, pixels, width, Color{127, 0, 0}); // structs are very cool!
    setpixel(3, 3, pixels, width, Color{127, 0, 0}); // structs are very cool!

    // FIGURED OUT HOW TEXTURES WORK!!!
    // creates texture which fills the screen ofc
    sf::Texture texture({width, height});

    // upload pixels
    // i dont actually know what this fart does...
    texture.update(pixels.data(), {width, height}, {0, 0});

    sf::Sprite sprite(texture);

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}
