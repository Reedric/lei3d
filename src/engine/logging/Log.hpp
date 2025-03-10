#pragma once

#include <spdlog/spdlog.h>

#include <memory>

#ifdef EDITOR
#define LEI_TRACE(...) ::lei3d::Log::GetLogger()->trace(__VA_ARGS__)
#define LEI_INFO(...) ::lei3d::Log::GetLogger()->info(__VA_ARGS__)
#define LEI_WARN(...) ::lei3d::Log::GetLogger()->warn(__VA_ARGS__)
#define LEI_ERROR(...) ::lei3d::Log::GetLogger()->error(__VA_ARGS__)
#define LEI_FATAL(...) ::lei3d::Log::GetLogger()->fatal(__VA_ARGS__)
#else
#define LEI_TRACE(...)
#define LEI_INFO(...)
#define LEI_WARN(...)
#define LEI_ERROR(...)
#define LEI_FATAL(...)
#endif

#ifdef LEI_ENABLE_ASSERTS

	#define LEI_ASSERT(x, ...)                                   \
		{                                                        \
			if (!(x))                                            \
			{                                                    \
				LEI_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
				__debugbreak();                                  \
			}                                                    \
		}

#else

	#define LEI_ASSERT(x, ...)

#endif

namespace lei3d
{
	class Log
	{
	public:
		static void Init();

		inline static spdlog::logger* GetLogger() { return s_Logger.get(); }

	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};
} // namespace lei3d