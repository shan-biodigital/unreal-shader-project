#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialExpression.h"
#include "MaterialExpressionCheckerboard.generated.h"

UCLASS(collapsecategories, hidecategories = Object, meta = (DisplayName = "Checkerboard", Category = "Custom"))
class MY2NDSHADERPLUGINV1_API UMaterialExpressionCheckerboard : public UMaterialExpression
{
  GENERATED_BODY()

public:
  // UV input (float2)
  UPROPERTY()
  FExpressionInput UV;

  // Tiling amount (float)
  UPROPERTY(EditAnywhere, Category = MaterialExpressionCustom)
  float Tiling = 4.0f;

#if WITH_EDITOR
  virtual int32 Compile(class FMaterialCompiler *Compiler, int32 OutputIndex) override;
  virtual void GetCaption(TArray<FString> &OutCaptions) const override;
#endif
};
