#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Whatta {
	
	class WHATTA_API Application
	{
	public :
		Application();
		virtual ~Application();
		void Run();
	};
	Application* CreateApplication();
}


