#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Export.hpp>
#include <SFML/Audio.hpp>
#include<Windows.h>
#include<iostream>
#include<fstream>

using namespace sf;
using namespace std;

#include"Tank.h"
#include"Bullet.h"
#include"map.h"
#include"Bot.h"

const int H = 1000;
const int W = 800;


class Header_class_tank_player : public Tank, public Map, public Tank_bot
{
protected:
	Tank_bot g2;
	
	Sound sound;
	SoundBuffer buffer;
	Bullet b_tank;
	Bullet b_bot;
	string up;
	float dyd_tank;
	float dxd_tank;
	float dxd_tank_bot;
	float dyd_tank_bot;
	float timer;
	int dlinapyli;
	int Sprite_tank_lenght;
	string right;
	float speedTank;
	float speedTank_bot;
	float speedBullet;
	float bot_speedBullet;

	int cnt;
	int cnt_bot1;
	int cnt_bot2;
	int rand_move;
	bool move_in_shoot;

	bool die_the_bot;
	bool end_game;
	bool shoot;
	bool move_player_right;
	bool move_player_left;
	bool move_player_up;
	bool move_player_down;

public:
	Header_class_tank_player()
	{
		
		buffer.loadFromFile("C:\\Users\\linec\\source\\repos\\My_First_Project_OOP_game_SFML\\fila\\bah3.ogg");
		sound.setBuffer(buffer);
		move_player_right = true;
		move_player_left = true;
		move_player_up = true;
		move_player_down = true;
		shoot = false;
		die_the_bot = false;
		end_game = false;
		timer = 0;
		up = "C:\\Users\\linec\\source\\repos\\My_First_Project_OOP_game_SFML\\fila\\up.png";
		right = "C:\\Users\\linec\\source\\repos\\My_First_Project_OOP_game_SFML\\fila\\right.png";
		dyd_tank = 100;
		dxd_tank = 100;
		dxd_tank_bot = 500;
		dyd_tank_bot = 500;
		Tank::Sprite_Tank(up);
		Tank_bot::Sprite_Tank(up);
		rand_move = 0;
		dlinapyli = 4000;
		Sprite_tank_lenght = 44;
		speedTank = 0.05;
		speedTank_bot = 0.05;
		speedBullet = 0.8;
		bot_speedBullet = 0.8;
		move_in_shoot = false;
		cnt = 0;
		cnt_bot1 = 0;
		cnt_bot2 = 0;
	}
	void knocks_tank_and_tank()
	{
		//right
		if ((int)s.getPosition().x + 30 == (int)s_bot.getPosition().x && (int)s.getPosition().y > (int)s_bot.getPosition().y && (int)s.getPosition().y < (int)s_bot.getPosition().y + 30)
			move_player_right = false;
		//down
		if ((int)s.getPosition().y + 27 == (int)s_bot.getPosition().y && (int)s.getPosition().x > (int)s_bot.getPosition().x && (int)s.getPosition().x < (int)s_bot.getPosition().x + 27)
			move_player_down = false;
		//up		
		if ((int)s.getPosition().y == (int)s_bot.getPosition().y + 27 && (int)s.getPosition().x > (int)s_bot.getPosition().x && (int)s.getPosition().x < (int)s_bot.getPosition().x + 27)
			move_player_up = false;
		//left
		if ((int)s.getPosition().x == (int)s_bot.getPosition().x + 30 && (int)s.getPosition().y > (int)s_bot.getPosition().y && (int)s.getPosition().y < (int)s_bot.getPosition().y + 30)
			move_player_left = false;
	}
	void hit_the_wal()
	{
		if ((int)dy == W - Sprite_tank_lenght)
		{
			dy = W - Sprite_tank_lenght;
			dyd_tank = -((W - Sprite_tank_lenght) - 200);
		}
		if ((int)dx == H - Sprite_tank_lenght)
		{
			dx = H - 44;
			dxd_tank = -((H - Sprite_tank_lenght) - 200);
		}
		if ((int)dxd_tank == 188)
		{
			dx = 12;
			dxd_tank = 188;
		}
		if ((int)dyd_tank == 185)
		{
			dy = 13;
			dyd_tank = 185;
		}
		//cout << dyd_tank << endl;
	}
	void hit_the_wal_bot()
	{
		if ((int)dy_bot == W - Sprite_tank_lenght)
		{
			dy_bot = W - Sprite_tank_lenght;
			dyd_tank = -((W - Sprite_tank_lenght) - 200);
		}
		if ((int)dx_bot == H - Sprite_tank_lenght)
		{
			dx_bot = H - 44;
			dxd_tank_bot = -((H - Sprite_tank_lenght) - 200);
		}
		if ((int)dxd_tank_bot == 988)
		{
			dx_bot = 12;
			dxd_tank_bot = 988;

		}
		if ((int)dyd_tank_bot == 986)
		{
			dy_bot = 13;
			dyd_tank_bot = 986;
		}
		//cout << dyd_tank_bot << endl;

	}
	void Right(float speedTank_, bool move_in_shot_)
	{
		Tank::Sprite_Tank(right);
		dx += speedTank_;
		if (move_in_shot_ == true)
			cnt = 1;
		dxd_tank -= speedTank_;
	}
	void Left(float speedTank_, bool move_in_shot_)
	{
		Tank::Sprite_Tank_left(right);
		dx -= speedTank_;
		if (move_in_shot_ == true)
			cnt = 2;
		dxd_tank += speedTank_;
	}
	void Up(float speedTank_, bool move_in_shot_)
	{
		Tank::Sprite_Tank(up);
		dy -= speedTank_;
		if (move_in_shot_ == true)
			cnt = 3;
		dyd_tank += speedTank_;
	}
	void Down(float speedTank_, bool move_in_shot_)
	{
		Tank::Sprite_Tank_Down(up);
		dy += speedTank_;
		if (move_in_shot_ == true)
			cnt = 4;
		dyd_tank -= speedTank_;
	}
	void Shoot(RenderWindow& window)
	{
		switch (cnt)
		{
		case 1:	b_tank.sprite(dx + 30, dy + 10); break;
		case 2: b_tank.sprite(dx - 10, dy + 10); break;
		case 3: b_tank.sprite(dx + 10, dy - 10);  break;
		case 4:	b_tank.sprite(dx + 10, dy + 30); break;
		default:
			break;
		}
		for (size_t i = 0; i < dlinapyli; i++)
		{
			shoot = true;
			switch (cnt)
			{
			case 1:b_tank.bb.move(speedBullet, 0);
				b_tank.dx_bullet += speedBullet;
				if (Keyboard::isKeyPressed(Keyboard::Right)) Right(speedTank, true);
				else if (Keyboard::isKeyPressed(Keyboard::Left)) Left(speedTank, false);
				else if (Keyboard::isKeyPressed(Keyboard::Up)) Up(speedTank, false);
				else if (Keyboard::isKeyPressed(Keyboard::Down)) Down(speedTank, false);
				break;
			case 2:b_tank.bb.move(-speedBullet, 0); b_tank.dx_bullet -= speedBullet;
				if (Keyboard::isKeyPressed(Keyboard::Left)) Left(speedTank, true);
				else if (Keyboard::isKeyPressed(Keyboard::Right)) Right(speedTank, false);
				else if (Keyboard::isKeyPressed(Keyboard::Up)) Up(speedTank, false);
				else if (Keyboard::isKeyPressed(Keyboard::Down)) Down(speedTank, false);
				break;
			case 3:b_tank.bb.move(0, -speedBullet); b_tank.dy_bullet -= speedBullet;
				if (Keyboard::isKeyPressed(Keyboard::Up)) Up(speedTank, true);
				else if (Keyboard::isKeyPressed(Keyboard::Right)) Right(speedTank, false);
				else if (Keyboard::isKeyPressed(Keyboard::Left)) Left(speedTank, false);
				else if (Keyboard::isKeyPressed(Keyboard::Down)) Down(speedTank, false);
				break;
			case 4:b_tank.bb.move(0, speedBullet); b_tank.dy_bullet += speedBullet;
				if (Keyboard::isKeyPressed(Keyboard::Down)) Down(speedTank, true);
				else if (Keyboard::isKeyPressed(Keyboard::Right)) Right(speedTank, false);
				else if (Keyboard::isKeyPressed(Keyboard::Left)) Left(speedTank, false);
				else if (Keyboard::isKeyPressed(Keyboard::Up)) Up(speedTank, false);
				break;
			default:
				break;
			}
			hit_the_wal();

			if ((int)b_tank.bb.getPosition().x == (int)s_bot.getPosition().x + 25 && b_tank.bb.getPosition().y< s_bot.getPosition().y + 25 //попадання в танк
				&& b_tank.bb.getPosition().y> s_bot.getPosition().y ||
				b_tank.bb.getPosition().x > s_bot.getPosition().x && b_tank.bb.getPosition().x < s_bot.getPosition().x + 25 && (int)b_tank.bb.getPosition().y == s_bot.getPosition().y)
			{
				die_the_bot = true;
				end_game = false;
				break;
			}

			if ((int)b_tank.bb.getPosition().y == (int)s_bot.getPosition().y + 25 && b_tank.bb.getPosition().x< s_bot.getPosition().x + 25 //попадання в танк
				&& b_tank.bb.getPosition().x> s_bot.getPosition().x
				|| b_tank.bb.getPosition().x > s_bot.getPosition().x && b_tank.bb.getPosition().x < s_bot.getPosition().x + 25 &&
				b_tank.bb.getPosition().y > s_bot.getPosition().y && b_tank.bb.getPosition().y < s_bot.getPosition().y + 25 && (int)b_tank.bb.getPosition().x == s_bot.getPosition().x)
			{
				die_the_bot = true;
				end_game = false;
				break;
			}

			if ((int)b_tank.dy_bullet == W - 20 + 6)
				break;
			if ((int)b_tank.dx_bullet == H - 20 + 6)
				break;
			if ((int)b_tank.dx_bullet == 15 - 15)
				break;
			if ((int)b_tank.dy_bullet == 15 - 15)
				break;

			if (die_the_bot == false)
			{
				move_bot1(window);
			}



			window.clear();

			map1(window);
			Tank::draw(window);
			if (die_the_bot == false)
			{
				Tank_bot::draw(window);
				//break;
			}
			b_tank.draw(window);
			window.display();
		}
		shoot = false;
	}
	void movePlayer()
	{
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			if (move_player_right == true)
				Right(speedTank, true);
			move_player_down = true;
			move_player_up = true;
			move_player_left = true;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			if (move_player_left == true)
				Left(speedTank, true);
			move_player_right = true;
			move_player_down = true;
			move_player_up = true;

		}
		else if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (move_player_up == true)
				Up(speedTank, true);
			move_player_left = true;
			move_player_right = true;
			move_player_down = true;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (move_player_down == true)
				Down(speedTank, true);
			move_player_right = true;
			move_player_up = true;
			move_player_left = true;

		}
		knocks_tank_and_tank();
		hit_the_wal();
	}
	void move_shoot(RenderWindow& window)
	{
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			sound.play();
			Shoot(window);
		}
	}
	void shoot_bot(RenderWindow& window)
	{
		sound.play();

		switch (cnt_bot2)         //пуля приймає позицію башні танка
		{
		case 1:	b_bot.sprite(dx_bot + 30, dy_bot + 10); break;
		case 2: b_bot.sprite(dx_bot - 10, dy_bot + 10); break;
		case 3: b_bot.sprite(dx_bot + 10, dy_bot - 10);  break;
		case 4: b_bot.sprite(dx_bot + 10, dy_bot + 30); break;
		default:
			break;
		}
		for (size_t i = 0; i < 5000; i++)
		{
			switch (cnt_bot1)
			{
			case 1:b_bot.bb.move(bot_speedBullet, 0);
				b_bot.dx_bullet += bot_speedBullet;
				Tank_bot::Sprite_Tank(right);
				dx_bot += speedTank_bot;
				dxd_tank_bot -= speedTank_bot;
				cnt_bot2 = 1;
				break;
			case 2:b_bot.bb.move(-bot_speedBullet, 0);
				b_bot.dx_bullet -= bot_speedBullet;
				Tank_bot::Sprite_Tank_left(right);
				dx_bot -= speedTank_bot;
				dxd_tank_bot += speedTank_bot;
				cnt_bot2 = 2;
				break;

			case 3:b_bot.bb.move(0, -bot_speedBullet);
				b_bot.dy_bullet -= bot_speedBullet;

				Tank_bot::Sprite_Tank(up);
				dy_bot -= speedTank_bot;
				dyd_tank_bot += speedTank_bot;
				cnt_bot2 = 3;

				break;

			case 4:b_bot.bb.move(0, bot_speedBullet);
				b_bot.dy_bullet += bot_speedBullet;

				Tank_bot::Sprite_Tank_Down(up);
				dy_bot += speedTank_bot;
				dyd_tank_bot -= speedTank_bot;
				cnt_bot2 = 4;
				break;
			default:
				break;
			}
			if ((int)b_bot.dy_bullet == W - 20 + 6)break;
			if ((int)b_bot.dx_bullet == H - 20 + 6)break;
			if ((int)b_bot.dx_bullet == 15 - 15)break;
			if ((int)b_bot.dy_bullet == 15 - 15)break;
			hit_the_wal_bot();

			if ((int)b_bot.bb.getPosition().x == (int)s.getPosition().x + 25 && b_bot.bb.getPosition().y< s.getPosition().y + 25 //попадання в танк
				&& b_bot.bb.getPosition().y> s.getPosition().y ||
				b_bot.bb.getPosition().x > s.getPosition().x && b_bot.bb.getPosition().x < s.getPosition().x + 25 && (int)b_bot.bb.getPosition().y == s.getPosition().y)
			{
				end_game = true;
				break;
			}

			if ((int)b_bot.bb.getPosition().y == (int)s.getPosition().y + 25 && b_bot.bb.getPosition().x< s.getPosition().x + 25 //попадання в танк
				&& b_bot.bb.getPosition().x> s.getPosition().x
				|| b_bot.bb.getPosition().x > s.getPosition().x && b_bot.bb.getPosition().x < s.getPosition().x + 25 &&
				b_bot.bb.getPosition().y > s.getPosition().y && b_bot.bb.getPosition().y < s.getPosition().y + 25 && (int)b_bot.bb.getPosition().x == s.getPosition().x)
			{
				end_game = true;
				break;
			}

			movePlayer();
			cout << b_bot.bb.getPosition().y << "             " << b_tank.bb.getPosition().y << endl;
			window.clear();
			map1(window);
			Tank::draw(window);
			if (die_the_bot == false)
			{
				Tank_bot::draw(window);
				b_bot.draw(window);
			}
			window.display();
		}

	}
	void bot_eyes(RenderWindow& window)
	{
		if (die_the_bot == false)
		{
			switch (cnt_bot1)
			{
			case 1: if (s.getPosition().y + 25 > s_bot.getPosition().y && s.getPosition().y < s_bot.getPosition().y + 25 && (int)dx >(int)dx_bot && shoot == false)shoot_bot(window);
				break;
			case 2: if (s.getPosition().y + 25 > s_bot.getPosition().y && s.getPosition().y < s_bot.getPosition().y + 25 && (int)dx < (int)dx_bot && shoot == false) shoot_bot(window);
				break;
			case 3: if (s.getPosition().x + 25 > s_bot.getPosition().x && s.getPosition().x < s_bot.getPosition().x + 25 && (int)dy < (int)dy_bot && shoot == false)  shoot_bot(window);
				break;
			case 4: if (s.getPosition().x + 25 > s_bot.getPosition().x && s.getPosition().x  < s_bot.getPosition().x + 25 && (int)dy >(int)dy_bot && shoot == false)  shoot_bot(window);
				break;
			default:
				break;
			}
		}
	}
	void move_bot1(RenderWindow& window)
	{
		if (timer == 1500)
		{
			rand_move =  rand() % 5;
			timer = 0;
		}
		if (rand_move == 1)
		{
			(Tank_bot::Sprite_Tank_Down(up));
			dy_bot += speedTank_bot;
			cnt_bot1 = 4;
			dyd_tank_bot -= speedTank_bot;
			cnt_bot2 = 4;

		}
		else if (rand_move == 2)
		{
			Tank_bot::Sprite_Tank(up);
			dy_bot -= speedTank_bot;
			cnt_bot1 = 3;
			dyd_tank_bot += speedTank_bot;
			cnt_bot2 = 3;
		}
		else if (rand_move == 3)
		{
			Tank_bot::Sprite_Tank_left(right);
			dx_bot -= speedTank_bot;
			cnt_bot1 = 2;
			dxd_tank_bot += speedTank_bot;
			cnt_bot2 = 2;
		}
		else if (rand_move == 4)
		{
			Tank_bot::Sprite_Tank(right);
			dx_bot += speedTank_bot;
			cnt_bot1 = 1;
			dxd_tank_bot -= speedTank_bot;
			cnt_bot2 = 1;
		}

		hit_the_wal_bot();
		bot_eyes(window);
		timer++;
	}
};
class Header :public Header_class_tank_player
{
public:
	void man_Up(RenderWindow& window)
	{
		string line;
		srand(time(NULL));
		Texture menuTexture1;
		Texture menuTexture2;

		Texture pointer;
		pointer.loadFromFile("C:\\Users\\linec\\source\\repos\\My_First_Project_OOP_game_SFML\\fila\\newTank.png");
		menuTexture1.loadFromFile("C:\\Users\\linec\\source\\repos\\My_First_Project_OOP_game_SFML\\fila\\play.png");
		menuTexture2.loadFromFile("C:\\Users\\linec\\source\\repos\\My_First_Project_OOP_game_SFML\\fila\\exit.PNG");

		Sprite menu1(menuTexture1);
		Sprite menu2(menuTexture2);

		Sprite pointer_s(pointer);
		pointer_s.setPosition(270, 130);
		pointer_s.setScale(0.3, 0.3);

		menu1.setPosition(350, 100);
		menu1.setScale(0.5, 0.5);

		menu2.setPosition(333, 300);
	

		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}

