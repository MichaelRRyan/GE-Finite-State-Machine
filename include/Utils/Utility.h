#ifndef UTILITY_H
#define UTILITY_H

#include <SDL.h>

namespace util
{
    // Written with instruction from Michał Krzyżanowski.
    inline SDL_Texture * loadFromFile(char const * t_path, SDL_Renderer * t_renderer)
    {
        SDL_Texture * newTexture{ nullptr };

        SDL_Surface * loadedSurface = IMG_Load(t_path);

        if (loadedSurface == nullptr)
        {
            printf("Unable to load image %s! SDL_image Error: %s\n", t_path, IMG_GetError());
        }
        else
        {
            newTexture = SDL_CreateTextureFromSurface(t_renderer, loadedSurface);

            if (newTexture == nullptr)
                printf("Unable to create texture from %s! SDL Error: %s\n", t_path, SDL_GetError());
            
            SDL_FreeSurface(loadedSurface);
        }

        return newTexture;
    }
}

#endif // !UTILITY_H