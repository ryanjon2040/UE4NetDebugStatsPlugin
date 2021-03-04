// Created by Satheesh (ryanjon2040). Copyright - 2021. Twitter: @ryanjon2040 - Discord: ryanjon2040#5319

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NetDebugStatsFunctions.generated.h"

UENUM(BlueprintType)
enum class ENetDebugStatConnectionState : uint8
{
	/** Connection is invalid, possibly uninitialized. */
	Invalid,

	/** Connection permanently closed. */
	Closed,
	
	/** Connection is awaiting connection. */
	Pending,

	/** Connection is open. */
	Open
};

USTRUCT(BlueprintType)
struct FNetDebugStatBytes
{
	GENERATED_USTRUCT_BODY();
	
	UPROPERTY(BlueprintReadOnly, Category = "Net Debug Stat Bytes")
	float InBytes;

	UPROPERTY(BlueprintReadOnly, Category = "Net Debug Stat Bytes")
	float OutBytes;

	FNetDebugStatBytes()
	{
		InBytes = OutBytes = -1.f;
	}

	FNetDebugStatBytes(const float& NewInBytes, const float& NewOutBytes)
	{
		InBytes = NewInBytes;
		OutBytes = NewOutBytes;
	}
};

USTRUCT(BlueprintType)
struct FNetDebugStatPackets
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(BlueprintReadOnly, Category = "Net Debug Stat Packets")
	int32 InPackets;

	UPROPERTY(BlueprintReadOnly, Category = "Net Debug Stat Packets")
	int32 OutPackets;

	FNetDebugStatPackets()
	{
		InPackets = OutPackets = INDEX_NONE;
	}

	FNetDebugStatPackets(const int32& NewInPackets, const int32& NewOutPackets)
	{
		InPackets = NewInPackets;
		OutPackets = NewOutPackets;
	}
};

