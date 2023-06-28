#include "PSFlip.h"


PSFlip::PSFlip(IPlayer* player)
{
	m_Player = player;
}

void PSFlip::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Character/Runflip"), sf::Vector2i(12, 1), 0.1f);
}

void PSFlip::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		m_Player->changeNextState(JUMPFLIP);
	}
	else if (m_Player->getHitBox()->getPosition().x > 10 && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
	}
	else if (m_Player->getHitBox()->getPosition().x < screenWidth - 20 && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_Player->check_flip() == true) {
		m_Player->changeNextState(RUN);
		m_Player->getHitBox()->move(0, -m_Player->getHitBox()->getPosition().y +250);
		m_Player->set_flip(false);
	}
	if (!m_Player->getHitBox()->isAlive()) {
		m_Player->changeNextState(IPState::DEATHFLIP);
		// chết thì mở cái mồm ra :))
		DATA->playMusic("quackquack");
		DATA->getMusic("quackquack")->setVolume(50);
	}
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSFlip::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSFlip::Reset()
{
	m_Animation->Reset();
}
