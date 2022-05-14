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

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My Window", sf::Style::Titlebar | sf::Style::Fullscreen);
	window.setFramerateLimit(144);

	Font font;
	if (!font.loadFromFile("AlexandriaFLF.ttf"))
	{
		cout << "font error";
	}

	Vector2f f1_position(595, 109);
	Vector2f f2_position(595, 289);
	Vector2f f3_position(595, 469);
	Vector2f f4_position(595, 649);
	Vector2f f5_position(595, 829);

	Vector2f invalid_position(1495, 20);

	Vector2f g_blackScreen(1795, 50);
	Vector2f h_blackScreen(1795, 235);
	Vector2f j_blackScreen(1795, 420);
	Vector2f k_blackScreen(1795, 605);
	Vector2f l_blackScreen(1795, 790);

	Vector2f player_blackScreen(1795, 990);

	RectangleShape black_screen(Vector2f(110, 161));
	RectangleShape black2_screen(Vector2f(100, 700));

	RectangleShape fp_FirstCardHolder(Vector2f(100, 151));
	RectangleShape fp_SecondCardHolder(Vector2f(100, 151));
	RectangleShape fp_ThirdCardHolder(Vector2f(100, 151));
	RectangleShape fp_FourthCardHolder(Vector2f(100, 151));
	RectangleShape fp_FifthCardHolder(Vector2f(100, 151));


	RectangleShape sp_FirstCardHolder(Vector2f(100, 151));
	RectangleShape sp_SecondCardHolder(Vector2f(100, 151));
	RectangleShape sp_ThirdCardHolder(Vector2f(100, 151));
	RectangleShape sp_FourthCardHolder(Vector2f(100, 151));
	RectangleShape sp_FifthCardHolder(Vector2f(100, 151));

	Text fp_firstCardPlacement;
	Text fp_secondCardPlacement;
	Text fp_thirdCardPlacement;
	Text fp_fourthCardPlacement;
	Text fp_fifthCardPlacement;

	Text sp_firstCardPlacement;
	Text sp_secondCardPlacement;
	Text sp_thirdCardPlacement;
	Text sp_fourthCardPlacement;
	Text sp_fifthCardPlacement;

	black_screen.setFillColor(Color(32, 120, 17));
	black2_screen.setFillColor(Color(32, 120, 17));

	fp_FirstCardHolder.setPosition(595, 110);
	fp_FirstCardHolder.setFillColor(Color::Black);
	fp_FirstCardHolder.setOutlineColor(Color::White);
	fp_FirstCardHolder.setOutlineThickness(5);

	fp_SecondCardHolder.setPosition(595, 290);
	fp_SecondCardHolder.setFillColor(Color::Black);
	fp_SecondCardHolder.setOutlineColor(Color::White);
	fp_SecondCardHolder.setOutlineThickness(5);

	fp_ThirdCardHolder.setPosition(595, 470);
	fp_ThirdCardHolder.setFillColor(Color::Black);
	fp_ThirdCardHolder.setOutlineColor(Color::White);
	fp_ThirdCardHolder.setOutlineThickness(5);

	fp_FourthCardHolder.setPosition(595, 650);
	fp_FourthCardHolder.setFillColor(Color::Black);
	fp_FourthCardHolder.setOutlineColor(Color::White);
	fp_FourthCardHolder.setOutlineThickness(5);

	fp_FifthCardHolder.setPosition(595, 830);
	fp_FifthCardHolder.setFillColor(Color::Black);
	fp_FifthCardHolder.setOutlineColor(Color::White);
	fp_FifthCardHolder.setOutlineThickness(5);


	sp_FirstCardHolder.setPosition(905, 110);
	sp_FirstCardHolder.setFillColor(Color::Black);
	sp_FirstCardHolder.setOutlineColor(Color::White);
	sp_FirstCardHolder.setOutlineThickness(5);

	sp_SecondCardHolder.setPosition(905, 290);
	sp_SecondCardHolder.setFillColor(Color::Black);
	sp_SecondCardHolder.setOutlineColor(Color::White);
	sp_SecondCardHolder.setOutlineThickness(5);

	sp_ThirdCardHolder.setPosition(905, 470);
	sp_ThirdCardHolder.setFillColor(Color::Black);
	sp_ThirdCardHolder.setOutlineColor(Color::White);
	sp_ThirdCardHolder.setOutlineThickness(5);

	sp_FourthCardHolder.setPosition(905, 650);
	sp_FourthCardHolder.setFillColor(Color::Black);
	sp_FourthCardHolder.setOutlineColor(Color::White);
	sp_FourthCardHolder.setOutlineThickness(5);

	sp_FifthCardHolder.setPosition(905, 830);
	sp_FifthCardHolder.setFillColor(Color::Black);
	sp_FifthCardHolder.setOutlineColor(Color::White);
	sp_FifthCardHolder.setOutlineThickness(5);

	fp_firstCardPlacement.setFont(font);
	fp_firstCardPlacement.setFillColor(Color::White);
	fp_firstCardPlacement.setString("1");
	fp_firstCardPlacement.setCharacterSize(40);
	fp_firstCardPlacement.setStyle(Text::Bold);
	fp_firstCardPlacement.setPosition(635, 160);

	fp_secondCardPlacement.setFont(font);
	fp_secondCardPlacement.setFillColor(Color::White);
	fp_secondCardPlacement.setString("2");
	fp_secondCardPlacement.setCharacterSize(40);
	fp_secondCardPlacement.setStyle(Text::Bold);
	fp_secondCardPlacement.setPosition(635, 340);

	fp_thirdCardPlacement.setFont(font);
	fp_thirdCardPlacement.setFillColor(Color::White);
	fp_thirdCardPlacement.setString("3");
	fp_thirdCardPlacement.setCharacterSize(40);
	fp_thirdCardPlacement.setStyle(Text::Bold);
	fp_thirdCardPlacement.setPosition(635, 520);

	fp_fourthCardPlacement.setFont(font);
	fp_fourthCardPlacement.setFillColor(Color::White);
	fp_fourthCardPlacement.setString("4");
	fp_fourthCardPlacement.setCharacterSize(40);
	fp_fourthCardPlacement.setStyle(Text::Bold);
	fp_fourthCardPlacement.setPosition(635, 700);

	fp_fifthCardPlacement.setFont(font);
	fp_fifthCardPlacement.setFillColor(Color::White);
	fp_fifthCardPlacement.setString("5");
	fp_fifthCardPlacement.setCharacterSize(40);
	fp_fifthCardPlacement.setStyle(Text::Bold);
	fp_fifthCardPlacement.setPosition(635, 880);

	sp_firstCardPlacement.setFont(font);
	sp_firstCardPlacement.setFillColor(Color::White);
	sp_firstCardPlacement.setString("F1");
	sp_firstCardPlacement.setCharacterSize(40);
	sp_firstCardPlacement.setStyle(Text::Bold);
	sp_firstCardPlacement.setPosition(935, 160);

	sp_secondCardPlacement.setFont(font);
	sp_secondCardPlacement.setFillColor(Color::White);
	sp_secondCardPlacement.setString("F2");
	sp_secondCardPlacement.setCharacterSize(40);
	sp_secondCardPlacement.setStyle(Text::Bold);
	sp_secondCardPlacement.setPosition(935, 340);

	sp_thirdCardPlacement.setFont(font);
	sp_thirdCardPlacement.setFillColor(Color::White);
	sp_thirdCardPlacement.setString("F3");
	sp_thirdCardPlacement.setCharacterSize(40);
	sp_thirdCardPlacement.setStyle(Text::Bold);
	sp_thirdCardPlacement.setPosition(935, 520);

	sp_fourthCardPlacement.setFont(font);
	sp_fourthCardPlacement.setFillColor(Color::White);
	sp_fourthCardPlacement.setString("F4");
	sp_fourthCardPlacement.setCharacterSize(40);
	sp_fourthCardPlacement.setStyle(Text::Bold);
	sp_fourthCardPlacement.setPosition(935, 700);

	sp_fifthCardPlacement.setFont(font);
	sp_fifthCardPlacement.setFillColor(Color::White);
	sp_fifthCardPlacement.setString("F5");
	sp_fifthCardPlacement.setCharacterSize(40);
	sp_fifthCardPlacement.setStyle(Text::Bold);
	sp_fifthCardPlacement.setPosition(935, 880);

	Texture texture;
	Texture secondTexture;
	Texture and0;
	Texture and1;
	Texture xor0;
	Texture xor1;
	Texture or0;
	Texture or1;

	Text player1;
	Text player2;

	Text card1;
	Text card2;
	Text card3;
	Text card4;
	Text card5;

	card1.setFont(font);
	card1.setFillColor(Color::White);
	card1.setString("G)");
	card1.setCharacterSize(40);
	card1.setStyle(Text::Bold);
	card1.setPosition(1720, 100);

	card2.setFont(font);
	card2.setFillColor(Color::White);
	card2.setString("H)");
	card2.setCharacterSize(40);
	card2.setStyle(Text::Bold);
	card2.setPosition(1720, 285);

	card3.setFont(font);
	card3.setFillColor(Color::White);
	card3.setString("J)");
	card3.setCharacterSize(40);
	card3.setStyle(Text::Bold);
	card3.setPosition(1720, 470);

	card4.setFont(font);
	card4.setFillColor(Color::White);
	card4.setString("K)");
	card4.setCharacterSize(40);
	card4.setStyle(Text::Bold);
	card4.setPosition(1720, 655);

	card5.setFont(font);
	card5.setFillColor(Color::White);
	card5.setString("L)");
	card5.setCharacterSize(40);
	card5.setStyle(Text::Bold);
	card5.setPosition(1720, 840);

	player1.setFont(font);
	player1.setFillColor(Color::White);
	player1.setString("Player 1");
	player1.setCharacterSize(40);
	player1.setStyle(Text::Bold);
	player1.setPosition(1735, 980);

	player2.setFont(font);
	player2.setFillColor(Color::White);
	player2.setString("Player 2");
	player2.setCharacterSize(40);
	player2.setStyle(Text::Bold);
	player2.setPosition(1735, 980);

	Text invalid;

	invalid.setFont(font);
	invalid.setFillColor(Color::White);
	invalid.setString("Invalid!");
	invalid.setCharacterSize(40);
	invalid.setStyle(Text::Bold);

	texture.loadFromFile("booleo01.png");
	secondTexture.loadFromFile("booleo10.png");

	and0.loadFromFile("and0.png");
	and1.loadFromFile("and1.png");
	xor0.loadFromFile("xor0.png");
	xor1.loadFromFile("xor1.png");
	or0.loadFromFile("or0.png");
	or1.loadFromFile("or1.png");

	Sprite firstCard;
	Sprite first2Card;
	Sprite first3Card;
	Sprite first4Card;
	Sprite first5Card;
	Sprite first6Card;

	Sprite fp_and_0;
	Sprite fp_and_1;
	Sprite fp_xor_0;
	Sprite fp_xor_1;
	Sprite fp_or_0;
	Sprite fp_or_1;

	Sprite sp_and_0;
	Sprite sp_and_1;
	Sprite sp_xor_0;
	Sprite sp_xor_1;
	Sprite sp_or_0;
	Sprite sp_or_1;

	Sprite and_0;
	Sprite and_1;
	Sprite xor_0;
	Sprite xor_1;
	Sprite or_0;
	Sprite or_1;

	Sprite secondCard;
	Sprite second2Card;
	Sprite second3Card;
	Sprite second4Card;
	Sprite second5Card;
	Sprite second6Card;

	firstCard.setTexture(texture);
	first2Card.setTexture(texture);
	first3Card.setTexture(texture);
	first4Card.setTexture(texture);
	first5Card.setTexture(texture);
	first6Card.setTexture(texture);

	firstCard.setPosition(700, 50);
	first2Card.setPosition(700, 220);
	first3Card.setPosition(700, 390);
	first4Card.setPosition(700, 560);
	first5Card.setPosition(700, 730);
	first6Card.setPosition(700, 900);

	secondCard.setTexture(secondTexture);
	second2Card.setTexture(secondTexture);
	second3Card.setTexture(secondTexture);
	second4Card.setTexture(secondTexture);
	second5Card.setTexture(secondTexture);
	second6Card.setTexture(secondTexture);

	secondCard.setPosition(700, 50);
	second2Card.setPosition(700, 220);
	second3Card.setPosition(700, 390);
	second4Card.setPosition(700, 560);
	second5Card.setPosition(700, 730);
	second6Card.setPosition(700, 900);

	and_0.setTexture(and0); // 100 * 155
	and_1.setTexture(and1); // 100 * 156
	xor_0.setTexture(xor0); // 100 * 154
	xor_1.setTexture(xor1); // 100 * 151
	or_0.setTexture(or0); // 100 * 152
	or_1.setTexture(or1); // 100 * 151

	fp_and_0.setTexture(and0); // 100 * 155
	fp_and_1.setTexture(and1); // 100 * 156
	fp_xor_0.setTexture(xor0); // 100 * 154
	fp_xor_1.setTexture(xor1); // 100 * 151
	fp_or_0.setTexture(or0); // 100 * 152
	fp_or_1.setTexture(or1); // 100 * 151

	sp_and_0.setTexture(and0); // 100 * 155
	sp_and_1.setTexture(and1); // 100 * 156
	sp_xor_0.setTexture(xor0); // 100 * 154
	sp_xor_1.setTexture(xor1); // 100 * 151
	sp_or_0.setTexture(or0); // 100 * 152
	sp_or_1.setTexture(or1); // 100 * 151

	int array[6];

	srand(time(NULL));
	for (int i = 0; i < 6; i++)
	{
		array[i] = rand() % 2;
	}

	int arr[5];

	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		arr[i] = rand() % 6 + 1;
	}

	int secondArr[5];
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		secondArr[i] = rand() % 6 + 1;
	}

	Vertex line[] =
	{
		Vertex(Vector2f(800, 0)),
		Vertex(Vector2f(1200, 0))
	};

	line[0].position = Vector2f(1680, 1200);
	line[1].position = Vector2f(1680, 0);

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