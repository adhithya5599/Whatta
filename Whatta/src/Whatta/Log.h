#pragma warning(push)
#pragma warning(disable:4251)
#pragma warning(pop)
#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Whatta {

	class WHATTA_API Log
	{
		public:
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// For Core
#define WH_CORE_TRACE(...)		::Whatta::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WH_CORE_INFO(...)		::Whatta::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WH_CORE_WARN(...)		::Whatta::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WH_CORE_ERROR(...)		::Whatta::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WH_CORE_FATAL(...)		::Whatta::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//For Client
#define WH_TRACE(...)		::Whatta::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WH_INFO(...)		::Whatta::Log::GetClientLogger()->info(__VA_ARGS__)
#define WH_WARN(...)		::Whatta::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WH_ERROR(...)		::Whatta::Log::GetClientLogger()->error(__VA_ARGS__)
#define WH_FATAL(...)		::Whatta::Log::GetClientLogger()->fatal(__VA_ARGS__)