#ifndef APPLICATION_H
#define APPLICATION_H

// All scenes here
#include "Emergent Behavior Algorithms/Flocking/Flocking.h"

class Application : public olc::PixelGameEngine
{
public:
	Application();
	~Application();

	bool OnUserCreate()				   override;
	bool OnUserUpdate(float deltaTime) override;
	bool OnUserDestroy()			   override;
private:
	ISimulation* m_simulation;
};

#endif