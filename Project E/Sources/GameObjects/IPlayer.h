#pragma once
#include "IPState.h"
#include "HitBox.h"

class IPlayer
{
public:
	virtual void changeNextState(IPState::STATE nextState)=0;
	virtual HitBox* getHitBox() = 0;
	inline void set_flip(bool check) { check_flp = check; }
	bool check_flip() { return check_flp; }
private:
	bool check_flp=false;
};