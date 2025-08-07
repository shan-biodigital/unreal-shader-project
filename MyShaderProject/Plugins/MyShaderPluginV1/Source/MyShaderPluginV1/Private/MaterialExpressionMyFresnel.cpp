#include "MaterialExpressionMyFresnel.h"
#include "MaterialCompiler.h"

#if WITH_EDITOR

int32 UMaterialExpressionMyFresnel::Compile(FMaterialCompiler *Compiler, int32 OutputIndex)
{
  int32 NormalCode = Normal.Expression ? Normal.Compile(Compiler) : Compiler->Constant3(0, 0, 1);
  int32 ViewDirCode = ViewDir.Expression ? ViewDir.Compile(Compiler) : Compiler->CameraVector();

  int32 DotVal = Compiler->Dot(NormalCode, ViewDirCode);
  int32 Saturated = Compiler->Saturate(DotVal);
  int32 OneMinus = Compiler->Sub(Compiler->Constant(1.0f), Saturated);
  int32 Pow = Compiler->Power(OneMinus, Compiler->Constant(Power));

  return Pow;
}

void UMaterialExpressionMyFresnel::GetCaption(TArray<FString> &OutCaptions) const
{
  OutCaptions.Add(TEXT("My Fresnel"));
}

#endif
