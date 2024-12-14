#pragma once

#ifdef PLATFORM_WINDOWS

extern App* CreateApp();

int main(int argc, char** argv)
{
	auto app = CreateApp();
	app->Run();
	delete app;
}

#endif
