#include "Funciones.h"

bool ingreso (float *XO,float *YO,float *XD,float *YD, float *d){

    cout << "\n\nIngrese distancia d HORIZONTAL entre los canones\n\n d --> ";cin >> *d;
    *XD = *d;

    cout << "\n\nIngrese la ubiacion del punto Y Defencivo\n\n XD --> " << *XD << "\n YD --> ";
    cin >> *YD;cout << "\n\n";

    cout << "Ingrese la ubiacion del punto Ofencivo\n\n XO --> ";
    cin >> *XO;cout << "\n YO --> ";cin >> *YO;cout << "\n\n";

    float dist,Y = *YD-*YO, X = *d - *XO; // El valor y es la diferencia de altura entre ambos puntos
    dist = sqrt ( pow (X,2) + pow(Y,2));

    //cout << "\n" << Y << "\n";
    //cout << "\n" << dist << "\n";

    if ( dist > 0.05*(*d) ) return false;
    else return true;
}


void tiempo ( float *XO, float *XD, float *YO, float *YD,int rep){
    float t = 0.0,X = *XD - *XO, Y = *YD - *YO, angulo = 0.0;
    float vx = 0.0,vy = 0.0;
    for (int i = rep;i>0;i-=1){
        cout << "\n\n\tIngrese el tiempo de colicion (en segundos)\n\n --> ";cin >> t;cout << "\n\n";
        vx = X /t;
        //cout << "\n" << X << "\n";
        //cout << "\n" << Y << "\n";
        //cout << "\n" << vx << "\n";
        vy = 9.81*pow(t,2);
        vy = vy/2;
        vy = vy + Y;
        vy = vy / t;
        vx = sqrt(pow(vx,2)+pow(vy,2));
        //cout << "\n" << vy << "\n";
        cout << "\tLa velocidad de disparo es = " << vx << "\n\n";
        angulo = asin(vy/vx);
        angulo = angulo*180 / 3.1415926536;
        cout << "\t el algunlo de tiro es = " << angulo << "\n\n";
    }
}

void ingreso_def (float *XO,float *YO,float *XD,float *YD, float *d){

    cout << "\n\nIngrese distancia d HORIZONTAL entre los canones\n\n d --> ";cin >> *d;
    *XD = *d;

    cout << "\n\nIngrese la ubiacion del punto Y Defencivo\n\n XD --> " << *XD << "\n YD --> ";
    cin >> *YD;cout << "\n\n";

    cout << "Ingrese la ubiacion del punto Ofencivo\n\n XO --> ";
    cin >> *XO;cout << "\n YO --> ";cin >> *YO;cout << "\n\n";

}

