#define OLC_PGE_APPLICATION
#include "Application.h"

int main()
{
	Application* app = new Application();

	if (app->Construct(1200, 700, 1, 1, false, true, false))
	{
		app->Start();
	}

	app = nullptr;
	delete app;

	return 0;
}