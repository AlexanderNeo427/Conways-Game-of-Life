#include "Flocking.h"

Flocking::Flocking(int scrWidth, int scrHeight)
	:
	m_screenWidth(scrWidth),
	m_screenHeight(scrHeight)
{}

void Flocking::Init()
{
	for (int i = 0; i < NUM_BOIDS; ++i)
	{
		float randX = glm::linearRand(0.f, (float)m_screenWidth);
		float randY = glm::linearRand(0.f, (float)m_screenHeight);

		glm::vec2 pos = glm::vec2(randX, randY);
		glm::vec2 dir = glm::circularRand(1.f);

		int r = glm::linearRand(0, 255);
		int g = glm::linearRand(0, 255);
		int b = glm::linearRand(0, 255);
		olc::Pixel randColour(r, g, b);

		m_boids.emplace_back(new Boid(pos, dir, randColour));
	}
}

void Flocking::Update(float deltaTime)
{
	for (Boid* boid : m_boids)
	{
	}
}

void Flocking::Render(olc::PixelGameEngine* pge)
{
	pge->Clear(olc::BLACK);

	for (Boid* boid : m_boids)
	{
		float angle = glm::atan(boid->dir.y, boid->dir.x);
		
		Body body;
		body.Scale(glm::vec2(26.f, 15.5f)).Rotate(pge->GetElapsedTime()).Translate(glm::vec2(250.f, 150.f));

		pge->DrawTriangle(body.points[0].x, body.points[0].y, 
						  body.points[1].x, body.points[1].y, 
						  body.points[2].x, body.points[2].y, 
						  boid->GetColour());
	}
}


void Flocking::Exit()
{
}
