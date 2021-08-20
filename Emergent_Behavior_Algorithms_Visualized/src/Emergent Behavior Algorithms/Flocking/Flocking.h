#ifndef FLOCKING_SIMULATION
#define FLOCKING_SIMULATION

#include "../src/ISimulation.h"
#include "Boid.h"

#include <vector>

class Flocking : public ISimulation
{
private:
	static const int NUM_BOIDS = 250;
public:
	Flocking(int scrWidth, int scrHeight);

	void Init();
	void Update(float deltaTime);
	void Render(olc::PixelGameEngine* pge);
	void Exit();
private:
	std::vector<Boid*> m_boids;

	int m_screenWidth;
	int m_screenHeight;
};

#endif

