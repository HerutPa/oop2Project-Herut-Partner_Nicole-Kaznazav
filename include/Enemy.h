#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include "Resources.h"
#include "GameObject.h"
#include "MovingObject.h"
#include "Factory.h"
#include "Player.h"
#include <memory>


class Enemy : public MovingObject {
public:
    Enemy(b2World& world, const GameTextures texture, const sf::Vector2f location)
        : MovingObject(world, texture, location) {}

    virtual void updateDirection() override = 0;
    virtual void move() override = 0;
};





