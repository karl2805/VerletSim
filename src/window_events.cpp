#include "window_events.hpp"
#include <SFML/Graphics.hpp>

void processevents(sf::Window& window)
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
    }
}