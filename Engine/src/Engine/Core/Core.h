#pragma once
#ifdef ENGINE_PLATFORM_WINDOWS



#else
	#error ENGINE ONLY SUPPORTS WINDOWS!
#endif // ENGINE_PLATFORM_WINDOWS

#ifdef ENGINE_ENABLE_ASSERTS
	#define ENGINE_ASSERT(x, ...) { if(!(x)) {ENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();} }
	#define ENGINE_CORE_ASSERT(x, ...) { if(!(x)) {ENGINE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();} }
#else
	#define ENGINE_ASSERT(x, ...)
	#define ENGINE_CORE_ASSERT(x, ...) 
#endif // ENGINE_ENABLE_ASSERTS

#ifdef NDEBUG
	#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup");
#endif


//禁止输入法
#pragma comment(lib, "imm32.lib")


//用于绑定事件的函数
#define ENGINE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
//用于事件过滤标志
#define BIT(x) (1 << x)

#include "Log.h"
