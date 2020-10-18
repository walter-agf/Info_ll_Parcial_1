#include "Funciones.h"

void ingreso (float *XO,float *YO,float *alfa,float *VelD){

    cout << "Ingrese la ubiacion del punto en que se realizo el ataque XO y YO\n\n XO --> ";
    cin >> *XO; cout << "\n YO --> ";cin >> *YO;cout << "\n\n";

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

bool posibilidad (float Y,float X, float d){
    float distancia;
    distancia = sqrt(pow(Y,2)+pow(X,2));
    cout << distancia << "\n\n";
    if (distancia <= d) return true;
    else return false;
}

void posicion2_5 (float *X,float *Y,float *alfa, float *VelD){
    float xve, yve,altura;
    *alfa = (*alfa * 3.14159265359)/180;
    yve = sin(*alfa)*(*VelD);
    xve = cos(*alfa)*(*VelD);
    *X += xve*2.5;
    altura = (yve*2.5)+(-0.00981 * pow(2.5,2)/2);
    if (altura > *Y) *Y += (altura - *Y);
    else *Y = altura;
    *VelD = sqrt(pow(yve,2)+pow(xve,2));
    *alfa = asin(yve/(*VelD));
    *alfa = (*alfa *180) /3.14159265359;
}

void ataque_1 (float XD, float YD, float XO, float YO){
    float x = XD - XO, y = YO - YD, time = 0.0,velocidad_x = 0.0,velocidad_y = 0.0;
    cout << "\n\n\n\n\t\t\t\tEl usuario ingresa el tiempo deseado( En segundos )\n\n\t\t\t\tTiempo --> ";cin >> time;cout << "\n\n";
    velocidad_x = x / time;
    velocidad_y = (y-(-9.81*pow(time,2)/2))/time;
    velocidad_x = sqrt(pow(velocidad_x,2)+pow(velocidad_y,2));
    velocidad_y = asin(velocidad_y/velocidad_x);
    velocidad_y = (velocidad_y*180) / 3.14159265359;

    cout << "\t\t\t\tLa velocidad de lanzamiento es = "<< velocidad_x << " (distacia sobre segundo)\n";
    cout << "\t\t\t\tY el angulo de tiro es = " << velocidad_y << " Grados\n\n\n";
}

void ataque_2 (float XD, float YD, float XO, float YO){
    float x = XD - XO, y = YO - YD, time = 0.0,angulo = 0.0,velocidad_x= 0.0,velocidad_y=0.0;
    cout << "\n\n\n\n\t\t\t\tEl usuario ingresa la velocidad horizontal de disparo( En distancia sobre segundo )\n\n\t\t\t\tVelocidad --> ";cin >> velocidad_x;cout << "\n\n";
    time = x / velocidad_x;
    velocidad_y = (y-(-9.81*pow(time,2)/2))/time;
    angulo = atan(velocidad_y/velocidad_x);
    angulo = (angulo * 180) / 3.14159265359;
    cout << "\t\t\t\tEl tiempo de choque es = "<< time << " (segundos)\n";
    cout << "\t\t\t\tY el angulo de tiro es = " << angulo << " Grados\n\n\n";
}


