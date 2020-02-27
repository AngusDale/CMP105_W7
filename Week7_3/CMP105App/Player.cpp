#include "Player.h"

Player::Player()
{
	setPosition(200, 200);
	setSize(sf::Vector2f(100, 100));	
	
	// initialises all the bullets
	for (int i = 0; i < MAX_BULL; i++) {
		bullets[i] = NULL;
	}
}


Player::~Player()
{
	
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		input->setKeyUp(sf::Keyboard::Space);
		int x = rand() % 600;
		int y = rand() % 400;
		setPosition((float)x, (float)y);
	}

	if (input->isKeyDown(sf::Keyboard::Enter))
	{	
		input->setKeyUp(sf::Keyboard::Enter);
		// find space for a bullet, creates a new one once space is found and then fires it, then breaks the for loop.
		for (int i = 0; i < MAX_BULL; i++) {
			if (bullets[i] == NULL) {
				bullets[i] = new Bullet;
				bullets[i]->setPosition(getPosition() + sf::Vector2f(getSize().x / 2, getSize().y / 2));
				break;
			}
		}		
	}
}

void Player::update(float dt) 
{
	// updates all the bullets positions
	for (int i = 0; i < MAX_BULL; i++) {
		if (bullets[i] != NULL) {
			bullets[i]->update(dt);
		}
	}
}

void Player::drawBullets(sf::RenderWindow* window) {
	// draws all the bullets
	for (int i = 0; i < MAX_BULL; i++) {
		if (bullets[i] != NULL) {
			window->draw(*(bullets[i]));
		}
	}
}