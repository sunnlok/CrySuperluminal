// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once
#include <CrySystem/ICryPlugin.h>

class CSuperluminal;

class CPlugin_CrySuperluminal: public ICryPlugin
{
	CRYINTERFACE_BEGIN()
	CRYINTERFACE_ADD(ICryPlugin)
	CRYINTERFACE_END()

	CRYGENERATE_SINGLETONCLASS_GUID(CPlugin_CrySuperluminal, "Plugin_CrySuperluminal", "7208857E-08FF-4CEF-8EBF-9A224D34E1E0"_cry_guid)

	CPlugin_CrySuperluminal();
	virtual ~CPlugin_CrySuperluminal();

	//! Retrieve name of plugin.
	virtual const char* GetName() const override { return "Plugin_CrySuperluminal"; }

	//! Retrieve category for the plugin.
	virtual const char* GetCategory() const override { return "Plugin"; }

	//! This is called to initialize the new plugin.
	virtual bool Initialize(SSystemGlobalEnvironment& env, const SSystemInitParams& initParams) override;

public:
protected:
	virtual void OnPluginUpdate(EPluginUpdateType updateType) override;
private:
	std::unique_ptr<CSuperluminal> m_pSuperluminal;
	HMODULE m_slLibHandle = NULL;
};
