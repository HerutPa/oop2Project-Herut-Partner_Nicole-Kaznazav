#pragma once

#include "ExitGame.h"
#include "Controller.h"

ExitGame::ExitGame(sf::RenderWindow& window, Controller& game)
	:Command(window), m_game(game)
{
}

void ExitGame::execute()
{
	m_game.quitGame();
}


