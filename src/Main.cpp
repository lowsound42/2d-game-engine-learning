#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <sol/sol.hpp>
#include <glm/glm.hpp>
#include <imgui/imgui.h>

int main()
{
    sol::state lua;
    lua.open_libraries(sol::lib::base);
    SDL_Init(SDL_INIT_EVERYTHING);

    glm::vec2 velocity = glm::vec2(5.0, -2.0);

    return 0;
}
