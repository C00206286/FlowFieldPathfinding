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
	void setVector(double vectorX, double vectorY);
	int getCost();
	int getIntegrationField();
	bool checkSet();
	int rectSize;
	sf::Vertex Line[2];

private:

	double vectX = 0;
	double vectY = 0;
	int distanceToGoal = 0;
	int integrationField = 0;
	sf::Text costText;
	sf::Text distanceText;
	sf::RectangleShape rectangle;
	bool start = false;
	bool goal = false;
	bool costSet = false;
	bool costDraw = true;
	bool distanceDraw = false;
	int cost = 0;
};