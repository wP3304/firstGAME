#pragma once
#include "../GameManager/ResourceManager.h"
#include "HitBox.h"

class Creep {
public:
	Creep();
	~Creep();
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render(sf::RenderWindow* window);

	HitBox* getHitBox() { return m_HitBox; }
	void setStartPoint(sf::Vector2f point) { m_startPoint = point; }

	void Reset();
	bool isStop() { return m_stop; }
protected:
	sf::Vector2f m_startPoint;
	HitBox* m_HitBox;
	Animation* m_currentAni;
	// cho giet quai nhung ko dung den nx vi k giet dc quai :((
	Animation* m_deathAni;//x
	Animation* m_runAni;//x

	bool m_stop;
	bool m_soundDeadisPlay;// cho giết quái // x
};