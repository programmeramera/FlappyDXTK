#include "pch.h"
#include "SampleSpriteRenderer.h"

#include "..\Common\DirectXHelper.h"
#include <future>


using namespace winrt;
using namespace FlappyDX;
using namespace DirectX;

// Loads vertex and pixel shaders from files and instantiates the cube geometry.
SampleSpriteRenderer::SampleSpriteRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources) :
	m_loadingComplete(false),
	m_deviceResources(deviceResources)
{
	CreateDeviceDependentResourcesAsync();
	CreateWindowSizeDependentResources();
}

// Initializes view parameters when the window size changes.
void SampleSpriteRenderer::CreateWindowSizeDependentResources()
{
	auto outputSize = m_deviceResources->GetOutputSize();
	m_screenPos.x = outputSize.Width / 2.f;
	m_screenPos.y = outputSize.Height / 2.f;
}

// Renders one frame using the vertex and pixel shaders.
void SampleSpriteRenderer::Render()
{
	// Loading is asynchronous. Only draw geometry after it's loaded.
	if (!m_loadingComplete)
	{
		return;
	}

	m_spriteBatch->Begin(SpriteSortMode_Deferred, m_states->NonPremultiplied());
	m_spriteBatch->Draw(m_texture.get(), m_screenPos, nullptr, Colors::White, 0.f, m_origin, 5.0f, DirectX::SpriteEffects::SpriteEffects_None, 0.f);
	m_spriteBatch->End();
}

void SampleSpriteRenderer::CreateDeviceDependentResourcesAsync()
{
	auto device = m_deviceResources->GetD3DDevice();
	auto deviceContext = m_deviceResources->GetD3DDeviceContext();

	m_spriteBatch = std::make_unique<SpriteBatch>(deviceContext);

	com_ptr<ID3D11Resource> resource;
	check_hresult(
		CreateWICTextureFromFile(device, L"assets//StoreLogo.png",
			resource.put(),
			m_texture.put()));

	com_ptr<ID3D11Texture2D> cat;
	cat = resource.as<ID3D11Texture2D>();

	CD3D11_TEXTURE2D_DESC catDesc;
	cat->GetDesc(&catDesc);

	m_origin.x = float(catDesc.Width / 2);
	m_origin.y = float(catDesc.Height / 2);

	m_states = std::make_unique<CommonStates>(device);

	m_loadingComplete = true;
}

void SampleSpriteRenderer::ReleaseDeviceDependentResources()
{
	m_loadingComplete = false;
	m_states = nullptr;
	m_spriteBatch = nullptr;
	m_texture = nullptr;
}