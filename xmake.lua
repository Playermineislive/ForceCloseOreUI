add_rules("mode.debug", "mode.release")

add_repositories("liteldev-repo https://github.com/LiteLDev/xmake-repo.git")
add_requires("nlohmann_json v3.11.3")

target("MyHelloChatMod")   -- 🔥 change this name
    set_kind("shared")
    set_languages("c++20")
    set_strip("all")

    add_files("src/**.cpp")
    add_includedirs("src")

    if is_plat("android") then
        remove_files("src/api/memory/win/**.cpp","src/api/memory/win/**.h")
        add_cxflags("-O3")
        add_links("GlossHook")
end
