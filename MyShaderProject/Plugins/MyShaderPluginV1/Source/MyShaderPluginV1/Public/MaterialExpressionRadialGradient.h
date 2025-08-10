#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialExpressionCustom.h"
#include "MaterialExpressionRadialGradient.generated.h"

UCLASS(collapsecategories, hidecategories = Object, meta = (DisplayName = "Radial Gradient"))
class MYSHADERPLUGINV1_API UMaterialExpressionRadialGradient : public UMaterialExpressionCustom
{
  GENERATED_BODY()

public:
  UMaterialExpressionRadialGradient();

  // Controls the sharpness/falloff of gradient
  UPROPERTY(EditAnywhere, Category = RadialGradient)
  float Radius;

#if WITH_EDITOR
  virtual int32 Compile(class FMaterialCompiler *Compiler, int32 OutputIndex) override;
  virtual void GetCaption(TArray<FString> &OutCaptions) const override;
#endif
};
