#include "ball_object.hpp"
#include <SFML/Graphics.hpp>

struct VerletSolver
{
	
	void update(float dt)
	{
		new_pos = pos + vel * dt + (0.5) * acc * dt * dt;
		new_acc = apply_forces();
		new_vel = vel + (0.5 * dt)(acc + new_acc);
		
		pos = new_pos;
		acc = new_acc;
		vel = new_vel;
	}

	void apply_forces()
	{
		new_acc = sf::Vector2f({ 0,-1000 });
	}
};

