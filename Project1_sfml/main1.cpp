#include <SFML/Graphics.hpp>

int main()
{
    int katObrotu = 0;
    sf::Clock zegar;//zegar start
    sf::Time czas;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(40.f,3);
    shape.setPosition(400, 300);
    shape.setFillColor(sf::Color::Cyan);
    shape.setRotation(katObrotu);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        czas = zegar.getElapsedTime();
        if (czas.asMilliseconds() > 100)
        {
            katObrotu += 20;
            zegar.restart();
        }
        
        shape.setRotation(katObrotu);
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}