#include "Funciones.h"

bool ingreso (float *XO,float *YO,float *XD,float *YD, float *d){

    cout << "\n\nIngrese distancia d HORIZONTAL entre los canones\n\n d --> ";cin >> *d;
    *XD = *d;

    cout << "\n\nIngrese la ubiacion del punto Y Defencivo\n\n XD --> " << *XD << "\n YD --> ";
    cin >> *YD;cout << "\n\n";

    cout << "Ingrese la ubiacion del punto Y Ofencivo\n\n XO --> 0";
    *XO = 0;
    cout << "\n YO --> ";cin >> *YO;cout << "\n\n";

    float dist,Y = *YD-*YO; // El valor y es la diferencia de altura entre ambos puntos
    dist = sqrt ( pow (*d,2) + pow(Y,2));

    cout << "\n" << Y << "\n";
    cout << "\n" << dist << "\n";

    if ( dist > 0.05*(*d) ) return false;
    else return true;
}

