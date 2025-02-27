#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "window_events.hpp"


float outline_thickness = 1;

float ball_radius = 100;

//random number generator for random colour
std::random_device rd;
std::uniform_int_distribution<int> dist(0, 255);

class Ball : public sf::Transformable, public sf::Drawable
{

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        // apply the entity's transform -- combine it with the one that was passed by the caller
        states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

        target.draw(object, states);
    }
    

public:

    Ball(sf::Window& window);

    sf::Vector2f a, v;

    

    sf::CircleShape object{ ball_radius };
};

Ball::Ball(sf::Window& window)
{
        //defalt position of ball
        object.setOrigin(sf::Vector2f({ 100,100 }));
        object.setPosition(sf::Vector2f({ static_cast<float>(window.getSize().x / 2), static_cast<float>(window.getSize().y / 2) }));

        object.setPointCount(1000);
        //give random colour
        object.setFillColor(sf::Color(dist(rd), dist(rd), dist(rd), dist(rd)));

        //outline of ball
        object.setOutlineColor(sf::Color::Black);
        object.setOutlineThickness(outline_thickness);
}

void update_ball(float dt, Ball& ball)
    {
        ball.move(sf::Vector2f({ball.v}));

        ball.v += ball.a * dt;
    }

int main()
{

    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "SFML shapes", sf::Style::Default, sf::State::Windowed, settings);
    window.setFramerateLimit(144);

  

    
    
    Ball ball(window);
    
   
    
    //ball.v = sf::Vector2f(2,5);
   // ball.a = sf::Vector2f(0,4);
   
    sf::Clock clock;

    while (window.isOpen())
    {
        processevents(window);


        window.clear(sf::Color(50.2,50.2,50.,50.2));
        float dt = clock.restart().asSeconds();

        
        
        update_ball(dt, ball);
        window.draw(ball);
        window.display();

        
    }
}
