#pragma once
//#include "Player.h"
#include "Node.h"
#include "AI.h"
#include <SFML/Graphics.hpp>

class Node;
class AI;

class Game
{
public:
	Game();
	void run();
	//sf::Vector2f getPlayerPosition();

protected:
	int randomSize = 1;
	int rectSize = 40;
	int gridX = 50;
	int gridY = 50;
	void update(double dt);
	void setCost();
	void setVector();
	void setDistance();
	void render();
	void createGrid(int random);
	void processEvents();
	void clearAll();
	void processGameEvents(sf::Event&);
	int goalNode;
	//Player* m_player;
	sf::RenderWindow m_window;
	sf::Font costFont;
	
	sf::Text randomText;

	bool UpPressed = false;
	bool DownPressed = false;

	bool UpAvailable = true;
	bool DownAvailable = true;
	bool LeftAvailable = true;
	bool RightAvailable = true;
	bool startSet = false;
	bool goalSet = false;
	bool leftPressed = false;
	double tempX = 0;
	double tempY = 0;

	sf::RectangleShape rectangle;
	std::vector<Node*> nodes;
	Node* node;
	std::vector<AI*> ais;
	AI* ai;

};
