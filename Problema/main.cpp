#include "Funciones.h"

int main()
{
    int ava = 0, pro = 0;
    float XD=0.0, YD = 0.0, XO = 0.0 , YO = 0.0,alfa = 0.0, VelD = 0.0;

    cout << "\n\tSe puede tomar dos bando para el enfrentameinto entre dos canones uno con intencion ofenciva\n";
    cout << "\tY el otro con intencion defenciva, el canon con intencion ofenciva (HO), tiene un radio de dispario de\n";
    cout << "\t0.05d y el de intencion defensiva (HD) tiene un radio de respuesta de 0.025d, siendo d la medida de longitud\n";
    cout << "\tescogida por el usuario, igual en todo el programa, los tiempos se entregan en segundos, y la ubiacion\n";
    cout << "\tse define en base a un punto (0,0) definido previamente, para calculos correspondiente.\n\n";
    cout << "\n\tIngrese el vando a ejercer:\n\n\t1) Defensivo\n\t2) Ofencivo\n\n --> ";
    cin >> ava;
    if (ava == 1) {
        while (true){

            cout << "\n\tIngresar la ubicacion de la defensa XD y YD\n\n XD --> ";
            cin >> XD; cout << "\n XY --> ";cin >> YD;cout << "\n\n";

            while (true){
                ava = 0;
                cout << "\tIngrese el modo de ataque(Todos los modos se hacen en conjuntos de 3 respuestas por 3 metodos distintos)\n\n\t1) Completamente defencivo\n\n\t2) Defensivo y posterior ataque\n\n --> ";
                cin >> ava;cout << "\n\n";

                while (true){


                    if (ava == 1){
                        ingreso(&XO,&YO,&alfa,&VelD);

                    }
                    else if (ava == 2){
                        ingreso(&XO,&YO,&alfa,&VelD);

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
    else if  (ava == 2) cout << "Como estas";
    else cout << "\n Valor fuera del rango";




    return 0;
}
