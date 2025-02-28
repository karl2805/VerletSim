#pragma once
#include <SFML/Graphics.hpp>

class Ball : public sf::Transformable, public sf::Drawable
{

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
public:

    Ball(sf::Window& window);

    sf::Vector2f a, v;

    sf::CircleShape object;
};



void update_ball(float dt, Ball& ball);