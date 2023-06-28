#include "Knight.h"

void CreepKnight::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(50, 80));
	m_HitBox->Init(sf::Vector2f(200, 0));
	setStartPoint(sf::Vector2f(screenWidth , groundY - 70));
	m_HitBox->setPosition(screenWidth, groundY );

	m_runAni = new Animation(*DATA->getTexture("Knight/Walk"), sf::Vector2i(8, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Knight/Walk"), sf::Vector2i(8, 1), 0.1f);
	//m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}
