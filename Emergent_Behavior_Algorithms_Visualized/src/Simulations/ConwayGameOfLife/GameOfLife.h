#ifndef CONWAY_GAME_OF_LIFE
#define CONWAY_GAME_OF_LIFE

#include "olcPixelGameEngine.h"
#include "../SimulationBase.h"

class GameOfLife : public SimulationBase
{
public:
	struct Direction 
	{ 
		int x, y; 
		Direction(int _x, int _y) : x(_x), y(_y) {};
	};
public:
	static const int NUM_GRID_X  = 30;
	static const int NUM_GRID_Y  = 30;
	const float		 TIME_STEP	 = 1.f;
	const float		 GRID_OFFSET = 0.1f;
public:
	GameOfLife(olc::PixelGameEngine* pge);

	void Init()					 override;
	void Update(float deltaTime) override;
	void Render()				 override;
	void Exit()					 override;

	int GetLiveNeighbourCount(int x, int y, bool* gridCopy);
private:
	bool *m_grid, *m_gridCopy;
	int	  m_numGridCells;
	int	  m_gridSizeX, m_gridSizeY;
	int	  m_gridDeltaX, m_gridDeltaY;

	float m_timeSinceLastStep;
	bool  m_isRunning;

	std::vector<Direction> m_directions;
};

#endif
