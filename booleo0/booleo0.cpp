#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include <stdlib.h>

using namespace sf;
using namespace std;

bool flagG = false;
bool flagH = false;
bool flagJ = false;
bool flagK = false;
bool flagL = false;

bool flag1 = false;
bool flag2 = false;
bool flag3 = false;
bool flag4 = false;
bool flag5 = false;

void main()
{
    RenderWindow MENU(VideoMode(1920, 1080), "Main Menu", Style::Fullscreen);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

	View view(Vector2f(0.0f, 0.0f), Vector2f(1920, 1080));
	MENU.setFramerateLimit(144);
		
	// main page background
	RectangleShape background;
	background.setSize(Vector2f(1920, 1080));
	Texture Maintexture;
	Maintexture.loadFromFile("mainPAGE.jpg");
	background.setTexture(&Maintexture);

	// photo to the game
	RectangleShape PBackground;
	PBackground.setSize(Vector2f(1920, 1080));
	Texture back_texture;
	back_texture.loadFromFile("gameOptions.jpg");
	PBackground.setTexture(&back_texture);

	while (MENU.isOpen())
	{
		Event event;
		while (MENU.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				MENU.close();
			}
			
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.MoveUp();
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}
				if (event.key.code == Keyboard::Return)
				{
					RenderWindow PVSP(VideoMode(1920, 1080), "Person vs. Person", Style::Fullscreen);
					MainMenu gameMenu(PVSP.getSize().x, PVSP.getSize().y);
					RenderWindow PVSC(VideoMode(1920, 1080), "Person vs. Computer", Style::Fullscreen);
					RenderWindow PVSPWNC(VideoMode(1920, 1080), "Person vs. Person with not-card", Style::Fullscreen);
					RenderWindow PVSCWNC(VideoMode(1920, 1080), "Person vs. Computer with not-card", Style::Fullscreen);

					PVSP.setFramerateLimit(144);
					PVSC.setFramerateLimit(144);
					PVSPWNC.setFramerateLimit(144);
					PVSCWNC.setFramerateLimit(144);

					int x = mainMenu.MainMenuPressed();
					if (x == 0)
					{
						while (PVSP.isOpen())
						{
							Event aevent;
							while (PVSP.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									PVSP.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										PVSP.close();
									}
								}
							}
							PVSC.close();
							PVSP.clear();
							PVSP.draw(PBackground);
							PVSPWNC.close();
							PVSCWNC.close();
							PVSP.display();
						}
					}
					if (x == 1)
					{
						while (PVSC.isOpen())
						{
							Event aevent;
							while (PVSC.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									PVSC.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										PVSC.close();
									}
								}
							}
							PVSP.close();
							PVSC.clear();
							PVSC.draw(PBackground);
							PVSPWNC.close();
							PVSCWNC.close();
							PVSC.display();
						}
					}
					if (x == 2)
					{
						while (PVSPWNC.isOpen())
						{
							Event aevent;
							while (PVSPWNC.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									PVSPWNC.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										PVSPWNC.close();
									}
								}
							}

							PVSP.close();
							PVSC.close();
							PVSCWNC.close();
							PVSPWNC.clear();
							PVSPWNC.draw(PBackground);
							PVSPWNC.display();
						}
					}
					if (x == 3)
					{
						while (PVSCWNC.isOpen())
						{
							Event aevent;
							while (PVSCWNC.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									PVSCWNC.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										PVSCWNC.close();
									}
								}
							}

							PVSP.close();
							PVSC.close();
							PVSPWNC.close();
							PVSCWNC.clear();
							PVSCWNC.draw(PBackground);
							PVSCWNC.display();
						}
					}
					if (x == 4)
					{
						MENU.close();
					}
					break;
				}
			}
		}
		MENU.clear();
		MENU.draw(background);
		mainMenu.draw(MENU);
		MENU.display();
	}
}