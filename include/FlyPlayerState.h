#pragma once

#include "PlayerState.h"

class FlyPlayerState : public PlayerState
{
public:
	void move(bool*, b2Body*, bool&, const b2Vec2, sf::Sprite&)override;

	//void collideBrick(bool&, bool&)override;

	//void jump(b2Body* body);

private:

};