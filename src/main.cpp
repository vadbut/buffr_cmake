#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main()
{
    const sf::Color windowColor{ sf::Color(0, 0, 0, 0) };
    const sf::Color windowColorGrabbed{ sf::Color(255, 255, 0, 64) };

    sf::RenderWindow window(sf::VideoMode(800, 600), "", sf::Style::None);

    sf::Vector2i grabbedOffset;
    bool grabbedWindow = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    grabbedOffset = window.getPosition() - sf::Mouse::getPosition();
                    grabbedWindow = true;
            }
    }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                    grabbedWindow = false;
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                if (grabbedWindow)
                    window.setPosition(sf::Mouse::getPosition() + grabbedOffset);
            }
}
        sf::Color clearColor{ windowColor };
        if (grabbedWindow)
            clearColor = windowColorGrabbed;
        
        window.clear(clearColor);
        window.display();
    }
}