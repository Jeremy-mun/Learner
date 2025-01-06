#pragma once

#include "Core/Layers/Layer.h"
#include "Core/App.h"

namespace Engine
{
	class API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& e);
	private:
		float m_Time = 0.0f;
	};
}