#include "pch.h"
#include "App.h"

#include "Events/Event.h"
#include "Core/Events/ApplicationEvent.h"
#include "Core/Log.h"

#include <GLFW/glfw3.h>

namespace Engine 
{
	App::App()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	App::~App()
	{

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