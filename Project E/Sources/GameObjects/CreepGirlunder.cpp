#include "CreepGirlunder.h"

void CreepGirlunder::Init()
{
	m_HitBox = new HitBox(sf::Vector2i(20, 20));
	m_HitBox->Init(sf::Vector2f(240, 0));
	setStartPoint(sf::Vector2f(screenWidth + 100, groundY + 25));
	m_HitBox->setPosition(screenWidth, groundY + 30);
	// tên là gái thôi nhưng nó là con người tuyết chứ lạnh kia làm gì có gái lắc đuýt

	m_runAni = new Animation(*DATA->getTexture("Girl/Girlunder"), sf::Vector2i(1, 1), 0.1f);
	m_deathAni = new Animation(*DATA->getTexture("Girl/Girlunder"), sf::Vector2i(1, 1), 0.1f);
	//m_deathAni->setModeEndFrame(true);
	m_currentAni = m_runAni;
	m_HitBox->SetTag(CREEP);
}
