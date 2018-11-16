#pragma once
#include <SFML/Graphics.hpp>

class Node
{
public:
	Node(int x,int y,int size,sf::Font &costFont,int obstacle);
	~Node();
	void update(double dt);
	void draw(sf::RenderWindow & window);
	int getPositionX();
	int getPositionY();
	void setColor(sf::Color color);
	void setCost(int x);
	void setDistance(int goalX,int goalY);
	int getCost();
	bool checkSet();

private:

	int distanceToGoal = 0;
	int integrationField = 0;
	sf::Text costText;
	sf::RectangleShape rectangle;
	bool start = false;
	bool goal = false;
	bool costSet = false;
	int cost = 0;
};