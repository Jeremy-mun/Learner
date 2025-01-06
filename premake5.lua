workspace "Learner"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Engine/vendor/GLFW/include"
IncludeDir["Glad"] = "Engine/vendor/Glad/include"

include "Engine/vendor/GLFW"
include "Engine/vendor/Glad"

project "Engine"
	location "Engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "%{prj.name}/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{prj.name}/vendor/glm/glm"
	}

	links
	{
		"GLFW",
		"GLAD",
		"opengl32.lib"
	}

	buildoptions "/utf-8"

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PLATFORM_WINDOWS",
			"BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/TestingGround")
		}

	filter "configurations:Debug"
		defines "DEBUG"
		symbols "On"
		buildoptions "/MDd"
	filter "configurations:Release"
		defines "RELEASE"
		optimize "On"
		buildoptions "/MD"
	filter "configurations:Dist"
		defines "DIST"
		optimize "On"
		buildoptions "/MD"
		
project "TestingGround"
	location "TestingGround"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"Engine/vendor/spdlog/include",
		"Engine/src"
	}

	buildoptions "/utf-8"

	links
	{
		"Engine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DEBUG"
		symbols "On"
		buildoptions "/MDd"
	filter "configurations:Release"
		defines "RELEASE"
		optimize "On"
		buildoptions "/MD"
	filter "configurations:Dist"
		defines "DIST"
		optimize "On"
		buildoptions "/MD"