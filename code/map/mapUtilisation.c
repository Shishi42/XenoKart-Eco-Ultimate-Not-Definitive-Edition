
SDL_FillRect(pSurface, NULL, SDL_MapRGB(pSurface->format, 0, 0, 0));
SDL_GetMouseState(&mouseX,&mouseY);
afficherMap(map, pSurface, camera);
afficher_perso_map(perso, pos.coord.x, pos.coord.y, camera, screen);

deplacement(e, &camera, mouseX, mouseY, map->v, &pos);




/////////////////////////////////// pos est la case_t sur laquelle on se trouve /////////////////////////////////////////
////////////////////////////////// switch en fonction de son subtype ////////////////////////////////////////////////////

if(pos.val == map->v[1][1].val) etatProg = initialisationCombat;







SDL_UpdateWindowSurface(screen);