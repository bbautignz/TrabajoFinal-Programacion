#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include <string>
using namespace std;

void aplicarEventoFijo(int mes, float &saldo_pesos, float &sueldo,float &gastos_alquiler, float &gastos_servicios,
float &gastos_transporte, float &gastos_comida,float &gastos_fijos);

void cobrarSueldo(float &saldo_pesos, float &sueldo, int mes, string nombre_jugador);

void aplicarImprevistos(float &saldo_pesos, float &fondo_emergencia,int &meses_sin_fondo)

void pagarGastos(float &saldo_pesos, float &gastos_fijos,int meses_en_rojo,bool game_over, int mes);

#endif
