#pragma once

#include "Core.h"

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


