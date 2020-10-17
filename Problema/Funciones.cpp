#include "Funciones.h"

void ingreso (float *X,float *Y,float *alfa,float *VelD){

    cout << "Ingrese la ubiacion del punto en que se realizo el ataque X y Y\n\n X --> ";
    cin >> *X; cout << "\n Y --> ";cin >> *Y;cout << "\n\n";

    while (true){
        cout << "Ingrese el angulo de tiro alfa\n\n alfa --> ";
        cin >> *alfa;cout << "\n\n";
        if (*alfa < -90 || *alfa > 90) cout << "Valor inconcluso\n\n";
        else break;
    }

    cout << "Ingrese la velocidad de disparon (VelD) en d sobre segundos \n\n VelD -->";
    cin >> *VelD;cout << "\n\n";

}
