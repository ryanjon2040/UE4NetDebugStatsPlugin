// Created by Satheesh (ryanjon2040). Copyright - 2021. Twitter: @ryanjon2040 - Discord: ryanjon2040#5319

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FNetDebugStatsModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
