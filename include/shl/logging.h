#pragma once

#include <iostream>
#include <cstring>

#ifdef SHLIB_LOG_TO_FILE
#ifndef SHLIB_TARGET_LOG_FILE
#define SHLIB_TARGET_LOG_FILE "logs.txt"
#endif
#endif

#define SHLIB_LOG_LEVEL_DEBUG 0
#define SHLIB_LOG_LEVEL_INFO 1
#define SHLIB_LOG_LEVEL_WARN 2
#define SHLIB_LOG_LEVEL_ERROR 3

#if defined(SHLIB_LOG_ALL)
#define SHLIB_LOG_LEVEL SHLIB_LOG_LEVEL_DEBUG
#elif defined(SHLIB_LOG_INFO)
#define SHLIB_LOG_LEVEL SHLIB_LOG_LEVEL_INFO
#elif defined(SHLIB_LOG_WARN)
#define SHLIB_LOG_LEVEL SHLIB_LOG_LEVEL_WARN
#elif defined(SHLIB_LOG_ERROR)
#define LOG_LEVEL_SHLIB_LOG_LEVEL_ERROR
#else
#define SHLIB_LOG_LEVEL SHLIB_LOG_LEVEL_DEBUG
#endif



#define CHECK_LOG_LEVEL(X) SHLIB_LOG_LEVEL <= X

#define FATAL_ERROR(...) shl::logFatal(__VA_ARGS__)

#if CHECK_LOG_LEVEL(SHLIB_LOG_LEVEL_ERROR)
#define LOG_ERROR(...) shl::logError(__VA_ARGS__)
#else
#define LOG_ERROR(...)
#endif

#if CHECK_LOG_LEVEL(SHLIB_LOG_LEVEL_WARN)
#define LOG_WARN(...) shl::logWarn(__VA_ARGS__)
#else
#define LOG_WARN(...)
#endif

#if CHECK_LOG_LEVEL(SHLIB_LOG_LEVEL_INFO)
#define LOG_INFO(...) shl::logInfo(__VA_ARGS__)
#else
#define LOG_INFO(...)
#endif

#if CHECK_LOG_LEVEL(SHLIB_LOG_LEVEL_DEBUG)
#define LOG_DEBUG(...) shl::logDebug(__VA_ARGS__)
#else
#define LOG_DEBUG(...)
#endif

namespace shl {
	template<typename T>
	static void print(T arg)
	{
		std::cout << arg;
	}

	template<typename T, typename...Args>
	static void print(T toPrint, Args... args)
	{
		std::cout << toPrint;
		print(args...);
	}

	template<typename...Args>
	static void println(Args... args)
	{
		print(args...);
		std::cout << '\n';
	}

	static const char* cutFilepath(const char* filepath) {
		size_t index = strlen(filepath);
		for (; index > 0; index--)
		{
			if (filepath[index - 1] == '\\' || filepath[index - 1] == '/')
				break;
		}
		return filepath + index;
	}

	template<typename... Args>
	static void logFatal(Args... args)
	{
#ifndef SHLIB_LOG_TO_FILE
		std::cout << "\033[31m[FATAL ERROR";
		println("]: [", args..., "]\033[0m");
		//std::cerr << e.what() << "\033[0m" << std::endl;
#endif
		exit(EXIT_FAILURE);
	}


	template<typename...Args>
	static void logError(Args... args)
	{
#if CHECK_LOG_LEVEL(SHLIB_LOG_LEVEL_ERROR)
		std::cout << "\033[31m[ERROR";
		println("]: [", args..., "]\033[0m");
#endif
	}

	template<typename...Args>
	static void logWarn(Args... args)
	{
#if CHECK_LOG_LEVEL(SHLIB_LOG_LEVEL_WARN)
		std::cout << "\033[33m[WARNING";
		println("]: [", args..., "]\033[0m");
#endif
	}

	template<typename...Args>
	static void logInfo(Args... args)
	{
#if CHECK_LOG_LEVEL(SHLIB_LOG_LEVEL_INFO)
		std::cout << "\033[32m[INFO";
		println("]: [", args..., "]\033[0m");
#endif
	}

	template<typename...Args>
	static void logDebug(Args... args)
	{
#if CHECK_LOG_LEVEL(SHLIB_LOG_LEVEL_DEBUG)
		std::cout << "[DEBUG";
		println("]: [", args..., ']');
#endif
	}
}