#pragma once
#include "PSJumpFlip.h"
#include "PSFallFlip.h"

PSJumpFlip::PSJumpFlip(IPlayer* player)
{
	m_Player = player;
	m_currentTime = 0.f;
}

void PSJumpFlip::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Character/Jumpflip"), sf::Vector2i(1, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
}

void PSJumpFlip::Update(float deltaTime)
{

	m_Animation->Update(deltaTime);
	m_currentTime += deltaTime;

	float v = 10 * m_currentTime;
	if (-m_Player->getHitBox()->getVelocity().y*0.6 * deltaTime + v >= 0) {
		m_Player->changeNextState(FALLFLIP);
		m_currentTime = 0.f;
	}
	else m_Player->getHitBox()->move(0, m_Player->getHitBox()->getVelocity().y * 0.6 * deltaTime - v);

	if (m_Player->getHitBox()->getPosition().x > 10 && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * 0.6 * deltaTime, 0);
	}
	else if (m_Player->getHitBox()->getPosition().x < screenWidth - 20 && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * 0.6 * deltaTime, 0);
	}
	if (!m_Player->getHitBox()->isAlive()) m_Player->changeNextState(IPState::FALLFLIP);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}




void PSJumpFlip::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSJumpFlip::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}
