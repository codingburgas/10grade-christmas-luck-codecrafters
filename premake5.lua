workspace "AstrophysicsDataViewer"
    startproject "AstrophysicsDataViewer"
    architecture "x86_64"
    configurations { "Debug", "Release" }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

        
project "AstrophysicsDataViewer"
    location "AstrophysicsDataViewer"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir ("./bin/" .. outputdir .. "/%{prj.name}")
    objdir ("./bin-int/" .. outputdir .. "/%{prj.name}")

    files { "./%{prj.name}/src/**.cpp", "./%{prj.name}/include/**.h", "./%{prj.name}/include/planets.h/**.h", 
    "./%{prj.name}/src/planets.src/**.cpp", "./%{prj.name}/assets/logo/**.png", "./%{prj.name}/assets/planets/**.png",
     "./%{prj.name}/assets/fonts/**.ttf", "./%{prj.name}/assets/profile_pictures/**.png", "./%{prj.name}/assets/3D_planets/**.obj",
      "./%{prj.name}/assets/planet_textures/**.png" }

    includedirs { "./vendor/raylib/include", "./%{prj.name}/src", "./%{prj.name}/include" }

    libdirs { "./vendor/raylib/lib", "./%{prj.name}/include" }

    links { "raylibdll" }

    postbuildcommands { "{COPY} \"%{wks.location}/vendor/raylib/lib/raylib.dll\" \"%{cfg.targetdir}\"" }

    staticruntime "On"
    systemversion "latest"

    filter "configurations:Debug"
        defines "OD_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "OD_RELEASE"
        optimize "On"