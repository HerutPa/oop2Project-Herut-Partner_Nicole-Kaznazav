﻿file(GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)

target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
        ${MY_SOURCE_FILES}
        "../include/Controller.h"
        "Controller.cpp"
        "../include/GameManager.h" 
        "GameManager.cpp"
         "../include/GdContactListener.h" 
        "GdContactListener.cpp"
        "../include/Resources.h"
        "Resources.cpp"
        "../include/Board.h"
        "Board.cpp"
        "../include/Command.h"
        "Command.cpp"
        "../include/PlayButton.h"
        "PlayButton.cpp"
        "../include/HelpButton.h"
        "HelpButton.cpp"
        "../include/SwitchPlayerButton.h"
        "SwitchPlayerButton.cpp"
        "../include/ScoreTableButton.h"
        "ScoreTableButton.cpp"
        "../include/ExitGame.h"
        "ExitGame.cpp"
        "../include/Menu.h"
        "Menu.cpp"
        "../include/PlayersMenu.h"
        "PlayersMenu.cpp"
        "../include/Player1Button.h"
        "Player1Button.cpp"
        "../include/Player2Button.h"
        "Player2Button.cpp"
        "../include/Player3Button.h"
        "Player3Button.cpp"
        "../include/Player4Button.h"
        "Player4Button.cpp" 
        "../include/LevelsMenu.h"
        "LevelsMenu.cpp"
        "../include/Level2_Button.h"
        "Level2_Button.cpp"
        "../include/Level3_Button.h"
        "Level3_Button.cpp"
        "../include/Factory.h"
         "Factory.cpp"
        "../include/GameObject.h" 
        "GameObject.cpp" 
        "../include/MovingObject.h" 
        "MovingObject.cpp" 
        "../include/StaticObject.h"
        "StaticObject.cpp" 
        "../include/Player.h" 
        "Player.cpp"
        "../include/PlayerState.h" 
        "../include/RegularPlayerState.h"
         "RegularPlayerState.cpp"
         "../include/SpeedPlayerState.h" 
         "SpeedPlayerState.cpp"
         "../include/ShieldPlayerState.h" 
         "ShieldPlayerState.cpp"
         "../include/FlyPlayerState.h" 
         "FlyPlayerState.cpp"
         "../include/Enemy.h"
         "../include/ShooterEnemy.h"
         "ShooterEnemy.cpp" 
         "../include/Bullet.h" "Bullet.cpp"
         "../include/ChaserEnemy.h"
         "ChaserEnemy.cpp"
         "../include/WheelSpike.h"
          "WheelSpike.cpp" 
         "../include/Floor.h" 
        "Floor.cpp" 
        "../include/Thorn.h" 
        "Thorn.cpp" 
        "../include/Coin.h" 
        "Coin.cpp" 
        "../include/Jumper.h" 
        "Jumper.cpp"
        "../include/Entrance.h" 
        "Entrance.cpp"
        "../include/ScoreTable.h" 
        "ScoreTable.cpp"
        "../include/MuteMusic.h" 
        "MuteMusic.cpp")
