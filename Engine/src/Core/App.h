#pragma once

#include "core.h"

namespace Engine {
	class API App
	{
	public:
		App();
		virtual ~App();

		void Run();
	};

	App* CreateApp();
}

