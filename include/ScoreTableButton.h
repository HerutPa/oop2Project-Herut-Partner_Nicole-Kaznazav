#pragma once

#include "Command.h"
//#include "LevelsMenu.h"

class Controller;

class ScoreTableButton : public Command
{
public:
	ScoreTableButton(sf::RenderWindow& window, Controller& game);
	void execute() override;

private:
	Controller& m_game;

};