#ifndef FLOCKING_SIMULATION
#define FLOCKING_SIMULATION

#include "../src/ISimulation.h"
#include "Boid.h"
#include <vector>

namespace Flocking
{
	class FlockingSim : public ISimulation
	{
	private:
		static const int NUM_BOIDS = 400;
		const olc::Pixel BG_CLR	   = olc::Pixel(1.f, 1.f, 1.f);
	public:
		FlockingSim(olc::PixelGameEngine* pge);

		void Init()					 override;
		void Update(float deltaTime) override;
		void Render()				 override;
		void Exit()					 override;
	private:
		olc::PixelGameEngine* m_pge;

		std::vector<Boid*> m_boids;

		int m_screenWidth;
		int m_screenHeight;

		float m_separation;
		float m_alignment;
		float m_cohesion;
	};
}

#endif

