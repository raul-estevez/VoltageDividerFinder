#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float vin = 12;
float vout = 6;
unsigned int datos[] = {1000,2000,2200,3300,4700,5100,6800,10000};
unsigned int datos_size = sizeof(datos) / sizeof(datos[0]);

unsigned int resultado [3][4];
unsigned short resultado_pos= 0;

float vout_function(float vin, float R1, float R2){
    return vin * (R2/(R1+R2));
}


int main(void){

    unsigned int count = 0;
    for(unsigned int i = 0; i < datos_size; i++){
        // Fijo un R1
        for(unsigned int j = i; j < datos_size; j++){
            // Itero por todos los R2
            float vout_parcial = vout_function(vin, datos[i], datos[j]);
            //count++;
            float current_error = fabs(vout-vout_parcial);
            //printf("%f\n", current_error);

            // First iteration
            if(i == 0 && j == 0){
                //printf("%f\n",(float)datos[i]);
                resultado[0][0] = (float)datos[i];
                resultado[1][0] = (float)datos[j];
                resultado[2][0] = current_error;
            } else {
                unsigned int resultado_max = resultado_pos;
                while(current_error <= resultado[2][resultado_pos]){
                    if(resultado_pos < 3){
                        // Si no estamos en el ultima posicion
                        resultado[0][resultado_pos+1] = resultado[0][resultado_pos];
                        resultado[1][resultado_pos+1] = resultado[1][resultado_pos];
                        resultado[2][resultado_pos+1] = resultado[2][resultado_pos];

                        resultado[0][resultado_pos] = (float)datos[i];
                        resultado[1][resultado_pos] = (float)datos[j];
                        resultado[2][resultado_pos] = current_error;

                        if(resultado_max == resultado_pos){
                            resultado_max++; 
                        }
                        if(resultado_pos != 0){
                            resultado_pos--;
                        } else {
                            break;
                        }
                    } else {
                        // Si estamos en la ultima posicion
                        resultado[0][resultado_pos] = (float)datos[i];
                        resultado[1][resultado_pos] = (float)datos[j];
                        resultado[2][resultado_pos] = current_error;
                       
                        resultado_pos--;
                    }
                }
                resultado_pos = resultado_max;
            }
        }
    }

    for(unsigned short i = 0; i < 4; i++){
        for(unsigned short j = 0; j < 3; j++){
            printf("%f\t", (float)resultado[j][i]);
        }
        printf("\n");
    }
    return 1;
}
