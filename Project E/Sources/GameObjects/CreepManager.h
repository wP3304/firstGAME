#pragma once
#include "../GameManager/ResourceManager.h"
#include "CreepGirl.h"
#include"CreepBat.h"
#include"CreepBatunder.h"
#include "CreepGirlunder.h"
#include"tachmonunder.h"
#include"tachmon.h"
#include"Knight.h"
#include"Mushroom.h"
#include "CollisionManager.h"

class CreepManager {
public:
	CreepManager();
	~CreepManager();
	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

private:
	void SpawnGirl();
	void SpawnBat();
	void SpawnBatunder();
	void SpawnGirlunder();
	void Spawntachmon();
	void Spawntachmonunder();
	void SpawnKnight(); // cờ nai trên
	void SpawnMushroom(); //mushroom dưới

	std::list<Creeptachmon*> m_Listtachmon;
	std::list<Creeptachmonunder*> m_Listtachmonunder;
	std::list<CreepGirl*> m_ListCreepGirl;
	std::list<CreepBat*> m_ListCreepBat;
	std::list<CreepBatunder*> m_ListCreepBatunder;
	std::list<CreepGirlunder*> m_ListCreepGirlunder;
	std::list<CreepKnight*> m_ListCreepKnight;
	std::list<CreepMushroom*> m_ListMushroom;
	int m_CreepNum;
	float m_TimeSpwanCreep;
	float m_currentTime;
};