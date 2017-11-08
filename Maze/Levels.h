#ifndef LEVELS_H_INCLUDED
#define LEVELS_H_INCLUDED
using namespace std;
enum{
    SOUND_COIN,
    SOUND_PSWITCH,
    SOUND_MBOX,
    NUM_SOUNDS
};
Mix_Chunk *sonidos[NUM_SOUNDS];
const char * nombres_sonidos[NUM_SOUNDS]={
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
    NUM_IMAGENES
};
SDL_Surface *imagenes[NUM_IMAGENES];
const char *nombres_imagenes[NUM_IMAGENES]={
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
SDL_Surface *pantalla;
SDL_Window *ventana;
void startup(void){
    SDL_Surface *carga;
    int i;
    if(SDL_Init(SDL_INIT_VIDEO)){
            cout<<"No video"<<endl;
    }
    ventana=SDL_CreateWindow("MAZE",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,640,520,0);
    if(ventana==NULL){
        cout<<"No ventana"<<endl;
    }
    pantalla = SDL_GetWindowSurface(ventana);
    if (pantalla==NULL){
        cout<<"No pude la segunda vez"<<endl;
    }
    for(i=0;i<NUM_IMAGENES;i++){
        carga=IMG_Load(nombres_imagenes[i]);
        if(carga==NULL){
            cout<<"No cargo imagen "<<nombres_imagenes[i]<<endl;
        }
        imagenes[i]=carga;
    }
    if(SDL_InitSubSystem(SDL_INIT_AUDIO)<0){
        cout<<"Audio no inicializado"<<endl;
    }
    if(Mix_OpenAudio(44100,AUDIO_S16,2,512)<0){
        cout<<"No pudo ajustar sonido de salida"<<endl;
    }else{
        Mix_AllocateChannels(5);
    }
    Mix_Chunk *carga_s;
    for(i=0;i<NUM_SOUNDS;i++){
        carga_s=Mix_LoadWAV(nombres_sonidos[i]);
        if(carga_s==NULL){cout<<"No cargó audio"<<nombres_sonidos[i]<<endl;
        }
        sonidos[i]=carga_s;
    }
}
int mapa_1[15][20]={
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
int characterSelection(TTF_Font *fuente,SDL_Color nigga){
    SDL_Surface *characterSelect;
    SDL_Event evento;
    SDL_Rect player,rectSelect;
    int seleccion=0,salir=0;
    rectSelect.h=128;
    rectSelect.w=128;
    rectSelect.y=196;
    characterSelect=TTF_RenderUTF8_Blended(fuente,"Select your character:",nigga);
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
                    Mix_PlayChannel(-1,sonidos[SOUND_PSWITCH],0);
                    break;
                case SDLK_RIGHT:
                    seleccion+=1;
                    if(seleccion>4)
                    {
                        seleccion=0;
                    }
                    Mix_PlayChannel(-1,sonidos[SOUND_PSWITCH],0);
                    break;
                case SDLK_RETURN:
                    Mix_PlayChannel(-1,sonidos[SOUND_MBOX],0);
                    salir=1;
                    break;
                }
            }
            player.x=98;
            player.y=100;
            SDL_FillRect(pantalla,NULL,0x00FFFF);
            SDL_BlitSurface(characterSelect,NULL,pantalla,&player);
            player.x=48;
            player.y=244;
            rectSelect.x=128*seleccion;
            SDL_FillRect(pantalla,&rectSelect,0x0000FF);
            SDL_BlitSurface(imagenes[0],NULL,pantalla,&player);
            player.x+=128;
            SDL_BlitSurface(imagenes[1],NULL,pantalla,&player);
            player.x+=128;
            SDL_BlitSurface(imagenes[2],NULL,pantalla,&player);
            player.x+=128;
            SDL_BlitSurface(imagenes[3],NULL,pantalla,&player);
            player.x+=128;
            SDL_BlitSurface(imagenes[4],NULL,pantalla,&player);
            player.x+=128;
            SDL_UpdateWindowSurface(ventana);
            SDL_WaitEvent(&evento);
        }
    }while(!salir);
    return seleccion;
}
const int mapa_2[15][20]={
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
