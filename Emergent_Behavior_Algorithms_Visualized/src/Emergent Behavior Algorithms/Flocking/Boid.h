#ifndef BOID
#define BOID

#include "olcPixelGameEngine.h"

#include "glm/gtc/random.hpp"
#include "glm/mat3x3.hpp"
#include "glm/common.hpp"
#include "glm/vec2.hpp"

struct Body
{
	glm::vec2 points[3];

	Body()
	{
		points[0] = glm::vec2(1.f, 0.f);
		points[1] = glm::vec2(-1.f, -1.f);
		points[2] = glm::vec2(-1.f, 1.f);
	}

	Body& Rotate(float theta)
	{
		float cs = glm::cos(theta);
		float sn = glm::sin(theta);

		for (int i = 0; i < 3; ++i)
		{
			points[i].x = points[i].x * cs - points[i].y * sn;
			points[i].y = points[i].x * sn + points[i].y * cs;
		}

		return *this;
	}

	Body& Translate(const glm::vec2 &translation)
	{
		for (int i = 0; i < 3; ++i)
		{
			points[i] += translation;
		}

		return *this;
	}

	Body& Scale(const glm::vec2& scale)
	{
		for (int i = 0; i < 3; ++i)
		{
			points[i] *= scale;
		}

		return *this;
	}
};

class Boid
{
public:
	Boid(const glm::vec2&  position, 
		 const glm::vec2&  direction, 
		 const olc::Pixel& colour);

	const olc::Pixel& GetColour() const;
public:
	glm::vec2 pos;
	glm::vec2 dir;
private:
	olc::Pixel m_colour;
};

#endif
