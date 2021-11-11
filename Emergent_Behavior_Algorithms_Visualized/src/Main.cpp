#define OLC_PGE_APPLICATION
#include "Application.h"

int main()
{
	Application* app = new Application();

	if (app->Construct(150, 100, 10, 10))
	{
		app->Start();
	}

	app = nullptr;
	delete app;

	return 0;
}