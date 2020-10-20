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
        cout << "\tLa velocidad de disparo es = " << vx << "  (distancia/segundos)\n\n";
        angulo = asin(vy/vx);
        angulo = angulo*180 / 3.1415926536;
        cout << "\t el algunlo de tiro es = " << angulo << "  (grados)\n\n";
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

void defensa (float *XO,float *YO,float *XD,float *YD,float *d){
    float X = *XD - *XO, Y = *YD - *YO, velocidad = 0.0, angulo = 0.0;
    float vx = 0.0, vy = 0.0, tiempo=0.0,dist = 0.025*(*d),px = 0.0,py = 0.0;
    cout << "\n\n\tIngrese la velocidad de disparo \n\n --> ";cin >> velocidad; cout << "\n\n";
    cout << "\n\n\tIngrese la angulo de disparo ( entre -90 y 90 )\n\n --> ";cin >> angulo; cout << "\n\n";
    angulo = angulo * 3.1415926536 / 180;
    vy = sin(angulo) * velocidad;
    vx = cos(angulo) * velocidad;

    tiempo = (X/vx)-2.5;
    if (tiempo <= 0) cout << "NO hay tiempo de reaccion";
    else {
        px = *XO + vx * 2.5;
        //cout << "\n" << vy << "\n";
        py = py*2.5;
        //cout << "\n" << vy << "\n";
        py = *YO+( py + (-9.81*pow(2.5,2)/2));
        //cout << "\n" << vx << "\n";
        //cout << "\n" << vy << "\n";

        if (*XD - px > dist ){
            //cout << "\n" << *XD - px << "\n";
            //cout << "\n" << dist << "\n";
            cout << "Fuera de rango de ataque";
        }
        else{

            //cout << "\n" << *XD - px << "\n";
            //cout << "\n" << dist << "\n";

            tiempo = tiempo / 2;
            px = *XO + vx * tiempo;
            py = py*tiempo;
            py = *YO+( py + (-9.81*pow(tiempo,2)/2));

            //cout << "\n" << px << "\n";
            //cout << "\n" << py << "\n";

            vy = 9.81*pow(tiempo,2);
            vy = vy/2;
            vy = vy + (py-(*YD));
            vy = vy / tiempo;

            vx = *XD - px /tiempo;

            //cout << "\n" << px << "\n";
            //cout << "\n" << py << "\n";


            //___________________

            velocidad = sqrt(pow(vx,2)+pow(vy,2));

            cout << "La velocidad de disparo debe ser = " << velocidad << "\n\n";

            angulo = asin(vy / velocidad);
            angulo = angulo * 180 /3.1415926536;

            cout << "El angulo de disparo debe ser = " << angulo << "\n\n";
        }
    }
}
