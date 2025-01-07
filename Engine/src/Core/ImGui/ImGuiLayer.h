#pragma once

#include "Core/Layers/Layer.h"
#include "Core/App.h"
#include "Core/Events/AppEvent.h"
#include "Core/Events/KeyEvent.h"
#include "Core/Events/MouseEvent.h"

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
		bool OnMouseButtonPressedEvent  (MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent (MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent          (MouseMovedEvent& e);
		bool OnMouseScrolledEvent       (MouseScrolledEvent& e);
		bool OnKeyPressedEvent          (KeyPressedEvent& e);
		bool OnKeyReleasedEvent         (KeyReleasedEvent& e);
		bool OnKeyTypedEvent            (KeyTypedEvent& e);
		bool OnWindowResizeEvent        (WindowResizeEvent& e);

		float m_Time = 0.0f;
	};
}