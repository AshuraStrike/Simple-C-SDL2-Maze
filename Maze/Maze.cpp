#include <iostream>
#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "Levels.h"
using namespace std;
int main(int argc, char **argv){
    int f,c,collition,cscore=0,exitFlag=0,selection=0,plusFlag=0,winnerX,winnerY;
    int lvlMap[15][20];
    char charScore[5],charTime[6];
    float time=30.0;
    SDL_Surface *scoring,*textScore,*timing,*textTime,*plusTime;
    SDL_Rect rect,player,next_player,rectVict,rectScoring,rectScore,rectTime,rectTiming,lastLine,rectplus;
    SDL_Color black,white,green;
    TTF_Font *font=TTF_OpenFont("abg.ttf",40);
    Mix_Music *music;
    SDL_Event event;

    for(f=0;f<15;f++){
        for(c=0;c<20;c++){
            lvlMap[f][c]=lvlMap_1[f][c];
            if(lvlMap[f][c]==-1){
                player.x=32*c;
                player.y=32*f;
            }else if(lvlMap[f][c]==IMG_FLAG){
                winnerX=32*c;
                winnerY=32*f;
            }
        }
    }
    rectplus.x=420;
    rectplus.y=450;
    rect.h=32;
    rect.w=32;
    player.w=32;
    player.h=32;
    next_player.x=576;
    next_player.y=32;
    next_player.w=32;
    next_player.h=32;
    rectVict.x=0;
    rectVict.y=160;
    rectVict.w=640;
    rectVict.h=200;
    rectScore.x=0;
    rectScore.y=480;
    rectScoring.x=137;
    rectScoring.y=480;
    rectTime.x=350;
    rectTime.y=480;
    rectTiming.x=464;
    rectTiming.y=480;
    lastLine.x=0;
    lastLine.y=480;
    lastLine.w=640;
    lastLine.h=40;
    startup();

    black.r=0x0;
    black.g=0x0;
    black.b=0x0;
    white.r=0xFF;
    white.g=0xFF;
    white.b=0xFF;
    green.r=0x00;
    green.g=0xFF;
    green.b=0x00;
    if(TTF_Init())
    {
        cout<<"No fonts"<<endl;
    }
    if(font==NULL)
    {
        cout<<"No font loaded"<<endl;
    }
    textScore=TTF_RenderUTF8_Shaded(font,"Score: ",white,black);
    textTime=TTF_RenderUTF8_Shaded(font,"Time: ",white,black);
    plusTime=TTF_RenderUTF8_Blended(font,"+10 secs",green);
    music=Mix_LoadMUS("unique.mp3");
    if(music==NULL)
    {
        cout<<"No music loaded"<<endl;
    }
    selection=characterSelection(font,black);
    Mix_PlayMusic(music,-1);
    do{
        while (SDL_PollEvent (&event)){
            if (event.type == SDL_QUIT) exitFlag = 1;
            if(event.type==SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    next_player.y-=32;
                    break;
                case SDLK_RIGHT:
                    next_player.x+=32;
                    break;
                case SDLK_DOWN:
                    next_player.y+=32;
                    break;
                case SDLK_LEFT:
                    next_player.x-=32;
                    break;
                default:
                    break;
                }
            }
            collition=0;
            if(lvlMap[next_player.y/32][next_player.x/32]==IMG_BLOCK)
            {
                collition=1;
            }
            if(collition==0)
            {
                player.x=next_player.x;
                player.y=next_player.y;
            }

        if(lvlMap[next_player.y/32][next_player.x/32]==IMG_COIN)
        {
            Mix_PlayChannel(-1,sounds[SOUND_COIN],0);
            cscore+=100;
            lvlMap[player.y/32][player.x/32]=-1;
        }
        //////////////////////////////////////////////////////////////
        else if(lvlMap[next_player.y/32][next_player.x/32]==IMG_CLOCK){
            time+=10;
            plusFlag=1;
            lvlMap[player.y/32][player.x/32]=-1;
            SDL_BlitSurface(plusTime,NULL,screen,&rectplus);
        }
        }

        //itoa(cscore,charScore,10);
        scoring=TTF_RenderUTF8_Shaded(font,charScore,white,black);
        sprintf(charTime,"%6.2f",time);
        timing=TTF_RenderUTF8_Shaded(font,charTime,white,black);
        next_player.x=player.x;
        next_player.y=player.y;
        SDL_FillRect(screen,NULL,0xFF);

        for(f=0; f<15; f++)
        {
            for(c=0; c<20; c++)
            {
                rect.x=c*32;
                rect.y=f*32;
                if(lvlMap[f][c]!=-1)
                {
                    SDL_BlitSurface(images[(lvlMap[f][c])],NULL,screen,&rect);
                }
            }
        }
        SDL_BlitSurface(images[selection],NULL,screen,&player);
        SDL_FillRect(screen,&lastLine,0);
        SDL_BlitSurface(textScore,NULL,screen,&rectScore);
        SDL_BlitSurface(scoring,NULL,screen,&rectScoring);
        SDL_BlitSurface(textTime,NULL,screen,&rectTime);
        SDL_BlitSurface(timing,NULL,screen,&rectTiming);
        SDL_FreeSurface(scoring);
        SDL_FreeSurface(timing);
        if(player.x==winnerX&&player.y==winnerY)
        {
            SDL_BlitSurface(images[IMG_VICTORIA],NULL,screen,&rectVict);
            Mix_PauseMusic();
            exitFlag=1;
        }else{
            cscore-=7;
            time-=0.1;
        }
        if(time<=0){
            SDL_BlitSurface(images[IMG_DERROTA],NULL,screen,&rectVict);
            Mix_PauseMusic();
            exitFlag=1;
        }
        if(plusFlag>0){
            plusFlag++;
        SDL_BlitSurface(plusTime,NULL,screen,&rectplus);
        if(plusFlag==6){
            plusFlag=0;
        }
    }
        SDL_UpdateWindowSurface(window);
        SDL_Delay(100);
    }

    while (!exitFlag);
    exitFlag=0;

    do{
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                exitFlag=1;
            }
        }
        SDL_UpdateWindowSurface(window);
        SDL_Delay(1000);
    }while(!exitFlag);
    return 0;
}
