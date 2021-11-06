#include "FlockingSim.h"

namespace Flocking
{
	FlockingSim::FlockingSim(olc::PixelGameEngine* pge)
		:
		SimulationBase(pge),
		m_separation(1.0f),
		m_alignment(1.0f),
		m_cohesion(1.0f)
	{}

	void FlockingSim::Init()
	{
		for (int i = 0; i < NUM_BOIDS; ++i)
		{
			float randX = glm::linearRand(0.f, (float)m_screenWidth);
			float randY = glm::linearRand(0.f, (float)m_screenHeight);

			glm::vec2 pos = glm::vec2(randX, randY);
			glm::vec2 vel = glm::circularRand(40.f);

			// Pick 2 random colours
			// Interpolate between then with a random t value
			std::vector<olc::Pixel> availableColours =
			{
				olc::RED,
				olc::GREEN,
				olc::BLUE,
				olc::YELLOW,
				olc::WHITE,
			};

			int idx1 = glm::linearRand(0, (int)availableColours.size() - 1);
			olc::Pixel col1 = availableColours[idx1];
			availableColours.erase(availableColours.begin() + idx1);

			int idx2 = glm::linearRand(0, (int)availableColours.size() - 1);
			olc::Pixel col2 = availableColours[idx2];

			float t = glm::linearRand(0.f, 1.f);
			float r = glm::lerp((float)col1.r, (float)col2.r, t);
			float g = glm::lerp((float)col1.g, (float)col2.g, t);
			float b = glm::lerp((float)col1.b, (float)col2.b, t);
			olc::Pixel randColour(r, g, b);

			Boid* boid = new Boid(pos, vel, randColour);
			m_boids.emplace_back(boid);
		}
	}

	void FlockingSim::Update(float deltaTime)
	{
		if (m_pge->GetKey(olc::O).bHeld) m_separation = glm::max(0.01f, m_separation - deltaTime);
		if (m_pge->GetKey(olc::P).bHeld) m_separation = glm::min(20.f, m_separation + deltaTime);

		if (m_pge->GetKey(olc::K).bHeld) m_alignment = glm::max(0.01f, m_alignment - deltaTime);
		if (m_pge->GetKey(olc::L).bHeld) m_alignment = glm::min(20.f, m_alignment + deltaTime);

		if (m_pge->GetKey(olc::N).bHeld) m_cohesion = glm::max(0.01f, m_cohesion - deltaTime);
		if (m_pge->GetKey(olc::M).bHeld) m_cohesion = glm::min(20.f, m_cohesion + deltaTime);

		// std::cout << "Separation: " << m_separation << std::endl;
		// std::cout << "Alignment: " << m_alignment << std::endl;
		// std::cout << "Cohesion: " << m_cohesion << std::endl << std::endl;

		for (Boid* boid : m_boids)
		{
			boid->Update(m_boids, deltaTime, m_separation, m_alignment, m_cohesion);

			// Wrap-Around
			if (boid->pos.x < 0.f)			  boid->pos.x += m_screenWidth;
			if (boid->pos.y < 0.f)			  boid->pos.y += m_screenHeight;
			if (boid->pos.x > m_screenWidth)  boid->pos.x -= m_screenWidth;
			if (boid->pos.y > m_screenHeight) boid->pos.y -= m_screenHeight;
		}
	}

	void FlockingSim::Render()
	{
		m_pge->Clear(BG_CLR);

		for (Boid* boid : m_boids)
		{
			float angle = glm::atan(boid->vel.y, boid->vel.x);

			Body body;
			body.Rotate(angle)
				.Translate(boid->pos);

			m_pge->DrawTriangle(body.points[0].x, body.points[0].y,
							    body.points[1].x, body.points[1].y, 
							    body.points[2].x, body.points[2].y, 
							    boid->GetColour());
		}
	}

	void FlockingSim::Exit() {}
}