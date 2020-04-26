#pragma once

#include "SER.h"
#include "ESCENARIO.h"
#include "Personaje_principal.h"

class PERSONAJES_SECUNDARIOS:public SER
{
    public:
        PERSONAJES_SECUNDARIOS(int x, int y);
        ~PERSONAJES_SECUNDARIOS();
        int Analizar_persecucion(PERSONAJE_PRINCIPAL Shivard, ESCENARIO Escenario_actual, int en_matriz_x, int en_mtriz_y);
        int Analizar_persecucion_fantasma(PERSONAJE_PRINCIPAL Shivard, ESCENARIO Escenario_actual, int en_matriz_x, int en_mtriz_y);
        int Analizar_movimiento_a_la_esquina(ESCENARIO Escenario_actual, int en_matriz_x, int en_mtriz_y, int esquina_x, int esquina_y);
};
