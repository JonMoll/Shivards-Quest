#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>

#include <allegro5/allegro5.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "ESCENARIO.h"
#include "SER.h"
#include "Personaje_principal.h"
#include "Personajes_secundarios.h"

typedef float rasmus;
typedef int travis;
using namespace std;

/*void Mostrar_escenario(int Escenario, ALLEGRO_FONT* fuente)
{
    char Escenario_letra;
    sprintf(&Escenario_letra, "%d", Escenario);
    al_draw_text(fuente, al_map_rgb(0, 0, 0), 280, 320, NULL, &Escenario_letra);
}*/

int main() {
    //OBJETOS
    PERSONAJE_PRINCIPAL Shivard;
    PERSONAJES_SECUNDARIOS Skull(880, 612);
    PERSONAJES_SECUNDARIOS Skull2(415, 612);
    PERSONAJES_SECUNDARIOS Fantasma(415, 116);
    PERSONAJES_SECUNDARIOS Fantasma2(880, 116);
    PERSONAJES_SECUNDARIOS Agobard(8 * 31 + 386, 31 + 116);
    Agobard.vida = 3;

    PERSONAJES_SECUNDARIOS Fuego1(880, 612);
    PERSONAJES_SECUNDARIOS Fuego2(415, 612);
    PERSONAJES_SECUNDARIOS Fuego3(415, 116);
    PERSONAJES_SECUNDARIOS Fuego4(880, 116);
    PERSONAJES_SECUNDARIOS Esfera_de_energia1(880, 116);
    PERSONAJES_SECUNDARIOS Esfera_de_energia2(880, 116);
    PERSONAJES_SECUNDARIOS Esfera_de_energia3(880, 116);
    PERSONAJES_SECUNDARIOS Esfera_de_energia4(880, 116);


    ALLEGRO_DISPLAY* display;
    float FPS = 8.0;

    if (!al_init())
    {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    display = al_create_display(990, 720);


    al_set_window_title(display, "Shivard's Quest");

    if (!display)
    {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }


    al_set_window_position(display, 0, 0);
    //Variables
    //#################################
    bool done = false, draw = true, active = false;


    //imagenes


    ALLEGRO_BITMAP* skull[12];
    ALLEGRO_BITMAP* shivard[12];
    ALLEGRO_BITMAP* fantasma[12];
    ALLEGRO_BITMAP* mago[12];
    ALLEGRO_BITMAP* fuegos[12];
    ALLEGRO_BITMAP* energy_ball[12];


    //usando
    al_install_keyboard();
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_FONT* gemas_recogidas = al_load_font("./Assets/Fonts/Alice_in_Wonderland_3.ttf", 50, NULL);

    al_reserve_samples(1);
    ALLEGRO_SAMPLE* song = al_load_sample("./Assets/Sounds/song2.flac");
    ALLEGRO_SAMPLE_INSTANCE* song_instance = al_create_sample_instance(song);
    al_set_sample_instance_position(song_instance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(song_instance, al_get_default_mixer());

    ALLEGRO_BITMAP* puerta_cerrada1 = al_load_bitmap("./Assets/Images/Puertas_cerrada1.png");
    ALLEGRO_BITMAP* puerta_cerrada2 = al_load_bitmap("./Assets/Images/Puertas_cerrada2.png");
    ALLEGRO_BITMAP* gameover = al_load_bitmap("./Assets/Images/Game Over.png");
    ALLEGRO_BITMAP* menu = al_load_bitmap("./Assets/Images/Menu.png");
    ALLEGRO_BITMAP* logo = al_load_bitmap("./Assets/Images/Logo.png");
    ALLEGRO_BITMAP* vida3 = al_load_bitmap("./Assets/Images/Vida 3.png");
    ALLEGRO_BITMAP* vida2 = al_load_bitmap("./Assets/Images/Vida 2.png");
    ALLEGRO_BITMAP* vida1 = al_load_bitmap("./Assets/Images/Vida 1.png");
    ALLEGRO_BITMAP* hist1 = al_load_bitmap("./Assets/Images/Cinematica1.png");
    ALLEGRO_BITMAP* hist2 = al_load_bitmap("./Assets/Images/Cinematica2.png");
    ALLEGRO_BITMAP* hist3 = al_load_bitmap("./Assets/Images/Cinematica3.png");
    ALLEGRO_BITMAP* hist4 = al_load_bitmap("./Assets/Images/Cinematica4.png");
    ALLEGRO_BITMAP* hist5 = al_load_bitmap("./Assets/Images/Pause.png");
    ALLEGRO_BITMAP* piso_madera = al_load_bitmap("./Assets/Images/Madera.png");
    ALLEGRO_BITMAP* piso_cesped = al_load_bitmap("./Assets/Images/Cesped.png");
    ALLEGRO_BITMAP* gema = al_load_bitmap("./Assets/Images/Cristal 1.png");
    ALLEGRO_BITMAP* caja = al_load_bitmap("./Assets/Images/Caja.png");
    ALLEGRO_BITMAP* mesa_de_3 = al_load_bitmap("./Assets/Images/mesa_de_3.png");
    ALLEGRO_BITMAP* mesa_de_4 = al_load_bitmap("./Assets/Images/mesa_de_4.png");
    ALLEGRO_BITMAP* mesa_de_4v = al_load_bitmap("./Assets/Images/mesa_de_4v.png");
    ALLEGRO_BITMAP* mesa_y_taburete = al_load_bitmap("./Assets/Images/mesa_y_taburete.png");
    ALLEGRO_BITMAP* piano = al_load_bitmap("./Assets/Images/Piano.png");
    ALLEGRO_BITMAP* posiones = al_load_bitmap("./Assets/Images/Posiones.png");
    ALLEGRO_BITMAP* librero_de_2 = al_load_bitmap("./Assets/Images/Librero_de_2.png");
    ALLEGRO_BITMAP* librero_de_4 = al_load_bitmap("./Assets/Images/Librero_de_4.png");
    ALLEGRO_BITMAP* librerov_de_4 = al_load_bitmap("./Assets/Images/Librerov_de_4.png");
    ALLEGRO_BITMAP* adorno1 = al_load_bitmap("./Assets/Images/adorno1.png");
    ALLEGRO_BITMAP* adorno2 = al_load_bitmap("./Assets/Images/adorno2.png");
    ALLEGRO_BITMAP* adorno3 = al_load_bitmap("./Assets/Images/adorno3.png");
    ALLEGRO_BITMAP* adorno4 = al_load_bitmap("./Assets/Images/adorno4.png");
    ALLEGRO_BITMAP* puerta_top = al_load_bitmap("./Assets/Images/Puerta_top.png");
    ALLEGRO_BITMAP* puerta_bot = al_load_bitmap("./Assets/Images/Puerta_bot.png");
    ALLEGRO_BITMAP* puerta_left = al_load_bitmap("./Assets/Images/Puerta_left.png");
    ALLEGRO_BITMAP* puerta_right = al_load_bitmap("./Assets/Images/Puerta_right.png");
    ALLEGRO_BITMAP* flores = al_load_bitmap("./Assets/Images/flores.png");
    ALLEGRO_BITMAP* arbol = al_load_bitmap("./Assets/Images/arbol2.png");
    ALLEGRO_BITMAP* sillon = al_load_bitmap("./Assets/Images/sillon.png");
    ALLEGRO_BITMAP* obelisco = al_load_bitmap("./Assets/Images/Obelisco.png");
    ALLEGRO_BITMAP* corazon = al_load_bitmap("./Assets/Images/Corazon.png");



    ALLEGRO_BITMAP* EspU = al_load_bitmap("./Assets/Images/espadaU.png");
    ALLEGRO_BITMAP* EspD = al_load_bitmap("./Assets/Images/espadaA.png");
    ALLEGRO_BITMAP* EspL = al_load_bitmap("./Assets/Images/espadaI.png");
    ALLEGRO_BITMAP* EspR = al_load_bitmap("./Assets/Images/espadaD.png");


    ALLEGRO_BITMAP* IMAGENES[26];
    ALLEGRO_BITMAP* ESPADAS[4];

    ESPADAS[0] = EspU;
    ESPADAS[1] = EspD;
    ESPADAS[2] = EspL;
    ESPADAS[3] = EspR;

    IMAGENES[0] = gema;
    IMAGENES[1] = caja;
    IMAGENES[2] = mesa_de_3;
    IMAGENES[3] = mesa_de_4;
    IMAGENES[4] = mesa_de_4v;
    IMAGENES[5] = mesa_y_taburete;
    IMAGENES[6] = piano;
    IMAGENES[7] = posiones;
    IMAGENES[8] = librero_de_2;
    IMAGENES[9] = librero_de_4;
    IMAGENES[10] = librerov_de_4;
    IMAGENES[11] = adorno1;
    IMAGENES[12] = adorno2;
    IMAGENES[13] = adorno3;
    IMAGENES[14] = adorno4;
    IMAGENES[15] = puerta_top;
    IMAGENES[16] = puerta_bot;
    IMAGENES[17] = puerta_left;
    IMAGENES[18] = puerta_right;
    IMAGENES[19] = flores;
    IMAGENES[20] = arbol;
    IMAGENES[21] = sillon;
    IMAGENES[22] = obelisco;
    IMAGENES[23] = corazon;
    IMAGENES[24] = puerta_cerrada1;
    IMAGENES[25] = puerta_cerrada2;


    //IMAGENES DE LOS PERSONAJES
    for (int i = 0; i < 12; i++)
    {
        std::stringstream str;
        str << "./Assets/Images/Skull/" << i + 1 << ".png";
        skull[i] = al_load_bitmap(str.str().c_str());
    }
    for (int i = 0; i < 12; i++)
    {
        std::stringstream str;
        str << "./Assets/Images/Shivard/" << i + 1 << ".png";
        shivard[i] = al_load_bitmap(str.str().c_str());
    }

    for (int i = 0; i < 12; i++)
    {
        std::stringstream str;
        str << "./Assets/Images/Fantasma/" << i + 1 << ".png";
        fantasma[i] = al_load_bitmap(str.str().c_str());
    }
    for (int i = 0; i < 12; i++)
    {
        std::stringstream str;
        str << "./Assets/Images/Agobard/" << i + 1 << ".png";
        mago[i] = al_load_bitmap(str.str().c_str());
    }
    for (int i = 0; i < 12; i++)
    {
        std::stringstream str;
        str << "./Assets/Images/Fire/" << i + 1 << ".png";
        fuegos[i] = al_load_bitmap(str.str().c_str());
    }
    for (int i = 0; i < 12; i++)
    {
        std::stringstream str;
        str << "./Assets/Images/Energy_ball1/" << i + 1 << ".png";
        energy_ball[i] = al_load_bitmap(str.str().c_str());
    }



    ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
    ALLEGRO_EVENT_QUEUE* cola_de_eventos = al_create_event_queue();
    ALLEGRO_KEYBOARD_STATE key_state;

    //teclado

    al_register_event_source(cola_de_eventos, al_get_keyboard_event_source());
    al_register_event_source(cola_de_eventos, al_get_timer_event_source(timer));
    al_register_event_source(cola_de_eventos, al_get_display_event_source(display));


    al_play_sample_instance(song_instance);




    //OBJETOS
        //ESENARIOS
        //el array de aledaños es [ ARRIBA, ABAJO, IZQUIERDA ,DERECHA ]

        //880-612,415-612,415-147,880,147
    int Escenario = 0;

    ESCENARIO Escenario_actual[12];

    ESCENARIO Escenario0;
    Escenario0.Escenarios_adyacentes[0] = 1;
    Escenario0.Escenarios_adyacentes[1] = 0;
    Escenario0.Escenarios_adyacentes[2] = 0;
    Escenario0.Escenarios_adyacentes[3] = 0;
    Escenario0.vida_enemigos[0] = 0;
    Escenario0.vida_enemigos[1] = 0;
    Escenario0.vida_enemigos[2] = 0;
    Escenario0.vida_enemigos[3] = 0;
    int arboles0_y[16] = { 4,4,7,7,7,7,8,8,10,10,10,10,13,13,15,15 };
    int arboles0_x[16] = { 7,10,3,7,10,14,5,12,3,7,10,14,2,15,4,13 };
    for (int i = 0; i < 16; i++) { Escenario0.Colocar_o_quitar_objeto('$', arboles0_x[i], arboles0_y[i]); }
    Escenario0.Colocar_o_quitar_objeto('8', 8, 0);

    ESCENARIO Escenario1;

    Escenario1.Escenarios_adyacentes[0] = 0;
    Escenario1.Escenarios_adyacentes[1] = 0;//VERIFICAR
    Escenario1.Escenarios_adyacentes[2] = 2;
    Escenario1.Escenarios_adyacentes[3] = 6;
    int cajas_y[18] = { 3,3,3,3,6,6,9,9,10,10,13,13,13,13,13,13,14,14 };
    int cajas_x[18] = { 2,6,11,15,7,10,4,13,6,11,1,2,5,12,15,16,8,9 };
    for (int i = 0; i < 18; i++) { Escenario1.Colocar_o_quitar_objeto('C', cajas_x[i], cajas_y[i]); }
    int gemas_y[8] = { 2,2,3,3,7,7,12,12 };
    int gemas_x[8] = { 3,13,7,10,6,11,8,9 };
    for (int i = 0; i < 8; i++) { Escenario1.Colocar_o_quitar_objeto('G', gemas_x[i], gemas_y[i]); }
    int mesita_y[4] = { 5,5,11,11 };
    int mesita_x[4] = { 3,14,3,14 };
    for (int i = 0; i < 4; i++) { Escenario1.Colocar_o_quitar_objeto('T', mesita_x[i], mesita_y[i]); }
    Escenario1.Colocar_o_quitar_objeto('5', 8, 17);
    Escenario1.Colocar_o_quitar_objeto('7', 0, 8);
    Escenario1.Colocar_o_quitar_objeto('9', 17, 8);
    Escenario1.Colocar_o_quitar_objeto('I', 5, 5);


    ESCENARIO Escenario2;

    Escenario2.Escenarios_adyacentes[0] = 3;
    Escenario2.Escenarios_adyacentes[1] = 0;
    Escenario2.Escenarios_adyacentes[2] = 0;
    Escenario2.Escenarios_adyacentes[3] = 1;
    int cajas2_y[13] = { 1,2,3,5,5,8,8,9,9,14,14,14,15 };
    int cajas2_x[13] = { 12,3,12,8,16,7,12,4,10,5,8,16,3 };
    for (int i = 0; i < 13; i++) { Escenario2.Colocar_o_quitar_objeto('C', cajas2_x[i], cajas2_y[i]); }
    int gemas2_y[8] = { 2,2,5,8,12,12,14,15 };
    int gemas2_x[8] = { 2,15,11,5,3,16,13,6 };
    for (int i = 0; i < 8; i++) { Escenario2.Colocar_o_quitar_objeto('G', gemas2_x[i], gemas2_y[i]); }
    int mesas2_de_4_y[8] = { 4,4,6,6,11,11,13,13 };
    int mesas2_de_4_x[8] = { 2,9,2,9,2,9,2,9 };
    for (int i = 0; i < 8; i++) { Escenario2.Colocar_o_quitar_objeto('M', mesas2_de_4_x[i], mesas2_de_4_y[i]); }
    int mesasv2_de_4_y[4] = { 3,3,11,11 };
    int mesasv2_de_4_x[4] = { 7,14,7,14 };
    for (int i = 0; i < 4; i++) { Escenario2.Colocar_o_quitar_objeto('V', mesasv2_de_4_x[i], mesasv2_de_4_y[i]); }
    Escenario2.Colocar_o_quitar_objeto('8', 8, 0);
    Escenario2.Colocar_o_quitar_objeto('9', 17, 8);
    Escenario2.Colocar_o_quitar_objeto('I', 2, 8);

    ESCENARIO Escenario3;

    Escenario3.Escenarios_adyacentes[0] = 4;
    Escenario3.Escenarios_adyacentes[1] = 2;
    Escenario3.Escenarios_adyacentes[2] = 0;
    Escenario3.Escenarios_adyacentes[3] = 10;
    int gemas3_y[10] = { 2,2,4,5,8,9,9,10,13,14 };
    int gemas3_x[10] = { 2,15,11,5,8,2,9,15,15,3 };
    for (int i = 0; i < 10; i++) { Escenario3.Colocar_o_quitar_objeto('G', gemas3_x[i], gemas3_y[i]); }
    int adorno13_y[4] = { 5,4,11,11 };
    int adorno13_x[4] = { 2,12,5,12 };
    for (int i = 0; i < 4; i++) { Escenario3.Colocar_o_quitar_objeto('1', adorno13_x[i], adorno13_y[i]); }
    int adorno23_y[4] = { 4,6,10,12 };
    int adorno23_x[4] = { 5,12,14,2 };
    for (int i = 0; i < 4; i++) { Escenario3.Colocar_o_quitar_objeto('2', adorno23_x[i], adorno23_y[i]); }
    int adorno33_y[4] = { 6,7,13,13 };
    int adorno33_x[4] = { 5,14,5,12 };
    for (int i = 0; i < 4; i++) { Escenario3.Colocar_o_quitar_objeto('3', adorno33_x[i], adorno33_y[i]); }
    Escenario3.Colocar_o_quitar_objeto('4', 5, 8);

    Escenario3.Colocar_o_quitar_objeto('8', 8, 0);
    Escenario3.Colocar_o_quitar_objeto('5', 8, 17);
    Escenario3.Colocar_o_quitar_objeto('9', 17, 8);
    Escenario3.Colocar_o_quitar_objeto('I', 12, 8);

    ESCENARIO Escenario4;

    Escenario4.Escenarios_adyacentes[0] = 0;
    Escenario4.Escenarios_adyacentes[1] = 3;
    Escenario4.Escenarios_adyacentes[2] = 5;
    Escenario4.Escenarios_adyacentes[3] = 0;
    int cajas4_y[8] = { 2,8,9,10,11,11,13,14 };
    int cajas4_x[8] = { 5,13,5,9,4,13,7,11 };
    for (int i = 0; i < 8; i++) { Escenario4.Colocar_o_quitar_objeto('C', cajas4_x[i], cajas4_y[i]); }
    int gemas4_y[10] = { 1,2,3,4,9,9,12,12,14,14 };
    int gemas4_x[10] = { 2,10,15,5,7,10,1,16,5,15 };
    for (int i = 0; i < 10; i++) { Escenario4.Colocar_o_quitar_objeto('G', gemas4_x[i], gemas4_y[i]); }
    int mesas4_de_3_y[2] = { 7,7 };
    int mesas4_de_3_x[2] = { 6,9 };
    for (int i = 0; i < 2; i++) { Escenario4.Colocar_o_quitar_objeto('E', mesas4_de_3_x[i], mesas4_de_3_y[i]); }
    Escenario4.Colocar_o_quitar_objeto('P', 8, 3);
    Escenario4.Colocar_o_quitar_objeto('S', 12, 2);
    int librerosv4_y[3] = { 2,5,12 };
    int librerosv4_x[3] = { 2,15,2 };
    for (int i = 0; i < 3; i++) { Escenario4.Colocar_o_quitar_objeto('R', librerosv4_x[i], librerosv4_y[i]); }
    Escenario4.Colocar_o_quitar_objeto('5', 8, 17);
    Escenario4.Colocar_o_quitar_objeto('7', 0, 8);
    Escenario4.Colocar_o_quitar_objeto('I', 4, 7);

    ESCENARIO Escenario5;

    Escenario5.Escenarios_adyacentes[0] = 0;
    Escenario5.Escenarios_adyacentes[1] = 0;
    Escenario5.Escenarios_adyacentes[2] = 0;
    Escenario5.Escenarios_adyacentes[3] = 4;
    int gemas5_y[22] = { 1,1,1,2,3,3,5,7,7,8,9,10,11,11,12,12,13,14,15,15,15,16 };
    int gemas5_x[22] = { 1,6,15,12,3,8,7,1,15,11,5,7,2,10,3,16,14,5,1,9,16,12 };
    for (int i = 0; i < 22; i++) { Escenario5.Colocar_o_quitar_objeto('G', gemas5_x[i], gemas5_y[i]); }
    int librerosv5_y[12] = { 2,2,2,2,7,7,7,7,12,12,12,12 };
    int librerosv5_x[12] = { 2,4,13,15,2,4,6,8,2,4,13,15 };
    for (int i = 0; i < 12; i++) { Escenario5.Colocar_o_quitar_objeto('R', librerosv5_x[i], librerosv5_y[i]); }
    int libreros5_y[3] = { 3,8,13 };
    int libreros5_x[3] = { 7,10,7 };
    for (int i = 0; i < 3; i++) { Escenario5.Colocar_o_quitar_objeto('B', libreros5_x[i], libreros5_y[i]); }

    Escenario5.Colocar_o_quitar_objeto('9', 17, 8);
    Escenario5.Colocar_o_quitar_objeto('I', 7, 15);

    ESCENARIO Escenario6;

    Escenario6.Escenarios_adyacentes[0] = 7;
    Escenario6.Escenarios_adyacentes[1] = 0;
    Escenario6.Escenarios_adyacentes[2] = 1;
    Escenario6.Escenarios_adyacentes[3] = 0;
    int gemas6_y[12] = { 2,3,4,5,7,9,10,12,12,12,14,15 };
    int gemas6_x[12] = { 6,15,2,11,9,14,7,3,11,15,5,10 };
    for (int i = 0; i < 12; i++) { Escenario6.Colocar_o_quitar_objeto('G', gemas6_x[i], gemas6_y[i]); }
    int mesas6_de_4_y[6] = { 4,4,6,11,13,13 };
    int mesas6_de_4_x[6] = { 5,11,8,6,3,9 };
    for (int i = 0; i < 6; i++) { Escenario6.Colocar_o_quitar_objeto('M', mesas6_de_4_x[i], mesas6_de_4_y[i]); }
    int mesasv6_de_4_y[4] = { 3,6,8,11 };
    int mesasv6_de_4_x[4] = { 3,6,12,14 };
    for (int i = 0; i < 4; i++) { Escenario6.Colocar_o_quitar_objeto('V', mesasv6_de_4_x[i], mesasv6_de_4_y[i]); }
    Escenario6.Colocar_o_quitar_objeto('8', 8, 0);
    Escenario6.Colocar_o_quitar_objeto('7', 0, 8);
    Escenario6.Colocar_o_quitar_objeto('I', 4, 9);

    ESCENARIO Escenario7;

    Escenario7.Escenarios_adyacentes[0] = 8;
    Escenario7.Escenarios_adyacentes[1] = 6;
    Escenario7.Escenarios_adyacentes[2] = 10;
    Escenario7.Escenarios_adyacentes[3] = 6;
    int gemas7_y[14] = { 2,2,4,4,4,5,6,9,9,11,11,12,14,15 };
    int gemas7_x[14] = { 5,11,2,8,15,12,3,7,16,4,12,14,7,13 };
    for (int i = 0; i < 14; i++) { Escenario7.Colocar_o_quitar_objeto('G', gemas7_x[i], gemas7_y[i]); }
    int adorno17_y[4] = { 3,5,7,13 };
    int adorno17_x[4] = { 5,15,7,7 };
    for (int i = 0; i < 4; i++) { Escenario7.Colocar_o_quitar_objeto('1', adorno17_x[i], adorno17_y[i]); }
    int adorno27_y[5] = { 3,4,10,14,14 };
    int adorno27_x[5] = { 13,3,3,5,13 };
    for (int i = 0; i < 5; i++) { Escenario7.Colocar_o_quitar_objeto('2', adorno27_x[i], adorno27_y[i]); }
    int adorno37_y[5] = { 4,7,10,12,13 };
    int adorno37_x[5] = { 7,3,7,15,3 };
    for (int i = 0; i < 5; i++) { Escenario7.Colocar_o_quitar_objeto('3', adorno37_x[i], adorno37_y[i]); }
    int adorno47_y[3] = { 5,8,11 };
    int adorno47_x[3] = { 11,15,11 };
    for (int i = 0; i < 3; i++) { Escenario7.Colocar_o_quitar_objeto('4', adorno47_x[i], adorno47_y[i]); }
    Escenario7.Colocar_o_quitar_objeto('8', 8, 0);
    Escenario7.Colocar_o_quitar_objeto('5', 8, 17);
    Escenario7.Colocar_o_quitar_objeto('7', 0, 8);
    Escenario7.Colocar_o_quitar_objeto('I', 10, 9);

    ESCENARIO Escenario8;

    Escenario8.Escenarios_adyacentes[0] = 0;
    Escenario8.Escenarios_adyacentes[1] = 7;
    Escenario8.Escenarios_adyacentes[2] = 0;
    Escenario8.Escenarios_adyacentes[3] = 9;
    int cajas8_y[13] = { 3,3,5,7,8,10,10,11,12,12,13,14,15 };
    int cajas8_x[13] = { 2,15,10,12,9,4,7,13,5,10,7,3,11 };
    for (int i = 0; i < 13; i++) { Escenario8.Colocar_o_quitar_objeto('C', cajas8_x[i], cajas8_y[i]); }
    int gemas8_y[17] = { 1,2,2,4,4,4,6,8,9,11,11,11,12,14,14,15,15 };
    int gemas8_x[17] = { 3,8,14,4,11,15,6,14,3,1,5,11,16,7,12,2,15 };
    for (int i = 0; i < 17; i++) { Escenario8.Colocar_o_quitar_objeto('G', gemas8_x[i], gemas8_y[i]); }
    int mesas8_de_3_y[2] = { 3,7 };
    int mesas8_de_3_x[2] = { 3,4 };
    for (int i = 0; i < 2; i++) { Escenario8.Colocar_o_quitar_objeto('E', mesas8_de_3_x[i], mesas8_de_3_y[i]); }
    int librerosv8_y[3] = { 4,9,10 };
    int librerosv8_x[3] = { 14,2,14 };
    for (int i = 0; i < 3; i++) { Escenario8.Colocar_o_quitar_objeto('R', librerosv8_x[i], librerosv8_y[i]); }
    Escenario8.Colocar_o_quitar_objeto('M', 9, 2);

    Escenario8.Colocar_o_quitar_objeto('5', 8, 17);
    Escenario8.Colocar_o_quitar_objeto('9', 17, 8);
    Escenario8.Colocar_o_quitar_objeto('I', 5, 15);

    ESCENARIO Escenario9;

    Escenario9.Escenarios_adyacentes[0] = 0;
    Escenario9.Escenarios_adyacentes[1] = 0;
    Escenario9.Escenarios_adyacentes[2] = 8;
    Escenario9.Escenarios_adyacentes[3] = 0;
    int gemas9_y[20] = { 1,1,1,2,3,3,4,4,6,8,9,10,11,11,12,12,14,14,15,16 };
    int gemas9_x[20] = { 4,7,14,9,1,11,6,15,3,14,5,11,1,16,3,8,4,13,15,6 };
    for (int i = 0; i < 20; i++) { Escenario9.Colocar_o_quitar_objeto('G', gemas9_x[i], gemas9_y[i]); }
    int mesasv9_de_4_y[4] = { 2,2,11,11 };
    int mesasv9_de_4_x[4] = { 7,10,2,15 };
    for (int i = 0; i < 4; i++) { Escenario9.Colocar_o_quitar_objeto('V', mesasv9_de_4_x[i], mesasv9_de_4_y[i]); }
    int mesas9_de_4_y[] = { 8,8,10 };
    int mesas9_de_4_x[3] = { 4,10,7 };
    for (int i = 0; i < 3; i++) { Escenario9.Colocar_o_quitar_objeto('M', mesas9_de_4_x[i], mesas9_de_4_y[i]); }
    int posiones9_y[4] = { 3,3,14,14 };
    int posiones9_x[4] = { 3,12,5,10 };
    for (int i = 0; i < 4; i++) { Escenario9.Colocar_o_quitar_objeto('S', posiones9_x[i], posiones9_y[i]); }

    Escenario9.Colocar_o_quitar_objeto('7', 0, 8);
    Escenario9.Colocar_o_quitar_objeto('I', 15, 9);

    ESCENARIO Escenario10;

    Escenario10.Escenarios_adyacentes[0] = 11;
    Escenario10.Escenarios_adyacentes[1] = 0;
    Escenario10.Escenarios_adyacentes[2] = 3;
    Escenario10.Escenarios_adyacentes[3] = 7;
    int gemas10_y[8] = { 4,4,7,7,9,9,15,15 };
    int gemas10_x[8] = { 2,15,8,9,8,9,2,15 };
    for (int i = 0; i < 8; i++) { Escenario10.Colocar_o_quitar_objeto('G', gemas10_x[i], gemas10_y[i]); }
    int flores10_y[76] = { 2,2,2,2,2,2,2,2,2,2,3,3,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,8,8,8,8,9,9,9,9,9,9,10,10,10,10,10,10,12,12,12,12,12,12,12,12,13,13,13,13,13,13,14,14,15,15,15,15,15,15,15,15 };
    int flores10_x[76] = { 2,3,4,5,7,10,12,13,14,15,7,10,4,5,6,7,10,11,12,13,1,2,3,7,8,9,10,14,15,16,3,5,7,10,12,14,3,5,12,14,3,5,7,10,12,14,3,7,8,9,10,14,2,3,4,5,12,13,14,15,2,7,8,9,10,15,4,13,4,5,6,7,10,11,12,13 };
    for (int i = 0; i < 76; i++) { Escenario10.Colocar_o_quitar_objeto('#', flores10_x[i], flores10_y[i]); }
    int arboles10_y[16] = { 4,4,7,7,7,7,8,8,10,10,10,10,13,13,15,15 };
    int arboles10_x[16] = { 7,10,3,7,10,14,5,12,3,7,10,14,2,15,4,13 };
    for (int i = 0; i < 16; i++) { Escenario10.Colocar_o_quitar_objeto('$', arboles10_x[i], arboles10_y[i]); }
    Escenario10.Colocar_o_quitar_objeto('8', 8, 0);
    Escenario10.Colocar_o_quitar_objeto('9', 17, 8);
    Escenario10.Colocar_o_quitar_objeto('7', 0, 8);

    ESCENARIO Escenario11;
    Escenario11.Escenarios_adyacentes[0] = 0;
    Escenario11.Escenarios_adyacentes[1] = 10;
    Escenario11.Escenarios_adyacentes[2] = 0;
    Escenario11.Escenarios_adyacentes[3] = 0;
    Escenario11.Colocar_o_quitar_objeto('K', 8, 0);
    int obeliscos_x[4] = { 4,13,4,13 };
    int obeliscos_y[4] = { 4,4,10,10 };
    for (int i = 0; i < 4; i++) { Escenario11.Colocar_o_quitar_objeto('O', obeliscos_x[i], obeliscos_y[i]); }

    Escenario11.Colocar_o_quitar_objeto(';', 8, 17);

    Escenario_actual[0] = Escenario0;
    Escenario_actual[1] = Escenario1;
    Escenario_actual[2] = Escenario2;
    Escenario_actual[3] = Escenario3;
    Escenario_actual[4] = Escenario4;
    Escenario_actual[5] = Escenario5;
    Escenario_actual[6] = Escenario6;
    Escenario_actual[7] = Escenario7;
    Escenario_actual[8] = Escenario8;
    Escenario_actual[9] = Escenario9;
    Escenario_actual[10] = Escenario10;
    Escenario_actual[11] = Escenario11;

    //GAME LOOP
    int contador_enemigos = 0;

    Shivard.posicion_x = 663; Shivard.posicion_y = 612;
    /*int Dir = Shivard.abajo, direccion_anterior, index = 0;
    int Dir_fantasma = Fantasma.abajo, direccion_anterior_fantasma, index2 = 0;
    int Dir_fantasma2 = Fantasma2.abajo, direccion_anterior_fantasma2, index3 = 0;
    int Dir_skull = Skull.abajo, direccion_anterior_skull, index4 = 0;
    int Dir_skull2 = Skull2.abajo, direccion_anterior_skull2, index5 = 0;
    int Dir_agobard = Agobard.abajo, direccion_anterior_agobard, index_agobard = 0;*/

    int Dir = 0;
    int Dir_fantasma = 0;
    int Dir_fantasma2 = 0;
    int Dir_skull = 0;
    int Dir_skull2 = 0;
    int Dir_agobard = 0;

    int direccion_anterior = 0;
    int direccion_anterior_fantasma = 0;
    int direccion_anterior_fantasma2 = 0;
    int direccion_anterior_skull = 0;
    int direccion_anterior_skull2 = 0;
    int direccion_anterior_agobard = 0;

    int index = 0;
    int index2 = 0;
    int index3 = 0;
    int index4 = 0;
    int index5 = 0;
    int index_agobard = 0;

    //bool shot=false,se_puede_disparar=true;

    //VARIABLES_MENU_Y_PANTALLA
    int cont_logo = 0;
    int cont_menu = 0;
    int cont_historia = 0;
    char Direccion_espada;

    bool cont_menus = false;
    //variables finales
    int variable_final = 0;
    bool Agobard_ataque = false, Agobard_ataque_secundario = false;
    int velocidad_final = 6;
    
    /*int Fire1_dir = Fuego1.abajo, Fire1_anterior, Fire1_index = 0;
    int Fire2_dir = Fuego2.abajo, Fire2_anterior, Fire2_index = 0;
    int Fire3_dir = Fuego3.abajo, Fire3_anterior, Fire3_index = 0;
    int Fire4_dir = Fuego4.abajo, Fire4_anterior, Fire4_index = 0;*/
    
    int Fire1_dir = 0;
    int Fire2_dir = 0;
    int Fire3_dir = 0;
    int Fire4_dir = 0;

    int Fire1_anterior = 0;
    int Fire2_anterior = 0;
    int Fire3_anterior = 0;
    int Fire4_anterior = 0;

    int Fire1_index = 0;
    int Fire2_index = 0;
    int Fire3_index = 0;
    int Fire4_index = 0;

    //int Ball_dir = Esfera_de_energia1.abajo, Ball_anterior, Ball_index = 0;

    int Ball_dir = 0;
    int Ball_anterior = 0;
    int Ball_index = 0;

    while (cont_logo < 160)
    {
        al_flip_display();
        al_draw_bitmap(logo, 0, 0, NULL);
        cont_logo++;
    }
    while (cont_menus == false)
    {
        al_flip_display();
        al_draw_bitmap(menu, 0, 0, NULL);
        if (cont_menu == 160) { cont_menus = true; }
        cont_menu++;
    }
    while (cont_historia < 160 * 5)
    {
        al_flip_display();
        if (cont_historia < 800 and cont_historia>640) { al_draw_bitmap(hist5, 0, 0, NULL); }
        if (cont_historia < 640 and cont_historia>480) { al_draw_bitmap(hist4, 0, 0, NULL); }
        if (cont_historia < 480 and cont_historia>320) { al_draw_bitmap(hist3, 0, 0, NULL); }
        if (cont_historia < 320 and cont_historia>160) { al_draw_bitmap(hist2, 0, 0, NULL); }
        if (cont_historia < 160) { al_draw_bitmap(hist1, 0, 0, NULL); }
        cont_historia++;
    }

    al_start_timer(timer);

    while (!done)
    {
        ALLEGRO_EVENT events;
        al_wait_for_event(cola_de_eventos, &events);
        al_get_keyboard_state(&key_state);

        if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }

        else if (events.type == ALLEGRO_EVENT_TIMER)
        {

            active = true;
            direccion_anterior = Dir;
            direccion_anterior_fantasma = Dir_fantasma;
            direccion_anterior_fantasma2 = Dir_fantasma2;
            direccion_anterior_skull = Dir_skull;
            direccion_anterior_skull2 = Dir_skull2;

            Skull.vida = Escenario_actual[Escenario].vida_enemigos[0];
            Skull2.vida = Escenario_actual[Escenario].vida_enemigos[1];
            Fantasma.vida = Escenario_actual[Escenario].vida_enemigos[2];
            Fantasma2.vida = Escenario_actual[Escenario].vida_enemigos[3];
            //ENEMIGOS

            if (contador_enemigos % 2 == 0 and Escenario < 11)
            {

                if (Skull.vida > 0) {
                    if (contador_enemigos > 0 and contador_enemigos < 16)
                    {
                        if (Skull.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Skull.posicion_x - 415 + 31) / 31, (Skull.posicion_y - 147 + 31) / 31, 880, 612) == 'U') { Skull.posicion_y -= Skull.velocidad_de_movimiento; Dir_skull = Skull.arriba; }
                        if (Skull.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Skull.posicion_x - 415 + 31) / 31, (Skull.posicion_y - 147 + 31) / 31, 880, 612) == 'D') { Skull.posicion_y += Skull.velocidad_de_movimiento; Dir_skull = Skull.abajo; }
                        if (Skull.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Skull.posicion_x - 415 + 31) / 31, (Skull.posicion_y - 147 + 31) / 31, 880, 612) == 'L') { Skull.posicion_x -= Skull.velocidad_de_movimiento; Dir_skull = Skull.izquierda; }
                        if (Skull.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Skull.posicion_x - 415 + 31) / 31, (Skull.posicion_y - 147 + 31) / 31, 880, 612) == 'R') { Skull.posicion_x += Skull.velocidad_de_movimiento; Dir_skull = Skull.derecha; }
                        if (Skull.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Skull.posicion_x - 415 + 31) / 31, (Skull.posicion_y - 147 + 31) / 31, 880, 612) == 'F') { Skull.posicion_x += 0; Skull.posicion_y += 0; Shivard.vida -= 1; }
                    }
                    else
                    {
                        if (Skull.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Skull.posicion_x - 415 + 31) / 31, (Skull.posicion_y - 147 + 31) / 31) == 'U') { Skull.posicion_y -= Skull.velocidad_de_movimiento; Dir_skull = Skull.arriba; }
                        if (Skull.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Skull.posicion_x - 415 + 31) / 31, (Skull.posicion_y - 147 + 31) / 31) == 'D') { Skull.posicion_y += Skull.velocidad_de_movimiento; Dir_skull = Skull.abajo; }
                        if (Skull.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Skull.posicion_x - 415 + 31) / 31, (Skull.posicion_y - 147 + 31) / 31) == 'L') { Skull.posicion_x -= Skull.velocidad_de_movimiento; Dir_skull = Skull.izquierda; }
                        if (Skull.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Skull.posicion_x - 415 + 31) / 31, (Skull.posicion_y - 147 + 31) / 31) == 'R') { Skull.posicion_x += Skull.velocidad_de_movimiento; Dir_skull = Skull.derecha; }
                        if (Skull.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Skull.posicion_x - 415 + 31) / 31, (Skull.posicion_y - 147 + 31) / 31) == 'F') { Skull.posicion_x += 0; Skull.posicion_y += 0; Shivard.vida -= 1; }

                    }
                }
                if (Skull2.vida > 0) {
                    if (contador_enemigos > 9 and contador_enemigos < 26)
                    {
                        if (Skull2.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Skull2.posicion_x - 415 + 31) / 31, (Skull2.posicion_y - 147 + 31) / 31, 415, 147) == 'U') { Skull2.posicion_y -= Skull2.velocidad_de_movimiento; Dir_skull2 = Skull2.arriba; }
                        if (Skull2.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Skull2.posicion_x - 415 + 31) / 31, (Skull2.posicion_y - 147 + 31) / 31, 415, 147) == 'D') { Skull2.posicion_y += Skull2.velocidad_de_movimiento; Dir_skull2 = Skull2.abajo; }
                        if (Skull2.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Skull2.posicion_x - 415 + 31) / 31, (Skull2.posicion_y - 147 + 31) / 31, 415, 147) == 'L') { Skull2.posicion_x -= Skull2.velocidad_de_movimiento; Dir_skull2 = Skull2.izquierda; }
                        if (Skull2.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Skull2.posicion_x - 415 + 31) / 31, (Skull2.posicion_y - 147 + 31) / 31, 415, 147) == 'R') { Skull2.posicion_x += Skull2.velocidad_de_movimiento; Dir_skull2 = Skull2.derecha; }
                        if (Skull2.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Skull2.posicion_x - 415 + 31) / 31, (Skull2.posicion_y - 147 + 31) / 31, 415, 147) == 'F') { Skull2.posicion_x += 0; Skull2.posicion_y += 0; Shivard.vida -= 1; }
                    }
                    else
                    {
                        if (Skull2.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Skull2.posicion_x - 415 + 31) / 31, (Skull2.posicion_y - 147 + 31) / 31) == 'U') { Skull2.posicion_y -= Skull2.velocidad_de_movimiento; Dir_skull2 = Skull2.arriba; }
                        if (Skull2.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Skull2.posicion_x - 415 + 31) / 31, (Skull2.posicion_y - 147 + 31) / 31) == 'D') { Skull2.posicion_y += Skull2.velocidad_de_movimiento; Dir_skull2 = Skull2.abajo; }
                        if (Skull2.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Skull2.posicion_x - 415 + 31) / 31, (Skull2.posicion_y - 147 + 31) / 31) == 'L') { Skull2.posicion_x -= Skull2.velocidad_de_movimiento; Dir_skull2 = Skull2.izquierda; }
                        if (Skull2.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Skull2.posicion_x - 415 + 31) / 31, (Skull2.posicion_y - 147 + 31) / 31) == 'R') { Skull2.posicion_x += Skull2.velocidad_de_movimiento; Dir_skull2 = Skull2.derecha; }
                        if (Skull2.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Skull2.posicion_x - 415 + 31) / 31, (Skull2.posicion_y - 147 + 31) / 31) == 'F') { Skull2.posicion_x += 0; Skull2.posicion_y += 0; Shivard.vida -= 1; }
                    }
                }
                if (Fantasma.vida > 0) {
                    if (contador_enemigos > 19 and contador_enemigos < 36)
                    {
                        if (Fantasma.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Fantasma.posicion_x - 415 + 31) / 31, (Fantasma.posicion_y - 147 + 31) / 31, 415, 612) == 'U') { Fantasma.posicion_y -= Fantasma.velocidad_de_movimiento; Dir_fantasma = Fantasma.arriba; }
                        if (Fantasma.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Fantasma.posicion_x - 415 + 31) / 31, (Fantasma.posicion_y - 147 + 31) / 31, 415, 612) == 'D') { Fantasma.posicion_y += Fantasma.velocidad_de_movimiento; Dir_fantasma = Fantasma.abajo; }
                        if (Fantasma.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Fantasma.posicion_x - 415 + 31) / 31, (Fantasma.posicion_y - 147 + 31) / 31, 415, 612) == 'L') { Fantasma.posicion_x -= Fantasma.velocidad_de_movimiento; Dir_fantasma = Fantasma.izquierda; }
                        if (Fantasma.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Fantasma.posicion_x - 415 + 31) / 31, (Fantasma.posicion_y - 147 + 31) / 31, 415, 612) == 'R') { Fantasma.posicion_x += Fantasma.velocidad_de_movimiento; Dir_fantasma = Fantasma.derecha; }
                        if (Fantasma.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Fantasma.posicion_x - 415 + 31) / 31, (Fantasma.posicion_y - 147 + 31) / 31, 415, 612) == 'F') { Fantasma.posicion_x += 0; Fantasma.posicion_y += 0; Shivard.vida -= 1; }
                    }
                    else
                    {
                        if (Fantasma.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Fantasma.posicion_x - 415 + 31) / 31, (Fantasma.posicion_y - 147 + 31) / 31) == 'U') { Fantasma.posicion_y -= Fantasma.velocidad_de_movimiento; Dir_fantasma = Fantasma.arriba; }
                        if (Fantasma.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Fantasma.posicion_x - 415 + 31) / 31, (Fantasma.posicion_y - 147 + 31) / 31) == 'D') { Fantasma.posicion_y += Fantasma.velocidad_de_movimiento; Dir_fantasma = Fantasma.abajo; }
                        if (Fantasma.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Fantasma.posicion_x - 415 + 31) / 31, (Fantasma.posicion_y - 147 + 31) / 31) == 'L') { Fantasma.posicion_x -= Fantasma.velocidad_de_movimiento; Dir_fantasma = Fantasma.izquierda; }
                        if (Fantasma.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Fantasma.posicion_x - 415 + 31) / 31, (Fantasma.posicion_y - 147 + 31) / 31) == 'R') { Fantasma.posicion_x += Fantasma.velocidad_de_movimiento; Dir_fantasma = Fantasma.derecha; }
                        if (Fantasma.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Fantasma.posicion_x - 415 + 31) / 31, (Fantasma.posicion_y - 147 + 31) / 31) == 'F') { Fantasma.posicion_x += 0; Fantasma.posicion_y += 0; Shivard.vida -= 1; }
                    }
                }
                if (Fantasma2.vida > 0) {
                    if (contador_enemigos > 29 and contador_enemigos < 46)
                    {
                        if (Fantasma2.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Fantasma2.posicion_x - 415 + 31) / 31, (Fantasma2.posicion_y - 147 + 31) / 31, 880, 147) == 'U') { Fantasma2.posicion_y -= Fantasma2.velocidad_de_movimiento; Dir_fantasma2 = Fantasma2.arriba; }
                        if (Fantasma2.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Fantasma2.posicion_x - 415 + 31) / 31, (Fantasma2.posicion_y - 147 + 31) / 31, 880, 147) == 'D') { Fantasma2.posicion_y += Fantasma2.velocidad_de_movimiento; Dir_fantasma2 = Fantasma2.abajo; }
                        if (Fantasma2.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Fantasma2.posicion_x - 415 + 31) / 31, (Fantasma2.posicion_y - 147 + 31) / 31, 880, 147) == 'L') { Fantasma2.posicion_x -= Fantasma2.velocidad_de_movimiento; Dir_fantasma2 = Fantasma2.izquierda; }
                        if (Fantasma2.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Fantasma2.posicion_x - 415 + 31) / 31, (Fantasma2.posicion_y - 147 + 31) / 31, 880, 147) == 'R') { Fantasma2.posicion_x += Fantasma2.velocidad_de_movimiento; Dir_fantasma2 = Fantasma2.derecha; }
                        if (Fantasma2.Analizar_movimiento_a_la_esquina(Escenario_actual[Escenario], (Fantasma2.posicion_x - 415 + 31) / 31, (Fantasma2.posicion_y - 147 + 31) / 31, 880, 147) == 'F') { Fantasma2.posicion_x += 0; Fantasma2.posicion_y += 0; Shivard.vida -= 1; }
                    }
                    else
                    {
                        if (Fantasma2.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Fantasma2.posicion_x - 415 + 31) / 31, (Fantasma2.posicion_y - 147 + 31) / 31) == 'U') { Fantasma2.posicion_y -= Fantasma2.velocidad_de_movimiento; Dir_fantasma2 = Fantasma2.arriba; }
                        if (Fantasma2.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Fantasma2.posicion_x - 415 + 31) / 31, (Fantasma2.posicion_y - 147 + 31) / 31) == 'D') { Fantasma2.posicion_y += Fantasma2.velocidad_de_movimiento; Dir_fantasma2 = Fantasma2.abajo; }
                        if (Fantasma2.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Fantasma2.posicion_x - 415 + 31) / 31, (Fantasma2.posicion_y - 147 + 31) / 31) == 'L') { Fantasma2.posicion_x -= Fantasma2.velocidad_de_movimiento; Dir_fantasma2 = Fantasma2.izquierda; }
                        if (Fantasma2.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Fantasma2.posicion_x - 415 + 31) / 31, (Fantasma2.posicion_y - 147 + 31) / 31) == 'R') { Fantasma2.posicion_x += Fantasma2.velocidad_de_movimiento; Dir_fantasma2 = Fantasma2.derecha; }
                        if (Fantasma2.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Fantasma2.posicion_x - 415 + 31) / 31, (Fantasma2.posicion_y - 147 + 31) / 31) == 'F') { Fantasma2.posicion_x += 0; Fantasma2.posicion_y += 0; Shivard.vida -= 1; }
                    }
                }
                if (contador_enemigos == 50) { contador_enemigos = 0; }//880-612,415-612,415-147,880,147
            }
            contador_enemigos++;
            if (Escenario == 11 and contador_enemigos % velocidad_final == 0)
            {
                if (Agobard_ataque == false)
                {
                    if (Agobard.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Agobard.posicion_x - 415 + 31) / 31, (Agobard.posicion_y - 147 + 31) / 31) == 'U') { Agobard.posicion_y -= Agobard.velocidad_de_movimiento; Dir_agobard = Agobard.arriba; }
                    if (Agobard.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Agobard.posicion_x - 415 + 31) / 31, (Agobard.posicion_y - 147 + 31) / 31) == 'D') { Agobard.posicion_y += Agobard.velocidad_de_movimiento; Dir_agobard = Agobard.abajo; }
                    if (Agobard.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Agobard.posicion_x - 415 + 31) / 31, (Agobard.posicion_y - 147 + 31) / 31) == 'L') { Agobard.posicion_x -= Agobard.velocidad_de_movimiento; Dir_agobard = Agobard.izquierda; }
                    if (Agobard.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Agobard.posicion_x - 415 + 31) / 31, (Agobard.posicion_y - 147 + 31) / 31) == 'R') { Agobard.posicion_x += Agobard.velocidad_de_movimiento; Dir_agobard = Agobard.derecha; }
                    if (Agobard.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Agobard.posicion_x - 415 + 31) / 31, (Agobard.posicion_y - 147 + 31) / 31) == 'F') { Agobard.posicion_x += 0; Agobard.posicion_y += 0; Shivard.vida -= 1; }
                }
                if ((contador_enemigos > 5 and contador_enemigos < 31) or (contador_enemigos > 70 and contador_enemigos < 103))
                {
                    Agobard_ataque_secundario = true;
                    velocidad_final = 3;
                    Esfera_de_energia1.posicion_x = Agobard.posicion_x + 31; Esfera_de_energia1.posicion_y = Agobard.posicion_y;
                    Esfera_de_energia2.posicion_x = Agobard.posicion_x - 31; Esfera_de_energia2.posicion_y = Agobard.posicion_y;
                    Esfera_de_energia3.posicion_x = Agobard.posicion_x; Esfera_de_energia3.posicion_y = Agobard.posicion_y + 31;
                    Esfera_de_energia4.posicion_x = Agobard.posicion_x; Esfera_de_energia4.posicion_y = Agobard.posicion_y - 31 - 31;

                }
                if (contador_enemigos == 36)
                {
                    Agobard_ataque_secundario = false;
                    Agobard_ataque = true;
                    velocidad_final = 3;
                    Fuego1.posicion_x = 880; Fuego1.posicion_y = 612;
                    Fuego2.posicion_x = 415; Fuego2.posicion_y = 612;
                    Fuego3.posicion_x = 415; Fuego3.posicion_y = 116 + 31;
                    Fuego4.posicion_x = 880; Fuego4.posicion_y = 116 + 31;
                }
                if (contador_enemigos == 66) { Agobard_ataque = false; velocidad_final = 6; }
                if (Agobard_ataque == true)
                {
                    direccion_anterior_agobard = Agobard.abajo;
                    if (Fuego1.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego1.posicion_x - 415 + 31) / 31, (Fuego1.posicion_y - 147 + 31) / 31) == 'U') { Fuego1.posicion_y -= Fuego1.velocidad_de_movimiento; Fire1_dir = Fuego1.arriba; }
                    if (Fuego1.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego1.posicion_x - 415 + 31) / 31, (Fuego1.posicion_y - 147 + 31) / 31) == 'D') { Fuego1.posicion_y += Fuego1.velocidad_de_movimiento; Fire1_dir = Fuego1.abajo; }
                    if (Fuego1.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego1.posicion_x - 415 + 31) / 31, (Fuego1.posicion_y - 147 + 31) / 31) == 'L') { Fuego1.posicion_x -= Fuego1.velocidad_de_movimiento; Fire1_dir = Fuego1.izquierda; }
                    if (Fuego1.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego1.posicion_x - 415 + 31) / 31, (Fuego1.posicion_y - 147 + 31) / 31) == 'R') { Fuego1.posicion_x += Fuego1.velocidad_de_movimiento; Fire1_dir = Fuego1.derecha; }
                    if (Fuego1.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego1.posicion_x - 415 + 31) / 31, (Fuego1.posicion_y - 147 + 31) / 31) == 'F') { Fuego1.posicion_x += 0; Fuego1.posicion_y += 0; Shivard.vida -= 1; }

                    if (Fuego2.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego2.posicion_x - 415 + 31) / 31, (Fuego2.posicion_y - 147 + 31) / 31) == 'U') { Fuego2.posicion_y -= Fuego2.velocidad_de_movimiento; Fire2_dir = Fuego2.arriba; }
                    if (Fuego2.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego2.posicion_x - 415 + 31) / 31, (Fuego2.posicion_y - 147 + 31) / 31) == 'D') { Fuego2.posicion_y += Fuego2.velocidad_de_movimiento; Fire2_dir = Fuego2.abajo; }
                    if (Fuego2.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego2.posicion_x - 415 + 31) / 31, (Fuego2.posicion_y - 147 + 31) / 31) == 'L') { Fuego2.posicion_x -= Fuego2.velocidad_de_movimiento; Fire2_dir = Fuego2.izquierda; }
                    if (Fuego2.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego2.posicion_x - 415 + 31) / 31, (Fuego2.posicion_y - 147 + 31) / 31) == 'R') { Fuego2.posicion_x += Fuego2.velocidad_de_movimiento; Fire2_dir = Fuego2.derecha; }
                    if (Fuego2.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego2.posicion_x - 415 + 31) / 31, (Fuego2.posicion_y - 147 + 31) / 31) == 'F') { Fuego2.posicion_x += 0; Fuego2.posicion_y += 0; Shivard.vida -= 1; }

                    if (Fuego3.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego3.posicion_x - 415 + 31) / 31, (Fuego3.posicion_y - 147 + 31) / 31) == 'U') { Fuego3.posicion_y -= Fuego3.velocidad_de_movimiento; Fire3_dir = Fuego3.arriba; }
                    if (Fuego3.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego3.posicion_x - 415 + 31) / 31, (Fuego3.posicion_y - 147 + 31) / 31) == 'D') { Fuego3.posicion_y += Fuego3.velocidad_de_movimiento; Fire3_dir = Fuego3.abajo; }
                    if (Fuego3.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego3.posicion_x - 415 + 31) / 31, (Fuego3.posicion_y - 147 + 31) / 31) == 'L') { Fuego3.posicion_x -= Fuego3.velocidad_de_movimiento; Fire3_dir = Fuego3.izquierda; }
                    if (Fuego3.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego3.posicion_x - 415 + 31) / 31, (Fuego3.posicion_y - 147 + 31) / 31) == 'R') { Fuego3.posicion_x += Fuego3.velocidad_de_movimiento; Fire3_dir = Fuego3.derecha; }
                    if (Fuego3.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego3.posicion_x - 415 + 31) / 31, (Fuego3.posicion_y - 147 + 31) / 31) == 'F') { Fuego3.posicion_x += 0; Fuego3.posicion_y += 0; Shivard.vida -= 1; }

                    if (Fuego4.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego4.posicion_x - 415 + 31) / 31, (Fuego4.posicion_y - 147 + 31) / 31) == 'U') { Fuego4.posicion_y -= Fuego4.velocidad_de_movimiento; Fire4_dir = Fuego4.arriba; }
                    if (Fuego4.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego4.posicion_x - 415 + 31) / 31, (Fuego4.posicion_y - 147 + 31) / 31) == 'D') { Fuego4.posicion_y += Fuego4.velocidad_de_movimiento; Fire4_dir = Fuego4.abajo; }
                    if (Fuego4.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego4.posicion_x - 415 + 31) / 31, (Fuego4.posicion_y - 147 + 31) / 31) == 'L') { Fuego4.posicion_x -= Fuego4.velocidad_de_movimiento; Fire4_dir = Fuego4.izquierda; }
                    if (Fuego4.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego4.posicion_x - 415 + 31) / 31, (Fuego4.posicion_y - 147 + 31) / 31) == 'R') { Fuego4.posicion_x += Fuego4.velocidad_de_movimiento; Fire4_dir = Fuego4.derecha; }
                    if (Fuego4.Analizar_persecucion(Shivard, Escenario_actual[Escenario], (Fuego4.posicion_x - 415 + 31) / 31, (Fuego4.posicion_y - 147 + 31) / 31) == 'F') { Fuego4.posicion_x += 0; Fuego4.posicion_y += 0; Shivard.vida -= 1; }
                }
                if (Agobard_ataque_secundario == true)
                {
                    if (Esfera_de_energia1.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia1.posicion_x - 415 + 31) / 31, (Esfera_de_energia1.posicion_y - 147 + 31) / 31) == 'U') { Esfera_de_energia1.posicion_y -= Esfera_de_energia1.velocidad_de_movimiento; Ball_dir = Esfera_de_energia1.arriba; }
                    if (Esfera_de_energia1.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia1.posicion_x - 415 + 31) / 31, (Esfera_de_energia1.posicion_y - 147 + 31) / 31) == 'D') { Esfera_de_energia1.posicion_y += Esfera_de_energia1.velocidad_de_movimiento; Ball_dir = Esfera_de_energia1.abajo; }
                    if (Esfera_de_energia1.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia1.posicion_x - 415 + 31) / 31, (Esfera_de_energia1.posicion_y - 147 + 31) / 31) == 'L') { Esfera_de_energia1.posicion_x -= Esfera_de_energia1.velocidad_de_movimiento; Ball_dir = Esfera_de_energia1.izquierda; }
                    if (Esfera_de_energia1.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia1.posicion_x - 415 + 31) / 31, (Esfera_de_energia1.posicion_y - 147 + 31) / 31) == 'R') { Esfera_de_energia1.posicion_x += Esfera_de_energia1.velocidad_de_movimiento; Ball_dir = Esfera_de_energia1.derecha; }
                    if (Esfera_de_energia1.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia1.posicion_x - 415 + 31) / 31, (Esfera_de_energia1.posicion_y - 147 + 31) / 31) == 'F') { Esfera_de_energia1.posicion_x += 0; Esfera_de_energia1.posicion_y += 0; Shivard.vida -= 1; }

                    if (Esfera_de_energia2.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia2.posicion_x - 415 + 31) / 31, (Esfera_de_energia2.posicion_y - 147 + 31) / 31) == 'U') { Esfera_de_energia2.posicion_y -= Esfera_de_energia2.velocidad_de_movimiento; }
                    if (Esfera_de_energia2.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia2.posicion_x - 415 + 31) / 31, (Esfera_de_energia2.posicion_y - 147 + 31) / 31) == 'D') { Esfera_de_energia2.posicion_y += Esfera_de_energia2.velocidad_de_movimiento; }
                    if (Esfera_de_energia2.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia2.posicion_x - 415 + 31) / 31, (Esfera_de_energia2.posicion_y - 147 + 31) / 31) == 'L') { Esfera_de_energia2.posicion_x -= Esfera_de_energia2.velocidad_de_movimiento; }
                    if (Esfera_de_energia2.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia2.posicion_x - 415 + 31) / 31, (Esfera_de_energia2.posicion_y - 147 + 31) / 31) == 'R') { Esfera_de_energia2.posicion_x += Esfera_de_energia2.velocidad_de_movimiento; }
                    if (Esfera_de_energia2.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia2.posicion_x - 415 + 31) / 31, (Esfera_de_energia2.posicion_y - 147 + 31) / 31) == 'F') { Esfera_de_energia2.posicion_x += 0; Esfera_de_energia2.posicion_y += 0; Shivard.vida -= 1; }

                    if (Esfera_de_energia3.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia3.posicion_x - 415 + 31) / 31, (Esfera_de_energia3.posicion_y - 147 + 31) / 31) == 'U') { Esfera_de_energia3.posicion_y -= Esfera_de_energia3.velocidad_de_movimiento; }
                    if (Esfera_de_energia3.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia3.posicion_x - 415 + 31) / 31, (Esfera_de_energia3.posicion_y - 147 + 31) / 31) == 'D') { Esfera_de_energia3.posicion_y += Esfera_de_energia3.velocidad_de_movimiento; }
                    if (Esfera_de_energia3.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia3.posicion_x - 415 + 31) / 31, (Esfera_de_energia3.posicion_y - 147 + 31) / 31) == 'L') { Esfera_de_energia3.posicion_x -= Esfera_de_energia3.velocidad_de_movimiento; }
                    if (Esfera_de_energia3.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia3.posicion_x - 415 + 31) / 31, (Esfera_de_energia3.posicion_y - 147 + 31) / 31) == 'R') { Esfera_de_energia3.posicion_x += Esfera_de_energia3.velocidad_de_movimiento; }
                    if (Esfera_de_energia3.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia3.posicion_x - 415 + 31) / 31, (Esfera_de_energia3.posicion_y - 147 + 31) / 31) == 'F') { Esfera_de_energia3.posicion_x += 0; Esfera_de_energia3.posicion_y += 0; Shivard.vida -= 1; }

                    if (Esfera_de_energia4.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia3.posicion_x - 415 + 31) / 31, (Esfera_de_energia4.posicion_y - 147 + 31) / 31) == 'U') { Esfera_de_energia4.posicion_y -= Esfera_de_energia4.velocidad_de_movimiento; }
                    if (Esfera_de_energia4.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia3.posicion_x - 415 + 31) / 31, (Esfera_de_energia4.posicion_y - 147 + 31) / 31) == 'D') { Esfera_de_energia4.posicion_y += Esfera_de_energia4.velocidad_de_movimiento; }
                    if (Esfera_de_energia4.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia3.posicion_x - 415 + 31) / 31, (Esfera_de_energia4.posicion_y - 147 + 31) / 31) == 'L') { Esfera_de_energia4.posicion_x -= Esfera_de_energia4.velocidad_de_movimiento; }
                    if (Esfera_de_energia4.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia3.posicion_x - 415 + 31) / 31, (Esfera_de_energia4.posicion_y - 147 + 31) / 31) == 'R') { Esfera_de_energia4.posicion_x += Esfera_de_energia4.velocidad_de_movimiento; }
                    if (Esfera_de_energia4.Analizar_persecucion_fantasma(Shivard, Escenario_actual[Escenario], (Esfera_de_energia3.posicion_x - 415 + 31) / 31, (Esfera_de_energia4.posicion_y - 147 + 31) / 31) == 'F') { Esfera_de_energia4.posicion_x += 0; Esfera_de_energia4.posicion_y += 0; Shivard.vida -= 1; }

                }
                if (contador_enemigos == 105) { contador_enemigos = 0; }
            }

            if (Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31) / 31][(Shivard.posicion_y - 147 + 31) / 31] == 'G')
            {
                Escenario_actual[Escenario].Colocar_o_quitar_objeto(' ', (Shivard.posicion_x - 415 + 31) / 31, (Shivard.posicion_y - 147 + 31) / 31);
                Shivard.Gemas_recogidas += 1;
            }
            if (Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31) / 31][(Shivard.posicion_y - 147 + 31) / 31] == 'I')
            {
                Escenario_actual[Escenario].Colocar_o_quitar_objeto(' ', (Shivard.posicion_x - 415 + 31) / 31, (Shivard.posicion_y - 147 + 31) / 31);
                Shivard.vida = 30;
            }
            if (al_key_down(&key_state, ALLEGRO_KEY_SPACE))
            {
                Shivard.Espadazo(Direccion_espada, ESPADAS);
                if (Direccion_espada = 'U')
                {
                    if (Shivard.posicion_x == Fantasma.posicion_x and Shivard.posicion_y == Fantasma.posicion_y - 31) { Escenario_actual[Escenario].vida_enemigos[2] -= 1; }
                    if (Shivard.posicion_x == Fantasma2.posicion_x and Shivard.posicion_y == Fantasma2.posicion_y - 31) { Escenario_actual[Escenario].vida_enemigos[3] -= 1; }
                    if (Shivard.posicion_x == Skull.posicion_x and (Shivard.posicion_y == Skull.posicion_y - 31 or Shivard.posicion_y == Skull.posicion_y)) { Escenario_actual[Escenario].vida_enemigos[0] -= 1; }
                    if (Shivard.posicion_x == Skull2.posicion_x and (Shivard.posicion_y == Skull2.posicion_y - 31 or Shivard.posicion_y == Skull2.posicion_y)) { Escenario_actual[Escenario].vida_enemigos[1] -= 1; }
                    if (Shivard.posicion_x == Agobard.posicion_x and (Shivard.posicion_y == Agobard.posicion_y - 31 or Shivard.posicion_y == Agobard.posicion_y)) { Agobard.vida -= 1; }
                }
                if (Direccion_espada = 'D')
                {
                    if (Shivard.posicion_x == Fantasma.posicion_x and Shivard.posicion_y == Fantasma.posicion_y + 31) { Escenario_actual[Escenario].vida_enemigos[2] -= 1; }
                    if (Shivard.posicion_x == Fantasma2.posicion_x and Shivard.posicion_y == Fantasma2.posicion_y + 31) { Escenario_actual[Escenario].vida_enemigos[3] -= 1; }
                    if (Shivard.posicion_x == Skull.posicion_x and (Shivard.posicion_y == Skull.posicion_y + 31 or Shivard.posicion_y == Skull.posicion_y)) { Escenario_actual[Escenario].vida_enemigos[0] -= 1; }
                    if (Shivard.posicion_x == Skull2.posicion_x and (Shivard.posicion_y == Skull2.posicion_y + 31 or Shivard.posicion_y == Skull2.posicion_y)) { Escenario_actual[Escenario].vida_enemigos[1] -= 1; }
                    if (Shivard.posicion_x == Agobard.posicion_x and (Shivard.posicion_y == Agobard.posicion_y + 31 or Shivard.posicion_y == Agobard.posicion_y)) { Agobard.vida -= 1; }
                }
                if (Direccion_espada = 'L')
                {
                    if (Shivard.posicion_x == Fantasma.posicion_x - 31 and Shivard.posicion_y == Fantasma.posicion_y) { Escenario_actual[Escenario].vida_enemigos[2] -= 1; }
                    if (Shivard.posicion_x == Fantasma2.posicion_x - 31 and Shivard.posicion_y == Fantasma2.posicion_y) { Escenario_actual[Escenario].vida_enemigos[3] -= 1; }
                    if (Shivard.posicion_x == Skull.posicion_x - 31 and (Shivard.posicion_y == Skull.posicion_y + 31 or Shivard.posicion_y == Skull.posicion_y)) { Escenario_actual[Escenario].vida_enemigos[0] -= 1; }
                    if (Shivard.posicion_x == Skull2.posicion_x - 31 and (Shivard.posicion_y == Skull2.posicion_y + 31 or Shivard.posicion_y == Skull2.posicion_y)) { Escenario_actual[Escenario].vida_enemigos[1] -= 1; }
                    if (Shivard.posicion_x == Agobard.posicion_x - 31 and (Shivard.posicion_y == Agobard.posicion_y + 31 or Shivard.posicion_y == Agobard.posicion_y)) { Agobard.vida -= 1; }
                }
                if (Direccion_espada = 'R')
                {
                    if (Shivard.posicion_x == Fantasma.posicion_x + 31 and Shivard.posicion_y == Fantasma.posicion_y) { Escenario_actual[Escenario].vida_enemigos[2] -= 1; }
                    if (Shivard.posicion_x == Fantasma2.posicion_x + 31 and Shivard.posicion_y == Fantasma2.posicion_y) { Escenario_actual[Escenario].vida_enemigos[3] -= 1; }
                    if (Shivard.posicion_x == Skull.posicion_x + 31 and (Shivard.posicion_y == Skull.posicion_y + 31 or Shivard.posicion_y == Skull.posicion_y)) { Escenario_actual[Escenario].vida_enemigos[0] -= 1; }
                    if (Shivard.posicion_x == Skull2.posicion_x + 31 and (Shivard.posicion_y == Skull2.posicion_y + 31 or Shivard.posicion_y == Skull2.posicion_y)) { Escenario_actual[Escenario].vida_enemigos[1] -= 1; }
                    if (Shivard.posicion_x == Agobard.posicion_x + 31 and (Shivard.posicion_y == Agobard.posicion_y + 31 or Shivard.posicion_y == Agobard.posicion_y)) { Agobard.vida -= 1; }
                }
            }

            if (al_key_down(&key_state, ALLEGRO_KEY_DOWN))
            {
                if (Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31) / 31][(Shivard.posicion_y - 147 + 31 + 31) / 31] == 'Z' or
                    Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31) / 31][(Shivard.posicion_y - 147 + 31 + 31) / 31] == '5')
                {
                    Escenario = Escenario_actual[Escenario].Escenarios_adyacentes[1];
                    Skull.posicion_x = 880; Skull.posicion_y = 612;
                    Skull2.posicion_x = 415; Skull2.posicion_y = 612;
                    Fantasma.posicion_x = 415; Fantasma.posicion_y = 116 + 31;
                    Fantasma2.posicion_x = 880; Fantasma2.posicion_y = 116 + 31;

                    Shivard.posicion_y -= 496;


                }
                if (Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31) / 31][(Shivard.posicion_y - 147 + 31 + 31) / 31] == ' ' or
                    Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31) / 31][(Shivard.posicion_y - 147 + 31 + 31) / 31] == 'G' or
                    Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31) / 31][(Shivard.posicion_y - 147 + 31 + 31) / 31] == 'I')
                {

                    Shivard.posicion_y += Shivard.velocidad_de_movimiento;
                    Direccion_espada = 'D';
                    Dir = Shivard.abajo;
                }
                else { Dir = Shivard.abajo; Direccion_espada = 'D'; }

                //al_play_sample(music,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
            }
            else if (al_key_down(&key_state, ALLEGRO_KEY_UP))
            {
                //Dragon.posicion_y -= Dragon.velocidad_de_movimiento;
                //Dir=Dragon.arriba;
                if (Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31) / 31][(Shivard.posicion_y - 147) / 31] == 'Z' or
                    Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31) / 31][(Shivard.posicion_y - 147) / 31] == '8')
                {
                    if (Escenario == 10 and Shivard.Gemas_recogidas < 127)
                    {
                        Shivard.posicion_x = Shivard.posicion_x;
                    }
                    else
                    {
                        Escenario = Escenario_actual[Escenario].Escenarios_adyacentes[0];
                        Skull.posicion_x = 880; Skull.posicion_y = 612;
                        Skull2.posicion_x = 415; Skull2.posicion_y = 612;
                        Fantasma.posicion_x = 415; Fantasma.posicion_y = 116 + 31;
                        Fantasma2.posicion_x = 880; Fantasma2.posicion_y = 116 + 31;
                        Shivard.posicion_y += 496;
                    }

                }
                if (Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31) / 31][(Shivard.posicion_y - 147) / 31] == ' ' or
                    Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31) / 31][(Shivard.posicion_y - 147) / 31] == 'G' or
                    Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31) / 31][(Shivard.posicion_y - 147) / 31] == 'I')
                {
                    Shivard.posicion_y -= Shivard.velocidad_de_movimiento;
                    Direccion_espada = 'U';
                    Dir = Shivard.arriba;
                }
                else { Dir = Shivard.arriba; Direccion_espada = 'U'; }
            }
            else if (al_key_down(&key_state, ALLEGRO_KEY_RIGHT))
            {
                //Dragon.posicion_x += Dragon.velocidad_de_movimiento;
                //Dir=Dragon.derecha;
                if (Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31 + 31) / 31][(Shivard.posicion_y - 147 + 31) / 31] == 'Z' or
                    Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31 + 31) / 31][(Shivard.posicion_y - 147 + 31) / 31] == '9')
                {
                    Escenario = Escenario_actual[Escenario].Escenarios_adyacentes[3];
                    Skull.posicion_x = 880; Skull.posicion_y = 612;
                    Skull2.posicion_x = 415; Skull2.posicion_y = 612;
                    Fantasma.posicion_x = 415; Fantasma.posicion_y = 116 + 31;
                    Fantasma2.posicion_x = 880; Fantasma2.posicion_y = 116 + 31;


                    Shivard.posicion_x -= 496;
                }
                if (Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31 + 31) / 31][(Shivard.posicion_y - 147 + 31) / 31] == ' ' or
                    Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31 + 31) / 31][(Shivard.posicion_y - 147 + 31) / 31] == 'G' or
                    Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415 + 31 + 31) / 31][(Shivard.posicion_y - 147 + 31) / 31] == 'I')
                {
                    Shivard.posicion_x += Shivard.velocidad_de_movimiento;
                    Direccion_espada = 'R';
                    Dir = Shivard.derecha;

                }
                else { Dir = Shivard.derecha; Direccion_espada = 'R'; }
            }
            else if (al_key_down(&key_state, ALLEGRO_KEY_LEFT))
            {
                //Dragon.posicion_x -= Dragon.velocidad_de_movimiento;
                //Dir=Dragon.izquierda;
                if (Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415) / 31][(Shivard.posicion_y - 147 + 31) / 31] == 'Z' or
                    Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415) / 31][(Shivard.posicion_y - 147 + 31) / 31] == '7')
                {
                    Escenario = Escenario_actual[Escenario].Escenarios_adyacentes[2];
                    Skull.posicion_x = 880; Skull.posicion_y = 612;
                    Skull2.posicion_x = 415; Skull2.posicion_y = 612;
                    Fantasma.posicion_x = 415; Fantasma.posicion_y = 116 + 31;
                    Fantasma2.posicion_x = 880; Fantasma2.posicion_y = 116 + 31;

                    Shivard.posicion_x += 496;

                }
                if (Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415) / 31][(Shivard.posicion_y - 147 + 31) / 31] == ' ' or
                    Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415) / 31][(Shivard.posicion_y - 147 + 31) / 31] == 'G' or
                    Escenario_actual[Escenario].Matriz_letras[(Shivard.posicion_x - 415) / 31][(Shivard.posicion_y - 147 + 31) / 31] == 'I')
                {
                    Shivard.posicion_x -= Shivard.velocidad_de_movimiento;
                    Direccion_espada = 'L';
                    Dir = Shivard.izquierda;

                }
                else { Dir = Shivard.izquierda; Direccion_espada = 'L'; }
            }
            else
                active = false;

            if (active == true)
            {
                index++;
                index2++;
                index3++;
                index4++;
                index5++;
                index_agobard++;
                Fire1_index++;
                Fire2_index++;
                Fire3_index++;
                Fire4_index++;
                Ball_index++;
            }
            else
            {
                index = Dir + 1;
                index2 = Dir_fantasma + 1;
                index3 = Dir_fantasma2 + 1;
                index4 = Dir_skull;
                index5 = Dir_skull2;
                index_agobard = direccion_anterior_agobard + 1;
                Fire1_index = Fire1_anterior + 1;
                Fire2_index = Fire2_anterior + 1;
                Fire3_index = Fire3_anterior + 1;
                Fire4_index = Fire4_anterior + 1;
                Ball_index = Ball_anterior + 1;
            }

            if (index >= Dir + 3)
            {
                index = Dir;
            }
            if (Dir != direccion_anterior)
            {
                index = Dir;
            }
            //Fantasma
            if (index2 >= Dir_fantasma + 3)
            {
                index2 = Dir_fantasma;
            }
            if (Dir_fantasma != direccion_anterior_fantasma)
            {
                index2 = Dir_fantasma;
            }
            //Fantasma2
            if (index3 >= Dir_fantasma2 + 3)
            {
                index3 = Dir_fantasma2;
            }
            if (Dir_fantasma2 != direccion_anterior_fantasma2)
            {
                index3 = Dir_fantasma2;
            }
            //Skull
            if (index4 >= Dir_skull + 3)
            {
                index4 = Dir_skull;
            }
            if (Dir_skull != direccion_anterior_skull)
            {
                index4 = Dir_skull;
            }
            //Skull2
            if (index5 >= Dir_skull2 + 3)
            {
                index5 = Dir_skull2;
            }
            if (Dir_skull2 != direccion_anterior_skull2)
            {
                index5 = Dir_skull2;
            }
            //agobard
            if (index_agobard >= Dir_agobard + 3)
            {
                index_agobard = Dir_agobard;
            }
            if (Dir_agobard != direccion_anterior_agobard)
            {
                index_agobard = Dir_agobard;
            }
            //Fuegos
            if (Fire1_index >= Fire1_dir + 3)
            {
                Fire1_index = Fire1_dir;
            }
            if (Fire1_dir != Fire1_anterior)
            {
                Fire1_index = Fire1_dir;
            }
            if (Fire2_index >= Fire2_dir + 3)
            {
                Fire2_index = Fire2_dir;
            }
            if (Fire2_dir != Fire2_anterior)
            {
                Fire2_index = Fire2_dir;
            }
            if (Fire3_index >= Fire3_dir + 3)
            {
                Fire3_index = Fire3_dir;
            }
            if (Fire3_dir != Fire3_anterior)
            {
                Fire3_index = Fire3_dir;
            }
            if (Fire4_index >= Fire4_dir + 3)
            {
                Fire4_index = Fire4_dir;
            }
            if (Fire4_dir != Fire4_anterior)
            {
                Fire4_index = Fire4_dir;
            }
            if (Ball_index >= Ball_dir + 3)
            {
                Ball_index = Ball_dir;
            }
            if (Ball_dir != Ball_anterior)
            {
                Ball_index = Ball_dir;
            }

            draw = true;
        }

        if (draw == true)
        {

            al_flip_display();
            if (Shivard.vida < 31 and Shivard.vida>20) { al_draw_bitmap(vida3, 0, 0, NULL); }
            if (Shivard.vida < 21 and Shivard.vida>10) { al_draw_bitmap(vida2, 0, 0, NULL); }
            if (Shivard.vida < 9 and Shivard.vida>0) { al_draw_bitmap(vida1, 0, 0, NULL); }
            if (Escenario == 0 or Escenario == 10) { al_draw_bitmap(piso_cesped, 0, 0, NULL); }
            else { al_draw_bitmap(piso_madera, 0, 0, NULL); }

            Escenario_actual[Escenario].Dibujar_Esenario(IMAGENES);
            if (Shivard.Gemas_recogidas < 127 and Escenario == 10) { al_draw_bitmap(puerta_cerrada1, 634, 116, NULL); }
            al_draw_bitmap(shivard[index], Shivard.posicion_x, Shivard.posicion_y - 15, NULL);
            if (Escenario < 11)
            {
                if (Skull.vida > 0) { al_draw_bitmap(skull[index4], Skull.posicion_x, Skull.posicion_y - 31, NULL); }
                if (Fantasma.vida > 0) { al_draw_bitmap(fantasma[index2], Fantasma.posicion_x, Fantasma.posicion_y, NULL); }
                if (Skull2.vida > 0) { al_draw_bitmap(skull[index5], Skull2.posicion_x, Skull2.posicion_y - 31, NULL); }
                if (Fantasma2.vida > 0) { al_draw_bitmap(fantasma[index3], Fantasma2.posicion_x, Fantasma2.posicion_y, NULL); }
            }
            else
            {
                if (Agobard.vida > 0) { al_draw_bitmap(mago[index_agobard], Agobard.posicion_x, Agobard.posicion_y - 31, NULL); }
                if (Agobard_ataque_secundario == true)
                {
                    al_draw_bitmap(energy_ball[Fire1_index], Esfera_de_energia1.posicion_x, Esfera_de_energia1.posicion_y - 31, NULL);
                    al_draw_bitmap(energy_ball[Fire1_index], Esfera_de_energia2.posicion_x, Esfera_de_energia2.posicion_y - 31, NULL);
                    al_draw_bitmap(energy_ball[Fire1_index], Esfera_de_energia3.posicion_x, Esfera_de_energia3.posicion_y - 31, NULL);
                    al_draw_bitmap(energy_ball[Fire1_index], Esfera_de_energia4.posicion_x, Esfera_de_energia4.posicion_y - 31, NULL);
                }
                if (Agobard_ataque == true)
                {
                    al_draw_bitmap(fuegos[Fire1_index], Fuego1.posicion_x, Fuego1.posicion_y - 31, NULL);
                    al_draw_bitmap(fuegos[Fire2_index], Fuego2.posicion_x, Fuego2.posicion_y - 31, NULL);
                    al_draw_bitmap(fuegos[Fire3_index], Fuego3.posicion_x, Fuego3.posicion_y - 31, NULL);
                    al_draw_bitmap(fuegos[Fire4_index], Fuego4.posicion_x, Fuego4.posicion_y - 31, NULL);
                }
            }



            //Mostrar_escenario(Escenario, gemas_recogidas);
            if (Shivard.Gemas_recogidas < 127 and Escenario == 10) { al_draw_bitmap(puerta_cerrada1, 634, 116, NULL); }
            //Shivard.Mostrar_gemas_totales(gemas_recogidas);
            if (Shivard.vida < 1) { al_draw_bitmap(gameover, 0, 0, NULL); }
        }


    }//FIN


    for (int i = 0; i < 12; i++) { al_destroy_bitmap(skull[i]); }
    for (int i = 0; i < 12; i++) { al_destroy_bitmap(shivard[i]); }
    for (int i = 0; i < 12; i++) { al_destroy_bitmap(fantasma[i]); }
    for (int i = 0; i < 12; i++) { al_destroy_bitmap(mago[i]); }
    al_destroy_display(display);
    al_destroy_bitmap(gameover);
    al_destroy_bitmap(vida3);
    al_destroy_bitmap(menu);
    al_destroy_bitmap(hist1);
    al_destroy_bitmap(hist2);
    al_destroy_bitmap(hist3);
    al_destroy_bitmap(hist4);
    al_destroy_bitmap(hist5);
    al_destroy_bitmap(vida1);
    al_destroy_bitmap(vida2);
    al_destroy_bitmap(logo);
    al_destroy_event_queue(cola_de_eventos);
    al_destroy_timer(timer);
    al_destroy_sample(song);

    al_destroy_sample_instance(song_instance);
    al_destroy_bitmap(caja);
    al_destroy_bitmap(mesa_de_4);
    al_destroy_bitmap(mesa_de_4v);
    al_destroy_bitmap(mesa_y_taburete);
    al_destroy_bitmap(piano);
    al_destroy_bitmap(posiones);
    al_destroy_bitmap(librero_de_2);
    al_destroy_bitmap(librero_de_4);
    al_destroy_bitmap(librerov_de_4);
    al_destroy_bitmap(flores);
    al_destroy_bitmap(arbol);
    al_destroy_bitmap(sillon);
    al_destroy_bitmap(obelisco);
    al_destroy_bitmap(corazon);
    al_destroy_bitmap(EspD);
    al_destroy_bitmap(EspU);
    al_destroy_bitmap(EspL);
    al_destroy_bitmap(EspR);


    al_destroy_font(gemas_recogidas);
    return 0;
}
