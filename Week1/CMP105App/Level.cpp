#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	rect.setSize(sf::Vector2f(50, 50));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	rectUp.setSize(sf::Vector2f(50, 50));
	rectUp.setFillColor(sf::Color::Green);


	// circle
	circle.setRadius(50);
	circle.setPosition(550, 282.5);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);

	// square rainbow
	bRed.setSize(sf::Vector2f(60, 60));
	bRed.setPosition(200, 100);
	bRed.setFillColor(sf::Color::Red);

	mGreen.setSize(sf::Vector2f(35, 35));
	mGreen.setPosition(212.5, 112.5);
	mGreen.setFillColor(sf::Color::Green);

	sBlue.setSize(sf::Vector2f(15, 15));
	sBlue.setPosition(222.5, 122.5);
	sBlue.setFillColor(sf::Color::Blue);

	

	// text
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading fint\n";
	}

	words.setFont(font);
	words.setString("Hello world");
	words.setCharacterSize(24);
	words.setFillColor(sf::Color::Yellow);
	words.setPosition(540, 0);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u res = window->getSize();
	//rectUp.setPosition(sf::Vector2f(pos));
	rectUp.setPosition(res.x-50,res.y-50);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect);
	window->draw(circle);
	window->draw(bRed);
	window->draw(mGreen);
	window->draw(sBlue);
	window->draw(words);
	window->draw(rectUp);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}