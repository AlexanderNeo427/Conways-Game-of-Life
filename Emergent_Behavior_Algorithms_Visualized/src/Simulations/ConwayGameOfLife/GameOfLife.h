#ifndef CONWAY_GAME_OF_LIFE
#define CONWAY_GAME_OF_LIFE

#include "olcPixelGameEngine.h"
#include "../SimulationBase.h"

namespace GOL
{
	class GameOfLife : public SimulationBase
	{
	public:
		struct Direction 
		{ 
			int x, y; 
			Direction(int _x, int _y) : x(_x), y(_y) {};
		};
	private:
		const float	TIME_STEP = 0.1f;
	public:
		GameOfLife(olc::PixelGameEngine* pge);

		void Init()					 override;
		void Update(float deltaTime) override;
		void Render()				 override;
		void Exit()					 override;

		int GetLiveNeighbourCount(int x, int y, bool* gridCopy);
	private:
		void MakeGridCopy(bool* grid, bool *gridCopy, int n);
	private:
		bool *m_grid, *m_gridCopy;
		int	  m_numGridCells;

		float m_timeStep;
		float m_timeSinceLastStep;
		bool  m_isRunning;

		std::vector<Direction> m_directions;
	};
}

#endif
