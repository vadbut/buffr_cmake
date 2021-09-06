#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <dwmapi.h>

int main()
{
    sf::Image backgroundImage;
    backgroundImage.loadFromFile("media/login_back.png");

    sf::Texture backgroundTexture;

    sf::Sprite backgroundSprite;

    backgroundTexture.loadFromImage(backgroundImage);
    backgroundSprite.setTexture(backgroundTexture);

    sf::RenderWindow window(sf::VideoMode(backgroundImage.getSize().x, backgroundImage.getSize().y), "", sf::Style::None);

    MARGINS margins;
    margins.cxLeftWidth = -1;

    SetWindowLong(window.getSystemHandle(), GWL_STYLE, WS_POPUP | WS_VISIBLE);
    DwmExtendFrameIntoClientArea(window.getSystemHandle(), &margins);

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
                {
                    grabbedWindow = false;
                }
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                if (grabbedWindow)
                    window.setPosition(sf::Mouse::getPosition() + grabbedOffset);
            }
        }

        window.clear(sf::Color::Transparent);
        window.draw(backgroundSprite);
        window.display();
    }
}