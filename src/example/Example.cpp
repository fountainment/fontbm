#include <iostream>
#include <exception>
#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include "BmFont.h"

using namespace SDL2pp;

int main(int /*argc*/, char** /*argv*/)
{
    try
    {
        SDL sdl(SDL_INIT_VIDEO);
        Window window("SDL2pp demo",
                      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                      640, 480,
                      SDL_WINDOW_RESIZABLE);

        Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
        renderer.Clear();

        BmFont bmFont(renderer, "test0.fnt");
        bmFont.print(SDL2pp::Point(0, 0), "Hello, World!");

        renderer.Present();
        SDL_Delay(5000);
        return 0;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
