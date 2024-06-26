workspace "SnEngine"
    architecture "x64"
    startproject "Sandbox"
    
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
IncludeDir["glm"] = "SnEngine/vendor/glm"

group "Dependencies"
    include "SnEngine/vendor/GLFW"
    include "SnEngine/vendor/Glad"
    include "SnEngine/vendor/imgui"

group ""
    
project "SnEngine"

    location "SnEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "snpch.h"
    pchsource "SnEngine/src/snpch.cpp"
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }
    
    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }
    
    filter "system:windows"
        systemversion "latest"
        
        defines
        {
            "SN_PLATFORM_WINDOWS",
            "SN_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }
        
    filter "configurations:Debug"
        defines "SN_DEBUG"
        symbols "on"
        runtime "Debug"
        
        
    filter "configurations:Release"
        defines "SN_RELEASE"
        optimize "on"
        runtime "Release"
        
    filter "configurations:Dist"
        defines "SN_DIST"
        optimize "on"
        runtime "Release"
        
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    
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
        "SnEngine/src",
        "SnEngine/vendor",
        "%{IncludeDir.glm}"
    }
    
    links
    {
        "SnEngine"
    }
    
    filter "system:windows"
        systemversion "latest"
        
        defines
        {
            "SN_PLATFORM_WINDOWS"
        }
        
    filter "configurations:Debug"
        defines "SN_DEBUG"
        symbols "on"
        runtime "Debug"
        
    filter "configurations:Release"
        defines "SN_RELEASE"
        optimize "on"
        runtime "Release"
        
    filter "configurations:Dist"
        defines "SN_DIST"
        optimize "on"
        runtime "Release"
