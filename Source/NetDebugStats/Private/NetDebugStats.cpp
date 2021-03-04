// Created by Satheesh (ryanjon2040). Copyright - 2021. Twitter: @ryanjon2040 - Discord: ryanjon2040#5319

#include "NetDebugStats.h"

#define LOCTEXT_NAMESPACE "FNetDebugStatsModule"

DEFINE_LOG_CATEGORY_STATIC(LogNetDebugStats, All, All)

void FNetDebugStatsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	UE_LOG(LogNetDebugStats, Log, TEXT("Net Debug Stats module started."));
}

void FNetDebugStatsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	UE_LOG(LogNetDebugStats, Log, TEXT("Net Debug Stats module shutdown."));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FNetDebugStatsModule, NetDebugStats)