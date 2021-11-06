#ifndef SIMULATION_BASE
#define SIMULATION_BASE

#include "olcPixelGameEngine.h"

class SimulationBase
{
public:
	// Remember sure to call this in your derived classes
	SimulationBase(olc::PixelGameEngine* pge)
		:
		m_pge(pge)
	{
		m_screenWidth  = pge->ScreenWidth();
		m_screenHeight = pge->ScreenHeight();
	}

	virtual void Init()					 = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render()				 = 0;
	virtual void Exit()					 = 0;
protected:
	olc::PixelGameEngine* m_pge;

	int m_screenWidth;
	int m_screenHeight;
};

#endif