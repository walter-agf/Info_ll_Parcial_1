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

    while (true){
        cout << "Ingrese la velocidad de disparon (VelD) en d sobre segundos \n\n VelD -->";
        cin >> *VelD;cout << "\n\n";
        if (*VelD <= 0) cout << "Valor sin sintido Fisico";
        else break;
    }

}

bool posibilidad (float Y,float alfa, float d){
    float distancia;
    distancia = Y/sin(alfa);
    if (distancia <= d) return true;
    else return false;
}

void posicion2_5 (float *X,float *Y,float *alfa, float *VelD){
    float xve, yve,altura;
    *alfa = (*alfa * 3.14159265359)/180;
    yve = sin(*alfa)*(*VelD);
    xve = cos(*alfa)*(*VelD);
    *X += xve*2.5;
    altura = (yve*2.5)+(-9.81 * pow(2.5,2)/2);
    if (altura > *Y) *Y += (altura - *Y);
    else *Y = altura;
    *VelD = sqrt(pow(yve,2)+pow(xve,2));
    *alfa = asin(yve/(*VelD));
    *alfa = (*alfa *180) /3.14159265359;
}
