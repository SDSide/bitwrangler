// all library used
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // x and y of retagle

    // window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "window");

    // retangle
    sf::RectangleShape rectangle({300.f, 300.f});

    // retagl origin
    rectangle.setOrigin({150.f, 150.f});

    // trnformat
    rectangle.setPosition({300.f, 300.f});
    
    // fill
    rectangle.setFillColor(sf::Color{127, 0, 127});
    rectangle.setOutlineThickness({-3.f});
    rectangle.setOutlineColor(sf::Color{0, 0, 127});

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
                sf::View view({400.f, 300.f}, sf::Vector2f(window.getSize()));
                window.setView(view);
            }
        }

        // fill window color
        window.clear(sf::Color(127, 0, 0));
        window.draw(rectangle);
        window.display();
    }

    return 0;
}