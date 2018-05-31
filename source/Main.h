#pragma once

#include "common\StepTimer.h"
#include "common\DeviceResources.h"
#include "content\Sample3DSceneRenderer.h"
#include "content\SampleFpsTextRenderer.h"
#include "content\SampleSpriteRenderer.h"

// Renders Direct2D and 3D content on the screen.
namespace FlappyDX
{
	class Main : public DX::IDeviceNotify
	{
	public:
		Main(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		~Main();
		void CreateWindowSizeDependentResources();
		void Update();
		bool Render();

		// IDeviceNotify
		virtual void OnDeviceLost();
		virtual void OnDeviceRestored();

	private:
		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources> m_deviceResources;

		// TODO: Replace with your own content renderers.
		std::unique_ptr<FlappyDX::Sample3DSceneRenderer> m_sceneRenderer;
		std::unique_ptr<FlappyDX::SampleFpsTextRenderer> m_fpsTextRenderer;
		std::unique_ptr<FlappyDX::SampleSpriteRenderer> m_spriteRenderer;

		// Rendering loop timer.
		DX::StepTimer m_timer;
	};
}