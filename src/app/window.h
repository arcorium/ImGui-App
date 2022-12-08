#pragma once

#include <string>

#include "util/vector.h"


struct GLFWwindow;

namespace vz
{
	class IWindow
	{
	public:
		virtual ~IWindow() = default;

		[[nodiscard]] virtual vz::Vec2i Size() const = 0;
		[[nodiscard]] virtual vz::Vec2i Position() const = 0;
		[[nodiscard]] virtual std::string Title() const = 0;

		virtual void Move(const vz::Vec2i& pos_) = 0;
		virtual void SetSize(const vz::Vec2i& size_) = 0;

		void Update(float dt_)
		{
			HandleInput();
			Update_Impl(dt_);
		}

		void Render()
		{
			Draw();
			Render_Impl();
		}

	private:
		virtual void HandleInput() {}
		virtual void Update_Impl(float dt_) {}

		virtual void Draw() {}
		virtual void Render_Impl() {}
	};

	class CommonWindow : public IWindow
	{
	public:
		CommonWindow(const std::string& title_, const vz::Vec2i size_, const vz::Vec2i pos_);

		~CommonWindow() override;

		void Move(const vz::Vec2i& pos_) override;
		void SetSize(const vz::Vec2i& size_) override;

		[[nodiscard]] vz::Vec2i Size() const override;
		[[nodiscard]] vz::Vec2i Position() const override;
		[[nodiscard]] std::string Title() const override;

		[[nodiscard]] GLFWwindow* Native() const;
		[[nodiscard]] bool IsClosed() const;

	private:
		void Render_Impl() override;
		void HandleInput() override;

		void InitGLFW();
		void InitGLAD();


	private:
		GLFWwindow* m_nativeWindow;

		std::string m_title;
		mutable vz::Vec2i m_size;
		mutable vz::Vec2i m_position;
	};
}