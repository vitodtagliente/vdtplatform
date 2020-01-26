/// Copyright (c) Vito Domenico Tagliente

#pragma once

namespace platform
{
	class FPS
	{
	public:

		friend class Application;

		FPS();

		unsigned int get() const { return m_fps; }
		
	private:

		void update(const double deltaTime);

		double m_frames;
		double m_time;
		unsigned int m_fps;
	};
}