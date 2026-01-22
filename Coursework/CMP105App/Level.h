#pragma once

#include "Framework/BaseLevel.h"

class Level : BaseLevel{
public:
	Level(sf::RenderWindow& window, Input& input);
	~Level() override = default;

	

	void handleInput(float dt) override;
	void update(float dt);
	void render();

private:
	enum class cDirection { Left, Right, Up, Down };
	cDirection m_cDirection;
	void spawnFood();
	sf::CircleShape m_player;
	sf::CircleShape m_food;
	float m_speed = 200.f;
	bool m_GameOver = false;
	
	// Default functions for rendering to the screen.

	// Default variables for level class.
	
};