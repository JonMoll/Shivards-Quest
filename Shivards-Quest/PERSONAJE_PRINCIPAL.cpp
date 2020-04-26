#include "PERSONAJE_PRINCIPAL.h"
#include "ESCENARIO.h"

PERSONAJE_PRINCIPAL::PERSONAJE_PRINCIPAL()
{
    this->velocidad_de_movimiento = 31;
    this->vida = 30;
}

PERSONAJE_PRINCIPAL::~PERSONAJE_PRINCIPAL()
{
    // Destructor
}

void PERSONAJE_PRINCIPAL::Espadazo(char Direccion, ALLEGRO_BITMAP* ESPADAS[4])
{
    if (Direccion == 'L') { al_draw_bitmap(ESPADAS[2], this->posicion_x - 31, this->posicion_y, NULL); }
    if (Direccion == 'R') { al_draw_bitmap(ESPADAS[3], this->posicion_x + 31, this->posicion_y, NULL); }
    if (Direccion == 'U') { al_draw_bitmap(ESPADAS[0], this->posicion_x, this->posicion_y - 31, NULL); }
    if (Direccion == 'D') { al_draw_bitmap(ESPADAS[1], this->posicion_x, this->posicion_y + 31, NULL); }
}

/*void PERSONAJE_PRINCIPAL::Mostrar_gemas_totales(ALLEGRO_FONT* fuente)
{
    char unidades;
    sprintf(&unidades, "%d", this->Gemas_recogidas);
    al_draw_text(fuente, al_map_rgb(250, 250, 250), 65, 655, NULL, &unidades);
}*/
