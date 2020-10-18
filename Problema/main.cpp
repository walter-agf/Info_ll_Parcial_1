#include "Funciones.h"

int main()
{
    int ava = 0, pro = 0;
    float XD=0.0, YD = 0.0, XO = 0.0 , YO = 0.0,alfa = 0.0, VelD = 0.0,diferencia=0.0,dif_x =0.0; //variables de calculo de posicionamiento
    bool dist; // valor de calculo de distancia

    cout << "\n\tSe puede tomar dos bando para el enfrentameinto entre dos canones uno con intencion ofenciva\n";
    cout << "\tY el otro con intencion defenciva, el canon con intencion ofenciva (HO), tiene un radio de dispario de\n";
    cout << "\t0.05d y el de intencion defensiva (HD) tiene un radio de respuesta de 0.025d, siendo d la medida de longitud\n";
    cout << "\tescogida por el usuario, igual en todo el programa, los tiempos se entregan en segundos, el angulo en grados, y la ubiacion\n";
    cout << "\tse define en base a un punto (0,0) definido previamente, para calculos correspondiente.\n\n";
    cout << "\n\tIngrese el vando a ejercer:\n\n\t1) Defensivo\n\t2) Ofencivo\n\n --> ";
    cin >> ava;
    if (ava == 1) {
        while (true){

            cout << "\n\tIngresar la ubicacion de la defensa XD y YD\n\n XD --> ";
            cin >> XD; cout << "\n YD --> ";cin >> YD;cout << "\n\n";

            while (true){
                ava = 0;
                cout << "\tIngrese el modo de ataque(Todos los modos se hacen en conjuntos de 3 respuestas por 3 metodos distintos)\n\n\t1) Completamente defencivo\n\n\t2) Defensivo y posterior ataque\n\n --> ";
                cin >> ava;cout << "\n\n";

                while (true){


                    if (ava == 1){
                        ingreso(&XO,&YO,&alfa,&VelD);
                        posicion2_5 (&XO,&YO,&alfa, &VelD);
                        diferencia = YD - YO;
                        if (diferencia < 0) diferencia *= -1;
                        dist = posibilidad(diferencia,alfa,0.025);
                        if (dist == false ) cout << "Lanzamiento fuera de rango";
                        else {



                        }
                    }
                    else if (ava == 2){

                        ingreso(&XO,&YO,&alfa,&VelD);
                        float XO2 = XO , YO2 = YO;
                        posicion2_5 (&XO,&YO,&alfa, &VelD);
                        cout << "\n\n" << XO << "\n\n" << YO << "\n\n";
                        dif_x = XO - XD;
                        diferencia = YD - YO;
                        if (diferencia < 0) diferencia *= -1;
                        cout << "\n\n" << diferencia << "\n\n" << dif_x << "\n\n";
                        dist = posibilidad(diferencia,dif_x,0.025);
                        if (dist == false ) cout << "Lanzamiento fuera de rango";
                        else {




                        }
                        XO = XO2;
                        YO = YO2;
                        //cout << "\n\n" << XO << "\n\n" << YO << "\n\n";
                        dif_x = XO - XD;
                        diferencia = YD - YO;
                        if (diferencia < 0) diferencia *= -1;
                        //cout << "\n\n" << dif_x << "\n\n" << diferencia << "\n\n";
                        //cout << diferencia << "\n\n";
                        dist = posibilidad(diferencia,dif_x,0.025);
                        //cout << dist << "\n\n";
                        if (dist == false ) cout << "Lanzamiento fuera de rango";
                        else {
                            ataque_1 (XD, YD, XO, YO);
                            ataque_2 (XD, YD, XO, YO);
                        }
                    }
                    else cout << "\n Valor fuera del rango\n\n";

                    pro = 0;
                    cout << "\n\tQue desea hacer\n\n\t1) Ingresar otro valor de ataque\n\n\t2) Cambiar modo\n\n\t3) Cambiar posicion de defensa\n\n\t4) SALIR\n\n\t --> ";
                    cin >> pro;cout<<"\n\n";
                    if (pro == 2 || pro == 3 || pro == 4) break;
                    else if (pro != 1) cout << "\n Valor fuera del rango";

                }
                if (pro == 3 || pro == 4) break;
            }
            if (pro == 4) break;
        }
    }
    else if  (ava == 2) {
        while (true){

            cout << "\n\tIngresar la ubicacion de lanzamiento de ataque XO y YO\n\n XO --> ";
            cin >> XO; cout << "\n YO --> ";cin >> YO;cout << "\n\n";

            while (true){

                cout << "Ingrese la ubiacion del punto en que se realizara el ataque XD y YD\n\n XD --> ";
                cin >> XD; cout << "\n YD --> ";cin >> YD;cout << "\n\n";
                dif_x = XD - XO;
                diferencia = YD - YO;
                if (diferencia < 0) diferencia *= -1;
                cout << diferencia;
                dist = posibilidad(diferencia,alfa,0.05);
                cout << "\n\n" << dist;
                if (dist == false ) cout << "Lanzamiento fuera de rango";
                else {
                    ataque_1 (XO, YO, XD, YD);

                    ataque_2 (XO, YO, XD, YD);
                }
                pro = 0;
                cout << "\n\tQue desea hacer\n\n\t1) Ingresar otro valor de ataque\n\n\t2) Cambiar posicion \n\n\t3) SALIR\n\n\t --> ";
                cin >> pro;cout<<"\n\n";
                if (pro == 2 || pro == 3) break;
                else if (pro != 1) cout << "\n Valor fuera del rango";
            }
            if (pro == 3) break;
        }
    }
    else cout << "\n Valor fuera del rango";




    return 0;
}
