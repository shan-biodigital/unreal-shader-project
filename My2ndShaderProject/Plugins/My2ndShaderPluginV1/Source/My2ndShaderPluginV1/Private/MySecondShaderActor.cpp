#include "MySecondShaderActor.h"
#include "MySecondShader.h" // your FMySecondShader
#include "Engine/World.h"
#include "RenderGraphUtils.h"
#include "RenderTargetPool.h"
// #include "ScreenPass.h"
// #include "GlobalRenderResources.h"
#include "ScreenRendering.h"       // ✅ for FScreenVS
#include "GlobalRenderResources.h" // ✅ for GTileVertexDeclaration

#include "MySecondShaderActor.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/World.h"
#include "Kismet/KismetRenderingLibrary.h"

AMySecondShaderActor::AMySecondShaderActor()
{
  PrimaryActorTick.bCanEverTick = false;

  TargetSize = 512; // default size if not set in editor
}

void AMySecondShaderActor::BeginPlay()
{
  Super::BeginPlay();

  // Create the render target
  RenderTarget = NewObject<UTextureRenderTarget2D>(this, TEXT("MyDynamicRT"));
  if (RenderTarget)
  {
    RenderTarget->RenderTargetFormat = RTF_RGBA8;
    RenderTarget->InitAutoFormat(TargetSize, TargetSize);
    RenderTarget->ClearColor = FLinearColor::Red;
    RenderTarget->SRGB = false;
    RenderTarget->bAutoGenerateMips = false;

    // Register with GC
    RenderTarget->AddToRoot();

    RenderTarget->UpdateResourceImmediate(true);

    // As a first test: just clear it red
    UKismetRenderingLibrary::ClearRenderTarget2D(this, RenderTarget, FLinearColor::Red);

    UE_LOG(LogTemp, Log, TEXT("Created RenderTarget successfully."));
  }
  else
  {
    UE_LOG(LogTemp, Error, TEXT("Failed to create RenderTarget!"));
  }
}

// AMySecondShaderActor::AMySecondShaderActor()
// {
//   PrimaryActorTick.bCanEverTick = false;
// }
// // AMySecondShaderActor::AMySecondShaderActor()
// // {
// //     PrimaryActorTick.bCanEverTick = true;
// // }

// void AMySecondShaderActor::BeginPlay()
// {
//   // Super::BeginPlay();

//   // // Create the RenderTarget
//   // RenderTarget = NewObject<UTextureRenderTarget2D>();
//   // RenderTarget->InitAutoFormat(TargetSize, TargetSize);
//   // RenderTarget->ClearColor = FLinearColor::Black;
//   // RenderTarget->UpdateResourceImmediate(true);

//   // // Run shader once
//   // ExecuteShader();

//   Super::BeginPlay();

//   // Create the RenderTarget
//   RenderTarget = NewObject<UTextureRenderTarget2D>(this);
//   RenderTarget->InitAutoFormat(TargetSize, TargetSize);
//   // RenderTarget->ClearColor = FLinearColor::Black;
//   RenderTarget->ClearColor = FLinearColor::Red;
//   // RenderTarget->UpdateResourceImmediate(true);

//   // Important: match material sampling
//   RenderTarget->SRGB = false;              // Treat as linear color
//   RenderTarget->bAutoGenerateMips = false; // Optional: disable mipmaps for shader output

//   RenderTarget->UpdateResourceImmediate(true);

//   // Run shader once
//   ExecuteShader();
// }

// void AMySecondShaderActor::ExecuteShader()
// {
//   if (!RenderTarget)
//     return;

//   FTextureRenderTargetResource *RTResource = RenderTarget->GameThread_GetRenderTargetResource();

//   ENQUEUE_RENDER_COMMAND(ExecuteMySecondShader)(
//       [this, RTResource](FRHICommandListImmediate &RHICmdList)
//       {
//         RunShader_RenderThread(RHICmdList, RTResource->GetRenderTargetTexture());
//       });
// }