			menu1.setColor(Color::White);
			
			window.clear(Color::White);


			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				pointer_s.setPosition(270, 130 + 200);
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				pointer_s.setPosition(270, 130);
			}

			if (pointer_s.getPosition().y==130+200 && Keyboard::isKeyPressed(Keyboard::Enter))
				window.close();

			if (pointer_s.getPosition().y == 130 && Keyboard::isKeyPressed(Keyboard::Enter))
			{
				while (window.isOpen())
				{
					Event event;
					while (window.pollEvent(event))
					{
						if (event.type == Event::Closed)
							window.close();
					}
					//якщо вбиваємо бота зписуємо у фалик 1 незнаю правда для чого але нехай буде))) 
					ofstream out;
					out.open("C:\\Users\\linec\\source\\repos\\My_First_Project_OOP_game_SFML\\My_First_Project_OOP_game_SFML\\die.txt");
					if (out.is_open() && die_the_bot == true)
						out << "1" << std::endl;
					out.close();


					movePlayer();
					move_shoot(window);

					if (die_the_bot == false)
						move_bot1(window);
					window.clear();
					map1(window);
					Tank::draw(window);
					if (die_the_bot == false)
						Tank_bot::draw(window);
					else
						s_bot.setPosition(-1, -1);
					window.display();
					if (end_game == true)
						window.close();
				}
			}
			
			window.draw(pointer_s);
			window.draw(menu1);
			window.draw(menu2);

			window.display();
		}
	}
};

int main()
{
	RenderWindow window(VideoMode(H , W), "Myfirstrealproject");
	Header h;
	h.man_Up(window);
}
