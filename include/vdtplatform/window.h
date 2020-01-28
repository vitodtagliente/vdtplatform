/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include <cstdint>
#include <set>
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

		class IListener
		{
		public:
			virtual void onClose() {};
			virtual void onOpen() {};
			virtual void onResize(const std::uint32_t width, const std::uint32_t height) {};
			virtual void onUpdate() {};
		};

		enum class State
		{
			Create,
			Closing,
			Closed,
			Error,
			Open
		};

		Window();
		virtual ~Window() = default;

		/// Open the window
		/// @param settings   The Window settings
		/// @return true if successful
		bool open(const Settings& settings);
		/// Update the window
		State update();
		/// Close the window
		void close();

		State getState() const { return m_state; }

		virtual void setTitle(const std::string& title) = 0;
		virtual void resize(const std::uint32_t width, const std::uint32_t height);

		virtual std::uint32_t getWidth() const = 0;
		virtual std::uint32_t getHeight() const = 0;

		/// listeners management
		void registerListener(IListener* const listener);
		void unregisterListener(IListener* const listener);

	protected:

		// open the window 
		virtual bool openImplementation(const Settings& settings) = 0;
		virtual void closeImplementation() = 0;
		// update the window
		virtual void updateImplementation() = 0;

		// window state
		State m_state;
		// window listeners
		std::set<IListener*> m_listeners;

	};
}