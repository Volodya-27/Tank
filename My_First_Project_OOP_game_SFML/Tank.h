#ifndef TANK_H
#define TANK_H
using namespace sf;
using namespace std;
class Tank
{
protected:
	float dx = 100, dy = 100;
	sf::Texture t;
	sf:: Sprite s;
public:
	Tank();
	void Sprite_Tank(string a);
	void Sprite_Tank_left(string a);
	void Sprite_Tank_Down(string a);
	void draw(RenderWindow& window);
};
#endif