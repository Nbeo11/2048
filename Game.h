#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <windows.h>


class Game
{
public:
    Game();
    ~Game();
    bool LoadImg(std::string path, SDL_Renderer* screen);
    void SetRect(const int& x, const int& y) {rect_.x = x; rect_.y = y;}
    SDL_Rect GetRect() const {return rect_;}
    SDL_Texture* GetObject() const {return p_object_;}
    void Render(SDL_Renderer* des);
    void Free();
protected:
    SDL_Texture* p_object_;
    SDL_Rect rect_;
};

#endif // GAME_H