// void AMySecondShaderActor::RunShader_RenderThread(FRHICommandListImmediate &RHICmdList, FTextureRHIRef OutputTexture)
// {
//   check(IsInRenderingThread());

//   FRDGBuilder GraphBuilder(RHICmdList);

//   // Allocate the target texture
//   FRDGTextureRef OutputRDG = GraphBuilder.RegisterExternalTexture(
//       CreateRenderTarget(OutputTexture, TEXT("MySecondShaderOutput")));

//   // // Add a pass that runs your shader
//   // GraphBuilder.AddPass(
//   //     RDG_EVENT_NAME("MySecondShaderPass"),
//   //     ERDGPassFlags::Raster,
//   //     [OutputRDG](FRHICommandListImmediate &RHICmdListInner)
//   //     {
//   //       // Bind and run your shader here
//   //       TShaderMapRef<FMySecondShader> PixelShader(GetGlobalShaderMap(GMaxRHIFeatureLevel));

//   //       // TODO: Set parameters, draw fullscreen quad, write to OutputRDG
//   //       // For now just clears the RT
//   //       FRHIRenderPassInfo RPInfo(OutputRDG->GetRHI(), ERenderTargetActions::Clear_Store);
//   //       RHICmdListInner.BeginRenderPass(RPInfo, TEXT("MySecondShader"));
//   //       RHICmdListInner.EndRenderPass();
//   //     });

//   GraphBuilder.AddPass(
//       RDG_EVENT_NAME("MySecondShaderPass"),
//       ERDGPassFlags::Raster,
//       [OutputRDG](FRHICommandListImmediate &RHICmdListInner)
//       {
//         // TShaderMapRef<FMySecondShader> PixelShader(GetGlobalShaderMap(GMaxRHIFeatureLevel));
//         // TShaderMapRef<FScreenVS> VertexShader(GetGlobalShaderMap(GMaxRHIFeatureLevel));
//         // FGraphicsPipelineStateInitializer PSOInit;
//         // RHICmdListInner.ApplyCachedRenderTargets(PSOInit);
//         // PSOInit.BlendState = TStaticBlendState<>::GetRHI();
//         // PSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
//         // PSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
//         // PSOInit.PrimitiveType = PT_TriangleList;
//         // PSOInit.BoundShaderState.VertexDeclarationRHI = GFilterVertexDeclaration.VertexDeclarationRHI;
//         // PSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
//         // PSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
//         // SetGraphicsPipelineState(RHICmdListInner, PSOInit);

//         TShaderMapRef<FScreenVS> VertexShader(GetGlobalShaderMap(GMaxRHIFeatureLevel));
//         TShaderMapRef<FMySecondShader> PixelShader(GetGlobalShaderMap(GMaxRHIFeatureLevel));

//         FGraphicsPipelineStateInitializer PSOInit;
//         RHICmdListInner.ApplyCachedRenderTargets(PSOInit);
//         PSOInit.BlendState = TStaticBlendState<>::GetRHI();
//         PSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
//         PSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
//         PSOInit.PrimitiveType = PT_TriangleList;
//         PSOInit.BoundShaderState.VertexDeclarationRHI = GTileVertexDeclaration.VertexDeclarationRHI; // ✅ fixed
//         PSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
//         PSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();

//         SetGraphicsPipelineState(RHICmdListInner, PSOInit, 0); // ✅ pass stencil ref

//         // Draw a fullscreen triangle (simpler than DrawRectangle)
//         RHICmdListInner.DrawPrimitive(0, 3, 1);

//         // DrawRectangle(
//         //     RHICmdListInner,
//         //     0, 0, OutputRDG->Desc.Extent.X, OutputRDG->Desc.Extent.Y,
//         //     0, 0, 1, 1,
//         //     FIntPoint(OutputRDG->Desc.Extent.X, OutputRDG->Desc.Extent.Y),
//         //     FIntPoint(1, 1),
//         //     VertexShader);
//       });

//   GraphBuilder.Execute();
// }
