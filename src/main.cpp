#include <thread>

#include "hooks/sdlhook.hpp"

void MainThread() {
    Hooks::initSDL();
}

/* Called on uninject */
void __attribute__((destructor)) Unload() {
    printf("[LOG] Uninjecting...");
    /* Unload hooks */
    if (!Hooks::unloadSDL()) {
        printf("[ERR] Failed to unload hooks!");
    }
    printf("[LOG] Uninjected!\n");
}

int __attribute__((constructor)) Main() {
	std::thread mainThread(MainThread);
	mainThread.detach();

    return 0;
}