#include "api/memory/Hook.h"
#include <thread>

extern "C" [[gnu::visibility("default")]]
void mod_init() {
    // Signature for "send chat message"
    uintptr_t sendChat = resolveSignature(
        "48 89 5C 24 ? 55 53 56 57 41 54 41 55 41 56 41 57 48 8D ? ? ? ? ? 48 81 EC ? ? ? ? 48 8B ? ? ? ? ? 48 33 ? 48 89");

    static uintptr_t orig = 0;
    if (sendChat && !orig) {
        SKY_AUTO_STATIC_HOOK(
            HelloChat, pl::Priority::Normal,
            nullptr, void, void* player, const char* msg) {
            origin(player, "[Levi] Hello from mod!");
        };
    }

    // Background thread to spam every 5 s
    std::thread([] {
        while (true) {
            if (auto send = reinterpret_cast<void(*)(void*, const char*)>(orig))
                send(nullptr, "[Levi] Hello again!");
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    }).detach();
}
