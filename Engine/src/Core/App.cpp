#include "pch.h"
#include "App.h"
#include "Log.h"

#include <GLFW/glfw3.h>

namespace Engine 
{

#define BIND_EVENT_FN(x) std::bind(&App::x, this, std::placeholders::_1)

	App::App()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	App::~App()
	{
	}

	void App::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		CORE_TRACE("{0}",e.ToString());
	}

	bool App::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void App::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}