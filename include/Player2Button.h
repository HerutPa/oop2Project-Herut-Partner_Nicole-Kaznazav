#pragma once

#include "Command.h"

class Controller;


class Player2Button : public Command
{
public:
    Player2Button(sf::RenderWindow& window, Controller& game, GameManager& manager);
    void execute() override;

private:
    GameManager& m_manager;
    Controller& m_game;
};
