#pragma once
#include <SDL2/SDL.h>

#include "imgui/imgui.h"
#include "imgui/GL/gl3w.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl3.h"

namespace Menu {
    inline bool open = true;
    inline bool initialised = false;

    inline bool demoWindow = false;

    void drawMenu();
    void drawDevWindow();
    void onPollEvent(SDL_Event* event, const int result);
    void onSwapWindow(SDL_Window* window);
}