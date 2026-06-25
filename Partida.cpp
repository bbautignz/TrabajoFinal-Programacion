#include "partida.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void aplicarEventoFijo(int mes, float &saldo_pesos, float &sueldo,float &gastos_alquiler, float &gastos_servicios,
float &gastos_transporte, float &gastos_comida,float &gastos_fijos){
// Deposito de garantia (mes 1)
                if (mes == 1)
                {
                    cout << "  ** DEPOSITO DE GARANTIA **" << endl;
                    cout << "  Te mudas a tu primer depa. Pago inicial:" << endl;
                    cout << "  -$180.000 de deposito de garantia." << endl;
                    saldo_pesos -= 180000.0;
                    cout << endl;
                }

                // Aguinaldo (meses 6 y 12)
                if (mes == 6 || mes == 12)
                {
                    float aguinaldo = sueldo * 0.5;
                    saldo_pesos += aguinaldo;
                    cout << "  ** AGUINALDO (SAC) **" << endl;
                    cout << "  Cobras medio sueldo extra: +$" << aguinaldo << endl;
                    cout << "  El SAC existe porque el sueldo no" << endl;
                    cout << "  ajusta continuamente. Usalo bien." << endl;
                    cout << endl;
                }

                // Actualizacion del alquiler (mes 9)
                if (mes == 9)
                {
                    gastos_alquiler *= 1.4;
                    gastos_fijos = gastos_alquiler + gastos_servicios
                                 + gastos_transporte + gastos_comida;
                    cout << "  ** ACTUALIZACION DEL ALQUILER **" << endl;
                    cout << "  Tu casero actualizo el alquiler." << endl;
                    cout << "  Nuevo alquiler: $" << gastos_alquiler << "/mes" << endl;
                    cout << endl;
                }
}


void cobrarSueldo(float &saldo_pesos, float &sueldo, int mes, string nombre_jugador)
{
    saldo_pesos += sueldo;
    cout << "  Sueldo cobrado: $" << sueldo << endl;

    if (mes == 4 || mes == 7 || mes == 10)
    {
        float aumento = sueldo * 0.15;
        sueldo += aumento;
        cout << "  ** AUMENTO PARITARIO **" << endl;
        cout << "  Tu sueldo subio un 15%: $" << sueldo << endl;
    }
}

void aplicarImprevistos(float &saldo_pesos, float &fondo_emergencia,
                        int &meses_sin_fondo)
{
    string imprevisto_nombre[12] = {
        "Se rompio el lavarropas",
        "Visita medica inesperada",
        "Multa de transito",
        "Tecnico de internet",
        "Regalo de cumpleanios obligado",
        "Subio la cuota del gimnasio",
        "Cena o salida social ineludible",
        "Se rompio la pantalla del celular",
        "Subio la expensa del edificio",
        "Mini escapada de ultimo momento",
        "Black Friday - oferta irresistible",
        "Regalos de fin de anio"
 };
    float  imprevisto_costo[12]  = {
        70000, 45000, 30000, 25000, 35000, 15000,
        50000, 80000, 20000, 90000, 60000, 55000 };
    int    cantidad_imprevistos  = 0;
    float  total_imprevistos     = 0.0;

    // Primer imprevisto: 70% de chance
                int dado1 = rand() % 100;
                if (dado1 < 70)
                {
                    int idx = rand() % 12;
                    cout << "  [!] IMPREVISTO: " << imprevisto_nombre[idx] << endl;
                    cout << "      Costo: -$" << imprevisto_costo[idx] << endl;
                    total_imprevistos += imprevisto_costo[idx];
                    cantidad_imprevistos++;
                    // Segundo imprevisto: 15% de chance
                    int dado2 = rand() % 100;
                    if (dado2 < 15)
                    {
                        idx = rand() % 12;
                        cout << "  [!] IMPREVISTO: " << imprevisto_nombre[idx] << endl;
                        cout << "      Costo: -$" << imprevisto_costo[idx] << endl;
                        total_imprevistos += imprevisto_costo[idx];
                        cantidad_imprevistos++;
                        // Tercer imprevisto: 10% de chance
                        int dado3 = rand() % 100;
                        if (dado3 < 10)
                        {
                            idx = rand() % 12;
                            cout << "  [!] IMPREVISTO: " << imprevisto_nombre[idx] << endl;
                            cout << "      Costo: -$" << imprevisto_costo[idx] << endl;
                            total_imprevistos += imprevisto_costo[idx];
                            cantidad_imprevistos++;
                        }
                    }
                }
                if (cantidad_imprevistos == 0)
                {
                    cout << "  [ok] Sin imprevistos este mes. Buen mes!" << endl;
                }
                else
                {
                    cout << "  Total imprevistos: -$" << total_imprevistos << endl;
                    cout << endl;
                    // Cubrir imprevistos: primero con fondo de emergencia
                    if (fondo_emergencia >= total_imprevistos)
                    {
                        fondo_emergencia -= total_imprevistos;
                        cout << "  >> Cubierto con el fondo de emergencia." << endl;
                        cout << "     Fondo restante: $" << fondo_emergencia << endl;
                    }
                    else if (fondo_emergencia > 0)
                    {
                        float resto = total_imprevistos - fondo_emergencia;
                        cout << "  >> Fondo de emergencia insuficiente!" << endl;
                        cout << "     Se usaron: $" << fondo_emergencia << " del fondo." << endl;
                        fondo_emergencia = 0;
                        saldo_pesos -= resto;
                        cout << "     El resto se desconto del saldo: -$" << resto << endl;
                    }
                    else
                    {
                        saldo_pesos -= total_imprevistos;
                        meses_sin_fondo++;
                        cout << "  >> No tenes fondo de emergencia!" << endl;
                        cout << "     Se desconto directo del saldo." << endl;
                    }
                }
                cout << endl;
}

void pagarGastos(float &saldo_pesos, float gastos_fijos,
                 int &meses_en_rojo, bool &game_over, int mes)
{
    saldo_pesos -= gastos_fijos;

    cout << "--------------------------------------------" << endl;
    if (saldo_pesos < 0)
    {
     cout << "  SALDO TRAS GASTOS: -$" << (saldo_pesos * -1)
                         << " EN ROJO!" << endl;
                    meses_en_rojo++;
    }
    else
    {
        cout << "  SALDO TRAS GASTOS: $" << saldo_pesos << endl;
                    meses_en_rojo = 0;
    }
    cout << "--------------------------------------------" << endl;

    if (meses_en_rojo >= 3)
    {
        system("cls");
                    cout << "============================================" << endl;
                    cout << "              GAME OVER                     " << endl;
                    cout << "============================================" << endl;
                    cout << endl;
                    cout << "  Tres meses seguidos en rojo." << endl;
                    cout << "  Te fuiste a vivir a lo de tus viejos." << endl;
                    cout << endl;
                    cout << "  Sobreviviste " << mes << " meses." << endl;
                    game_over = true;

                    cout << endl;
                    cout << "  Presiona ENTER para continuar...";
                    cin.ignore();
                    cin.get();
                }
}
