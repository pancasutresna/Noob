workspace "Noob"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    project "Noob"
        location "Noob"
        kind "SharedLib"
        language "c++"

        targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
        objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "%{prj.name}/vendor/spdlog/include"
        }

        filter "system:windows"
            cppdialect "c++17"
            staticruntime "On"
            systemversion "latest"

            defines 
            {
                "NB_PLATFORM_WINDOWS",
                "NB_BUILD_DLL"
            }

            postbuildcommands
            {
                ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
            }

        filter "configurations:Debug"
            defines "NB_DEBUG"
            symbols "On"
            
        filter "configurations:Release"
            defines "NB_RELEASE"
            optimize "On"
            
        filter "configurations:Dist"
            defines "NB_DIST"
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
            symbols "On"
            
        filter "configurations:Release"
            defines "NB_RELEASE"
            optimize "On"
            
        filter "configurations:Dist"
            defines "NB_DIST"
            optimize "On"


        filter {"system:windows", "configurations:Release"}
            buildoptions "/MT"