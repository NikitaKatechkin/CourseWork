#include "Bar.h"
#include "ActiveItem.h"
#include "Text.h"
#include "ButtomPanel.h"

int main()
{
    sf::RenderWindow window(
        sf::VideoMode(640, 480), "SFML works!");
    
    ButtomPanel panel(sf::Vector2f(float(window.getSize().x), 120.0f));
    
    panel.SetAlign(BAR_ALIGN::BUTTOM);
    panel.SetPosition(sf::Vector2f(0.0f, float(window.getSize().y)));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        panel.Draw(window);

        window.display();
    }

	return 0;
}