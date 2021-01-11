#include "menu.hpp"
#include "imgui/imgui.h"

void style() {
    /* Put imgui styling here */
}

void Menu::onPollEvent(SDL_Event* event, const int result) {
    if (result && ImGui_ImplSDL2_ProcessEvent(event) && Menu::open) {
        event->type = 0;
    } 
}

void Menu::onSwapWindow(SDL_Window* window) {
    if (!initialised) {
        gl3wInit();
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImGui_ImplOpenGL3_Init("#version 100");
        ImGui_ImplSDL2_InitForOpenGL(window, nullptr);
        initialised = true;
    }

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(window);

    ImGuiIO& io = ImGui::GetIO();
    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    io.DisplaySize = ImVec2((float)w, (float)h);

    ImGui::NewFrame();
    
    if (Menu::open) {
        io.MouseDrawCursor = true; // TODO: find workaround at some point because ugly
        Menu::drawMenu();
        if (demoWindow) {
            ImGui::ShowDemoWindow();
        }
    }
    else {
        io.MouseDrawCursor = false;
    }


    if (ImGui::IsKeyPressed(SDL_SCANCODE_INSERT, false)) {
        Menu::open = !Menu::open;
    }

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Menu::drawMenu() {
    style();
    ImGui::SetNextWindowSize(ImVec2{400, 300});
    ImGui::Begin("Test Window!", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
    ImGui::Checkbox("Demo window", &demoWindow);
    ImGui::End();
}