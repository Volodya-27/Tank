#include<string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/Texture.hpp>
const int H = 1000;
const int W = 800;
#include"map.h"

Map::Map() {};//передбачається наявність стін тому робив класом
void Map::map1(RenderWindow& window)
{
	RectangleShape rectangle1(Vector2f(2, 2));
	rectangle1.setFillColor(Color(115, 134, 120));

	rectangle1.setTextureRect(IntRect(0, 0, 2, 2));
	rectangle1.setPosition(0, 0);
	rectangle1.setSize(Vector2f(H, 10));


	RectangleShape rectangle2(Vector2f(2, 2));
	rectangle2.setFillColor(Color(115, 134, 120));
	rectangle2.setPosition(0, 0);
	rectangle2.setSize(Vector2f(10, W));

	RectangleShape rectangle3(Vector2f(2, 2));
	rectangle3.setFillColor(Color(115, 134, 120));
	rectangle3.setPosition(H - 10, 0);
	rectangle3.setSize(Vector2f(10, W));

	RectangleShape rectangle4(Vector2f(2, 2));
	rectangle4.setFillColor(Color(115, 134, 120));
	rectangle4.setPosition(0, W - 10);
	rectangle4.setSize(Vector2f(H, 10));
	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(rectangle3);
	window.draw(rectangle4);
}
