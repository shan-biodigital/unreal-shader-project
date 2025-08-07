// #include "MaterialExpressionCheckerboard.h"

// // UMaterialExpressionCheckerboard::UMaterialExpressionCheckerboard(const FObjectInitializer &ObjectInitializer)
// //     : Super(ObjectInitializer)
// UMaterialExpressionCheckerboard::UMaterialExpressionCheckerboard()
// {
//   // Description = TEXT("Checkerboard");

//   // Code = TEXT(R"(
//   //       float2 uv_scaled = UV * Scale;
//   //       float checker = fmod(floor(uv_scaled.x) + floor(uv_scaled.y), 2.0);
//   //       return lerp(float3(0, 0, 0), float3(1, 1, 1), checker);
//   //   )");

//   // OutputType = CMOT_Float3; // RGB

//   // // UV Input
//   // Inputs.Add(FExpressionInput());
//   // Inputs[0].InputName = TEXT("UV");

//   // // Scale Input
//   // Inputs.Add(FExpressionInput());
//   // Inputs[1].InputName = TEXT("Scale");

//   // bShowOutputNameOnPin = true;
//   // bCollapsed = false;

//   Description = TEXT("Checkerboard");

//   // HLSL code - use inputs Input0=UV, Input1=Scale
//   Code = TEXT(R"(
//         float2 uv = Input0;
//         float scale = Input1;
//         float2 coord = floor(uv * scale);
//         float checker = fmod(coord.x + coord.y, 2.0);
//         return checker;
//     )");

//   OutputType = CMOT_Float1; // single float output

//   // Set number of inputs
//   Inputs = 2;

//   // Assign input names
//   InputNames.Add(TEXT("UV"));
//   InputNames.Add(TEXT("Scale"));
// }
