#pragma once

#include "Core.h"

namespace Noob {

	class NOOB_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

