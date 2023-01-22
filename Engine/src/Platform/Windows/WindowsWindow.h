#pragma once
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "Engine/Window.h"


namespace Engine
{

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();
		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }


		//窗口属性设置
		void SetEventCallback(const EventCallbackFn& callback) override
		{
			m_Data.EventCallback = callback;
		}
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			//回调函数
			EventCallbackFn EventCallback;
		};

		WindowData m_Data;

	};


}


