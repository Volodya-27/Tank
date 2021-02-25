#include<string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/Texture.hpp>
#include"Bullet.h"
Bullet::Bullet() {};
void Bullet::sprite(float dxb, float dyb) {
	b.loadFromFile("C:\\Users\\linec\\source\\repos\\My_First_Project_OOP_game_SFML\\fila\\bullets.PNG");
	bb.setTexture(b);
	bb.setTextureRect(IntRect(0, 0, 25, 25));
	bb.setScale(0.4, 0.4);
	bb.setPosition(dxb, dyb);
	dx_bullet = dxb;
	dy_bullet = dyb;
}
void Bullet::draw(RenderWindow& window)
{
	window.draw(bb);
}
