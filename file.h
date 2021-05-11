#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <windows.h>
#include "Game.h"
#include <SDL_ttf.h>

class File : public Game
{
public:
    File();
    ~File();

    enum FileColor
    {
        RED_TEXT = 0,
        WHITE_TEXT = 1,
        BLACK_TEXT = 2,
        GREY_TEXT =3,

    };
    bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen);
    void Free();

    void setColor(Uint8 red, Uint8 green, Uint8 blue);
    void setColor(int type);

    void RenderText(SDL_Renderer* screen, int xpos, int ypos, SDL_Rect* clip = NULL, double angle = 0.0,
                     SDL_Point* center = NULL,
                     SDL_RendererFlip flip = SDL_FLIP_NONE);

    int getWidth() const {return width_;}
    int getHeight() const {return height_;}
    void setText(const std::string& text) {str_val_ = text;}
    std::string getText() const {return str_val_;}
private:
    std::string str_val_;
    SDL_Color text_color_;
    SDL_Texture* texture_;
    int width_;
    int height_;

};


#endif // FILE_H

