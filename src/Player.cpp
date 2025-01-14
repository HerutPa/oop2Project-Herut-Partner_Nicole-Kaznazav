#pragma once

#include "Player.h"


Player::Player(b2World& world, const std::vector<GameTextures> textures, const sf::Vector2f location)
    : MovingObject(world, textures[0], location),
    m_player_textures(textures),
    m_state(std::make_unique<RegularPlayerState>()),
    m_coins(0),
    m_first_location(m_object_body->GetPosition()),
    m_gravity(world.GetGravity())
{
}

void Player::setTouchingFloor(bool touching)
{
    m_touchingFloor = touching;
}

void Player::setWin()
{
    m_win = true;
}

void Player::move()
{
    //moving according to the state
    m_state->move(m_direction, m_object_body, m_touchingFloor, m_gravity, m_object);
}

// Player class implementation
void Player::updateDirection()
{
    // Check for pressed keys and update directions accordingly
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_direction[Left] = true;
        m_direction[Stay] = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_direction[Right] = true;
        m_direction[Stay] = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        m_direction[Up] = true;
        m_direction[Stay] = false;
    }
}

void Player::releaseRight()
{
    m_direction[Right] = false;
    m_direction[Stay] = true;
}
void Player::releaseLeft()
{
    m_direction[Left] = false;
    m_direction[Stay] = true;
}
void Player::releaseSpace()
{
    m_direction[Up] = false;
    m_direction[Stay] = true;
}

void Player::increasePoints()
{
    m_coins += 5;
}

void Player::resetPlayerAfterKill()
{
    //reset state and gravity
    if (m_gravity.y < 0)
    {
        m_gravity_changed = true;
        m_gravity = -m_gravity;
    }
    //reset to first location
    m_object_body->SetTransform(m_first_location, m_object_body->GetAngle());
    m_object_body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
    m_alive = true;
}

//function is designed to apply a vertical impulse to the player's physics body, 
//enabling the player to perform a hopping action
void Player::hop(const float hop_force) const
{
    //to avoid "icetower" jumps
    m_object_body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));

    //make the player jump according to the gravity
    if (m_gravity.y > 0)
        m_object_body->ApplyLinearImpulseToCenter(b2Vec2(0.0f, -hop_force), true);
    else
        m_object_body->ApplyLinearImpulseToCenter(b2Vec2(0.0f, hop_force), true);
}

void Player::reverseGravity()
{
    m_gravity = -m_gravity;
    m_gravity_changed = true;
}

//return reguler state
void Player::setRegular()
{
    m_beFly = false;
    m_beSpeed = false;
    m_beShield = false;
    m_state_change = true;
}
void Player::setRegularState()
{
    //changed the player body
    changeBodyAndSprite(m_player_textures[0]);
    //changed the pointer
    m_state.reset(new RegularPlayerState());
    m_object.setRotation(0);
}
bool Player::isRegularState() const
{
    return m_state_change;
}

//This function is used to manage and update the status of power-up tools for the player
void Player::updateTools(sf::Sprite& background)
{
    if (m_beSpeed && m_speedClock.getElapsedTime().asSeconds() > 4)
    {
        m_beSpeed = false;
        setRegularState();
    }
    else if (m_beShield && m_shieldClock.getElapsedTime().asSeconds() > 5)
    {
        m_beShield = false;
        setRegularState();
    }
}

//Speed state
void Player::beSpeed()
{
    m_beSpeed = true;
    m_speedClock.restart();
}
bool Player::isSpeedState() const
{
    return m_beSpeed;
}
void Player::setSpeedState()
{
    //changed the player body
    changeBodyAndSprite(m_player_textures[1]);
    //changed the pointer
    m_state.reset(new SpeedPlayerState());
    m_object.setRotation(0);

}

//Shield state
void Player::beShield()
{
    m_beShield = true;
    m_shieldClock.restart(); 
}
bool Player::isShieldState() const
{
    return m_beShield;
}
void Player::setShieldState()
{
    //changed the player body
    changeBodyAndSprite(m_player_textures[2]);
    //changed the pointer
    m_state.reset(new ShieldPlayerState());
    m_object.setRotation(0);
}

//Fly state
void Player::beFly()
{
    m_beFly = true;
}
bool Player::isFlystate() const
{
    return m_beFly;
}
void Player::setFlyState()
{
    //changed the player body
    changeBodyAndSprite(m_player_textures[3]);
    //changed the pointer
    m_state.reset(new FlyPlayerState());
    m_object.setRotation(0);
}

void Player::setGravity()
{
    m_gravity_changed = true;
}

const bool Player::isGravityChange()
{
    if (m_gravity_changed)
    {
        m_gravity_changed = false;
        return true;
    }
    else
        return m_gravity_changed;
}

const bool Player::isWinner() const
{
    return m_win;
}

//This function handles the player's jumping mechanics in the game. 
void Player::chooseAndJump(const float jump)
{
    // Stop the player's movement
    m_object_body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));

    // Apply an impulse for jumping based on gravity direction
    if (m_gravity.y > 0)
        m_object_body->ApplyLinearImpulseToCenter(b2Vec2(0.0f, -jump), true);
    else
        m_object_body->ApplyLinearImpulseToCenter(b2Vec2(0.0f, jump), true);
}


void Player::setPlayerKill()
{
    if (!m_beShield)
    {
        m_beFly = false;
        m_beShield = false;
        m_beSpeed = false;
        m_alive = false;
    }
}

const bool Player::isAlive()const
{
    return m_alive;
}

const int Player::getCoins()const
{
    return m_coins;
}


b2Vec2 Player::getPosition() const
{
    return m_object_body->GetPosition();
}

void Player::changeBodyAndSprite(const GameTextures game_texture)
{
    //changed texture
    m_object.setTexture(Resources::instance().getGameTexture(game_texture), true);
    const sf::Vector2f spriteSize(m_object.getTextureRect().width, m_object.getTextureRect().height);
    m_object.setOrigin(spriteSize.x / 2, spriteSize.y / 2);

    //create new shape
    b2PolygonShape shape;
    const sf::Vector2u boxSize = Resources::instance().getGameTexture(game_texture).getSize();
    shape.SetAsBox(boxSize.x / 2.0f / SCALE, boxSize.y / 2.0f / SCALE);

    //distroy the old fixture
    m_object_body->DestroyFixture(m_object_body->GetFixtureList());

    //change the fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    m_object_body->CreateFixture(&fixtureDef);
}
