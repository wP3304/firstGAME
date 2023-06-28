﻿#include "PSDeath.h"

PSDeath::PSDeath(IPlayer* player)
{
	m_Player = player;
	m_timeRemain = 2.f;
}

void PSDeath::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Character/Death"), sf::Vector2i(7, 1), 0.1f);
	m_Animation->setModeEndFrame(true);
}

void PSDeath::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime >= m_timeRemain) {
		GSM->ChangeState(StateTypes::END);
		DATA->getMusic("Uprising")->stop();
		// xong rồi thì ngậm mồm vào
		DATA->getMusic("quackquack")->stop();
	}
	m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSDeath::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSDeath::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}
