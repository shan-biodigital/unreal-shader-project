# Unreal Shader Project

# Overview

Started looking into Unreal and how we could create custom HLSL shaders. I'm still getting used to to engine (since I never used it before) and ran into lots of compiler errors, but managed to make some progress.

# Technical Details

### Installing Unreal

First, I needed to install the Unreal engine, but kept running into errors while trying to instal the Epic Games Store. Just glad I was (eventually) able to install it, and that it runs (at all) on my 2019, Intel chip, Mac. Here's the error that I kept getting, not sure if your team faced this before (but I got past it so no worries).

![Epic Games Launcher Error](./MyShaderProject/Screenshots/01-epic-games-launcher-error.png)

---

### Starting off with a lerp shader

Then, I wanted to create the simplest material shader to learn the basics. Here's a material that interpolates between 2 textures based on remapped sin. Had some experience with Unity shader graph, so this wasn't too bad.

![Lerp Textures](./MyShaderProject/Screenshots/02-lerp-textures.png)

---

### Writing custom HLSL Shader code

Then, I wanted to figure out how to write custom HLSL shader code (since it seemed to be the best place where a graphics engineer could help). Here's some shader code that creates a checkerboard pattern and uses it as a mask to switch between textures. Techinically, it's animated based on time, but I don't want to upload videos to GitHub. This was also pretty straightforward.

![Custom Material Node](./MyShaderProject/Screenshots/03-custom-material-node.png)

---

### Easy, but no Vim commands, or auto-complete...

Quickly realized it is difficult to work out of the Custom Material Expression node (since no auto-complete, or vim commands, or EVEN keyboard shortcuts). Have ya'll run into this problem? Is there a fix?

---

### Maybe a C++ plugin can fix this (custom Checkerboard node)

Anyways, I figured the next approach would be to make a custom C++ plugin with `UMaterialExpression`. Made an example with Checkerboard pattern that takes in customizable tiling values and outputs color. ChatGPT kinda slowed me down here because (presumably) it kept mixing up Unreal 4 code with Unreal 5 code. Anyway, eventually got it working.

![Checkerboard Shader Plugin](./MyShaderProject/Screenshots/05-checkerboard-shader-plugin.png)

---

### Uh oh, it requires writing (complex?) C++ compiler code

However, the problem with this approach seemed to be that I need to write (complex?) C++ compiler code. Not really the best developer experience (dx). Did your team figure out a way around this?

![C++, not HLSL](./MyShaderProject/Screenshots/06-cpp-not-hlsl.png)

---

### Maybe there is a way forward with `UMaterialExpressionCustom`

Finally, I started to think that the ideal approach would be for graphics engineers to be able to write HLSL code directly in VS Code, and then create some plugin that artists can install and use. My initial thought process on this is that the artist + eng would agree on inputs + outputs of a custom node, and the eng/tech artist does the HLSL math coding?

---

### But I keep getting compiler errors

To accomplish that, it seemed I needed to create a C++ plugin using `UMaterialExpressionCustom`, not `UMaterialExpression`. The former allows engineers to write custom HLSL code while the latter seems to require C++ compiler code. But I kept running into linker errors when compiling the code. Have you or your team seen this before? Is there a workaround?

---

### More involved approach to solve this problem?

Another approach that I saw was that engineers could create `.usf` files (basically Unreal’s version of HLSL) and draw to render targets. Seems like this required more C++ setup which I haven’t fully explored yet. I could learn how to do this, but again, not sure how to prioritize my work between Unreal (C++), Maya (Python), 3D Web Engine (WebGL, Typescript). Way too much to context switch between lol.

---

### Let's go back to the basics + write HLSL code in the Material editor

All this lead me back to using the Custom Material Expression node in the material editor. It's kinda annoying, but it gets the job done. We can create custom inputs, and even multiple outputs. Here's a fun little ray marching example where SDF blends smoothly into a plane.

# Questions

All this exploration gave me some questions.

I’m wondering what approach your team takes for writing and sharing custom HLSL shader code?

- Is it writing HLSL code directly in the material node editor?
- Is it with custom plugin in C++ code compiler code?
- Is it with custom plugin using `UMaterialExpressionCustom` nodes where user can write HLSL code?
- Is it with using the `.usf` approach with render targets which seems to require more C++ setup?
- Or somthing else?

Some of these approaches are pretty good. But the developer experience (dx) of writing shaders was not as smooth as working in Shadertoy.

- Is it just a pipedream to wish it could be better?
- Maybe, these are things your team already solved?
- Maybe, I just don't know enough about Unreal? (I remember that writing shaders in Unity was also pretty annoying.)

Finally, some more general questions.

- Is there any documentation on how to learn/use Unreal engine?
- Do's, and don'ts?
- My understanding is that each team using Unreal may have different list of best practices, so I'm curious if something like that exists for me to read or learn from.

# Commands

Leaving some commands here incase I ever pick this up again.

```bash
# seems like we need to remove binaries and intermediate folders first
# otherwise, Unreal does not actually do the build (which is very annoying)
make clean

# rebuild C++ code with the following command
# restarting Unreal is way too slow, especially if you run into any compiler errors
/Users/Shared/Epic\ Games/UE_5.4/Engine/Build/BatchFiles/RunUAT.sh BuildCookRun -project="/Users/<username>/Desktop/dev/unreal-projects/MyShaderProject/MyShaderProject.uproject"  -noP4 -platform=Mac -clientconfig=Development -serverconfig=Development -cook -allmaps -build
```
