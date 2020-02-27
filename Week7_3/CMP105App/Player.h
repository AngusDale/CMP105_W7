#pragma once

#include "Framework/GameObject.h"
#include "Bullet.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt);
	void update(float dt);

	void drawBullets(sf::RenderWindow* window);

	/*Bullet* getBullet() {
		return bullet;
	};*/

protected:
	//Bullet* bullet;
	static const int MAX_BULL = 20;
	Bullet* bullets[MAX_BULL];

};