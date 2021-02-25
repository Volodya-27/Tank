#ifndef BULLET_H
#define BULLET_H
using namespace sf;
using namespace std;

class Bullet
{
public:
	Bullet() ;

	int direction = 0;
	float dx_bullet = 0;
	float dy_bullet = 0, x, y;
	bool life;
	Texture b;
	Sprite bb;
	void sprite(float dxb, float dyb);
	void draw(RenderWindow& window);

};
#endif
