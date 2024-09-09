#include <SDL2/SDL.h>
#include <iostream>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Function to handle rendering
void render(SDL_Renderer *renderer)
{
    // Set draw color to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red with full opacity
    SDL_RenderClear(renderer);                        // Clear the window with the current draw color (red)

    // Here is where you would draw more objects if needed (like lines, rectangles, textures, etc.)

    SDL_RenderPresent(renderer); // Present the renderer to the window
}

int main(int argc, char *args[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window
    SDL_Window *window = SDL_CreateWindow("SDL Tutorial",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Main loop flag
    bool quit = false;

    // Event handler
    SDL_Event e;

    // While the application is running
    while (!quit)
    {
        // Handle events in the queue
        while (SDL_PollEvent(&e) != 0)
        {
            // User requests to quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        // Render the scene (call the render function)
        render(renderer);

        // Optionally, control the frame rate (e.g., delay to 60 FPS)
        SDL_Delay(16); // Delay ~16ms for a ~60 FPS loop
    }

    // Cleanup: Destroy the renderer and window, and quit SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
