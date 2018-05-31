﻿#pragma once

#include "..\Common\DeviceResources.h"
#include "Content\ShaderStructures.h"
#include "..\Common\StepTimer.h"
#include <pplawait.h>

namespace DirectX_Shared
{
	// This sample renderer instantiates a basic rendering pipeline.
	class Sample3DSceneRenderer
	{
	public:
		Sample3DSceneRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		concurrency::task<void> CreateDeviceDependentResourcesAsync();
		void CreateWindowSizeDependentResources();
		void ReleaseDeviceDependentResources();
		void Update(DX::StepTimer const& timer);
		void Render();
		void StartTracking();
		void TrackingUpdate(float positionX);
		void StopTracking();
		bool IsTracking() { return m_tracking; }

	private:
		void Rotate(float radians);
		void LoadVertexShader(const std::vector<byte>& fileData);
		void LoadPixelShader(const std::vector<byte>& fileData);
		void CreateCube();

	private:
		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources> m_deviceResources;

		// Direct3D resources for cube geometry.
		winrt::com_ptr<ID3D11Buffer>		m_vertexBuffer;
		winrt::com_ptr<ID3D11Buffer>		m_constantBuffer;
		winrt::com_ptr<ID3D11Buffer>		m_indexBuffer;
		winrt::com_ptr<ID3D11InputLayout>	m_inputLayout;
		winrt::com_ptr<ID3D11VertexShader>	m_vertexShader;
		winrt::com_ptr<ID3D11PixelShader>	m_pixelShader;

		// System resources for cube geometry.
		ModelViewProjectionConstantBuffer	m_constantBufferData;
		uint32_t	m_indexCount;

		// Variables used with the rendering loop.
		bool	m_loadingComplete;
		float	m_degreesPerSecond;
		bool	m_tracking;
	};
}

