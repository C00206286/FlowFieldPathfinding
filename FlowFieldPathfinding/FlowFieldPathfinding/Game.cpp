#include "Game.h"
#include <iostream>

// Updates per milliseconds
static double const MS_PER_UPDATE = 1.0;

Game::Game()
	: m_window(sf::VideoMode(2200, 2200), "Brendans Game :)")

{
	if (!costFont.loadFromFile("font.ttf"))
	{
	}
	srand(time(NULL));

	for (int x = 1; x <= gridX; x++)
	{
		for (int y = 1; y <= gridY; y++)
		{
			int obstacleRand = rand() % 3 + 1;
			//int obstacleRand 1;
			if (obstacleRand != 3)
			{
				node = new Node(x * (rectSize + 1), y * (rectSize + 1), rectSize, costFont,0);
			}
			else
			{
				node = new Node(x * (rectSize + 1), y * (rectSize + 1), rectSize, costFont,1);
			}
			nodes.push_back(node);
		}
	}
	
	m_window.setVerticalSyncEnabled(true);
	//m_player = new Player();

}

void Game::update(double dt)
{
	sf::Time deltaTime;
	//m_player->update(dt);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i position = sf::Mouse::getPosition(m_window);

		for (int i = 0; i < nodes.size(); i++)
		{
			if (position.x > nodes[i]->getPositionX() && position.x < nodes[i]->getPositionX() + rectSize && position.y > nodes[i]->getPositionY() && position.y < nodes[i]->getPositionY() + rectSize)
			{
				if (goalSet == false)
				{
					nodes[i]->setColor(sf::Color::Red);
					goalNode = i;
					goalSet = true;
					setCost();
					setDistance();
					setVector();
				}

			}
		}
	}
}

