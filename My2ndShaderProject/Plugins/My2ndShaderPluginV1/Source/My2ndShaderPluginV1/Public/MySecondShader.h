#pragma once

#include "CoreMinimal.h"
#include "GlobalShader.h"
#include "ShaderParameterStruct.h"

class FMySecondShader : public FGlobalShader
{
  DECLARE_GLOBAL_SHADER(FMySecondShader);
  SHADER_USE_PARAMETER_STRUCT(FMySecondShader, FGlobalShader);

public:
  BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
  // SHADER_PARAMETER(FVector2D, UV)
  SHADER_PARAMETER(FVector2f, UV)
  RENDER_TARGET_BINDING_SLOTS()
  END_SHADER_PARAMETER_STRUCT()

  static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters &Parameters)
  {
    return true;
  }
};
