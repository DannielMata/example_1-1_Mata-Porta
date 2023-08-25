#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    DigitalIn gasDetector(D2);

    DigitalOut alarmLed(LED1);

    /*
    al principio, no pudimos ver el led encendido porque
    tuvimos problemas con la conexión (COM a GND), 
    gracias a esta parte nos dimos cuenta de que COM
    debía estar a 3.3V 
    */
    gasDetector.mode(PullDown);

    alarmLed = OFF;
    /*
    //agregamos línea de printf, para probarlo abrimos CoolTerm
    le dimos connect y luego pudimos observar que al resetear
    muestra de nuevo esta linea, ya que no se encuentra detro
    del loop "while true"
    */
    printf("%s\n", "Hello World"); 
    
    /*
    en esta parte probamos los break points del debug
    y veíamos en qué parte del código encendía o no
    de acuerdo al estado del switch
    */
    while (true) {
        if ( gasDetector == ON ) {
            alarmLed = ON;
        }
        
        if ( gasDetector == OFF ) {
            alarmLed = OFF;
        }
    }
}

/*
pudimos observar que con el keil cloud no hizo falta
cargar el código "arrastrando" el archivo bin al
dispositivo conectado ya que este cargaba el código
presionando run project
*/