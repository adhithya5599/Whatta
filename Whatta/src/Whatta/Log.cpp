#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Whatta {
	
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n : %v%$"); // Timestamp, name of logger and log message
		
		s_CoreLogger = spdlog::stdout_color_mt("WHATTA");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_CoreLogger->set_level(spdlog::level::trace);
	}
}