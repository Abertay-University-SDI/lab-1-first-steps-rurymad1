#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	m_player.setRadius(50.f);
	m_player.setFillColor(sf::Color::Green);
	m_player.setPosition({ 300,300 });

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

}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_player);


	endDraw();
}

