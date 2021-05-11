#include "Game.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <windows.h>
#include <string>
#include <SDL_ttf.h>
#include <time.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <dos.h>

#include "file.h"

static SDL_Window* g_window;
static SDL_Renderer* g_screen;
static SDL_Event g_event;


TTF_Font* font_score ;
TTF_Font* font_mang;
TTF_Font* font_menu;
TTF_Font* font_end;


int mang[4][4]={0};
bool replay=false;

bool Init()
{
    bool check = true;


    g_window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,575, 648, SDL_WINDOW_SHOWN);
    if (g_window == NULL)
    {
        check = false;
    }
    else
    {
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if (g_screen == NULL)
        {
            check = false;
        }
        else
        {
            SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) && imgFlags))
                check = false;
        }
        if (TTF_Init() == -1)
        {
            check = false;
        }
        font_score= TTF_OpenFont("font.ttf", 40);
        if (font_score == NULL)
        {
            check = false;
        }
        font_mang =TTF_OpenFont("font.ttf", 30);

        if (font_mang == NULL)
        {
            check = false;
        }
        font_menu =TTF_OpenFont("font.ttf",40);
        if(font_menu ==NULL)
        {
            check=false;
        }
        font_end =TTF_OpenFont("font.ttf",60);
        if(font_end ==NULL)
        {
            check=false;
        }


    }



    return check;



}





Game g_background;
bool LoadBG()
{
    bool ret = g_background.LoadImg("anh.png", g_screen);
    if (ret == false) return false;
    return true;
}


int score=0;


void khoitaostart()//tao 2 so dau
{
	//score = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mang[i][j] = 0;
		}
	}

	srand(time(NULL));
	int x1,y1,x2,y2;

	x1 = rand() % 4;
	y1 = rand() % 4;

	do {
		x2 = rand() % 4;
		y2 = rand() % 4;
	} while (x1 == x2 || y1 == y2);


	mang[x1][y1] = 2;
	mang[x2][y2] = 2;
}



void Move(int m) // di chuyen
{
switch(m)
    {
    case 0:  // Ðua các giá lên trên cùng
        for (int j = 0; j < 4; j++)
        {
            int t = 0;
            for (int i = 0; i < 4; i++)
            {
                if (mang[i][j] != 0)
                {
                    mang[t][j] = mang[i][j];
                    t++;
                }
            }
            for (int i = t; i < 4; i++) mang[i][j] = 0;
        }


	// Gop cac gt trung nhau

        for (int j = 0; j < 4; j++)
        {
            int t = 0;
            for (int i = 0; i < 4; i++)
            {
                if (mang != 0)
                {
                    if (mang[i][j] == mang[i + 1][j])
                    {
                        mang[t][j] = 2 * mang[i][j];
                        score += mang[t][j];
                        t++;
                        i++;
                    }
                    else
                    {
                        mang[t][j] = mang[i][j];
                        t++;
                    }
                }
            }
            for (int i = t; i < 4; i++)
            {
                mang[i][j] = 0;
            }
        }

    break;


    case 1:     // Ðua các giá tri xuong duoi

        for (int j = 0; j < 4; j++)
        {
            int t = 3;
            for (int i = 3; i >= 0; i--)
            {
                if (mang[i][j] != 0)
                {
                    mang[t][j] = mang[i][j];
                    t--;
                }
            }
            for (int i = t; i >= 0; i--)
            {
                mang[i][j] = 0;
            }
        }

	// Gop cac gt trung nhau

        for (int j = 0; j < 4; j++)
        {
            int t = 3;
            for (int i = 3; i >= 0; i--)
            {
                if (mang != 0)
                {
                    if (mang[i][j] == mang[i - 1][j])
                    {
                        mang[t][j] = 2 * mang[i][j];
                        score += mang[t][j];
                        t--;
                        i--;
                    }
                    else
                    {
                        mang[t][j] = mang[i][j];
                        t--;
                    }
                }
            }
            for (int i = t; i >= 0; i--)
            {
                mang[i][j] = 0;
            }
        }

			//addTile();
    break;


	case 2:     // Ðua các giá tri ve ben phai

        for (int i = 0; i < 4; i++)
        {
            int t = 3;
            for (int j = 3; j >= 0; j--)
            {
                if (mang[i][j] != 0)
                {
                    mang[i][t] = mang[i][j];
                    t--;
                }
            }
            for (int j = t; j >= 0; j--) mang[i][j] = 0;
        }

	// Gop cac gt trung nhau

        for (int i = 0; i < 4; i++)
        {
            int t = 3;
            for (int j = 3; j >= 0; j--)
            {
                if (mang[i][j] != 0)
                {
                    if (mang[i][j] == mang[i][j - 1])
                    {
                        mang[i][t] = 2 * mang[i][j];
                        score += mang[i][t];
                        j--;
                        t--;
                    }
                    else
                    {
                        mang[i][t] = mang[i][j];
                        t--;
                    }
                }
            }
            for (int j = t; j >= 0; j--)
            {
                mang[i][j] = 0;
            }
        }

    break;


	case 3:     // Ðua các giá tri ve ben trai

        for (int i = 0; i < 4; i++)
        {
            int t = 0;
            for (int j = 0; j < 4; j++)
            {
                if (mang[i][j] != 0)
                {
                    mang[i][t] = mang[i][j];
                    t++;
                }
            }
		for (int j = t; j < 4; j++)
		{
		    mang[i][j] = 0;
		}
        }

	// Gop cac gt trung nhau

        for (int i = 0; i < 4; i++)
        {
            int t = 0;
            for (int j = 0; j < 4; j++)
            {
                if (mang[i][j] != 0)
                {
                    if (mang[i][j] == mang[i][j + 1])
                    {
                        mang[i][t] = 2 * mang[i][j];
                        score += mang[i][t];
                        j++;
                        t++;
                    }
                    else
                    {
                        mang[i][t] = mang[i][j];
                        t++;
                    }
                }
            }
            for (int j = t; j < 4; j++)
            {
                mang[i][j] = 0;
            }
        }

    break;
	}

}



