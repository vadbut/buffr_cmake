#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <dwmapi.h>

int main()
{
    sf::Image backgroundImage;
    backgroundImage.loadFromFile("media/background.png");

    sf::Texture backgroundTexture;
    sf::Texture im1_texture;
    sf::Texture im2_texture;

    sf::Sprite backgroundSprite;
    sf::Sprite im1;
    sf::Sprite im2;

    backgroundTexture.loadFromImage(backgroundImage);
    backgroundSprite.setTexture(backgroundTexture);

    im1_texture.loadFromFile("media/im1.png");
    im1.setTexture(im1_texture);
    im1.setPosition(100.f, backgroundImage.getSize().y / 2.f);

    im2_texture.loadFromFile("media/im2.png");
    im2.setTexture(im2_texture);
    im2.setPosition(400.f, backgroundImage.getSize().y / 2.f);

    sf::RenderWindow window(sf::VideoMode(backgroundImage.getSize().x, backgroundImage.getSize().y), "", sf::Style::None);

    MARGINS margins;
    margins.cxLeftWidth = -1;

    SetWindowLong(window.getSystemHandle(), GWL_STYLE, WS_POPUP | WS_VISIBLE);
    DwmExtendFrameIntoClientArea(window.getSystemHandle(), &margins);

    sf::Vector2i grabbedOffset;
    bool grabbedWindow = false;
    bool leftClickPressed = false;


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
                    leftClickPressed = true;
                    //const sf::Vector2u sz(1000, 2000);
                    //window.setSize(sz);
                }
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    grabbedWindow = false;
                    leftClickPressed = false;
                    //const sf::Vector2u sz(739,195);
                    //window.setSize(sz);
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
        window.draw(im1);
        if (leftClickPressed) { window.draw(im2); }
        window.display();
    }
}