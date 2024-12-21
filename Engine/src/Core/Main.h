#pragma once

#ifdef PLATFORM_WINDOWS

extern Engine::App* Engine::CreateApp();

int main(int argc, char** argv)
{
	Engine::Log::Init();
	CORE_WARN("Initialized Log!");
	INFO("Hello from App!");
	auto app = Engine::CreateApp();
	app->Run();
	delete app;
}
#endif
