/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include <chrono>

namespace platform
{
	class API;

	class Time
	{
	public:

		friend class Application;

		Time(API* const api);

		// retrieve the time data
		inline double getTime() const { return m_time; }
		inline double getDeltaTime() const { return m_deltaTime; }
		
		void reset();

	private:

		// tick the time
		void tick();

		// high resolution clocks
		std::chrono::high_resolution_clock::time_point m_startingClock;
		std::chrono::high_resolution_clock::time_point m_clock;

		// api
		API* m_api;
		// cache time and delta time
		double m_time;
		double m_deltaTime;
	};
}