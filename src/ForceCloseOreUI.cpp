#include "api/memory/Hook.h"
#include <cstdio>

// Declare hook at global scope — never inside a function/struct
SKY_AUTO_STATIC_HOOK(
    SendChatHook,                          // DefType (unique name)
    memory::HookPriority::Normal,          // priority
    std::initializer_list<const char*>({
        // Replace with the correct sendChat signature for your version
        "48 89 5C 24 ? 55 53 56 57 41 54 41 55 41 56 41 57 48 8D"
    }),
    void,                                  // return type
    void* player, const char* msg          // parameters
) {
    // Example hook: override message
    origin(player, "[Mod] Hello from ForceCloseOreUI!");
}

// Entry point
extern "C" [[gnu::visibility("default")]]
void mod_init() {
    std::puts("[ForceCloseOreUI] mod_init OK");
}
