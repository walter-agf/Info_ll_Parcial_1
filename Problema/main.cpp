#include "Funciones.h"

int main()
{
    int ava = 0;
    float XD=0.0, YD = 0.0, XO = 0.0 , YO = 0.0,d=0.0; //variables de calculo de posicionamiento
    bool dist; // valor de calculo de distancia

    cout << "\n\tSe puede tomar dos bando para el enfrentameinto entre dos canones uno con intencion ofenciva\n";
    cout << "\tY el otro con intencion defenciva, el canon con intencion ofenciva (HO), tiene un radio de dispario de\n";
    cout << "\t0.05*d y el de intencion defensiva (HD) tiene un radio de respuesta de 0.025*d, siendo d la medida de longitud\n";
    cout << "\n\tVariables primarias que define el usuario:\n";
    cout << "\n\t . Distancia (d), Que es la distancia HORIZONTAL entre el canon defensivo y el origen\n";
    cout << "\n\t . Posicion del Ofencivo (XO,YO), pocicion del Defencivo (YD)";
    cout << "\n\t (NOTA: XO se toma como la distacia HORIONTAL al origen y XD es igual al valor de la distancia";
    cout << "\n\t HORIZONTAL entre el Defencivo y el origen que es igual a la distanca d )\n";
    cout << "\n\n\t(NOTA: Se toma en cuenta un diagrama carteciano con origen en (0,0) del lado del canon ofencivo";
    cout << "\n\tY con medidas tomadas a partir de la distancia definida por el usuario ya sean en cm,m,km..\n";
    cout << "\tNo se podra realizar un disparon si no se esta dentro del rango de ataque del canon)\n\n";
    cout << "\n\tIngrese el vando a ejercer:\n\n\t1) Defensivo\n\t2) Ofencivo\n\n --> ";
    cin >> ava;
    if (ava == 1) {
        cout << "Hola";
    }
    else if  (ava == 2) {
        dist = ingreso (&XO, &YO, &XD, &YD, &d);
        if (dist == false) cout << "\n\nEl Defensor esta fuera de rango de ataque\n\n";
        else{



        }
    }
    else cout << "\n Valor fuera del rango";
    return 0;
}
