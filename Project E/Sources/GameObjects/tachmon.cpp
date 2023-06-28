#include "tachmon.h"

// day la con lợn đấy

void Creeptachmon::Init()
{
		m_HitBox = new HitBox(sf::Vector2i(38, 30));
		m_HitBox->Init(sf::Vector2f(240, 0));
		setStartPoint(sf::Vector2f(screenWidth + 100, groundY - 25));
		m_HitBox->setPosition(screenWidth, groundY - 30);

		m_runAni = new Animation(*DATA->getTexture("tachmon/mo"), sf::Vector2i(4, 1), 0.1f);
		m_deathAni = new Animation(*DATA->getTexture("tachmon/mo"), sf::Vector2i(4, 1), 0.1f);
		//m_deathAni->setModeEndFrame(true);
		m_currentAni = m_runAni;
		m_HitBox->SetTag(CREEP);

}
