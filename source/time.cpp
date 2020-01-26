#include <vdtplatform/time.h>

#include <vdtplatform/api.h>

namespace platform
{
	Time::Time(API* const api)
		: m_api(api)
		, m_startingClock()
		, m_clock()
		, m_time(0.0)
		, m_deltaTime(0.0)
	{
		m_startingClock = m_clock = std::chrono::high_resolution_clock::now();
	}

	void Time::tick()
	{
		const auto& m_clock = std::chrono::high_resolution_clock::now();
		const double temp_time = static_cast<double>(
			std::chrono::duration_cast<std::chrono::milliseconds>(
			m_clock - m_startingClock
			).count());
		
		m_deltaTime = temp_time - m_time;
		m_time = temp_time;
	}
	
	void Time::reset()
	{
		m_startingClock = m_clock = std::chrono::high_resolution_clock::now();
		m_time = 0.0;
		m_deltaTime = 0.0;
	}
}