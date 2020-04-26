#include "ESCENARIO.h"

ESCENARIO::ESCENARIO()
{
    // Constructor
}

ESCENARIO::~ESCENARIO()
{
    // Destructor
}

void ESCENARIO::Dibujar_Esenario(ALLEGRO_BITMAP* IMAGENES[26])
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (this->Matriz_letras[i][j] == 'G') { al_draw_bitmap(IMAGENES[0], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == 'C') { al_draw_bitmap(IMAGENES[1], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == 'M') { al_draw_bitmap(IMAGENES[3], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == 'E') { al_draw_bitmap(IMAGENES[2], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == 'V') { al_draw_bitmap(IMAGENES[4], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == 'T') { al_draw_bitmap(IMAGENES[5], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == 'L') { al_draw_bitmap(IMAGENES[8], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == 'B') { al_draw_bitmap(IMAGENES[9], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == 'R') { al_draw_bitmap(IMAGENES[10], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == 'P') { al_draw_bitmap(IMAGENES[6], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == 'S') { al_draw_bitmap(IMAGENES[7], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == '1') { al_draw_bitmap(IMAGENES[11], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == '2') { al_draw_bitmap(IMAGENES[12], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == '3') { al_draw_bitmap(IMAGENES[13], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == '4') { al_draw_bitmap(IMAGENES[14], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == '8') { al_draw_bitmap(IMAGENES[15], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == '5') { al_draw_bitmap(IMAGENES[16], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == '7') { al_draw_bitmap(IMAGENES[17], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == '9') { al_draw_bitmap(IMAGENES[18], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == '#') { al_draw_bitmap(IMAGENES[19], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == '$') { al_draw_bitmap(IMAGENES[20], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == 'K') { al_draw_bitmap(IMAGENES[21], i * 31 + 386, j * 31 + 116, NULL); } // Sillon
            if (this->Matriz_letras[i][j] == 'O') { al_draw_bitmap(IMAGENES[22], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == 'I') { al_draw_bitmap(IMAGENES[23], i * 31 + 386, j * 31 + 116, NULL); } // Obelsico detruido
            if (this->Matriz_letras[i][j] == '/') { al_draw_bitmap(IMAGENES[24], i * 31 + 386, j * 31 + 116, NULL); }
            if (this->Matriz_letras[i][j] == ';') { al_draw_bitmap(IMAGENES[25], i * 31 + 386, j * 31 + 116, NULL); }
        }
    }
}

void ESCENARIO::Colocar_o_quitar_objeto(char letra, int x, int y)
{
    this->Matriz_letras[x][y] = letra;

    if (letra == 'M') { this->Matriz_letras[x + 1][y] = 'F', this->Matriz_letras[x + 2][y] = 'F', this->Matriz_letras[x + 3][y] = 'F'; }
    if (letra == 'E') { this->Matriz_letras[x + 1][y] = 'F', this->Matriz_letras[x + 2][y] = 'F'; }
    if (letra == 'V' or letra == 'R') { this->Matriz_letras[x][y + 1] = 'F', this->Matriz_letras[x][y + 2] = 'F', this->Matriz_letras[x][y + 3] = 'F'; }
    if (letra == 'T' or letra == '4') { this->Matriz_letras[x][y + 1] = 'F'; }
    if (letra == 'B') { this->Matriz_letras[x][y + 1] = 'F', this->Matriz_letras[x + 1][y] = 'F', this->Matriz_letras[x + 2][y] = 'F', this->Matriz_letras[x + 3][y] = 'F'; this->Matriz_letras[x + 1][y + 1] = 'F', this->Matriz_letras[x + 2][y + 1] = 'F', this->Matriz_letras[x + 3][y + 1] = 'F'; }
    if (letra == 'P' or letra == 'K') { this->Matriz_letras[x][y + 1] = 'F', this->Matriz_letras[x + 1][y + 1] = 'F', this->Matriz_letras[x + 1][y] = 'F'; }
    if (letra == 'S') { this->Matriz_letras[x][y + 1] = 'F', this->Matriz_letras[x + 1][y] = 'F', this->Matriz_letras[x + 2][y] = 'F'; this->Matriz_letras[x + 1][y + 1] = 'F', this->Matriz_letras[x + 2][y + 1] = 'F'; }
    if (letra == '7' or letra == '9') { this->Matriz_letras[x][y + 1] = 'Z'; }
    if (letra == '8' or letra == '5') { this->Matriz_letras[x + 1][y] = 'Z'; }
    if (letra == 'O') { this->Matriz_letras[x][y + 1] = 'F'; }
}
