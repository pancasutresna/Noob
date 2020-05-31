#include "nbpch.h"
#include "Application.h"

#include "Noob/Events/ApplicationEvent.h"
#include "Noob/Log.h"

namespace Noob {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		NB_TRACE(e);

		while (true);
	}

}