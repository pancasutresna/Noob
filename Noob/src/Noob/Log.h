#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"



namespace Noob {

	class NOOB_API Log {

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core Log macros
#define NB_CORE_TRACE(...) ::Noob::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NB_CORE_INFO(...)  ::Noob::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NB_CORE_WARN(...)  ::Noob::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NB_CORE_ERROR(...) ::Noob::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NB_CORE_FATAL(...) ::Noob::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define NB_TRACE(...) ::Noob::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NB_INFO(...)  ::Noob::Log::GetClientLogger()->info(__VA_ARGS__)
#define NB_WARN(...)  ::Noob::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NB_ERROR(...) ::Noob::Log::GetClientLogger()->error(__VA_ARGS__)
#define NB_FATAL(...) ::Noob::Log::GetClientLogger()->fatal(__VA_ARGS__)