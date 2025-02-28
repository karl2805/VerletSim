#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "window_events.hpp"
#include "ball_object.hpp"
#include "Engine.hpp"


int main()
{

    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "SFML shapes", sf::Style::Default, sf::State::Windowed, settings);
    window.setFramerateLimit(144);

    //create a ball and verlet object
    Ball ball(window);

    VerletSolver solver;

    
   
    sf::Clock clock;

    while (window.isOpen())
    {
        processevents(window);


        window.clear(sf::Color(50.2,50.2,50.,50.2));
        float dt = clock.restart().asSeconds();

        
        
        
        

        
        window.draw(ball);

        window.display();

        
    }
}