void Game::setCost()
{	
	std::vector<int> que;
	que.push_back(goalNode);
	nodes[goalNode]->setCost(0);
	int indexHorizontal = gridY;
	int indexVertical = 1;
	while (que.empty() == false)
	{
		UpAvailable = true;
		DownAvailable = true;
		LeftAvailable = true;
		RightAvailable = true;

		if (que.front() < gridY)
		{
			LeftAvailable = false;
		}
		if (que.front() > ((gridX * gridY) - (gridY + 1))) //2249
		{
			RightAvailable = false;
		}
		if (que.front() % gridY == 0)
		{
			UpAvailable = false;
		}
		for (int x = 0; x < gridX; x++)
		{
			if (que.front() == ((gridY - 1) + (gridY * x)))
			{
				DownAvailable = false;
			}
		}
		if (UpAvailable == true)
		{
			if (nodes[que.front() - indexVertical]->checkSet() == false)
			{
				nodes[(que.front() - indexVertical)]->setCost(nodes[que.front()]->getCost() + 1);
				que.push_back(que.front() - indexVertical);
			}
		}
		if (DownAvailable == true)
		{
			if (nodes[que.front() + indexVertical]->checkSet() == false)
			{
				nodes[(que.front() + indexVertical)]->setCost(nodes[que.front()]->getCost() + 1);
				que.push_back(que.front() + indexVertical);
			}
		}
		if (LeftAvailable == true)
		{
			if (nodes[que.front() - indexHorizontal]->checkSet() == false)
			{
				nodes[(que.front() - indexHorizontal)]->setCost(nodes[que.front()]->getCost() + 1);
				que.push_back(que.front() - indexHorizontal);
			}
		}
		if (RightAvailable == true)
		{
			if (nodes[que.front() + indexHorizontal]->checkSet() == false)
			{
				nodes[(que.front() + indexHorizontal)]->setCost(nodes[que.front()]->getCost() + 1);
				que.push_back(que.front() + indexHorizontal);
			}
		}
		que.erase(que.begin());
	}
}
void Game::setVector()
{
	for (int i = 0; i < nodes.size(); i++)
	{
	
			UpAvailable = true;
			DownAvailable = true;
			LeftAvailable = true;
			RightAvailable = true;
			int indexHorizontal = gridY;
			int indexVertical = 1;
			double leftIntField = 0;
			double rightIntField = 0;
			double upIntField = 0;
			double downIntField = 0;
			double vectorX = 0;
			double vectorY = 0;
			if (nodes[i]->getIntegrationField() < 9000)
			{
				if (i < gridY)
				{
					LeftAvailable = false;
				}
				if (i > ((gridX * gridY) - (gridY + 1))) //2249
				{
					RightAvailable = false;
				}
				if (i % gridY == 0)
				{
					UpAvailable = false;
				}
				for (int iter = 0; iter < gridX; iter++)
				{
					if (i == ((gridY - 1) + (gridY * iter)))
					{
						DownAvailable = false;
					}
				}
				if (UpAvailable == true)
				{
					if (nodes[i - indexVertical]->getIntegrationField() < 9000)
					{
						upIntField = nodes[i - indexVertical]->getIntegrationField();
					}
					else
					{
						upIntField = nodes[i]->getIntegrationField();
					}
				}
				else
				{
					upIntField = nodes[i]->getIntegrationField();
				}
				if (DownAvailable == true)
				{

					if (nodes[i + indexVertical]->getIntegrationField() < 9000)
					{
						downIntField = nodes[i + indexVertical]->getIntegrationField();
					}
					else
					{
						downIntField = nodes[i]->getIntegrationField();
					}
				}
				else
				{
					downIntField = nodes[i]->getIntegrationField();
				}
				if (LeftAvailable == true)
				{
					if (nodes[i - indexHorizontal]->getIntegrationField() < 9000)
					{
						leftIntField = nodes[i - indexHorizontal]->getIntegrationField();
					}
					else
					{
						leftIntField = nodes[i]->getIntegrationField();
					}
				}
				else
				{
					leftIntField = nodes[i]->getIntegrationField();
				}
				if (RightAvailable == true)
				{
					if (nodes[i + indexHorizontal]->getIntegrationField() < 9000)
					{
						rightIntField = nodes[i + indexHorizontal]->getIntegrationField();
					}
					else
					{
						rightIntField = nodes[i]->getIntegrationField();
					}
				}
				else
				{
					rightIntField = nodes[i]->getIntegrationField();
				}
				vectorX = leftIntField - rightIntField;
				vectorY = upIntField - downIntField;
				double vectMag = sqrt(((((nodes[i]->getPositionX() + (rectSize / 2)) + vectorX) - (nodes[i]->getPositionX() + (rectSize / 2))) * (((nodes[i]->getPositionX() + (rectSize / 2)) + vectorX) - (nodes[i]->getPositionX() + (rectSize / 2)))) + ((((nodes[i]->getPositionY() + (rectSize / 2)) + vectorY) - (nodes[i]->getPositionY() + (rectSize / 2))) * (((nodes[i]->getPositionY() + (rectSize / 2)) + vectorY) - (nodes[i]->getPositionY() + (rectSize / 2)))));
				vectorX = vectorX / vectMag;
				vectorY = vectorY / vectMag;
				nodes[i]->setVector(vectorX, vectorY);
			}

	}
}
void Game::setDistance()
{
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i]->setDistance((nodes[goalNode]->getPositionX() + (rectSize / 2)), (nodes[goalNode]->getPositionY() + (rectSize / 2)));
	}
}

void Game::render()
{
	m_window.clear(sf::Color(0, 0, 0));
	//m_player->draw(m_window);
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i]->draw(m_window);
	}
	m_window.display();
}
void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		processEvents();

		while (lag > MS_PER_UPDATE)
		{
			update(MS_PER_UPDATE);
			lag -= MS_PER_UPDATE;
		}
		update(MS_PER_UPDATE);

		render();
	}

}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		processGameEvents(event);
	}
}

void Game::processGameEvents(sf::Event& event)
{


}
//sf::Vector2f Game::getPlayerPosition()
//{
	//return m_player->getPlayerPosition();
//}