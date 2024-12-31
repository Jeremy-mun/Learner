#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Events/AppEvent.h"

namespace Engine 
{
	class API App
	{
	public:
		App();
		virtual ~App();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be define in CLIENT
	App* CreateApp();
}

