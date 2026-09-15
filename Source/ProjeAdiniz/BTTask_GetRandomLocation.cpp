#include "BTTask_GetRandomLocation.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_GetRandomLocation::UBTTask_GetRandomLocation()
{
    NodeName = "Find Random Patrol Location";
}

EBTNodeResult::Type UBTTask_GetRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (!AIController) return EBTNodeResult::Failed;

    APawn* Pawn = AIController->GetPawn();
    if (!Pawn) return EBTNodeResult::Failed;

    UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
    if (!NavSys) return EBTNodeResult::Failed;

    FNavLocation RandomLocation;
    if (NavSys->GetRandomReachablePointInRadius(Pawn->GetActorLocation(), Radius, RandomLocation))
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsVector(PatrolLocationKey.SelectedKeyName, RandomLocation.Location);
        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed;
}
