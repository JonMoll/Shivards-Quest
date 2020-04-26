#pragma once

#include "SER.h"
#include "ESCENARIO.h"
#include <stdio.h>
#include <stdio.h>

class PERSONAJE_PRINCIPAL:public SER
{
    public:
        PERSONAJE_PRINCIPAL();
        ~PERSONAJE_PRINCIPAL();
        int Gemas_recogidas = 0;
        void Espadazo(char Direccion, ALLEGRO_BITMAP* ESPADAS[4]);
        //void Mostrar_gemas_totales(ALLEGRO_FONT* fuente);
};
