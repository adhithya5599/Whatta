#include "whpch.h"

#include "Application.h"
#include "Events/ApplicationEvent.h"

#include "Log.h"

namespace Whatta {
	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		WH_INFO("Started the application");
		WindowResizeEvent e(1280, 720);
		WH_CORE_TRACE(e);
		while (true);
	}
}