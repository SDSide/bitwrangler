// all library used
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdint>

unsigned int WIDTH = 800.f;
unsigned int HEIGHT = 600.f;

sf::Texture texture(sf::Vector2u(WIDTH, HEIGHT));

int main()
{
    sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "window");

    // loop
    while (window.isOpen())
    {
        // events
        while (std::optional event = window.pollEvent())
        {
            // close button click
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (event->is<sf::Event::Resized>())
            {
                sf::View view({WIDTH/2, HEIGHT/2}, sf::Vector2f(window.getSize()));
                window.setView(view);
            }
        }
        window.clear(sf::Color(127, 127, 127));
        window.display();
    }

    return 0;
}