UCLASS(NotBlueprintable)
class NETDEBUGSTATS_API UNetDebugStatsFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/**
	* public static UNetDebugStatsFunctions::GetMaxPacket
	* Gets the maximum packet size. -1 if return value is false.
	* @param OutMaxPacket [int32&] Maximum packet size.
	* @return [bool] True if valid UNetConnection was found from PlayerController. False otherwise.
	**/
	UFUNCTION(BlueprintPure, Category = "Net Debug Stats", meta = (WorldContext="WorldContextObject"))	
	static bool GetMaxPacket(const UObject* WorldContextObject, int32& OutMaxPacket);

	/**
	* public static UNetDebugStatsFunctions::GetConnectionState
	* Returns the state this connection is in.
	* @return [ENetDebugStatConnectionState] Current state of connection.
	**/
	UFUNCTION(BlueprintPure, Category = "Net Debug Stats", meta = (WorldContext = "WorldContextObject"))	
	static ENetDebugStatConnectionState GetConnectionState(const UObject* WorldContextObject);

	/**
	* public static UNetDebugStatsFunctions::GetAverageLag
	* Gets the average lag seen during the last StatPeriod
	* @param OutAverageLag [float&] Average lag.
	* @return [bool] True if valid UNetConnection was found from PlayerController. False otherwise.
	**/
	UFUNCTION(BlueprintPure, Category = "Net Debug Stats", meta = (WorldContext = "WorldContextObject"))	
	static bool GetAverageLag(const UObject* WorldContextObject, float& OutAverageLag);

	/**
	* public static UNetDebugStatsFunctions::GetBytes
	* Returns bytes (not total sent/received on this connection (accumulated during a StatPeriod).
	* @param OutBytes [FNetDebugStatBytes&] Struct that holds sent/received data.
	* @param bConvertToKB [const bool] True to convert bytes to kb.
	* @return [bool] True if valid UNetConnection was found from PlayerController. False otherwise.
	**/
	UFUNCTION(BlueprintPure, Category = "Net Debug Stats", meta = (WorldContext = "WorldContextObject"))	
	static bool GetBytes(const UObject* WorldContextObject, FNetDebugStatBytes& OutBytes, const bool bConvertToKB = true);

	/**
	* public static UNetDebugStatsFunctions::GetBytesPerSecond
	* Returns bytes sent/received on this connection (per second) - these are from previous StatPeriod interval
	* @param OutBytes [FNetDebugStatBytes &] Struct that holds sent/received data.
	* @param bConvertToKB [const bool] True to convert bytes to kb.
	* @return [bool] True if valid UNetConnection was found from PlayerController. False otherwise.
	**/
	UFUNCTION(BlueprintPure, Category = "Net Debug Stats", meta = (WorldContext = "WorldContextObject"))	
	static bool GetBytesPerSecond(const UObject* WorldContextObject, FNetDebugStatBytes& OutBytes, const bool bConvertToKB = true);

	/**
	* public static UNetDebugStatsFunctions::GetTotalBytes
	* Returns total bytes sent/received on this connection.
	* @param OutBytes [FNetDebugStatBytes&] Struct that holds sent/received data.
	* @param bConvertToKB [const bool] True to convert bytes to kb.
	* @return [bool] True if valid UNetConnection was found from PlayerController. False otherwise.
	**/
	UFUNCTION(BlueprintPure, Category = "Net Debug Stats", meta = (WorldContext = "WorldContextObject"))	
	static bool GetTotalBytes(const UObject* WorldContextObject, FNetDebugStatBytes& OutBytes, const bool bConvertToKB = true);

	/**
	* public static UNetDebugStatsFunctions::GetPackets
	* Returns packets sent/received on this connection (accumulated during a StatPeriod)
	* @param OutPackets [FNetDebugStatPackets&] Struct that holds send/received data.
	* @return [bool] True if valid UNetConnection was found from PlayerController. False otherwise.
	**/
	UFUNCTION(BlueprintPure, Category = "Net Debug Stats", meta = (WorldContext = "WorldContextObject"))	
	static bool GetPackets(const UObject* WorldContextObject, FNetDebugStatPackets& OutPackets);

	/**
	* public static UNetDebugStatsFunctions::GetPacketsPerSecond
	* Returns packets sent/received on this connection (per second) - these are from previous StatPeriod interval
	* @param OutPackets [FNetDebugStatPackets&] Struct that holds send/received data.
	* @return [bool] True if valid UNetConnection was found from PlayerController. False otherwise.
	**/
	UFUNCTION(BlueprintPure, Category = "Net Debug Stats", meta = (WorldContext = "WorldContextObject"))	
	static bool GetPacketsPerSecond(const UObject* WorldContextObject, FNetDebugStatPackets& OutPackets);

	/**
	* public static UNetDebugStatsFunctions::GetTotalPackets
	* Returns total packets lost on this connection.
	* @param OutPackets [FNetDebugStatPackets&] Struct that holds send/received data.
	* @return [bool] True if valid UNetConnection was found from PlayerController. False otherwise.
	**/
	UFUNCTION(BlueprintPure, Category = "Net Debug Stats", meta = (WorldContext = "WorldContextObject"))	
	static bool GetTotalPackets(const UObject* WorldContextObject, FNetDebugStatPackets& OutPackets);

	/**
	* public static UNetDebugStatsFunctions::GetPacketLost
	* Returns packets lost on this connection (accumulated during a StatPeriod).
	* @param OutPackets [FNetDebugStatPackets&] Struct that holds send/received data.
	* @return [bool] True if valid UNetConnection was found from PlayerController. False otherwise.
	**/
	UFUNCTION(BlueprintPure, Category = "Net Debug Stats", meta = (WorldContext = "WorldContextObject"))	
	static bool GetPacketLost(const UObject* WorldContextObject, FNetDebugStatPackets& OutPackets);

	/**
	* public static UNetDebugStatsFunctions::GetTotalAcks
	* Returns total acks sent on this connection.
	* @param OutTotalAcks [int32&] Total acks if return value is true.
	* @return [bool] True if valid UNetConnection was found from PlayerController. False otherwise.
	**/
	UFUNCTION(BlueprintPure, Category = "Net Debug Stats", meta = (WorldContext = "WorldContextObject"))	
	static bool GetTotalAcks(const UObject* WorldContextObject, int32& OutTotalAcks);

	/**
	* public static UNetDebugStatsFunctions::GetPacketLostPercentage
	* Percentage of packets lost during the last StatPeriod.
	* @param InPercentage [float&] Loss percentage of incoming packets.
	* @param OutPercentage [float&] Loss percentage of outgoing packets.
	* @param bGetAverage [const bool] True to get the average loss.
	* @return [bool] True if valid UNetConnection was found from PlayerController. False otherwise.
	**/
	UFUNCTION(BlueprintPure, Category = "Net Debug Stats", meta = (WorldContext = "WorldContextObject"))	
	static bool GetPacketLostPercentage(const UObject* WorldContextObject, float& InPercentage, float& OutPercentage, const bool bGetAverage = false);

private:

	static class UNetConnection* Internal_GetNetConnection(const UObject* WorldContextObject);
	
};
