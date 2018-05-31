#include "..\Common\DeviceResources.h"

namespace FlappyDX
{
	// This sample renderer instantiates a basic rendering pipeline.
	class SampleSpriteRenderer
	{
	public:
		SampleSpriteRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		void CreateDeviceDependentResourcesAsync();
		void CreateWindowSizeDependentResources();
		void ReleaseDeviceDependentResources();
		void Render();

	private:
		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources> m_deviceResources;

		// Direct3D resources for cube geometry.
		winrt::com_ptr<ID3D11ShaderResourceView> m_texture;
		std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
		std::unique_ptr<DirectX::CommonStates> m_states;
		DirectX::SimpleMath::Vector2 m_screenPos;
		DirectX::SimpleMath::Vector2 m_origin;

		// Variables used with the rendering loop.
		bool	m_loadingComplete;
	};
}

