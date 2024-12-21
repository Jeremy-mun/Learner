#pragma once

#include "core.h"
#include "Window.h"

namespace Engine 
{
	class API App
	{
	public:
		App();
		virtual ~App();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be define in CLIENT
	App* CreateApp();
}

