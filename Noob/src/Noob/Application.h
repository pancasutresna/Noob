#pragma once

#include "Core.h"


#include "Window.h"
#include "Noob/LayerStack.h"
#include "Noob/Events/Event.h"
#include "Noob/Events/ApplicationEvent.h"


namespace Noob {

	class NOOB_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

