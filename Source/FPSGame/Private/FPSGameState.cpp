// Copyright 2018 Sebastien Rombauts (sebastien.rombauts@gmail.com)

#include "FPSGameState.h"

#include "FPSPlayerController.h"


void AFPSGameState::MulticastOnMissionComplete_Implementation(APawn* InstigatorPawn, bool bMissionSuccess)
{
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; It++)
	{
		AFPSPlayerController* PlayerController = Cast<AFPSPlayerController>(It->Get());
		if (PlayerController && PlayerController->IsLocalController())
		{
			PlayerController->OnMissionComplete(InstigatorPawn, bMissionSuccess);
		}
	}
}
