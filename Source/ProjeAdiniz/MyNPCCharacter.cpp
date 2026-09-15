#include "MyNPCCharacter.h"
#include "MyAIController.h"

AMyNPCCharacter::AMyNPCCharacter()
{
    PrimaryActorTick.bCanEverTick = false;

    AIControllerClass = AMyAIController::StaticClass();
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}
