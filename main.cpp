#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "interfaz.h"
#include "partida.h"
#include "inversion.h"
#include "logros.h"

using namespace std;

int main()
{
    srand(time(0));

    // Variables de sesion
    int    sesion_partidas         = 0;
    float  sesion_mejor_patrimonio = 0;
    string sesion_mejor_jugador    = "";

    int opcion_menu = 0;

    while (opcion_menu != 4)
    {
        mostrarMenu();
        cin >> opcion_menu;

        switch (opcion_menu)
        {
        case 1:
        {
            // Variables de partida
            string nombre_jugador  = "";
            float  sueldo          = 500000.0;
            float  saldo_pesos     = 150000.0;
            float  fondo_emergencia= 0.0;
            int    dolares         = 0;
            float  btc             = 0.0;
            float  sp500           = 0.0;
            float  precio_dolar    = 1100.0;
            float  precio_btc      = 65000.0;
            float  precio_sp500    = 500.0;
            const float INFLACION  = 0.07;
            float  gastos_alquiler = 180000.0;
            float  gastos_servicios= 45000.0;
            float  gastos_transporte=30000.0;
            float  gastos_comida   = 80000.0;
            float  gastos_fijos    = gastos_alquiler + gastos_servicios
                                   + gastos_transporte + gastos_comida;
            int   meses_en_rojo    = 0;
            int   meses_sin_fondo  = 0;
            float ahorro_maximo    = -9999999.0;
            float ahorro_minimo    =  9999999.0;
            int   mes_mejor        = 0;
            int   mes_peor         = 0;
            float inflacion_acumulada = 1.0;
            bool  game_over        = false;

            // Pedir nombre y cantidad de meses
            cout << "  Ingresá tu nombre: ";
            cin  >> nombre_jugador;

            int eleccion;
            cout << "  ¿Cuántos meses querés jugar? (1 a 12): ";
            cin  >> eleccion;
            while (eleccion < 1 || eleccion > 12)
            {
                cout << "  Número inválido. Ingresá entre 1 y 12: ";
                cin  >> eleccion;
            }

            mostrarBienvenida(nombre_jugador);

            // Ciclo principal
            for (int mes = 1; mes <= eleccion && !game_over; mes++)
            {
                mostrarPanel(mes, eleccion, nombre_jugador, saldo_pesos,
                             fondo_emergencia, dolares, btc, sp500,
                             sueldo, gastos_fijos);

                aplicarEventoFijo(mes, saldo_pesos, sueldo,
                                  gastos_alquiler, gastos_servicios,
                                  gastos_transporte, gastos_comida,
                                  gastos_fijos);

                cobrarSueldo(saldo_pesos, sueldo, mes, nombre_jugador);

                aplicarImprevistos(saldo_pesos, fondo_emergencia,
                                   meses_sin_fondo);

                pagarGastos(saldo_pesos, gastos_fijos, meses_en_rojo,
                            game_over, mes);

                if (!game_over && saldo_pesos > 0)
                {
                    elegirInstrumento(saldo_pesos, fondo_emergencia,
                                      dolares, btc, sp500,
                                      precio_dolar, precio_btc, precio_sp500);
                }

                actualizarPrecios(mes, precio_dolar, precio_btc, precio_sp500,
                                  saldo_pesos, fondo_emergencia, gastos_fijos,
                                  gastos_alquiler, gastos_servicios,
                                  gastos_transporte, gastos_comida,
                                  inflacion_acumulada, INFLACION,
                                  ahorro_maximo, ahorro_minimo,
                                  mes_mejor, mes_peor);

                verificarLogros(fondo_emergencia, gastos_fijos, btc,
                                precio_btc, precio_dolar, sp500,
                                precio_sp500, sueldo, meses_en_rojo);

                mostrarTip(mes);
            }

            mostrarResumen(nombre_jugador, saldo_pesos, fondo_emergencia,
                           dolares, btc, sp500, precio_dolar, precio_btc,
                           precio_sp500, inflacion_acumulada, ahorro_maximo,
                           ahorro_minimo, mes_mejor, mes_peor,
                           meses_sin_fondo, game_over,
                           sesion_partidas, sesion_mejor_patrimonio,
                           sesion_mejor_jugador);
            break;
        }

        case 2:
            mostrarHighscore(sesion_partidas, sesion_mejor_jugador,
                             sesion_mejor_patrimonio);
            break;

        case 3:
            mostrarGlosario();
            break;

        case 4:
            mostrarSalida();
            break;

        default:
            break;
        }
    }

    return 0;
}
