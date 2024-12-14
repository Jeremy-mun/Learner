#pragma once

#include "core.h"
class API App
{
public:
	App();
	virtual ~App();

	void Run();
};

App* CreateApp();

