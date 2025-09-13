#include "MaterialExpressionShaderBallV1.h"
#include "MaterialCompiler.h"

UMaterialExpressionShaderBallV1::UMaterialExpressionShaderBallV1(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
  Radius = 100.0f;
  Falloff = 0.0f;
}

int32 UMaterialExpressionShaderBallV1::Compile(FMaterialCompiler *Compiler, int32 OutputIndex)
{
  // int32 PosCode = Position.Compile(Compiler);
  // int32 CenterCode = Center.Compile(Compiler);

  // Default Position → AbsoluteWorldPosition if nothing is connected
  int32 PosCode = Position.Expression
                      ? Position.Compile(Compiler)
                      : Compiler->WorldPosition(WPT_Default);
  // Default Center → zero vector if nothing is connected
  int32 CenterCode = Center.Expression
                         ? Center.Compile(Compiler)
                         : Compiler->Constant3(0.0f, 0.0f, 0.0f);

  if (PosCode == INDEX_NONE || CenterCode == INDEX_NONE)
  {
    return Compiler->Errorf(TEXT("Missing Position or Center input"));
  }

  // distance between position and center
  int32 Distance = Compiler->Sub(PosCode, CenterCode);
  Distance = Compiler->Dot(Distance, Distance);
  Distance = Compiler->SquareRoot(Distance);

  int32 Inner = Compiler->Sub(Compiler->Constant(Radius), Compiler->Constant(Falloff));
  int32 Outer = Compiler->Add(Compiler->Constant(Radius), Compiler->Constant(Falloff));

  return Compiler->Sub(
      Compiler->Constant(1.0f),
      Compiler->SmoothStep(Inner, Outer, Distance));
}

void UMaterialExpressionShaderBallV1::GetCaption(TArray<FString> &OutCaptions) const
{
  OutCaptions.Add(TEXT("ShaderBall"));
}
