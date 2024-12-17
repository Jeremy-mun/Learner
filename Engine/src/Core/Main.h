#pragma once

#ifdef PLATFORM_WINDOWS

extern Engine::App* Engine::CreateApp();

int main(int argc, char** argv)
{
	Engine::Log::Init();
	CORE_WARN("Initialized Log!");
	int a = 5;
	INFO("Hello Var={0}", a);
	auto app = Engine::CreateApp();
	app->Run();
	delete app;
}
#endif
