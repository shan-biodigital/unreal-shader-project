// #include "MaterialExpressionRadialGradient.h"

// UMaterialExpressionRadialGradient::UMaterialExpressionRadialGradient()
// {
//   Description = TEXT("Radial Gradient");
//   Radius = 0.5f;
//   OutputType = CMOT_Float1;

//   Code = TEXT(R"(
//         // UV expected in [0,1] range
//         float2 center = float2(0.5, 0.5);
//         float dist = distance(UV, center);
//         return saturate(1.0 - dist / Radius);
//     )");

//   Inputs.Add(FCustomInput{FName("UV")});
//   Inputs.Add(FCustomInput{FName("Radius")});
// }

// #if WITH_EDITOR

// int32 UMaterialExpressionRadialGradient::Compile(FMaterialCompiler *Compiler, int32 OutputIndex)
// {
//   return Super::Compile(Compiler, OutputIndex);
// }

// void UMaterialExpressionRadialGradient::GetCaption(TArray<FString> &OutCaptions) const
// {
//   OutCaptions.Add(TEXT("Radial Gradient"));
// }

// #endif
