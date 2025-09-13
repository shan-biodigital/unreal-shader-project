#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialExpression.h"
#include "MaterialExpressionShaderBallV1.generated.h"

// UCLASS(collapsecategories, hidecategories = Object, meta = (DisplayName = "ShaderBall", Category = "Custom"))
UCLASS(collapsecategories, hidecategories = Object)
class MY2NDSHADERPLUGINV1_API UMaterialExpressionShaderBallV1 : public UMaterialExpression
{
  GENERATED_UCLASS_BODY()

public:
  // Input: object/world position
  UPROPERTY(EditAnywhere, Category = MaterialExpression)
  FExpressionInput Position;

  // Input: center of sphere
  UPROPERTY(EditAnywhere, Category = MaterialExpression)
  FExpressionInput Center;

  // Radius of sphere
  UPROPERTY(EditAnywhere, Category = MaterialExpression)
  float Radius;

  // Falloff for soft edges
  UPROPERTY(EditAnywhere, Category = MaterialExpression)
  float Falloff;

  virtual int32 Compile(class FMaterialCompiler *Compiler, int32 OutputIndex) override;
  virtual void GetCaption(TArray<FString> &OutCaptions) const override;
};
