#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialExpression.h"
#include "MaterialExpressionMyFresnel.generated.h"

UCLASS(collapsecategories, hidecategories = Object, meta = (DisplayName = "My Fresnel"))
class MYSHADERPLUGINV1_API UMaterialExpressionMyFresnel : public UMaterialExpression
{
  GENERATED_BODY()

public:
  UPROPERTY()
  FExpressionInput Normal;

  UPROPERTY()
  FExpressionInput ViewDir;

  UPROPERTY(EditAnywhere, Category = MaterialExpressionCustom)
  float Power = 5.0f;

#if WITH_EDITOR
  virtual int32 Compile(class FMaterialCompiler *Compiler, int32 OutputIndex) override;
  virtual void GetCaption(TArray<FString> &OutCaptions) const override;
#endif
};
