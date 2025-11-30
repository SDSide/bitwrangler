// all library used
#include <SFML/Graphics.hpp>
#include <iostream>

sf::Sprite sprite;
sf::RectangleShape shape;
sf::Text text;

int main()
{
    // Create a new render-window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");

    // Create a new render-texture
    sf::RenderTexture texture({500, 500});

    // The main loop
    while (window.isOpen())
    {
       // Event processing
       // ...

       // Clear the whole texture with red color
       texture.clear(sf::Color::Red);

       // Draw stuff to the texture
       texture.draw(sprite);  // sprite is a sf::Sprite
       texture.draw(shape);   // shape is a sf::Shape
       texture.draw(text);    // text is a sf::Text

       // We're done drawing to the texture
       texture.display();

       // Now we start rendering to the window, clear it first
       window.clear();

       // Draw the texture
       sf::Sprite sprite(texture.getTexture());
       window.draw(sprite);

       // End the current frame and display its contents on screen
       window.display();
    }
}   