#include "Menu.h"
#include "InfoLevel.h"
#include "Scene.h"
#include "Results.h"
#include "Credits.h"
#include "Instructions.h"
#include "Game.h"
#include "StateManager.h"

void StateManager::changeMenu()
{
	Menu::getInstance().init();
	Game::instance().setGameState(&Menu::getInstance());
}

void StateManager::changeInfo(int levelMode, int levelNum)
{
	InfoLevel::instance().init();
	InfoLevel::instance().setLevel(levelNum, levelMode);
	Game::instance().setGameState(&InfoLevel::instance());
}

void StateManager::changeScene(int levelMode, int levelNum)
{
	Scene::getInstance().init();
	Scene::getInstance().startLevel(levelMode, levelNum);
}

void StateManager::changeResults(int goalPercentage, int currentPercentage)
{
	Results::getInstance().init();
	Results::getInstance().setPercentages(goalPercentage, currentPercentage);
	Game::instance().setGameState(&Results::getInstance());
}

void StateManager::changeCredits()
{
	Credits::instance().init();
	Game::instance().setGameState(&Credits::instance());
}

void StateManager::changeInstructions()
{
	Instructions::getInstance().init();
	Game::instance().setGameState(&Instructions::getInstance());
}
