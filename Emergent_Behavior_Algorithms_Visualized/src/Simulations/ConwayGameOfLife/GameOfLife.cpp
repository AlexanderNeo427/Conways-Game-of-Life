#include "GameOfLife.h"

GameOfLife::GameOfLife(olc::PixelGameEngine* pge) 
	:
	SimulationBase(pge), 
	m_grid(nullptr),
	m_numGridCells(0),
	m_gridSizeX(0), m_gridSizeY(0), 
	m_gridDeltaX(0), m_gridDeltaY(0),
	m_timeSinceLastStep(0.f),
	m_isRunning(false)
{}

void GameOfLife::Init()
{
	m_numGridCells = NUM_GRID_X * NUM_GRID_Y;

	m_grid = m_gridCopy = new bool[m_numGridCells];
	for (int i = 0; i < m_numGridCells; ++i)
	{
		m_grid[i] = m_gridCopy[i] = false;
	}

	m_gridDeltaX = m_screenWidth / NUM_GRID_X;
	m_gridDeltaY = m_screenHeight / NUM_GRID_Y;

	m_gridSizeX = m_gridDeltaX * (1.f - GRID_OFFSET);
	m_gridSizeY = m_gridDeltaY * (1.f - GRID_OFFSET);

	m_directions =
	{
		Direction(-1, 1),
		Direction( 0, 1),
		Direction( 1, 1),
		Direction( 1, 0),
		Direction( 1,-1),
		Direction( 0,-1),
		Direction(-1,-1),
		Direction(-1, 0),
	};
}

void GameOfLife::Update(float deltaTime)
{
	//------------- Input ---------------
	if (m_pge->GetMouse(0).bPressed)
	{
		int gridX = m_pge->GetMouseX() / NUM_GRID_X;
		int gridY = m_pge->GetMouseY() / NUM_GRID_Y;
		int index = (gridY * NUM_GRID_X) + gridX;

		m_grid[index] = !m_grid[index];
		*m_gridCopy = *m_grid;
	}

	if (m_pge->GetKey(olc::SPACE).bPressed)
		m_isRunning = !m_isRunning;

	//------------ Pause state -------------
	if (!m_isRunning) return;

	//--------- Simulation Logic ---------
	m_timeSinceLastStep += deltaTime;

	if (m_timeSinceLastStep < TIME_STEP)
		return;

	m_timeSinceLastStep = 0.f;

	// Update rules
	*m_gridCopy = *m_grid;

	for (int y = 0; y < NUM_GRID_Y; ++y)
	{
		for (int x = 0; x < NUM_GRID_X; ++x)
		{
			int index = (y * NUM_GRID_X) + x;

			if (m_gridCopy[index] == true)
			{
				int neighbourCount = GetLiveNeighbourCount(x, y, m_gridCopy);

				if (neighbourCount != 2 && neighbourCount != 3)
					m_grid[index] = false;
			}
			else
			{
				int neighbourCount = GetLiveNeighbourCount(x, y, m_gridCopy);

				if (neighbourCount == 3)
					m_grid[index] = true;
			}
		}
	}
}

void GameOfLife::Render()
{
	m_pge->Clear(olc::DARK_GREY);

	int posX = GRID_OFFSET;
	int posY = GRID_OFFSET;

	for (int y = 0; y < NUM_GRID_Y; ++y)
	{
		for (int x = 0; x < NUM_GRID_X; ++x)
		{
			int index = (y * NUM_GRID_X) + x;
			olc::Pixel fillColor = m_grid[index] ? olc::BLACK : olc::WHITE;
			m_pge->FillRect(posX, posY, m_gridSizeX, m_gridSizeY, fillColor);
			posX += m_gridDeltaX;
		}
		posY += m_gridDeltaY;
		posX = GRID_OFFSET;
	}
}

void GameOfLife::Exit() {}

int GameOfLife::GetLiveNeighbourCount(int x, int y, bool* grid) 
{
	int numNeighbours = 0;

	for (Direction const& dir : m_directions)
	{
		int nextX = x + dir.x;
		int nextY = y + dir.y;

		if (nextX < 0 || nextX >= NUM_GRID_X ||
			nextY < 0 || nextY >= NUM_GRID_Y)
		{
			continue;
		}

		if (grid[(nextY * NUM_GRID_X) + nextX])
			++numNeighbours;
	}

	return numNeighbours;
}
