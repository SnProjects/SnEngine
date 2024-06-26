workspace "SnEngine"
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
IncludeDir["GLFW"] = "SnEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "SnEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "SnEngine/vendor/imgui"

include "SnEngine/vendor/GLFW"
include "SnEngine/vendor/Glad"
include "SnEngine/vendor/imgui"
    
project "SnEngine"

    location "SnEngine"
    kind "SharedLib"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "snpch.h"
    pchsource "SnEngine/src/snpch.cpp"
    
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
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        
        defines
        {
            "SN_PLATFORM_WINDOWS",
            "SN_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }
        
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
        
    filter "configurations:Debug"
        defines "SN_DEBUG"
        symbols "On"
        buildoptions "/MDd"
        
        
    filter "configurations:Release"
        defines "SN_RELEASE"
        optimize "On"
        buildoptions "/MD"
        
    filter "configurations:Dist"
        defines "SN_DIST"
        optimize "On"
        buildoptions "/MD"
        
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "SnEngine/vendor/spdlog/include",
        "SnEngine/src"
    }
    
    links
    {
        "SnEngine"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        
        defines
        {
            "SN_PLATFORM_WINDOWS"
        }
        
    filter "configurations:Debug"
        defines "SN_DEBUG"
        symbols "On"
        buildoptions "/MDd"
        
    filter "configurations:Release"
        defines "SN_RELEASE"
        optimize "On"
        buildoptions "/MD"
        
    filter "configurations:Dist"
        defines "SN_DIST"
        optimize "On"
        buildoptions "/MD"
   

    