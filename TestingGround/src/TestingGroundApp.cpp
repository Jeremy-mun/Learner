#include "Engine.h"

class TestingGround : public Engine::App
{
public:
	TestingGround()
	{

	}

	~TestingGround()
	{

	}
};

Engine::App* Engine::CreateApp()
{
	return new TestingGround();
}