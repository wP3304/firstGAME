#include "Mushroom.h"

void CreepMushroom::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(30, 25));
	m_HitBox->Init(sf::Vector2f(240, 0));
	setStartPoint(sf::Vector2f(screenWidth + 100, groundY - 25));
	m_HitBox->setPosition(screenWidth, groundY - 30);

	m_runAni = new Animation(*DATA->getTexture("Mushroom/Run"), sf::Vector2i(8, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Mushroom/Run"), sf::Vector2i(8, 1), 0.1f);
	//m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}
