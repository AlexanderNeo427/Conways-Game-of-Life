#ifndef BOID
#define BOID

#include "olcPixelGameEngine.h"
#include "Body.h"

namespace Flocking
{
	class Boid
	{
	private:
		const float MAX_SPEED	 = 3.5f;
		const float VISUAL_RANGE = 220.f;
	public:
		Boid(const glm::vec2&  position, 
			 const glm::vec2&  direction, 
			 const olc::Pixel& colour);

		void Update(const std::vector<Boid*>& boids, float deltaTime, 
					float separation, float alignment, float cohesion);
		const olc::Pixel& GetColour() const;
	private:
		std::vector<Boid*> GetNeighbours(const std::vector<Boid*>& boids);
		glm::vec2 Separation(const std::vector<Boid*>& neighbours);
		glm::vec2 Alignment(const std::vector<Boid*>& neighbours);
		glm::vec2 Cohesion(const std::vector<Boid*>& neighbours);
	public:
		float	  speed;
		glm::vec2 pos;
		glm::vec2 vel;
		glm::vec2 accel;
	private:
		olc::Pixel m_colour;
	};
}

#endif
