#pragma once

#include "CoreMinimal.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundWaveProcedural.h"
#include "Speaker.generated.h"

UCLASS()
class WATSONSDK_API USpeaker : public UObject
{
	GENERATED_BODY()

public:
	USpeaker();
	void PlayAudio(const TArray<uint8>& AudioData, uint32 AudioLength);

private:
	UPROPERTY()
	UAudioComponent* AudioOutputComponent;
	
	UPROPERTY()
	USoundWaveProcedural* AudioPCMComponent;
};
