#ifndef LEVELS_H_INCLUDED
#define LEVELS_H_INCLUDED
using namespace std;
enum{
    SOUND_COIN,
    SOUND_PSWITCH,
    SOUND_MBOX,
    NUM_SOUNDS
};
Mix_Chunk *sounds[NUM_SOUNDS];
const char * names_sounds[NUM_SOUNDS]={
    "coin.wav",
    "Pswitch.wav",
    "HintBlock.wav",
};
enum{
    IMG_ICHIGO,
    IMG_KIRA,
    IMG_GOKU,
    IMG_NARUTO,
    IMG_SAITAMA,
    IMG_BLOCK,
    IMG_COIN,
    IMG_FLAG,
    IMG_VICTORIA,
    IMG_DERROTA,
    IMG_CLOCK,
    NUM_IMAGES
};
SDL_Surface *images[NUM_IMAGES];
const char *names_images[NUM_IMAGES]={
    "ichigo.png",
    "kira.png",
    "goku.png",
    "naruto.png",
    "saitama.png",
    "block.png",
    "coin.png",
    "flag.gif",
    "victoriaA.bmp",
    "loseA.bmp",
    "clock.png",
};
SDL_Surface *screen;
SDL_Window *window;
void startup(void){
    SDL_Surface *load;
    int i;
    if(SDL_Init(SDL_INIT_VIDEO)){
            cout<<"No video"<<endl;
    }
    window=SDL_CreateWindow("MAZE",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,640,520,0);
    if(window==NULL){
        cout<<"No window"<<endl;
    }
    screen = SDL_GetWindowSurface(window);
    if (screen==NULL){
        cout<<"No windows surface"<<endl;
    }
    for(i=0;i<NUM_IMAGES;i++){
        load=IMG_Load(names_images[i]);
        if(load==NULL){
            cout<<"No image loaded "<<names_images[i]<<endl;
        }
        images[i]=load;
    }
    if(SDL_InitSubSystem(SDL_INIT_AUDIO)<0){
        cout<<"Audio not initialized"<<endl;
    }
    if(Mix_OpenAudio(44100,AUDIO_S16,2,512)<0){
        cout<<"No output sound"<<endl;
    }else{
        Mix_AllocateChannels(5);
    }
    Mix_Chunk *load_s;
    for(i=0;i<NUM_SOUNDS;i++){
        load_s=Mix_LoadWAV(names_sounds[i]);
        if(load_s==NULL){cout<<"No audio loaded"<<names_sounds[i]<<endl;
        }
        sounds[i]=load_s;
    }
}
int lvlMap_1[15][20]={
    {IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,
    IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK},
    {IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,
    IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,-1,IMG_BLOCK},
    {IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_BLOCK,
    IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK},
    {IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_COIN,
    IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_BLOCK,},
    {IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,
    IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_BLOCK},
    {IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,
    IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK},
    {IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,
    IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_BLOCK},
    {IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_COIN,
    IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_CLOCK,IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK},
    {IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_COIN,
    IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_BLOCK},
    {IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_COIN,
    IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_BLOCK},
    {IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_BLOCK,
    IMG_COIN,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_BLOCK},
    {IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_COIN,
    IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_BLOCK},
    {IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_COIN,
    IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_BLOCK},
    {IMG_BLOCK,IMG_FLAG,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_COIN,
    IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_COIN,IMG_BLOCK},
    {IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,
    IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK}
};
int characterSelection(TTF_Font *font,SDL_Color black){
    SDL_Surface *characterSelect;
    SDL_Event evento;
    SDL_Rect player,rectSelect;
    int seleccion=0,salir=0;
    rectSelect.h=128;
    rectSelect.w=128;
    rectSelect.y=196;
    characterSelect=TTF_RenderUTF8_Blended(font,"Select your character:",black);
    do{
        while(SDL_PollEvent(&evento))
        {
            if(evento.type==SDL_QUIT){salir=1;}
            if(evento.type==SDL_KEYDOWN)
            {
                switch (evento.key.keysym.sym)
                {
                case SDLK_LEFT:
                    seleccion-=1;
                    if(seleccion<0)
                    {
                        seleccion=4;
                    }
                    Mix_PlayChannel(-1,sounds[SOUND_PSWITCH],0);
                    break;
                case SDLK_RIGHT:
                    seleccion+=1;
                    if(seleccion>4)
                    {
                        seleccion=0;
                    }
                    Mix_PlayChannel(-1,sounds[SOUND_PSWITCH],0);
                    break;
                case SDLK_RETURN:
                    Mix_PlayChannel(-1,sounds[SOUND_MBOX],0);
                    salir=1;
                    break;
                }
            }
            player.x=98;
            player.y=100;
            SDL_FillRect(screen,NULL,0x00FFFF);
            SDL_BlitSurface(characterSelect,NULL,screen,&player);
            player.x=48;
            player.y=244;
            rectSelect.x=128*seleccion;
            SDL_FillRect(screen,&rectSelect,0x0000FF);
            SDL_BlitSurface(images[0],NULL,screen,&player);
            player.x+=128;
            SDL_BlitSurface(images[1],NULL,screen,&player);
            player.x+=128;
            SDL_BlitSurface(images[2],NULL,screen,&player);
            player.x+=128;
            SDL_BlitSurface(images[3],NULL,screen,&player);
            player.x+=128;
            SDL_BlitSurface(images[4],NULL,screen,&player);
            player.x+=128;
            SDL_UpdateWindowSurface(window);
            SDL_WaitEvent(&evento);
        }
    }while(!salir);
    return seleccion;
}
const int lvlMap_2[15][20]={
    {IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK},
    {IMG_BLOCK,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,IMG_BLOCK},
    {IMG_BLOCK,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,IMG_BLOCK},
    {IMG_BLOCK,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,IMG_BLOCK,},
    {IMG_BLOCK,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,IMG_BLOCK},
    {IMG_BLOCK,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,IMG_BLOCK},
    {IMG_BLOCK,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,IMG_BLOCK},
    {IMG_BLOCK,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,IMG_BLOCK},
    {IMG_BLOCK,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,IMG_BLOCK},
    {IMG_BLOCK,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,IMG_BLOCK},
    {IMG_BLOCK,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,IMG_BLOCK},
    {IMG_BLOCK,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,IMG_BLOCK},
    {IMG_BLOCK,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,IMG_BLOCK},
    {IMG_BLOCK,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,IMG_BLOCK},
    {IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK,IMG_BLOCK}
};
#endif // LEVELS_H_INCLUDED
