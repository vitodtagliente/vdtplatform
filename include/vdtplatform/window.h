/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include <cstdint>
#include <string>

namespace platform
{
	class Window
	{
	public:

		// generic window settings
		struct Settings
		{
			Settings();

			std::string title;
			std::uint32_t width, height;
			bool fullscreen;
			bool vsync;
		};

		Window();

		// open the window
		bool open(const Settings& settings);
		void close();
		// update the window
		void update();

		inline bool isOpen() const { return m_isOpen; }

		virtual void setTitle(const std::string& title) = 0;
		virtual void resize(const std::uint32_t width, const std::uint32_t height) = 0;

		virtual std::uint32_t getWidth() const = 0;
		virtual std::uint32_t getHeight() const = 0;

	protected:

		// open the window 
		virtual bool open_implementation(const Settings& settings) = 0;
		virtual void close_implementation() = 0;
		// update the window
		virtual void update_implementation() = 0;

		// window state
		bool m_isOpen;
	};
}