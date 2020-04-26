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

class SER
{
    public:
        SER();
        ~SER();
        int vida = 3;
        int posicion_x, posicion_y;
        enum Dierecciones { abajo = 0, izquierda = 3, derecha = 6, arriba = 9 };
        int velocidad_de_movimiento = 31;
};
