// #include "MaterialExpressionAbsSinTime.h"

// UMaterialExpressionAbsSinTime::UMaterialExpressionAbsSinTime()
// {
//   Description = TEXT("abs(sin(Time))");
//   OutputType = CMOT_Float1;
//   Code = TEXT("return abs(sin(Time));");

//   // Add one input named "Time"
//   Inputs.Add(FCustomInput{FName("Time")});

//   // Desc = TEXT("abs(sin(Time))");
// }

// // UMaterialExpressionAbsSinTime::UMaterialExpressionAbsSinTime()
// // {
// //   Description = TEXT("abs(sin(Time))");
// //   OutputType = CMOT_Float1;
// //   // Load from external .usf file
// //   Code = TEXT("return AbsSinTime(Time);");
// //   // This must match the function signature in your .usf file
// //   Inputs.Add(FCustomInput{FName("Time")});
// //   // Point to the usf file (note: this is virtual shader path, not physical disk path)
// //   IncludeFilePaths.Add(TEXT("/Plugin/MyShaderPluginV1/Shaders/Private/AbsSinTime.usf"));
// // }

// #if WITH_EDITOR

// int32 UMaterialExpressionAbsSinTime::Compile(FMaterialCompiler *Compiler, int32 OutputIndex)
// {
//   // Compile the custom expression using the base implementation
//   return Super::Compile(Compiler, OutputIndex);
// }

// void UMaterialExpressionAbsSinTime::GetCaption(TArray<FString> &OutCaptions) const
// {
//   OutCaptions.Add(TEXT("Abs Sin Time"));
// }

// // bool UMaterialExpressionAbsSinTime::GenerateHLSLExpression(
// //     FMaterialHLSLGenerator &Generator,
// //     UE::HLSLTree::FScope &Scope,
// //     int32 OutputIndex,
// //     UE::HLSLTree::FExpression const *&OutExpression) const
// // {
// //   UMaterialExpressionCustom *InternalExpression = GetInternalExpression();
// //   // if (!InternalExpression)
// //   // {
// //   //   return Generator.Errorf(TEXT("Internal expression is null."));
// //   // }
// //   InternalExpression->Code = TEXT(R"(
// //       return abs(sin(Time));;
// //   )");
// //   // InternalExpression->Inputs[0].Input = InputA;
// //   // InternalExpression->Inputs[1].Input = InputB;
// //   return InternalExpression->GenerateHLSLExpression(Generator, Scope, OutputIndex, OutExpression);
// // }

// // // Inside your UMaterialExpressionAbsSinTime.cpp or similar file
// // bool UMaterialExpressionAbsSinTime::GenerateHLSLExpression(
// //     FMaterialHLSLGenerator &Generator,
// //     UE::HLSLTree::FScope &Scope,
// //     int32 OutputIndex,
// //     UE::HLSLTree::FExpression const *&OutExpression) const
// // {
// //   // Implement your HLSL expression generation here.
// //   // You'll use the Generator and Scope to construct the HLSL code.
// //   // For example, you might access inputs, perform calculations, and
// //   // set OutExpression to the final result.
// //   // Refer to Unreal Engine documentation and examples for UMaterialExpressionCustom::GenerateHLSLExpression
// //   // or other material expressions for how to implement this.
// //   // Example: Returning a constant float expression (replace with your actual logic)
// //   // OutExpression = Generator.NewFloatConstant(Scope, 0.5f);
// //   // return true;
// //   // Ensure you return true if the expression is successfully generated, false otherwise.
// //   return false; // Placeholder, replace with your actual implementation.
// // }

// #endif
