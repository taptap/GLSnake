#ifndef _S_INGAME
#define _S_INGAME

#include "globals.h"
#include "targa.h"

/*-----------------------------------------------*/
struct SPoint {
    int x, y;
    struct SPoint *next;
};
typedef struct SPoint SPoint;

/*-----------------------------------------------*/
struct SInGame {

    SApp *App;

    Mix_Music *Music;
    Sound Nyam;
    SPoint Food;
    SPoint *Head;
    int KeyPressed;
    int Timer;
    int dx, dy;
    int Speed;
    STGAFile textureFile;
    GLuint texture;

    unsigned char Field [MATRIXSIZE * MATRIXSIZE];

    int Score;
};
typedef struct SInGame SInGame;


/*--- INITIALIZATION ---*/
/* public         */ void SInGame_Init(SApp *);
/* static private */ void SInGame_InitGraphics(void);

/*--- LOGICS ---*/
/* public         */ void SInGame_Loop(SApp *);

/*--- EVENT PROCESSING --- */
/* private        */ void SInGame_OnKeyDown(SApp *, SDLKey);
/* public         */ void SInGame_ProcessEvent(SApp *, SDL_Event *);
/* private        */ void SInGame_ProcessNewState(SApp *);

/*--- GRAPHICS ---*/
/* public         */ void SInGame_Render(SApp *);

/*--- OpenGL Drawing ---*/
/* static         */ void SInGame_Cube(SApp *, int, int, int);
/* static         */ void SInGame_Grid(void);

/*--- Sound and music ---*/
/* private         */ void SInGame_InitSound(SApp *);
/* static          */ void SInGame_PlaySound(Sound *);

/* deinitializator */ void SInGame_Clear(SApp *);

/* constructor     */ void SInGame_Create(SApp *);
/* destructor      */ void SInGame_Delete(SApp *);

/* switcher        */ void SInGame_Switch(SApp *);
#endif
