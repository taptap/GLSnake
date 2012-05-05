#include <SDL/SDL.h>
#include <GL/gl.h>
#include <SDL/SDL_mixer.h>

#define CUBESIZE 30
#define CELLSIZE 36
#define MATRIXSIZE 20

typedef struct {
    int Running;

    struct vtable_State *State;
    SDL_Surface *SDisplay;
    struct SInGame *InGame;
} SApp;


/*-----------------------------------------------*/
struct vtable_State{
    void (* Init)(SApp *);
    void (* Loop)(SApp *);
    void (* Event)(SApp *, SDL_Event *);
    void (* Render)(SApp *);
    void (* Cleanup)(SApp *);
};
typedef struct vtable_State vtable_State;


/*-----------------------------------------------*/
