#ifndef APPLICATION_H
#define APPLICATION_H

// All scenes here
#include "Simulations/Flocking/FlockingSim.h"
#include "Simulations/ConwayGameOfLife/GameOfLife.h"

class Application : public olc::PixelGameEngine
{
public:
	Application();
	~Application();

	bool OnUserCreate()				   override;
	bool OnUserUpdate(float deltaTime) override;
	bool OnUserDestroy()			   override;
private:
	SimulationBase* m_simulation;
};

#endif