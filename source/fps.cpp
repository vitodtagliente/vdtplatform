#include <vdtplatform/fps.h>

namespace platform
{
	FPS::FPS()
		: m_frames()
		, m_time()
		, m_fps()
	{
	}

	void FPS::update(const double deltaTime)
	{
		++m_frames;
		m_time += deltaTime;
		if (m_time >= 1.0)
		{
			m_fps = static_cast<unsigned int>(m_frames / m_time);

			m_frames = 0;
			m_time = 0.0;
		}
	}
}