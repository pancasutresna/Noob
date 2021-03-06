workspace "Noob"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    -- Include directories relative to root folder (solution directory)
    IncludeDir = {}
    IncludeDir["GLFW"] = "Noob/vendor/GLFW/include"
    IncludeDir["Glad"] = "Noob/vendor/Glad/include"

    include "Noob/vendor/GLFW"
    include "Noob/vendor/Glad"

    project "Noob"
        location "Noob"
        kind "SharedLib"
        language "c++"

        targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
        objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")

        pchheader "nbpch.h"
        pchsource "Noob/src/nbpch.cpp"

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
            "%{IncludeDir.Glad}"
        }

        links{
            "GLFW",
            "Glad",
            "opengl32.lib"
        }

        filter "system:windows"
            cppdialect "c++17"
            staticruntime "On"
            systemversion "latest"

            defines 
            {
                "NB_PLATFORM_WINDOWS",
                "NB_BUILD_DLL",
                "GLFW_INCLUDE_NONE"
            }

            postbuildcommands
            {
                ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
            }

        filter "configurations:Debug"
            defines "NB_DEBUG"
            buildoptions "/MDd"
            symbols "On"
            
        filter "configurations:Release"
            defines "NB_RELEASE"
            buildoptions "/MD"
            optimize "On"
            
        filter "configurations:Dist"
            defines "NB_DIST"
            buildoptions "/MD"
            optimize "On"
        
project "Sandbox"
    location "Sandbox"
    kind "consoleApp"
    language "C++"

        targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
        objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "Noob/vendor/spdlog/include",
            "Noob/src"
        }

        links
        {
            "Noob"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

            defines 
            {
                "NB_PLATFORM_WINDOWS"
            }

        filter "configurations:Debug"
            defines "NB_DEBUG"
            buildoptions "/MDd"
            symbols "On"
            
        filter "configurations:Release"
            defines "NB_RELEASE"
            buildoptions "/MD"
            optimize "On"
            
        filter "configurations:Dist"
            defines "NB_DIST"
            buildoptions "/MD"
            optimize "On"