bool checkZero()     //kiem tra xem co so 0 khong
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (mang[i][j] == 0) {
				return true;
			}
		}
	}
	return false;
}

int mangkt[4][4];

void creCheck()     //sao chep mang sang mang khac
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mangkt[i][j] = mang[i][j];
		}
	}
}


bool checkMove()     //kiem tra xem co di chuyen duoc khong
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (mangkt[i][j] != mang[i][j]) return true;
		}
	}
	return false;
}


void themso()     //tao 1 so ngau nhien len vi tri trong
 {
	if (checkZero() == false) return;

	// tao 1 so tai vi tri x, y
	int x, y;
	srand(time(NULL));

	do {
		x = rand() % 4;
		y = rand() % 4;
	} while (mang[x][y] != 0);

	// ti le rand 4 la 10%, 2 la 90%
	int s = rand() % 100;
	if (s > 90) mang[x][y] = 4;
	else mang[x][y] = 2;
}


bool checkGameOver()
{
	if (checkZero() == false) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (mang[i][j] == mang[i][j + 1] ||
					mang[i][j] == mang[i + 1][j]) return false;
			}
		}
	}
	else if (checkZero() == true) return false;
	return true;
}

void test()
{
    switch(g_event.key.keysym.sym)
    {
        case SDLK_UP: //move up
            Move(0);
            break;

        case SDLK_DOWN:
            Move(1);
            break;

        case SDLK_RIGHT: //move right
            Move(2);
            break;

        case SDLK_LEFT: //move left
            Move(3);
            break;
        case SDLK_r:
            replay=true;
    }
}

void close()
{
    g_background.Free();


    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}






