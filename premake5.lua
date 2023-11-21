workspace "Whatta"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Whatta"
	location "Whatta"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }
	includedirs { "%{prj.name}/vendor/spdlog/include" }

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines { "WH_PLATFORM_WINDOWS", "WH_BUILD_DLL" }

		postbuildcommands { ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox") }
	
	filter "system:Debug"
		defines "WH_DEBUG"
		symbols "On"

	filter "system:Release"
		defines "WH_RELEASE"
		optimize "On"

	filter "system:Dist"
		defines "WH_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }
	includedirs { "Whatta/vendor/spdlog/include", "Whatta/src" }
	links { "Whatta" }

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines { "WH_PLATFORM_WINDOWS" }
	
	filter "system:Debug"
		defines "WH_DEBUG"
		symbols "On"

	filter "system:Release"
		defines "WH_RELEASE"
		optimize "On"

	filter "system:Dist"
		defines "WH_DIST"
		optimize "On"