#pragma once

#ifdef WH_PLATFORM_WINDOWS
	extern Whatta::Application* Whatta::CreateApplication();
	int main(int argc, char** argv)
	{
		Whatta::Log::Init();
		auto app = Whatta::CreateApplication();
		app->Run();
		delete app;
	}
#else
	#error Whatta only supports Windows!!!
#endif // WH_PLATFORM_WINDOWS
