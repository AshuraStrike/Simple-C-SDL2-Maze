#include <iostream>
#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "Levels.h"
using namespace std;
int main(int argc, char **argv){
    int f,c,colision,cscore=0,salir=0,seleccion=0,plusFlag=0,winnerX,winnerY;
    int mapa[15][20];
    char charScore[5],charTime[6];
    float time=30.0;
    SDL_Surface *scoring,*textScore,*timing,*textTime,*plusTime;
    SDL_Rect rect,player,next_player,rectVict,rectScoring,rectScore,rectTime,rectTiming,lastLine,rectplus;
    for(f=0;f<15;f++){
        for(c=0;c<20;c++){
            mapa[f][c]=mapa_1[f][c];
            if(mapa[f][c]==-1){
                player.x=32*c;
                player.y=32*f;
            }else if(mapa[f][c]==IMG_FLAG){
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
    SDL_Color nigga,white,weed;
    nigga.r=0x0;
    nigga.g=0x0;
    nigga.b=0x0;
    white.r=0xFF;
    white.g=0xFF;
    white.b=0xFF;
    weed.r=0x00;
    weed.g=0xFF;
    weed.b=0x00;
    if(TTF_Init())
    {
        cout<<"No fuentes"<<endl;
    }
    TTF_Font *fuente=TTF_OpenFont("abg.ttf",40);
    if(fuente==NULL)
    {
        cout<<"No cargo fuente"<<endl;
    }
    textScore=TTF_RenderUTF8_Shaded(fuente,"Score: ",white,nigga);
    textTime=TTF_RenderUTF8_Shaded(fuente,"Time: ",white,nigga);
    plusTime=TTF_RenderUTF8_Blended(fuente,"+10 secs",weed);
    Mix_Music *musica;
    musica=Mix_LoadMUS("unique.mp3");
    if(musica==NULL)
    {
        cout<<"No pudo cargar musica"<<endl;
    }
    SDL_Event evento;
    seleccion=characterSelection(fuente,nigga);
    Mix_PlayMusic(musica,-1);
    do{
        while (SDL_PollEvent (&evento)){
            if (evento.type == SDL_QUIT) salir = 1;
            if(evento.type==SDL_KEYDOWN)
            {
                switch (evento.key.keysym.sym)
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
            colision=0;
            if(mapa[next_player.y/32][next_player.x/32]==IMG_BLOCK)
            {
                colision=1;
            }
            if(colision==0)
            {
                player.x=next_player.x;
                player.y=next_player.y;
            }

        if(mapa[next_player.y/32][next_player.x/32]==IMG_COIN)
        {
            Mix_PlayChannel(-1,sonidos[SOUND_COIN],0);
            cscore+=100;
            mapa[player.y/32][player.x/32]=-1;
        }
        //////////////////////////////////////////////////////////////
        else if(mapa[next_player.y/32][next_player.x/32]==IMG_CLOCK){
            time+=10;
            plusFlag=1;
            mapa[player.y/32][player.x/32]=-1;
            SDL_BlitSurface(plusTime,NULL,pantalla,&rectplus);
        }
        }
        itoa(cscore,charScore,10);
        scoring=TTF_RenderUTF8_Shaded(fuente,charScore,white,nigga);
        sprintf(charTime,"%6.2f",time);
        timing=TTF_RenderUTF8_Shaded(fuente,charTime,white,nigga);
        next_player.x=player.x;
        next_player.y=player.y;
        SDL_FillRect(pantalla,NULL,0xFF);

        for(f=0; f<15; f++)
        {
            for(c=0; c<20; c++)
            {
                rect.x=c*32;
                rect.y=f*32;
                if(mapa[f][c]!=-1)
                {
                    SDL_BlitSurface(imagenes[(mapa[f][c])],NULL,pantalla,&rect);
                }
            }
        }
        SDL_BlitSurface(imagenes[seleccion],NULL,pantalla,&player);
        SDL_FillRect(pantalla,&lastLine,0);
        SDL_BlitSurface(textScore,NULL,pantalla,&rectScore);
        SDL_BlitSurface(scoring,NULL,pantalla,&rectScoring);
        SDL_BlitSurface(textTime,NULL,pantalla,&rectTime);
        SDL_BlitSurface(timing,NULL,pantalla,&rectTiming);
        SDL_FreeSurface(scoring);
        SDL_FreeSurface(timing);
        if(player.x==winnerX&&player.y==winnerY)
        {
            SDL_BlitSurface(imagenes[IMG_VICTORIA],NULL,pantalla,&rectVict);
            Mix_PauseMusic();
            salir=1;
        }else{
            cscore-=7;
            time-=0.1;
        }
        if(time<=0){
            SDL_BlitSurface(imagenes[IMG_DERROTA],NULL,pantalla,&rectVict);
            Mix_PauseMusic();
            salir=1;
        }
        if(plusFlag>0){
            plusFlag++;
        SDL_BlitSurface(plusTime,NULL,pantalla,&rectplus);
        if(plusFlag==6){
            plusFlag=0;
        }
    }
        SDL_UpdateWindowSurface(ventana);
        SDL_Delay(100);
    }

    while (!salir);
    salir=0;
    /*Mix_Music *scream;
    scream=Mix_LoadMUS("maiga.mp3");
    Mix_PlayMusic(scream,0);
    SDL_Surface *imgScream;
    imgScream=IMG_Load("maiga.png");*
    player.x=0;
    player.y=0;*/
    do{
        while(SDL_PollEvent(&evento)){
            if(evento.type == SDL_QUIT){
                salir=1;
            }
        }
        //SDL_BlitSurface(imgScream,NULL,pantalla,&player);
        SDL_UpdateWindowSurface(ventana);
        SDL_Delay(1000);
    }while(!salir);
    return 0;
}
