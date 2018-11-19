#include "Node.h"
#include <iostream>
#include <math.h>

Node::Node(int x,int y,int size, sf::Font &costFont,int obstacle)
{
	rectSize = size;

	rectangle.setSize(sf::Vector2f(size, size));
	rectangle.setFillColor(sf::Color::White);
	rectangle.setPosition(x, y);

	costText.setFont(costFont);
	costText.setStyle(sf::Text::Bold);
	costText.setCharacterSize(size/2);
	costText.setFillColor(sf::Color::Black);
	costText.setPosition(x + size/10, y + size/2);

	distanceText.setFont(costFont);
	distanceText.setStyle(sf::Text::Bold);
	distanceText.setCharacterSize(size / 2);
	distanceText.setFillColor(sf::Color::Black);
	distanceText.setPosition(x + size / 10, y + size / 2);
	//costText.setString(std::to_string(cost));
	if (obstacle == 1)
	{
		setCost(999999);
	}
}

Node::~Node()
{
}



void Node::update(double dt)
{


}
void Node::setCost(int x)
{
	cost = x;
	if (cost < 64)
	{
		rectangle.setFillColor(sf::Color(0, 255 - (cost * 4), 255, 255));
	}
	else
	{
		rectangle.setFillColor(sf::Color(0, 0, 255, 255));
	}
	if (cost >= 999999)
	{
		rectangle.setFillColor(sf::Color(0, 0, 0, 0));
	}
	costText.setString(std::to_string(cost));
	costSet = true;
}
int Node::getCost()
{
	return cost;
}
bool Node::checkSet()
{
	return costSet;
}

void Node::setDistance(int goalX, int goalY)
{
	distanceToGoal = sqrt((((goalX - rectangle.getPosition().x)*(goalX - rectangle.getPosition().x)) + ((goalY - rectangle.getPosition().y)*(goalY - rectangle.getPosition().y))));
	integrationField = distanceToGoal + cost;
	distanceText.setString(std::to_string(integrationField));
}
int Node::getIntegrationField()
{
	return integrationField;
}

void Node::setColor(sf::Color color)
{
	if (start == false)
	{
		rectangle.setFillColor(color);
		start = true;
	}
	else if (goal == false)
	{
		rectangle.setFillColor(sf::Color::Red);
		goal = true;
	}
	//rectangle.setFillColor(color);
}
void Node::setVector(double vectorX, double vectorY)
{
	vectX = vectorX;
	vectY = vectorY;
}

int Node::getPositionX()
{
	return rectangle.getPosition().x;
}
int Node::getPositionY()
{
	return rectangle.getPosition().y;
}
void Node::draw(sf::RenderWindow & window)
{
	window.draw(rectangle);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C))
	{
		costDraw = true;
		distanceDraw = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		distanceDraw = true;
		costDraw = false;
	}

	if (costDraw == true)
	{
		window.draw(costText);
	}
	if (distanceDraw == true)
	{
		window.draw(distanceText);
	}
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f((rectangle.getPosition().x + (rectSize / 2)), (rectangle.getPosition().y + (rectSize / 2)))),
		sf::Vertex(sf::Vector2f(rectangle.getPosition().x + vectX, rectangle.getPosition().y + vectY))
	};
	window.draw(line, 2, sf::Lines);
}