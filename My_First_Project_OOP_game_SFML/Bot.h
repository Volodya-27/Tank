#ifndef BOT_H
#define BOT_H
using namespace sf;
using namespace std;

class Tank_bot
{
	
public:
	Tank_bot();
	float dx_bot, dy_bot;
	Texture t_bot;
	Sprite s_bot;
	void Sprite_Tank(string a);
	void Sprite_Tank_left(string a);
	void Sprite_Tank_Down(string a);
	void draw(RenderWindow& window);
};

#endif
