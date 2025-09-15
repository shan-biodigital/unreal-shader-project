// // #include "MaterialExpressionMyThirdShader.h"

// // UMaterialExpressionMyThirdShader::UMaterialExpressionMyThirdShader()
// // {
// //   // Call the .usf shader function
// //   Code = TEXT("MyThirdShaderFunc(UV);");

// //   // Input definition
// //   Input.Add(FCustomInput());
// //   Input[0].InputName = TEXT("UV");

// //   // Output type
// //   OutputType = CMOT_Float3;

// //   // Include the .usf for this shader
// //   // IncludeFile = TEXT("/Plugin/My2ndShaderPluginV1/Shaders/Private/MyThirdShader.usf");
// //   IncludeFile = TEXT("/Plugin/My2ndShaderPluginV1/Shaders/MyThirdShader.usf");
// // }

// #include "MaterialExpressionMyThirdShader.h"

// UMaterialExpressionMyThirdShader::UMaterialExpressionMyThirdShader(const FObjectInitializer &ObjectInitializer)
//     : Super(ObjectInitializer)
// {
//   // Call the .usf shader function directly
//   Code = TEXT("#include \"/Plugin/My2ndShaderPluginV1/Shaders/Private/MyThirdShader.usf\"\nMyThirdShaderFunc(UV);");

//   // Define inputs
//   Inputs.Add(FCustomInput());
//   Inputs[0].InputName = TEXT("UV");

//   // Output type
//   OutputType = CMOT_Float3;
// }
