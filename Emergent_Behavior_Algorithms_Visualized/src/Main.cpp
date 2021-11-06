#define OLC_PGE_APPLICATION
#include "Application.h"

int main()
{
	Application* app = new Application();

	if (app->Construct(900, 900, 1, 1, false, false, false))
	{
		app->Start();
	}

	app = nullptr;
	delete app;

	return 0;
}