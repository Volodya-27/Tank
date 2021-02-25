#include<vector>
#include<string>
#include<map>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Export.hpp>
#include <list>
#include<Windows.h>
#include<iostream>
#include <vector>
#include<fstream>
using namespace sf;
using namespace std;
#include"Bot.h"



Tank_bot::Tank_bot() {
	 dx_bot = 500; dy_bot = 500;
}

void Tank_bot::Sprite_Tank(string a)
{
	t_bot.loadFromFile(a);//вверх
	s_bot.setTexture(t_bot);
	s_bot.setTextureRect(IntRect(0, 0, 75, 75));
	s_bot.setPosition(dx_bot, dy_bot);
	s_bot.setScale(0.4, 0.4);
}
void Tank_bot::Sprite_Tank_left(string a)
{
	t_bot.loadFromFile(a);//вверх
	s_bot.setTexture(t_bot);
	s_bot.setTextureRect(IntRect(0 + 77, 0, -77, 75));
	s_bot.setPosition(dx_bot, dy_bot);
	s_bot.setScale(0.4, 0.4);
}
void Tank_bot::Sprite_Tank_Down(string a)
{
	t_bot.loadFromFile(a);//вверх
	s_bot.setTexture(t_bot);
	s_bot.setTextureRect(IntRect(0, 0 + 75, 75, -75));
	s_bot.setPosition(dx_bot, dy_bot);
	s_bot.setScale(0.4, 0.4);
}
void Tank_bot::draw(RenderWindow& window)
{
	window.draw(s_bot);
}













