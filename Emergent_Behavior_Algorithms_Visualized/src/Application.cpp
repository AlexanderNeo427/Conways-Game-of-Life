#include "Application.h"

Application::Application()
	:
	m_simulation(nullptr)
{}

Application::~Application()
{
	if (m_simulation != nullptr)
	{
		delete m_simulation;
		m_simulation = nullptr;
	}
}

bool Application::OnUserCreate()
{
	m_simulation = new Flocking(ScreenWidth(), ScreenHeight());
	m_simulation->Init();
	return true;
}

bool Application::OnUserUpdate(float deltaTime)
{
	m_simulation->Update(deltaTime);
	m_simulation->Render(this);
	return true;
}

bool Application::OnUserDestroy()
{
	m_simulation->Exit();
	return true;
}
