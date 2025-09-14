#include "screen.hpp"

Platform::Platform(char const* title, int windowWidth, int windowHeight, int textureWidth, int textureHeight)
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	window = SDL_CreateWindow(
		title,
		windowWidth, windowHeight,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	gl_context = SDL_GL_CreateContext(window);
	SDL_GL_SetSwapInterval(1);
	gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

	glGenTextures(1, &framebuffer_texture);
	glBindTexture(GL_TEXTURE_2D, framebuffer_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 640, 320, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glBindTexture(GL_TEXTURE_2D, 0);
}

Platform::~Platform()
{
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Platform::Update(void const* buffer, int pitch)
{
	SDL_UpdateTexture(texture, nullptr, buffer, pitch);
	SDL_RenderClear(renderer);
	SDL_RenderTexture(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

bool Platform::ProcessInput(uint8_t* keys) {
    SDL_Event event;
    bool quit = false;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) quit = true;

        if (event.type == SDL_EVENT_KEY_DOWN || event.type == SDL_EVENT_KEY_UP) {
            bool pressed = (event.type == SDL_EVENT_KEY_DOWN);
            SDL_Keycode keycode = event.key.key;  

            switch (keycode) {
                case SDLK_1: keys[0x1] = pressed; break;
                case SDLK_2: keys[0x2] = pressed; break;
                case SDLK_3: keys[0x3] = pressed; break;
                case SDLK_4: keys[0xC] = pressed; break;

                case SDLK_Q: keys[0x4] = pressed; break;
                case SDLK_W: keys[0x5] = pressed; break;
                case SDLK_E: keys[0x6] = pressed; break;
                case SDLK_R: keys[0xD] = pressed; break;

                case SDLK_A: keys[0x7] = pressed; break;
                case SDLK_S: keys[0x8] = pressed; break;
                case SDLK_D: keys[0x9] = pressed; break;
                case SDLK_F: keys[0xE] = pressed; break;

                case SDLK_Z: keys[0xA] = pressed; break;
                case SDLK_X: keys[0x0] = pressed; break;
                case SDLK_C: keys[0xB] = pressed; break;
                case SDLK_V: keys[0xF] = pressed; break;
            }
        }
    }

    return quit;
}
