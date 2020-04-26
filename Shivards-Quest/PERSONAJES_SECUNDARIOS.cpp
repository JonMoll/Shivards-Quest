#include "PERSONAJES_SECUNDARIOS.h"

PERSONAJES_SECUNDARIOS::PERSONAJES_SECUNDARIOS(int x, int y)
{
    this->velocidad_de_movimiento = 31;
    this->posicion_x = x;
    this->posicion_y = y;
}

PERSONAJES_SECUNDARIOS::~PERSONAJES_SECUNDARIOS()
{
    // Destructor
}

int PERSONAJES_SECUNDARIOS::Analizar_persecucion(PERSONAJE_PRINCIPAL Shivard, ESCENARIO Escenario_actual, int en_matriz_x, int en_matriz_y)
{
    float distancia1 = 1000, distancia2 = 1000, distancia3 = 1000, distancia4 = 1000;
    char letra = 'D';
    if (Shivard.posicion_x > this->posicion_x) { letra = 'L'; }
    if (Shivard.posicion_y > this->posicion_y) { letra = 'D'; }
    if (Escenario_actual.Matriz_letras[(this->posicion_x - 415 + 31) / 31][(this->posicion_y - 147 + 31 + 31) / 31] == ' ' or Escenario_actual.Matriz_letras[(this->posicion_x - 415 + 31) / 31][(this->posicion_y - 147 + 31 + 31) / 31] == 'G' or Escenario_actual.Matriz_letras[(this->posicion_x - 415 + 31) / 31][(this->posicion_y - 147 + 31 + 31) / 31] == 'I')
    {
        distancia1 = sqrt(pow((Shivard.posicion_x - 415 + 31) / 31 - en_matriz_x, 2) + pow((Shivard.posicion_y - 147 + 31) / 31 - en_matriz_y - 1, 2));
    }
    if (Escenario_actual.Matriz_letras[(this->posicion_x - 415 + 31) / 31][(this->posicion_y - 147) / 31] == ' ' or Escenario_actual.Matriz_letras[(this->posicion_x - 415 + 31) / 31][(this->posicion_y - 147) / 31] == 'G' or Escenario_actual.Matriz_letras[(this->posicion_x - 415 + 31) / 31][(this->posicion_y - 147) / 31] == 'I')
    {
        distancia2 = sqrt(pow((Shivard.posicion_x - 415 + 31) / 31 - en_matriz_x, 2) + pow((Shivard.posicion_y - 147 + 31) / 31 - en_matriz_y + 1, 2));
    }
    if (Escenario_actual.Matriz_letras[(this->posicion_x - 415 + 31 + 31) / 31][(this->posicion_y - 147 + 31) / 31] == ' ' or Escenario_actual.Matriz_letras[(this->posicion_x - 415 + 31 + 31) / 31][(this->posicion_y - 147 + 31) / 31] == 'G' or Escenario_actual.Matriz_letras[(this->posicion_x - 415 + 31 + 31) / 31][(this->posicion_y - 147 + 31) / 31] == 'I')
    {
        distancia3 = sqrt(pow((Shivard.posicion_x - 415 + 31) / 31 - en_matriz_x - 1, 2) + pow((Shivard.posicion_y - 147 + 31) / 31 - en_matriz_y, 2));
    }
    if (Escenario_actual.Matriz_letras[(this->posicion_x - 415) / 31][(this->posicion_y - 147 + 31) / 31] == ' ' or Escenario_actual.Matriz_letras[(this->posicion_x - 415) / 31][(this->posicion_y - 147 + 31) / 31] == 'G' or Escenario_actual.Matriz_letras[(this->posicion_x - 415) / 31][(this->posicion_y - 147 + 31) / 31] == 'I')
    {
        distancia4 = sqrt(pow((Shivard.posicion_x - 415 + 31) / 31 - en_matriz_x + 1, 2) + pow((Shivard.posicion_y - 147 + 31) / 31 - en_matriz_y, 2));
    }
    int menor = distancia1;
    if (distancia1 == menor) { letra = 'D'; }
    if (distancia2 < menor) { menor = distancia2, letra = 'U'; }
    if (distancia3 < menor) { menor = distancia3, letra = 'R'; }
    if (distancia4 < menor) { menor = distancia4, letra = 'L'; }
    if ((Shivard.posicion_x - 415 + 31) / 31 == en_matriz_x and (Shivard.posicion_y - 147 + 31) / 31 == en_matriz_y) { return 'F'; }
    return letra;
}

