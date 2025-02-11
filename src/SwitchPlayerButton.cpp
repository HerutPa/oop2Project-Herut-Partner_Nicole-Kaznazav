#include "SwitchPlayerButton.h"
#include "Player1Button.h"
#include "Player2Button.h"
#include "Player3Button.h"
#include "Player4Button.h"

SwitchPlayerButton::SwitchPlayerButton(sf::RenderWindow& window, GameManager& manager, Controller& game)
    : Command(window), m_playerMenu(window), m_game(game), m_manager(manager)
{
    // Add player selection commands to the player menu
    m_playerMenu.add(PLAYER1, std::make_unique<Player1Button>(window, game, manager));
    m_playerMenu.add(PLAYER2, std::make_unique<Player2Button>(window, game, manager));
    m_playerMenu.add(PLAYER3, std::make_unique<Player3Button>(window, game, manager));
    m_playerMenu.add(PLAYER4, std::make_unique<Player4Button>(window, game, manager));
}


void SwitchPlayerButton::execute()
{
    while (m_window.isOpen())
    {
        m_window.clear();
        m_playerMenu.drawPlayer();
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::MouseButtonReleased:
            {
                // Getting the click location, checking what button pressed
                const auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

                // Performing the button action accordingly
                m_playerMenu.handleAction(location);
                return;
            }
            case sf::Event::MouseMoved:
            {
                // Indicate if the mouse is on the buttons
                const auto location = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
                m_playerMenu.handleSwitchPlayerMouseMoved(location);
                break;
            }
            case sf::Event::Closed:
                m_window.close();
                return;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            return;
        }
    }
}
