
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "deplacement.h"

void deplacementManette(SDL_GameController* controller, int indiceJoueur, Personnage* equipe[]) {

    //Valeur � partir de laquelle on se d�place � l'aide du stick analogique (compris entre 0 et 32767)



    int distanceX = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX);

    int distanceY = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY);

    int distance = sqrt(distanceX*distanceX + distanceY*distanceY);

    //premi�re fa�con de ce d�placer
    if(distance > ANCOURSE) {

        if(SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX) > 5000 || SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX) < -5000) equipe[indiceJoueur]->vitX=distanceX/(32766/VITDPL);

        if(SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY) > 5000 || SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY) < -5000) equipe[indiceJoueur]->vitY=distanceY/(32766/VITDPL);

    } else {

        equipe[indiceJoueur]->vitX=0;
        equipe[indiceJoueur]->vitY=0;

    }

}


void deplacementClavier(int indiceJoueur, Personnage* equipe[], doublet clavier[]) {

    equipe[indiceJoueur]->vitX=0;
    equipe[indiceJoueur]->vitY=0;


    if (clavier[SDL_SCANCODE_W].enfonce && clavier[SDL_SCANCODE_D].enfonce)
    {
        equipe[indiceJoueur]->vitX = 4;
        equipe[indiceJoueur]->vitY = -4;

    } else if (clavier[SDL_SCANCODE_A].enfonce && clavier[SDL_SCANCODE_W].enfonce)
    {
        equipe[indiceJoueur]->vitX = -4;
        equipe[indiceJoueur]->vitY = -4;

    } else if (clavier[SDL_SCANCODE_D].enfonce && clavier[SDL_SCANCODE_S].enfonce)
    {
        equipe[indiceJoueur]->vitX = 4;
        equipe[indiceJoueur]->vitY = 4;

    } else if (clavier[SDL_SCANCODE_S].enfonce && clavier[SDL_SCANCODE_A].enfonce)
    {
        equipe[indiceJoueur]->vitX = -4;
        equipe[indiceJoueur]->vitY = 4;

    } else if (clavier[SDL_SCANCODE_W].enfonce)
    {
        equipe[indiceJoueur]->vitY = -5;

    } else if (clavier[SDL_SCANCODE_D].enfonce)
    {
        equipe[indiceJoueur]->vitX = 5;

    } else if (clavier[SDL_SCANCODE_S].enfonce)
    {
        equipe[indiceJoueur]->vitY = 5;

    } else if (clavier[SDL_SCANCODE_A].enfonce)
    {
        equipe[indiceJoueur]->vitX = -5;

    }

}