int main(int argc, char* argv[])
{

    if (Init() == false) return -1;
    Game g_menu_;
    bool ret1 = g_menu_.LoadImg("menu.png", g_screen);
    if (ret1 == false) return -1;

    const int num_item_menu = 2;
    SDL_Rect pos_arr[num_item_menu];

    pos_arr[0].x = 200;
    pos_arr[0].y = 400;

    pos_arr[1].x = 200;
    pos_arr[1].y = 450;

    File text_menu[num_item_menu];

    text_menu[0].setText("Play");
    text_menu[0].setColor(File::BLACK_TEXT);
    text_menu[0].LoadFromRenderText(font_menu, g_screen);


    text_menu[1].setText("Exit");
    text_menu[1].setColor(File::BLACK_TEXT);
    text_menu[1].LoadFromRenderText(font_menu, g_screen);

    SDL_Event m_event;



    while (true)
    {
        g_menu_.Render(g_screen);
        text_menu[0].RenderText(g_screen, pos_arr[0].x, pos_arr[0].y);
        text_menu[1].RenderText(g_screen,  pos_arr[1].x, pos_arr[1].y);
        while (SDL_PollEvent(&m_event))
        {
            switch (m_event.type)
            {
            case SDL_QUIT:
                return 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
            {
                int xm = m_event.button.x;
                int ym = m_event.button.y;

                if (xm >=200 && xm <= 250 && ym >=450 && ym <= 500)
                {
                    close();
                }

                if (xm >= 200 && xm <= 250 && ym >= 400 && ym <=450)
                {
                if (LoadBG() == false) return -1;

                bool is_quit = false;
                creCheck();
                khoitaostart();
                while (!is_quit)
                {
                    if (replay == true)
                    {
                        khoitaostart();
                        replay = false;
                    }
                    while (SDL_PollEvent(&g_event) != 0)
                    {

                        if (g_event.type == SDL_QUIT)
                        {
                            is_quit = true;
                            break;

                        }
                        else if(g_event.type == SDL_KEYDOWN)
                        {


                        creCheck();

                        test();
                        if (checkMove()==false)
                        {
                            continue;

                        }
                        else
                        {
                            themso();
                        }
                        }
                        if(g_event.type ==SDL_MOUSEBUTTONDOWN)
                        {

                            int xr = g_event.button.x;
                            int yr = g_event.button.y;

                        if (xr >=85 && xr <= 130 && yr >=150 && yr <= 190)
                        {
                            replay=true;

                        }



                        }


                    SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
                    SDL_RenderClear(g_screen);

                    g_background.Render(g_screen);





                    File mang_text[4][4];

                    int posa =240;
                    for(int i=0;i<4;i++)
                    {
                        int posb=115;

                        for(int j=0;j<4;j++)
                        {

                            if(mang[i][j]==0)
                            {
                                mang_text[i][j].setColor(File::GREY_TEXT);
                            }

                            if(mang[i][j]>=2)
                            {
                                mang_text[i][j].setColor(File::BLACK_TEXT);

                            }
                            //mang_text[i][j].setColor(File::BLACK_TEXT);
                            //UINT score = 0; // UNIT là unsigned int
                            std::string mang_val = std::to_string(mang[i][j]); // chuyển biến score sang kiểu string
                            std::string str_mang;
                            str_mang += mang_val;
                            mang_text[i][j].setText(str_mang);
                            mang_text[i][j].LoadFromRenderText(font_mang, g_screen);
                            mang_text[i][j].RenderText(g_screen, posb, posa);
                            posb+=95;


                        }
                    posa+=95;

                }
                File score_text;
                score_text.setColor(File::BLACK_TEXT);
                //UINT score = 0; // UNIT là unsigned int

                std::string score_val = std::to_string(score); // chuyển biến score sang kiểu string
                std::string str_score;
                str_score += score_val;
                score_text.setText(str_score);
                score_text.LoadFromRenderText(font_score, g_screen);
                score_text.RenderText(g_screen, 215, 88);
                if(checkGameOver()==true)
                {
                    File end_text;
                    end_text.setColor(File::BLACK_TEXT);
                    std::string str_end("Game over");
                    end_text.setText(str_end);
                    end_text.LoadFromRenderText(font_end, g_screen);
                    end_text.RenderText(g_screen, 120, 360);

                }


                }

                SDL_RenderPresent(g_screen);

            }

            }

                break;
            }
            default:
                break;
            }
        }
        SDL_RenderPresent(g_screen);
    }



    close();
    return 0;

}
