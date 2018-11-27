// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#include "StdAfx.h"

// Included only once per DLL module.
#include <CryCore/Platform/platform_impl.inl>

#include "CrySuperluminalDLL.h"
#include "Superluminal.h"



CPlugin_CrySuperluminal::CPlugin_CrySuperluminal()
{
}

CPlugin_CrySuperluminal::~CPlugin_CrySuperluminal()
{
	CryFreeLibrary(m_slLibHandle);
}

bool CPlugin_CrySuperluminal::Initialize(SSystemGlobalEnvironment& env, const SSystemInitParams& initParams)
{ 
	m_slLibHandle = CryLoadLibrary("PerformanceAPI.dll");
	if (m_slLibHandle != NULL)
	{
		CryLogAlways("[Superluminal] Loaded Performance API.");
		SetUpdateFlags(EPluginUpdateType::EUpdateType_Update);
		m_pSuperluminal = std::make_unique<CSuperluminal>();
	}
	else
		CryLogAlways("[Superluminal] Failed to load Performance API.");
	
	return m_slLibHandle != NULL;
}

void CPlugin_CrySuperluminal::OnPluginUpdate(EPluginUpdateType updateType)
{
	if (m_pSuperluminal.get())
	{
		m_pSuperluminal->Update();
	}
}


CRYREGISTER_SINGLETON_CLASS(CPlugin_CrySuperluminal)
