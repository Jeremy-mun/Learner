#include "Engine.h"

class TestingGround : public App
{
public:
	TestingGround()
	{

	}

	~TestingGround()
	{

	}
};

App* CreateApp()
{
	return new TestingGround();
}