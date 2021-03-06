#pragma once

#include "CoreMinimal.h"
#include "Voice.h"
#include "Interfaces/VoiceCapture.h"
#include "Runtime/Engine/Public/Tickable.h"
#include "Microphone.generated.h"

UCLASS()
class WATSONSDK_API UMicrophone : public UObject, public FTickableGameObject
{
	GENERATED_BODY()

public:
	UMicrophone();

	void StartRecording();
	void StopRecording();
	TArray<uint8> GetRecording();

	void Tick(float DeltaTime) override;
	bool IsTickableInEditor() const override;
	bool IsTickableWhenPaused() const override;
	bool IsTickable() const override;
	TStatId GetStatId() const override;
	void BeginDestroy() override;

	UPROPERTY()
	TArray<uint8> VoiceCaptureBuffer;
	
	UPROPERTY()
	int32 VoiceCaptureSize;

private:
	TSharedPtr<class IVoiceCapture> VoiceCapture;
};
