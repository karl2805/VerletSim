#include "ball_object.hpp"
#include <random>
#include <SFML/Graphics.hpp>
#include <cmath>

const float outline_thickness = 1;

const float ball_radius = 100;

//random number generator for random colour
std::random_device rd;
std::uniform_int_distribution<int> dist(0, 255);

Ball::Ball(sf::Window& window)
{

    object.setRadius(ball_radius);
    //defalt position of ball middle of screen
    object.setOrigin(sf::Vector2f({ 100,100 }));
    object.setPosition(sf::Vector2f({ static_cast<float>(window.getSize().x / 2), static_cast<float>(window.getSize().y / 2) }));



    object.setPointCount(1000);

    //give random colour
    object.setFillColor(sf::Color(dist(rd), dist(rd), dist(rd), dist(rd)));

    //outline of ball
    object.setOutlineColor(sf::Color::Black);
    object.setOutlineThickness(outline_thickness);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    
    states.transform *= getTransform(); 

    target.draw(object, states);
}
