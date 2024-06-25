#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace SnEngine
{
    class SN_API Log
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
#define SN_CORE_TRACE(...)    ::SnEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SN_CORE_INFO(...)     ::SnEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SN_CORE_WARN(...)     ::SnEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SN_CORE_ERROR(...)    ::SnEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SN_CORE_FATAL(...)    ::SnEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SN_TRACE(...)         ::SnEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SN_INFO(...)          ::SnEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define SN_WARN(...)          ::SnEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SN_ERROR(...)         ::SnEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define SN_FATAL(...)         ::SnEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
