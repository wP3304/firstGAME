#include "PSRun.h"

PSRun::PSRun(IPlayer* player)
{
	m_Player = player;
}

void PSRun::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Character/Run"), sf::Vector2i(12, 1), 0.1f);

}

void PSRun::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		m_Player->changeNextState(JUMP);
	}
	else if (m_Player->getHitBox()->getPosition().x > 10 && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
	}
	else if (m_Player->getHitBox()->getPosition().x < screenWidth - 20 && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_Player->check_flip()==false ) {
		m_Player->changeNextState(FLIP);
		m_Player->getHitBox()->move(0 , m_Player->getHitBox()->getPosition().y -170 );
		m_Player->set_flip(true);
	}
	if (!m_Player->getHitBox()->isAlive()) {
		m_Player->changeNextState(IPState::DEATH);
		// chết thì mở cái mồm ra :))
		DATA->playMusic("quackquack");
		DATA->getMusic("quackquack")->setVolume(75);
	}
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSRun::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSRun::Reset()
{
	m_Animation->Reset();

}
