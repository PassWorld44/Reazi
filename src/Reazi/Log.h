#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Reazi {

	class REAZI_API Log
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

// Core log macros
#define HZ_CORE_TRACE(...)    ::Reazi::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)     ::Reazi::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)     ::Reazi::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)    ::Reazi::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)    ::Reazi::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HZ_TRACE(...)	      ::Reazi::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)	      ::Reazi::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)	      ::Reazi::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)	      ::Reazi::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)	      ::Reazi::Log::GetClientLogger()->fatal(__VA_ARGS__)