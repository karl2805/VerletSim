#pragma once
#include <SFML/Graphics.hpp>

struct VerletSolver
{

	sf::Vector2f pos, vec, acc, new_pos, new_acc, new_vel;

	
		
	void update(float dt);

	void apply_forces();
};