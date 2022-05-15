#include "MainMenu.h"

MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("Fonts/Oswald-Bold.ttf"))
	{
		cout << "No font is here!";
	}

	// Person vs. Person
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("Person vs. Person");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(400, 270);

	// Person vs. Computer
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Person vs. Computer");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(400, 380);


	// Person vs. Person with not-card
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("Person vs. Person with not-card");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(400, 480);

	// Person vs. Computer with not-card
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("Person vs. Computer with not-card");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(400, 590);

	// Exit
	mainMenu[4].setFont(font);
	mainMenu[4].setFillColor(Color::White);
	mainMenu[4].setString("Exit");
	mainMenu[4].setCharacterSize(70);
	mainMenu[4].setPosition(400, 700);

	MainMenuSelected = -1;
}

MainMenu::~MainMenu()
{

}

// Draw MainMenu
void MainMenu::draw(RenderWindow& window)
{
	for (int i = 0; i < Max_main_menu; ++i)
	{
		window.draw(mainMenu[i]);
	}
}

/// MoveUp
void MainMenu::MoveUp()
{
	if (MainMenuSelected - 1 >= 0)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::White);
		MainMenuSelected--;

		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 2;
		}

		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}

// MoveDown
void MainMenu::MoveDown()
{
	if (MainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::White);
		MainMenuSelected++;

		if (MainMenuSelected == 5)
		{
			MainMenuSelected = 0;
		}

		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}