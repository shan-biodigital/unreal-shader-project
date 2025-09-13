clean:
	rm -rf Plugins/My2ndShaderPluginV1/Binaries Plugins/My2ndShaderPluginV1/Intermediate

build:
	/Users/Shared/Epic\ Games/UE_5.4/Engine/Build/BatchFiles/RunUAT.sh BuildCookRun -project="/Users/shanmadhirala/Desktop/dev/unreal-projects/My2ndShaderProject/My2ndShaderProject.uproject"  -noP4 -platform=Mac -clientconfig=Development -serverconfig=Development -cook -allmaps -build

run:
	/Users/Shared/Epic\ Games/UE_5.4/Engine/Binaries/Mac/UnrealEditor.app/Contents/MacOS/UnrealEditor /Users/shanmadhirala/Desktop/dev/unreal-projects/My2ndShaderProject/My2ndShaderProject.uproject

all: clean build run
