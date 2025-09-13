#include "MySecondShader.h"
#include "ShaderParameterUtils.h"
#include "RHIStaticStates.h"

IMPLEMENT_GLOBAL_SHADER(FMySecondShader, "/Plugin/My2ndShaderPluginV1/MySecondShader.usf", "MySecondShaderFunc", SF_Pixel);
