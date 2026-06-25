#ifndef INVERSION_H
#define INVERSION_H

#include <iostream>
#include <string>
using namespace std;

void elegirInstrumento(float &saldo_pesos, float &fondo_emergencia,
                  int &dolares, float &btc, float &sp500,
                  float precio_dolar, float precio_btc, float precio_sp500);

void actualizarPrecios(int mes, float precio_dolar, float precio_btc, float precio_sp500,
                  float &saldo_pesos, float &fondo_emergencia, float &gastos_fijos,
                  float &gastos_alquiler, float &gastos_servicios,
                  float &gastos_transporte, float &gastos_comida,
                  float &inflacion_acumulada,float INFLACION,
                  float &ahorro_maximo, float &ahorro_minimo,
                  int &mes_mejor, int &mes_peor);

#endif
