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
	double getVectX();
	double getVectY();
	void setColor(sf::Color color);
	void setCost(double x);
	void setDistance(int goalX,int goalY);
	void setVector(double vectorX, double vectorY);
	void setIntegrationField(double field);
	void setCheck(int num);
	double getCost();
	double getIntegrationField();
	bool checkSet();
	int rectSize;
	sf::Vertex Line[2];
	void swapIntegrationCalc();

private:

	bool useDistance = true;
	double vectX = 0;
	double vectY = 0;
	double distanceToGoal = 0;
	double integrationField = 0;
	sf::Text costText;
	sf::Text distanceText;
	sf::RectangleShape rectangle;
	bool start = false;
	bool goal = false;
	bool costSet = false;
	bool costDraw = true;
	bool vectorDraw = true;
	bool distanceDraw = false;
	double cost = 0;
};