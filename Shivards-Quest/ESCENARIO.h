#pragma once

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include "SER.h"

using namespace std;

class ESCENARIO
{
    public:
        ESCENARIO();
        ~ESCENARIO();
        void Dibujar_Esenario(ALLEGRO_BITMAP* IMAGENES[26]);
        void Colocar_o_quitar_objeto(char letra, int x, int y);
        int Escenarios_adyacentes[4];
        int vida_enemigos[4] = { 3,3,3,3 };
        char Matriz_letras[20][20]{
        "XXXXXXXXXXXXXXXXXX",
        "X                X",
        "X                X",
        "X                X",
        "X                X",
        "X                X",
        "X                X",
        "X                X",
        "X                X",
        "X                X",
        "X                X",
        "X                X",
        "X                X",
        "X                X",
        "X                X",
        "X                X",
        "X                X",
        "XXXXXXXXXXXXXXXXXX", };
};
