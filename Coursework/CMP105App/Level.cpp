#include "Level.h"

void Level::spawnFood()
{
	float x = rand() % m_window.getSize().x;
	float y = rand() % m_window.getSize().y;
	m_food.setPosition({ x, y });
}

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	m_player.setRadius(20.f);
	m_player.setFillColor(sf::Color::Green);
	m_player.setPosition({ 300,300 });

	m_food.setRadius(10.f);
	m_food.setFillColor(sf::Color::Red);
	spawnFood();

	// initialise game objects

}



// handle user input
void Level::handleInput(float dt)
{
	if (m_input.isLeftMousePressed())
	{
		std::cout << "left mouse pressed" << std::endl;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::D)) {

		std::cout << "d pressed" << std::endl;
		m_cDirection = cDirection::Right;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::A)) {

		std::cout << "a pressed" << std::endl;
		m_cDirection = cDirection::Left;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::W)) {

		std::cout << "w pressed" << std::endl;
		m_cDirection = cDirection::Up;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::S)) {

		std::cout << "s pressed" << std::endl;
		m_cDirection = cDirection::Down;
	}

}

// Update game objects
void Level::update(float dt)
{
	if (m_GameOver) return; 

	switch (m_cDirection) {

		case cDirection::Left: {
			//move left
			m_player.move({ -m_speed * dt, 0.f });
			break;
		}
		case cDirection::Right: {
			//move right
			m_player.move({m_speed * dt,0.f });
			break;
		}
		case cDirection::Up: {
			//move up
			m_player.move({0.f,-m_speed * dt});
			break;
		}
		case cDirection::Down: {
			//move Down
			m_player.move({ 0.f,m_speed * dt });
			break;
		}
	}

	sf::Vector2f Position = m_player.getPosition();
	sf::Vector2 Border = m_window.getSize();
	float Radius = m_player.getRadius();

	if (Position.x>Border.x - Radius * 2|| Position.x<0 || Position.y>Border.y - Radius * 2 || Position.y<0) {
		std::cout << "outside" << std::endl;

		m_player.setPosition({ Border.x * 0.5f,Border.y * 0.5f });
	}

	float xDistance = (Position.x + Radius) - (m_food.getPosition().x + m_food.getRadius());
	float YDistance = (Position.y + Radius) - (m_food.getPosition().y + m_food.getRadius());

	float SquaredDistance = (xDistance * xDistance) + (YDistance * YDistance);
	float RadiusSum = Radius + m_food.getRadius();
	if (SquaredDistance < RadiusSum * RadiusSum)
	{
		spawnFood();
		m_speed = m_speed*1.1f;
	}

}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_player);
	m_window.draw(m_food);


	endDraw();
}

