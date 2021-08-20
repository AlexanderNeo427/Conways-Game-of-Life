#ifndef ISIMULATION
#define ISIMULATION

#include "olcPixelGameEngine.h"

class ISimulation
{
public:
	virtual void Init()							   = 0;
	virtual void Update(float deltaTime)		   = 0;
	virtual void Render(olc::PixelGameEngine* pge) = 0;
	virtual void Exit()							   = 0;
};

#endif