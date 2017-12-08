#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "EdNode_GenericGraphNode.generated.h"

class UGenericGraphNode;
class UEdNode_GenericGraphEdge;

UCLASS(MinimalAPI)
class UEdNode_GenericGraphNode : public UEdGraphNode
{
	GENERATED_BODY()

public:
	UEdNode_GenericGraphNode();
	virtual ~UEdNode_GenericGraphNode();

	UPROPERTY(VisibleAnywhere, Instanced, Category = "GenericGraph")
	UGenericGraphNode* GenericGraphNode;

	void SetGenericGraphNode(UGenericGraphNode* InNode);
	UEdGraph_GenericGraph* GetGenericGraphEdGraph();

	virtual void AllocateDefaultPins() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual void PrepareForCopying() override;
	virtual void AutowireNewNode(UEdGraphPin* FromPin) override;

	virtual FLinearColor GetBackgroundColor() const;
	virtual UEdGraphPin* GetInputPin() const;
	virtual UEdGraphPin* GetOutputPin() const;

#if WITH_EDITOR
	virtual void PostEditUndo() override;
#endif

};