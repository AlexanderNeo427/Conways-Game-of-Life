#ifndef BODY
#define BODY

#include "glm/glm.hpp"
#include "glm/common.hpp"
#include "glm/gtx/compatibility.hpp"

#include "glm/gtc/constants.hpp"
#include "glm/gtc/random.hpp"

#include "glm/mat3x3.hpp"
#include "glm/vec2.hpp"

namespace Flocking
{
	struct Body
	{
		glm::vec2 points[3];

		Body()
		{
			points[0] = glm::vec2( 7.f,  0.f);
			points[1] = glm::vec2(-3.f, -2.8f);
			points[2] = glm::vec2(-3.f,  2.8f);
		}

		Body& Rotate(float theta)
		{
			float cosTheta = glm::cos(theta);
			float sinTheta = glm::sin(theta);

			for (int i = 0; i < 3; ++i)
			{
				float x = points[i].x;
				float y = points[i].y;
				points[i].x = cosTheta * x - sinTheta * y;
				points[i].y = sinTheta * x + cosTheta * y;
			}
			return *this;
		}

		Body& Translate(const glm::vec2& translation)
		{
			for (int i = 0; i < 3; ++i)
			{
				points[i] += translation;
			}
			return *this;
		}
	};
}

#endif