int PERSONAJES_SECUNDARIOS::Analizar_persecucion_fantasma(PERSONAJE_PRINCIPAL Shivard, ESCENARIO Escenario_actual, int en_matriz_x, int en_matriz_y)
{
    float distancia1, distancia2, distancia3, distancia4;
    char letra = 'D';
    distancia1 = sqrt(pow((Shivard.posicion_x - 415 + 31) / 31 - en_matriz_x, 2) + pow((Shivard.posicion_y - 147 + 31) / 31 - en_matriz_y - 1, 2));
    distancia2 = sqrt(pow((Shivard.posicion_x - 415 + 31) / 31 - en_matriz_x, 2) + pow((Shivard.posicion_y - 147 + 31) / 31 - en_matriz_y + 1, 2));
    distancia3 = sqrt(pow((Shivard.posicion_x - 415 + 31) / 31 - en_matriz_x - 1, 2) + pow((Shivard.posicion_y - 147 + 31) / 31 - en_matriz_y, 2));
    distancia4 = sqrt(pow((Shivard.posicion_x - 415 + 31) / 31 - en_matriz_x + 1, 2) + pow((Shivard.posicion_y - 147 + 31) / 31 - en_matriz_y, 2));
    int menor = distancia1;
    if (distancia1 == menor) { letra = 'D'; }
    if (distancia2 < menor) { menor = distancia2, letra = 'U'; }
    if (distancia3 < menor) { menor = distancia3, letra = 'R'; }
    if (distancia4 < menor) { menor = distancia4, letra = 'L'; }
    if ((Shivard.posicion_x - 415 + 31) / 31 == en_matriz_x and (Shivard.posicion_y - 147 + 31) / 31 == en_matriz_y) { return 'F'; }
    return letra;
}

int PERSONAJES_SECUNDARIOS::Analizar_movimiento_a_la_esquina(ESCENARIO Escenario_actual, int en_matriz_x, int en_matriz_y, int esquina_x, int esquina_y)
{
    float distancia1 = 1000, distancia2 = 1000, distancia3 = 1000, distancia4 = 1000;
    char letra = 'D';
    if (esquina_x > this->posicion_x) { letra = 'L'; }
    if (esquina_y > this->posicion_y) { letra = 'D'; }
    if (Escenario_actual.Matriz_letras[(this->posicion_x - 415 + 31) / 31][(this->posicion_y - 147 + 31 + 31) / 31] == ' ' or Escenario_actual.Matriz_letras[(this->posicion_x - 415 + 31) / 31][(this->posicion_y - 147 + 31 + 31) / 31] == 'G')
    {
        distancia1 = sqrt(pow((esquina_x - 415 + 31) / 31 - en_matriz_x, 2) + pow((esquina_y - 147 + 31) / 31 - en_matriz_y - 1, 2));
    }
    if (Escenario_actual.Matriz_letras[(this->posicion_x - 415 + 31) / 31][(this->posicion_y - 147) / 31] == ' ' or Escenario_actual.Matriz_letras[(this->posicion_x - 415 + 31) / 31][(this->posicion_y - 147) / 31] == 'G')
    {
        distancia2 = sqrt(pow((esquina_x - 415 + 31) / 31 - en_matriz_x, 2) + pow((esquina_y - 147 + 31) / 31 - en_matriz_y + 1, 2));
    }
    if (Escenario_actual.Matriz_letras[(this->posicion_x - 415 + 31 + 31) / 31][(this->posicion_y - 147 + 31) / 31] == ' ' or Escenario_actual.Matriz_letras[(this->posicion_x - 415 + 31 + 31) / 31][(this->posicion_y - 147 + 31) / 31] == 'G')
    {
        distancia3 = sqrt(pow((esquina_x - 415 + 31) / 31 - en_matriz_x - 1, 2) + pow((esquina_y - 147 + 31) / 31 - en_matriz_y, 2));
    }
    if (Escenario_actual.Matriz_letras[(this->posicion_x - 415) / 31][(this->posicion_y - 147 + 31) / 31] == ' ' or Escenario_actual.Matriz_letras[(this->posicion_x - 415) / 31][(this->posicion_y - 147 + 31) / 31] == 'G')
    {
        distancia4 = sqrt(pow((esquina_x - 415 + 31) / 31 - en_matriz_x + 1, 2) + pow((esquina_y - 147 + 31) / 31 - en_matriz_y, 2));
    }
    int menor = distancia1;
    if (distancia1 == menor) { letra = 'D'; }
    if (distancia2 < menor) { menor = distancia2, letra = 'U'; }
    if (distancia3 < menor) { menor = distancia3, letra = 'R'; }
    if (distancia4 < menor) { menor = distancia4, letra = 'L'; }
    if ((esquina_x - 415 + 31) / 31 == en_matriz_x and (esquina_y - 147 + 31) / 31 == en_matriz_y) { return 'F'; }
    return letra;
}
