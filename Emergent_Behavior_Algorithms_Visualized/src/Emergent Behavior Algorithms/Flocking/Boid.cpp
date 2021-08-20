#include "Boid.h"

Boid::Boid(const glm::vec2&  position, 
		   const glm::vec2&  direction, 
		   const olc::Pixel& colour)
	:
	pos(position), 
	dir(direction),
	m_colour(colour)
{}

const olc::Pixel& Boid::GetColour() const
{
	return m_colour;
}
