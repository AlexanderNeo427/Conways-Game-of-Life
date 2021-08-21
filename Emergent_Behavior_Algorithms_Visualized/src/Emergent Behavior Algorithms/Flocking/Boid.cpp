#include "Boid.h"

Boid::Boid(const glm::vec2&  position, 
		   const glm::vec2&  velocity, 
		   const olc::Pixel& colour)
	:
	speed(50.f),
	pos(position), 
	vel(velocity),
	accel(glm::vec2(0.f)),
	m_colour(colour)
{}

void Boid::Update(const std::vector<Boid*>& boids, float deltaTime, 
				  float separation, float alignment, float cohesion)
{
	std::vector<Boid*> neighbours = GetNeighbours(boids);

	if (neighbours.size() == 0)
	{
		pos += vel * deltaTime * speed;
		return;
	}

	accel = glm::vec2(0.f);
	accel += Alignment(neighbours) * alignment;
	accel += Cohesion(neighbours) * cohesion;
	accel += Separation(neighbours) * separation;

	vel += accel * deltaTime;

	if (vel.length() > MAX_SPEED)
		vel = glm::normalize(vel) * MAX_SPEED;

	pos += vel * deltaTime * speed;
}

const olc::Pixel& Boid::GetColour() const
{
	return m_colour;
}

std::vector<Boid*> Boid::GetNeighbours(const std::vector<Boid*>& boids)
{
	std::vector<Boid*> neighbours;

	for (Boid* boid : boids)
	{
		if (boid == this) continue;

		if (glm::distance(this->pos, boid->pos) <= VISUAL_RANGE)
		{
			neighbours.emplace_back(boid);
		}
	}

	return neighbours;
}

glm::vec2 Boid::Separation(const std::vector<Boid*>& neighbours)
{
	glm::vec2 separation = glm::vec2(0.f);

	for (Boid* neighbour : neighbours)
		separation += (neighbour->pos - this->pos);

	separation *= (1.f / (float)neighbours.size());

	return glm::normalize(-separation);
}

glm::vec2 Boid::Alignment(const std::vector<Boid*>& neighbours)
{
	glm::vec2 alignment = glm::vec2(0.f);

	for (Boid* neighbour : neighbours)
		alignment += neighbour->vel;

	alignment *= (1.f / (float)neighbours.size());

	return glm::normalize(alignment);
}

glm::vec2 Boid::Cohesion(const std::vector<Boid*>& neighbours)
{
	glm::vec2 cohesion = glm::vec2(0.f);

	for (Boid* neighbour : neighbours)
		cohesion += neighbour->pos;

	cohesion *= (1.f / (float)neighbours.size());

	return glm::normalize(cohesion - this->pos);
}
