#pragma once

#include "core.h"

namespace Engine 
{
	class API App
	{
	public:
		App();
		virtual ~App();

		void Run();
	};

	// To be define in CLIENT
	App* CreateApp();
}

