#include "MaterialExpressionCheckerboard.h"
#include "MaterialCompiler.h"

#if WITH_EDITOR

int32 UMaterialExpressionCheckerboard::Compile(FMaterialCompiler *Compiler, int32 OutputIndex)
{
  // Compile UV input or fallback to default texture coordinates (channel 0)
  int32 UVCode = UV.Expression ? UV.Compile(Compiler) : Compiler->TextureCoordinate(0, false, false);

  // Multiply UV by Tiling factor
  int32 ScaledUV = Compiler->Mul(UVCode, Compiler->Constant(Tiling));

  // Floor(ScaledUV)
  int32 Floored = Compiler->Floor(ScaledUV);

  // Sum X + Y components
  int32 XComp = Compiler->ComponentMask(Floored, true, false, false, false); // x
  int32 YComp = Compiler->ComponentMask(Floored, false, true, false, false); // y
  int32 Sum = Compiler->Add(XComp, YComp);

  // Modulo 2
  int32 Checker = Compiler->Fmod(Sum, Compiler->Constant(2.0f));

  return Checker;
}

void UMaterialExpressionCheckerboard::GetCaption(TArray<FString> &OutCaptions) const
{
  OutCaptions.Add(TEXT("Checkerboard"));
}

#endif
