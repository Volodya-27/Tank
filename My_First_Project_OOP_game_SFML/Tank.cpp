
#include<string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/Texture.hpp>

#include"Tank.h"

Tank::Tank() {}
void Tank::Sprite_Tank(string a)
{
	t.loadFromFile(a);
	s.setTexture(t);
	s.setTextureRect(IntRect(0, 0, 75, 75));
	s.setPosition(dx, dy);
	s.setScale(0.4, 0.4);
}
void Tank::Sprite_Tank_left(string a)
{
	t.loadFromFile(a);
	s.setTexture(t);
	s.setTextureRect(IntRect(0 + 77, 0, -77, 75));
	s.setPosition(dx, dy);
	s.setScale(0.4, 0.4);
}
void Tank::Sprite_Tank_Down(string a) {
	t.loadFromFile(a);
	s.setTexture(t);
	s.setTextureRect(IntRect(0, 0 + 75, 75, -75));
	s.setPosition(dx, dy);
	s.setScale(0.4, 0.4);
}
void Tank::draw(RenderWindow& window)
{
	window.draw(s);
}



