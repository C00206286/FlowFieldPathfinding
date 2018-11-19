#pragma once
//#include "Player.h"
#include "Node.h"
#include <SFML/Graphics.hpp>

class Node;

class Game
{
public:
	Game();
	void run();
	//sf::Vector2f getPlayerPosition();

protected:
	int rectSize = 40;
	int gridX = 50;
	int gridY = 50;
	void update(double dt);
	void setCost();
	void setVector();
	void setDistance();
	void render();
	void processEvents();
	void processGameEvents(sf::Event&);
	int goalNode;
	//Player* m_player;
	sf::RenderWindow m_window;
	sf::Font costFont;
	
	bool UpAvailable = true;
	bool DownAvailable = true;
	bool LeftAvailable = true;
	bool RightAvailable = true;

	bool goalSet = false;

	sf::RectangleShape rectangle;
	std::vector<Node*> nodes;
	Node* node;

};
