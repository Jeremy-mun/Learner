workspace "Learner"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Engine"
	location "Engine"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	buildoptions "/utf-8"

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PLATFORM_WINDOWS",
			"BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/TestingGround")
		}

	filter "configurations:Debug"
		defines "DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "DIST"
		optimize "On"

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
	filter "configurations:Release"
		defines "RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "DIST"
		optimize "On"