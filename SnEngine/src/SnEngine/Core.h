#pragma once

#ifdef SN_PLATFORM_WINDOWS
    #ifdef SN_BUILD_DLL
        #define SN_API __declspec(dllexport)
    #else
        #define SN_API __declspec(dllimport)
    #endif

#else
    #error SnEngine only supports Windows!
#endif

#ifdef SN_ENABLE_ASSERTS
    #define SN_ASSERT(x, ...) { if(!(x)) { SN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define SN_CORE_ASSERT(x, ...) { if(!(x)) { SN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define SN_ASSERT(x, ...)
    #define SN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
#define SN_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
