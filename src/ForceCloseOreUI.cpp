// src/ForceCloseOreUI.cpp
#include "api/memory/Hook.h"
#include <cstdio>

// NOTE: Keep the hook at GLOBAL scope (not inside a function).
// The AUTO variant will register/unregister automatically.

SKY_AUTO_STATIC_HOOK(
    SendChatHook,                          // DefType (any unique name)
    memory::HookPriority::Normal,          // priority
    std::initializer_list<const char*>({   // identifier: signature(s)
        // Put a valid signature for the "send chat" function here.
        // This is just a placeholder pattern; adjust if needed.
        "48 89 5C 24 ? 55 53 56 57 41 54 41 55 41 56 41 57 48 8D ? ? ? ? ? 48 81 EC ? ? ? ? 48 8B ? ? ? ? ? 48 33 ? 48 89"
    }),
    void,                                  // return type of target
    void* player, const char* msg          // params of target
) {
    // Example behavior: replace any outgoing message with our own.
    // Call the original with our message:
    origin(player, "[Levi] Hello from mod!");
}

// Entry point required by the loader. Leave empty; AUTO hook already registers.
extern "C" [[gnu::visibility("default")]]
void mod_init() {
    // Nothing needed here because SKY_AUTO_STATIC_HOOK auto-registers the hook.
    // If you want logs:
    // std::puts("[ForceCloseOreUI] mod_init");
}
