#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TextureRenderTarget2D.h"
#include "MySecondShaderActor.generated.h"

UCLASS()
class MY2NDSHADERPLUGINV1_API AMySecondShaderActor : public AActor
{
  GENERATED_BODY()

public:
  AMySecondShaderActor();

protected:
  virtual void BeginPlay() override;

public:
  // The render target artists can assign in Materials
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shader")
  UTextureRenderTarget2D *RenderTarget;

  // Size of the render target
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shader")
  int32 TargetSize = 512;

  // Runs the shader into the render target
  void RunShader_RenderThread(FRHICommandListImmediate &RHICmdList, FTextureRHIRef OutputTexture);

  // Kicks off shader execution
  void ExecuteShader();
};
