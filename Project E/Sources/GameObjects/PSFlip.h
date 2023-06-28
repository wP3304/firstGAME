#pragma once
#pragma once
#include "IPState.h"
#include "IPlayer.h"

class PSFlip :public IPState {
public:
	PSFlip(IPlayer* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IPlayer* m_Player;
	Animation* m_Animation;
	bool check_flip = false;

};