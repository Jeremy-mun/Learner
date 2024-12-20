#include "pch.h"
#include "App.h"

#include "Events/Event.h"
#include "Core/Events/ApplicationEvent.h"
#include "Core/Log.h"

namespace Engine 
{
	App::App()
	{

	}

	App::~App()
	{

	}

	void App::Run()
	{
		WindowResizeEvent e(1280, 720);
		TRACE(e.ToString());

		while (true);
	}
}