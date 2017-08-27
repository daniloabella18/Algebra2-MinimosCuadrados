/// Danilo Guillermo Abellá de Oliveira
/// LCC Álgebra 2
/// Prof : Mónica
/// Ayudante : Luis Hernan Herrera
/// S.O : Windows 8.1
/// Compilador : Code::Blocks ( con librerías winbgim.h y graphics.h instaladas )





#include<iostream>
//#include<winbgim.h>
#include<graphics.h>
#include<cstdlib>
#define MAX 30

using namespace std;

/// Definiciones

void muestra_de_puntos( short puntos , int p[MAX] );
int determinante( int n , int A_t_A[MAX][MAX] );
short grado_1( int puntos , int p[MAX] , short graf );
short grado_2( int puntos , int p[MAX] , short graf);
short grado_3( int puntos , int p[MAX] , short graf);
void systema();


/// Funcion Principal ///----------------------------------------------------------------------------------------------------///

int main()
{
    /// Declaraciones

    short h=1 , k , i , num , ing = 2 , puntos , u , pol , graf=0 ;
    int x , y ;
    int p[MAX];

    cout<<"\n\t\tBienvenido/a Least Squares LCC V 1.0 !\n"<<endl;
    cout<<"\tIntroduzca el numero de la tarea correspondiente: "<<endl;
    cout<<"\t(1)Ingreso de puntos.  \n\t(2)Evaluar en polinomios.    \n\t(3)Trabajar con sistemas ( x,y,z ). \n\t(4)Cerrar Grafica.  \n\t(Cualquier Tecla)Salir."<<endl;

    while( h!= 0 )
    {
        cout<<"\n\tTarea #:";
        cin>> k;

        switch( k )
        {

/// Ingreso de Puntos ///----------------------------------------------------------------------------------------------------///

            case 1 :
                if ( ing ==1 )
                {
                    cout<<"\n\tUsted ya tiene puntos ingresados. \n\tDesea reemplazarlos por unos nuevos?"<<endl;
                    cout<<"\t(1)Si.  \n\t(2)No."<<endl;
                    cout<<"\tOpcion #:";
                    cin>> u;
                    i=0;
                    while ( i==0 )
                    {   if ( u==1 ){ ing=2; i=1; }
                        if ( u==2 ){ ing=1; i=1; }
                        if ( (u!=1) & (u!=2) ){ cout<<"\n\tIngrese un dato valido:"; cin>>u; }

                    }
                }
                if ( ing == 2)
                {   ing = 1;
                    cout<<"\n\tIngreso de puntos:"<<endl;
                    cout<<"\n\tIntroduzca la cantidad de puntos a agregar (MIN 2 - MAX 16):";
                    cin>> puntos;
                    i=0;
                    while ( i== 0)
                    {
                        if ( puntos>16 || puntos<2){ cout<<"\n\tIntroduzca un numero valido:"; cin>>puntos; }
                        else { i=1; }
                    }
                    cout<<"\n\tSolo se admiten coordenadas desde -25 hasta 25."<<endl;
                    cout<<"";
                    num = 1;
                    for ( i=0; (i/2)<puntos ; i=i+2 )
                    {   cout<<"\tPunto #" << ( num++ ) << ":" <<endl;
                        cout<<"\tIngrese valor de X:";
                        cin>> x ;
                        if ( x>=-25 && x<=25 ) {  p[i] = x;   }
                        else
                        {   u=0;
                            while ( u==0 )
                            {
                                cout<<"\tIngrese un valor para X dentro del rango admitido:";   cin>> x ;
                                if ( x>=-25 && x<=25 ){  p[i] = x; u=1;  }
                            }
                        }
                        cout<<"\tIngrese valor de Y:";
                        cin>> y ;
                        if ( y>=-25 && y<=25 ) {  p[ i+1 ] = y;   }
                        else
                        {   u=0;
                            while ( u==0 )
                            {
                                cout<<"\tIngrese un valor para Y dentro del rango admitido:";   cin>> y ;
                                if ( x>=-25 && x<=25 ){  p[ i+1 ] = y; u=1;  }
                            }
                        }
                    }
                    cout<<"\n\tLos puntos ingresados son:"<<endl;

                    muestra_de_puntos( puntos , p );

                }

                break;

/// Trabajo con Polinomios ///---------------------------------------------------------------------------------------------///

            case 2 :

                if ( ing == 1 )
                {
                    cout<<"\n\tPolinomios:"<<endl;
                    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),1);
                    cout<<"\t(1) y = ax + b"<<endl;
                    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),2);
                    cout<<"\t(2) y = a(x)^2 + bx + c "<<endl;
                    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),4);
                    cout<<"\t(3) y = a(x)^3 + b(x)^2 + cx + d"<<endl;
                    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
                    cout<<"\tEliga un grado de polinomio:";
                    cin>>pol;
                    i=0;
                    while( i==0 )
                    {
                        if ( pol == 1)
                        {
                            i=1;
                            if( num < 3) { cout<<"\n\tPara polinomios de grado 1 ingrese almenos 2 puntos!"<<endl;      }
                            else    {   graf=grado_1( puntos , p , graf );      }
                        }
                        if ( pol == 2)
                        {
                            i=1;
                            if( num < 4) { cout<<"\n\tPara polinomios de grado 2 ingrese almenos 3 puntos!"<<endl;      }
                            else    {   graf=grado_2( puntos , p , graf );      }
                        }
                        if ( pol == 3)
                        {
                            i=1;
                            if( num < 5) { cout<<"\n\tPara polinomios de grado 3 ingrese almenos 4 puntos!"<<endl;      }
                            else    {   graf=grado_3( puntos , p , graf );      }
                        }
                        if ((pol!=1) && (pol!=2) && (pol!=3)){ cout<<"\tIngrese un valor valido:";  cin>>pol; }
                    }
                }
                else
                {
                    cout<<"\n\tIngrese puntos primero."<<endl;
                }

                break;

            case 3:

                systema();

                break;

            case 4:

/// Abrir - Cerrar Grafica ///---------------------------------------------------------------------------------------------///

                if( graf==0 ){ cout<<"\n\tEl grafico no esta activado."<<endl;}
                if( graf==1 ){ cout<<"\n\tGrafico Cerrado."<<endl;  graf=0;    closegraph();}

                break;

            default:

                h = 0;

                break;

        }

        cout<<"\n\tQue tarea desea realizar ahora?:"<<endl;
        cout<<"\t(1)Ingreso de puntos.  \n\t(2)Evaluar en polinomios.    \n\t(3)Trabajar con sistemas ( x,y,z ). \n\t(4)Cerrar Grafica.  \n\t(Cualquier Tecla)Salir."<<endl;

    }

    if ( graf==1 ){ graf=0; closegraph();}
    return 0;
}
















/// Funciones ///------------------------------------------------------------------------------------------------------------------------///

/// Funcion #1 - Muestra

void muestra_de_puntos( short puntos , int p[MAX] )
{   short i , num=1 ;
    cout<<"\n\tPuntos Ingresados:\n"<<endl;
    for ( i=0 ; (i/2)<puntos ; i=i+2 )
    {   cout<<"\tPunto #" << ( num++ ) << ": (" << p[i] << "," << p[ i+1 ] << ")" <<endl;
    }
}

///--------------------------------------------------------------------------------------------------------------------------------------///

/// Funcion #2 - Base de Pol #1

short grado_1( int puntos , int p[MAX] ,  short graf )
{   short i , f , fil=puntos , c , col=2 , j , f1 , c1 , fil_t , col_t ;
    int A[MAX][MAX] , B[MAX][MAX] , A_t[MAX][MAX] , A_t_A[MAX][MAX] ;
    float A_t_A_inv[MAX][MAX] , A_t_B[MAX][MAX] , X[MAX][MAX] ;
    int det;

    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),1);
/// Matris A

    j=0;
    for( f = 1 ; f <= fil ; f++ )
    {
       for( c = 1 ; c <= col ; c++ )
       {
            if ( c = 1){   A[f][c] = p[j];  j = j+2;    }
            if ( c = 2){   A[f][c] = 1 ;    }
       }
    }

/// Matris B

    j=1;
    for( f = 1 ; f <= fil ; f++ )
    {
       for( c = 1 ; c <= 1 ; c++ )
       {
            B[f][c] = p[j];  j = j+2;
       }
    }

/// Ver

    cout<<"\n\tMatrices:"<<endl;

///-------------------------------------------------------------------------------------------------/

    cout<<"\n\tA:\n"<<endl;

    for( f = 1 ; f <= fil ; f++ )
    {
       for( c = 1 ; c <= col ; c++ )
       {
            cout << "\t" << A[f][c] ;
            if( c==col )
            {   cout << endl;
            }
       }
    }

///-------------------------------------------------------------------------------------------------/

    cout<<"\n\tB:\n"<<endl;

    for( f = 1 ; f <= fil ; f++ )
    {
       for( c = 1 ; c <= 1 ; c++ )
       {    cout << "\t" << B[f][c] ;
            cout << endl;
       }
    }

///-------------------------------------------------------------------------------------------------/
    cout<<"\n\tA^t:\n"<<endl;

    for( f = 1 ; f <= fil ; f++ )
    {
       for( c = 1 ; c <= col ; c++ )
       {
            A_t[c][f] = A[f][c];
       }
    }

    fil_t = col;
    col_t = fil;

    for( f = 1 ; f <= fil_t ; f++ )
    {
       for( c = 1 ; c <= col_t ; c++ )
       {
            cout << "\t" << A_t[f][c] ;
            if( c==fil )
            {   cout << endl;
            }
       }
    }

///-------------------------------------------------------------------------------------------------/
    cout<<"\n\t(A^t)*A:\n"<<endl;

    // Inicializamos la matriz A_t_A.
    for( f=1; f<=fil; f++)
    {
        for( c=1; c<=col; c++)
        {
            A_t_A[f][c] = 0;
        }
    }

    // Generamos la matriz A_t_A.
    for( f=1 ; f<=fil_t ; f++ )
    {
        for( c1=1 ; c1<=col ; c1++ )
        {
            for( c=1 ; c<=col_t ; c++)
            {
                A_t_A[f][c1] += A_t[f][c] * A[c][c1];
            }
        }
    }

    //Mostramos la matriz A_t_A.
    for( f=1; f<=fil_t; f++)
    {
        for( c=1; c<=col; c++)
        {
            cout << "\t" << A_t_A[f][c];
            if( c==col )
            {   cout << endl;
            }
        }
    }

///-------------------------------------------------------------------------------------------------/
    int a , b , d , e , x , y , w , z;

    det = determinante( fil_t , A_t_A );
    if ( det == 0)  {   cout<<"\n\tLa determinante de la matriz ((A^t)*A) es = 0.   \n\tPor lo que no existe solucion para este caso."<<endl;   }
    else
    {
        cout<<"\n\t((A^t)*A)^(-1):\n"<<endl;

        //Obtener las posiciones
        for( f=1; f<=fil_t; f++)
        {   for( c=1; c<=col; c++)
            {   if ((f== 1) && (c== 1)){ a = A_t_A[f][c]; }
                if ((f== 1) && (c== 2)){ b = A_t_A[f][c]; }
                if ((f== 2) && (c== 1)){ d = A_t_A[f][c]; }
                if ((f== 2) && (c== 2)){ e = A_t_A[f][c]; }
            }
        }

        //Colocar las posiciones
        for( f=1; f<=fil_t; f++)
        {   for( c=1; c<=col; c++)
            {   if ((f== 1) && (c== 1)){ A_t_A_inv[f][c] = e; }
                if ((f== 1) && (c== 2)){ A_t_A_inv[f][c] = -b; }
                if ((f== 2) && (c== 1)){ A_t_A_inv[f][c] = -d; }
                if ((f== 2) && (c== 2)){ A_t_A_inv[f][c] = a; }
            }
        }

        //Colocar las posiciones
        cout<<"\tPaso #1:\n"<<endl;
        cout<<"\t(1/"<<det<<")";
        for( f=1; f<=fil_t; f++)
        {
            for( c=1; c<=col; c++)
            {
                if ((f==2) && (c==1)) { cout << "\t\t" << A_t_A_inv[f][c]; }
                if ((f==2) && (c==2)) { cout << "\t" << A_t_A_inv[f][c]; }
                if ( f== 1 ){ cout << "\t" << A_t_A_inv[f][c]; }
                if( c==col ){   cout << endl;   }
            }
        }

        //Dividir por determinante
        for( f=1; f<=fil_t; f++)
        {
            for( c=1; c<=col; c++)
            {
                A_t_A_inv[f][c] = A_t_A_inv[f][c]/det;
            }
        }

        cout<<"\n\tPaso #2:\n"<<endl;
        for( f=1; f<=fil_t; f++)
        {
            for( c=1; c<=col; c++)
            {
                cout << "\t" << A_t_A_inv[f][c];
                if( c==col ){   cout << endl;   }
            }
        }

///-------------------------------------------------------------------------------------------------/

        cout<<"\n\t(A^t)*B:\n"<<endl;

        // Inicializamos la matriz A_t_B.
        for( f=1; f<=fil; f++)
        {
            for( c=1; c<=col; c++)
            {
                A_t_B[f][c] = 0;
            }
        }


        // Generamos la matriz A_t_A_B
        for( f=1 ; f<=fil_t ; f++ )
        {
            for( c1=1 ; c1<=1 ; c1++ )
            {
                for( c=1 ; c<=col_t ; c++)
                {
                    A_t_B[f][c1] += A_t[f][c] * B[c][c1];
                }
            }
        }

        //Mostramos la matriz A_t_B.
        for( f=1; f<=fil_t ; f++)
        {
            for( c=1; c<=1 ; c++)
            {
                cout << "\t" << A_t_B[f][c];
                if( c==1 )
                {   cout << endl;
                }
            }
        }

///-------------------------------------------------------------------------------------------------/

        cout<<"\n\tX:\n"<<endl;


        // Inicializamos la matriz X.
        for( f=1 ; f<=2 ; f++ )
        {
            for( c=1 ; c<=1 ; c++ )
            {
                X[f][c] = 0;
            }
        }

        // Generamos la matriz X.
        for( f=1 ; f<=fil_t ; f++ )
        {
            for( c1=1 ; c1<=1 ; c1++ )
            {
                for( c=1 ; c<=col ; c++)
                {
                    X[f][c1] += A_t_A_inv[f][c] * A_t_B[c][c1];
                }
            }
        }

        //Mostramos la matriz X.
        for( f=1; f<=2; f++)
        {
            for( c=1; c<=1; c++)
            {
                cout << "\t" << X[f][c];
                if( c==1 )
                {   cout << endl;
                }
            }
        }



///-------------------------------------------------------------------------------------------------/

        cout<<"\n\tEc que mejor se aproxima:"<<endl;
        cout<<"\n\ty = " << X[1][1] << "X + " << X[2][1] <<endl;

        float X1 , Y1 , X2 , Y2 ;
        short r=0 ;


        X1=10000;
        Y1=(X[1][1])*X1 + (X[2][1]);
        X2=-10000;
        Y2=(X[1][1])*X2 + (X[2][1]);

        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),9);
        cout<<"\n\tManipulacion Grafica Activada."<<endl;
        cout<<"\n\tSeleccione la grafica y extiendala o maximicela a gusto."<<endl;
        cout<<"\n\tPara Desactivar su control solo presione una \n\ttecla con la grafica seleccionada y vuelva a \n\tseleccionar el programa para poder trabajar.\n"<<endl;

        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);

        if ( graf== 0 )
        {   initwindow(800,600);
            setcolor(15);
            line ( -10000 , 500 , 10000 , 500 );
            line ( 500 , -10000 , 500 , 10000 );
        }
        graf=1;

        for ( i=0 ; (i/2)<puntos ; i=i+2 )
        {   if( (r == 1) || (r == 0) || (r>15) ) { r=2; }
            setcolor(r); r++;
            circle( (p[i/*+1*/])*12+500 , ((-1)*(p[i+1]))*12+500 , 2 );
        }
        setcolor(1);
        line( (X1)*12+500 , (-1)*Y1*12+500 , (X2)*12+500 , (-1)*Y2*12+500 );

        while(!kbhit());      //Espera a que el usuario presione una tecla
        getch();
        cout<<"\n\tManipulacion Grafica Desactivada!.\n"<<endl;
        cout<<"\n\tPara volver a manipular la grafica debe activarla nuevamente!.\n"<<endl;
    }
    return graf;

}











///--------------------------------------------------------------------------------------------------------------------------------------///

/// Funcion #3 - Base de Pol #2

short grado_2( int puntos , int p[MAX] ,  short graf )
{   short i , f , fil=puntos , c , col=3 , j , f1 , c1 , fil_t , col_t ;
    int A[MAX][MAX] , B[MAX][MAX] , A_t[MAX][MAX] , A_t_A[MAX][MAX];
    float A_t_A_inv[MAX][MAX] , A_t_B[MAX][MAX] , X_3[MAX][MAX] ;
    int det , k ;

    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),2);
/// Matris A

    //Generando matriz
    for( f = 0 ; f < MAX ; f++ )
    {   for( c = 0 ; c < MAX ; c++ )
       {    A[f][c] = 0;
       }
    }

    //Dandole datos X^2
    i=0;
    j=0;
    for( f = 0 ; f < fil ; f++ )
    {
       for( c = 0 ; c < col ; c++ )
       {
            if ( c == 0){   A[f][c] = (p[i])*(p[i]);  i = i+2;    }
            if ( c == 1){   A[f][c] = p[j];  j = j+2;    }
            if ( c == 2){   A[f][c] = 1 ;    }
       }
    }

/// Matris B

    j=1;
    for( f = 0 ; f < fil ; f++ )
    {
       for( c = 0 ; c < 1 ; c++ )
       {
            B[f][c] = p[j];  j = j+2;
       }
    }

/// Ver

    cout<<"\n\tMatrices:"<<endl;

///-------------------------------------------------------------------------------------------------/

    cout<<"\n\tA:\n"<<endl;

    for( f = 0 ; f < fil ; f++ )
    {
       for( c = 0 ; c < col ; c++ )
       {
            cout << "\t" << A[f][c] ;
            if( c==col-1 )
            {   cout << endl;
            }
       }
    }

///-------------------------------------------------------------------------------------------------/

    cout<<"\n\tB:\n"<<endl;

    for( f = 0 ; f < fil ; f++ )
    {
       for( c = 0 ; c < 1 ; c++ )
       {    cout << "\t" << B[f][c] ;
            cout << endl;
       }
    }

///-------------------------------------------------------------------------------------------------/
    cout<<"\n\tA^t:\n"<<endl;

    for( f = 0 ; f < fil ; f++ )
    {
       for( c = 0 ; c < col ; c++ )
       {
            A_t[c][f] = A[f][c];
       }
    }

    fil_t = col;
    col_t = fil;

    for( f = 0 ; f < fil_t ; f++ )
    {
       for( c = 0 ; c < col_t ; c++ )
       {
            cout << "\t" << A_t[f][c] ;
            if( c==fil-1 )
            {   cout << endl;
            }
       }
    }

///-------------------------------------------------------------------------------------------------/
    cout<<"\n\t(A^t)*A:\n"<<endl;

    // Inicializamos la matriz A_t_A.
    for( f=0 ; f<fil_t ; f++)
    {
        for( c=0 ; c<col ; c++)
        {
            A_t_A[f][c] = 0;
        }
    }

    // Generamos la matriz A_t_A.
    for( f=0 ; f<fil_t ; f++ )
    {
        for( c1=0 ; c1<col ; c1++ )
        {
            for( c=0 ; c<col_t ; c++)
            {
                A_t_A[f][c1] += A_t[f][c] * A[c][c1];
            }
        }
    }

    //Mostramos la matriz A_t_A.
    for( f=0 ; f<fil_t ; f++ )
    {
        for( c=0 ; c<col ; c++ )
        {
            cout << "\t" << A_t_A[f][c];
            if( c==col-1 )
            {   cout << endl;
            }
        }
    }

///-------------------------------------------------------------------------------------------------/

    det = determinante( fil_t , A_t_A );
    if ( det!=0 )
    {

///-------------------------------------------------------------------------------------------------/

        cout<<"\n\t[(A^t)*A]^(-1):\n"<<endl;

    /// Definición de variables y asignación dinámica de memoria

        float sum , factor , *L[fil_t] , D[fil_t] , X[fil_t] ;
        float a[MAX][MAX] , ainv[MAX][MAX];

        /// Lectura de la matriz
        for(i=0; i<fil_t; i++)
        {
            for(j=0; j<fil_t; j++)
            {
                a[i][j] = A_t_A[i][j];
            }
        }

///--------------------------------------------------------------------------------------------------------------------------/

	/// Algoritmo para la eliminación simple de Gauss
//-----------------------------------------------------------------------------------------------------------------------------------/
        for ( j=0 ; j<fil_t ; j++ )
        {
            L[j] = new float [fil_t];
        }
        for (k =0 ; k<fil_t-1 ; k++)
        {
            for ( i = k+1; i<fil_t ;  i++ )
            {
                factor = a[i][k]/a[k][k];
                for ( j = k+1 ; j < fil_t + 1 ; j++ )
                {
                    a[i][j] = a[i][j] - factor * a[k][j];
                }
            }

        }
//-----------------------------------------------------------------------------------------------------------------------------------/
/// Rutina para determinar las matrices L (inferior) y U (superior) de la descomposición LU.


        for ( i = 0 ; i < fil_t ; i++ )
        {
            for ( j = 0 ; j < fil_t ; j++ )
            {
                if (i > j)
                {
                    L[i][j] = a[i][j]/a[j][j];
                    a[i][j] = 0;
                }
            }
        }
//-----------------------------------------------------------------------------------------------------------------------------------/
        for ( i = 0 ; i < fil_t ; i++ )
        {
            for ( j = 0; j < fil_t ; j++ )
            {
                L[j][j] = 1;
            }
        }

///------------------------------------------------------------------------------------------------------------------------------------------------///

        for ( k = 0; k < fil_t ; k++ )         /// Implementación de la rutina para el cálculo de la inversa
        {
            for ( i = 0; i < fil_t ; i++ )    /// Esta rutina inicializa los L[i][n] para ser utilizados con la matriz L
            {
                if (i == k) { L[i][fil_t] = 1; }
               else{  L[i][fil_t] = 0; }
            }

//-----------------------------------------------------------------------------------------------------------------------------------/

                                        /// Esta función implementa la sustitución hacia adelante con la matriz L y los L[i][n] que produce la rutina anterior
            D[0] = L[0][fil_t];

            for (i = 1; i < fil_t; i++)
            {
                sum = 0;
                for (j = 0; j < i; j++)
                {
                    sum = sum + L[i][j]*D[j];
                }
                D[i] = L[i][fil_t] - sum;
            }

//-----------------------------------------------------------------------------------------------------------------------------------/

            for (i = 0; i <fil_t ; i++)         /// Esta rutina asigna los D[i] que produce forward para ser utilizados con la matriz U.
            {
                a[i][fil_t] = D[i];
            }

            X[fil_t-1] = a[fil_t-1][fil_t]/a[fil_t-1][fil_t-1];     /// Rutina que aplica la sustitución hacia atras.

//-----------------------------------------------------------------------------------------------------------------------------------/

            for (i = fil_t - 2; i > -1; i--)     /// Determinación de las raíces restantes.
            {
                sum = 0;
                for (j = i+1; j < fil_t; j++)
                {
                    sum = sum + a[i][j]*X[j];
                }

                X[i] = (a[i][fil_t] - sum)/a[i][i];
            }

//-----------------------------------------------------------------------------------------------------------------------------------/

            for (i = 0; i < fil_t ; i++)     /// Esta rutina asigna los X[i] que produce Sustituir como los elementos de la matriz inversa
            {
                A_t_A_inv[i][k] = X[i];

            }

        }

///-------------------------------------------------------------------------------------------------/

        ///Muestra la Matriz Inversa
        for(i=0 ; i<fil_t ; i++)
        {
            for(j=0 ; j<fil_t ; j++)
            {
                cout << "\t" << A_t_A_inv[i][j];
                if( j==fil_t-1 ){   cout << endl;   }
            }
        }


//-----------------------------------------------------------------------------------------------------------------------------------/

        for ( j=0 ; j<fil_t ; j++ )
        {
            delete  L[j];
        }


///------------------------------------------------------------------------------------------------------------------------------------------------///


        cout<<"\n\t(A^t)*B:\n"<<endl;

        // Inicializamos la matriz A_t_B.
        for( f=0; f<fil ; f++ )
        {
            for( c=0 ; c<col ; c++ )
            {
                A_t_B[f][c] = 0;
            }
        }


        // Generamos la matriz A_t_A_B
        for( f=0 ; f<fil_t ; f++ )
        {
            for( c1=0 ; c1<1 ; c1++ )
            {
                for( c=0 ; c<col_t ; c++ )
                {
                    A_t_B[f][c1] += A_t[f][c] * B[c][c1];
                }
            }
        }

        //Mostramos la matriz A_t_B.
        for( f=0 ; f<fil_t ; f++ )
        {
            for( c=0 ; c<1 ; c++ )
            {
                cout << "\t" << A_t_B[f][c];
                if( c==0 )
                {   cout << endl;
                }
            }
        }

///-------------------------------------------------------------------------------------------------/

        cout<<"\n\tX:\n"<<endl;

        // Inicializamos la matriz X.
        for( f=0 ; f<3 ; f++ )
        {
            for( c=0 ; c<1 ; c++ )
            {
                X_3[f][c] = 0;
            }
        }

        // Generamos la matriz X.
        for( f=0 ; f<fil_t ; f++ )
        {
            for( c1=0 ; c1<1 ; c1++ )
            {
                for( c=0 ; c<col ; c++)
                {
                    X_3[f][c1] += A_t_A_inv[f][c] * A_t_B[c][c1];
                }
            }
        }

        //Mostramos la matriz X.
        for( f=0; f<3; f++)
        {
            for( c=0 ; c<=0 ; c++ )
            {
                cout << "\t" << X_3[f][c];
                if( c==0 )
                {   cout << endl;
                }
            }
        }



///-------------------------------------------------------------------------------------------------/

        cout<<"\n\tEc que mejor se aproxima:"<<endl;
        cout<<"\n\ty = " << X_3[0][0] << "(X)^2 + " << X_3[1][0] << "(X) + " << X_3[2][0] << endl;

        float X1 , Y1 , X2 , Y2 ;
        short r=0 ;

        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),10);
        cout<<"\n\tManipulacion Grafica Activada."<<endl;
        cout<<"\n\tSeleccione la grafica y extiendala o maximicela a gusto."<<endl;
        cout<<"\n\tPara Desactivar su control solo presione una \n\ttecla con la grafica seleccionada y vuelva a \n\tseleccionar el programa para poder trabajar.\n"<<endl;

        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);

        if ( graf== 0 )
        {   initwindow(800,600);
            setcolor(15);
            line ( -10000 , 500 , 10000 , 500 );
            line ( 500 , -10000 , 500 , 10000 );
        }

        graf=1;

        for ( i=0 ; (i/2)<puntos ; i=i+2 )
        {   if( (r == 1) || (r == 0) || (r>15) ) { r=2; }
            setcolor(r); r++;
            circle( (p[i/*+1*/])*12+500 , ((-1)*(p[i+1]))*12+500 , 2 );
        }

        for ( X1=-300 ; X1<300 ; X1 = X1+(0.5) )
        {
            X2 = X1+(0.5) ;
            Y1=(X_3[0][0])*X1*X1 + (X_3[1][0])*X1 + (X_3[2][0]);
            Y2=(X_3[0][0])*X2*X2 + (X_3[1][0])*X2 + (X_3[2][0]);
            setcolor(2);
            line( (X1)*12+500 , (-1)*Y1*12+500 , (X2)*12+500 , (-1)*Y2*12+500 );
        }

        while(!kbhit());      //Espera a que el usuario presione una tecla
        getch();
        cout<<"\n\tManipulacion Grafica Desactivada!.\n"<<endl;
        cout<<"\n\tPara volver a manipular la grafica debe activarla nuevamente!.\n"<<endl;

    }
    else
    {
        cout<<"\n\tLa determinante = 0 , por lo que no tiene inversa."<<endl;
    }
    return graf;

}













///--------------------------------------------------------------------------------------------------------------------------------------///

/// Funcion #4 - Base de Pol #3

short grado_3( int puntos , int p[MAX] ,  short graf )
{   short i , f , fil=puntos , c , col=4 , j , f1 , c1 , fil_t , col_t ;
    int A[MAX][MAX] , B[MAX][MAX] , A_t[MAX][MAX] , A_t_A[MAX][MAX];
    float A_t_A_inv[MAX][MAX] , A_t_B[MAX][MAX] , X_4[MAX][MAX] ;
    int det , k ;

    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),4);
/// Matris A

    //Generando matriz
    for( f = 0 ; f < MAX ; f++ )
    {   for( c = 0 ; c < MAX ; c++ )
       {    A[f][c] = 0;
       }
    }

    //Dandole datos X^2

    j=0;   i=0;  f=0;
    for( f1 = 0 ; f1 < fil ; f1++ )
    {
       for( c1 = 0 ; c1 < col ; c1++ )
       {
            if ( c1 == 0){   A[f1][c1] = (p[f])*(p[f])*(p[f]);  f = f+2;    }
            if ( c1 == 1){   A[f1][c1] = (p[i])*(p[i]);  i = i+2;    }
            if ( c1 == 2){   A[f1][c1] = p[j];  j = j+2;    }
            if ( c1 == 3){   A[f1][c1] = 1 ;    }
       }
    }

/// Matris B

    j=1;
    for( f = 0 ; f < fil ; f++ )
    {
       for( c = 0 ; c < 1 ; c++ )
       {
            B[f][c] = p[j];  j = j+2;
       }
    }

/// Ver

    cout<<"\n\tMatrices:"<<endl;

///-------------------------------------------------------------------------------------------------/

    cout<<"\n\tA:\n"<<endl;

    for( f = 0 ; f < fil ; f++ )
    {
       for( c = 0 ; c < col ; c++ )
       {
            cout << "\t" << A[f][c] ;
            if( c==col-1 )
            {   cout << endl;
            }
       }
    }

///-------------------------------------------------------------------------------------------------/

    cout<<"\n\tB:\n"<<endl;

    for( f = 0 ; f < fil ; f++ )
    {
       for( c = 0 ; c < 1 ; c++ )
       {    cout << "\t" << B[f][c] ;
            cout << endl;
       }
    }

///-------------------------------------------------------------------------------------------------/
    cout<<"\n\tA^t:\n"<<endl;

    for( f = 0 ; f < fil ; f++ )
    {
       for( c = 0 ; c < col ; c++ )
       {
            A_t[c][f] = A[f][c];
       }
    }

    fil_t = col;
    col_t = fil;

    for( f = 0 ; f < fil_t ; f++ )
    {
       for( c = 0 ; c < col_t ; c++ )
       {
            cout << "\t" << A_t[f][c] ;
            if( c==fil-1 )
            {   cout << endl;
            }
       }
    }

///-------------------------------------------------------------------------------------------------/
    cout<<"\n\t(A^t)*A:\n"<<endl;

    // Inicializamos la matriz A_t_A.
    for( f=0 ; f<fil_t ; f++)
    {
        for( c=0 ; c<col ; c++)
        {
            A_t_A[f][c] = 0;
        }
    }

    // Generamos la matriz A_t_A.
    for( f=0 ; f<fil_t ; f++ )
    {
        for( c1=0 ; c1<col ; c1++ )
        {
            for( c=0 ; c<col_t ; c++)
            {
                A_t_A[f][c1] += A_t[f][c] * A[c][c1];
            }
        }
    }

    //Mostramos la matriz A_t_A.
    for( f=0 ; f<fil_t ; f++ )
    {
        for( c=0 ; c<col ; c++ )
        {
            cout << "\t" << A_t_A[f][c];
            if( c==col-1 )
            {   cout << endl;
            }
        }
    }

///-------------------------------------------------------------------------------------------------/

    //-----------------------------------------------------------------------------------------------------------------------------------/
/// Cálculo del determinante

    det = 1.;
	for (i = 0 ; i <fil_t ; i++)
    {
        det = det * A_t_A[i][i];
    }
    cout<<"\n\tDeterminante: "<<det<<endl;;

    if ( det!=0 )
    {

///-------------------------------------------------------------------------------------------------/

        cout<<"\n\t[(A^t)*A]^(-1):\n"<<endl;

    /// Definición de variables y asignación dinámica de memoria

        float sum , factor , L[MAX][MAX] , D[fil_t] , X[fil_t] ;
        float a[MAX][MAX] , ainv[MAX][MAX];

        /// Lectura de la matriz
        for(i=0; i<fil_t; i++)
        {
            for(j=0; j<fil_t; j++)
            {
                a[i][j] = A_t_A[i][j];
            }
        }

///--------------------------------------------------------------------------------------------------------------------------/

	/// Algoritmo para la eliminación simple de Gauss
//-----------------------------------------------------------------------------------------------------------------------------------/

        for (k =0 ; k<fil_t-1 ; k++)
        {
            for ( i = k+1; i<fil_t ;  i++ )
            {
                factor = a[i][k]/a[k][k];
                for ( j = k+1 ; j < fil_t + 1 ; j++ )
                {
                    a[i][j] = a[i][j] - factor * a[k][j];
                }
            }

        }
//-----------------------------------------------------------------------------------------------------------------------------------/
/// Rutina para determinar las matrices L (inferior) y U (superior) de la descomposición LU.


        for ( i = 0 ; i < fil_t ; i++ )
        {
            for ( j = 0 ; j < fil_t ; j++ )
            {
                if (i > j)
                {
                    L[i][j] = a[i][j]/a[j][j];
                    a[i][j] = 0;
                }
            }
        }
//-----------------------------------------------------------------------------------------------------------------------------------/
        for ( i = 0 ; i < fil_t ; i++ )
        {
            for ( j = 0; j < fil_t ; j++ )
            {
                L[j][j] = 1;
            }
        }

///------------------------------------------------------------------------------------------------------------------------------------------------///

        for ( k = 0; k < fil_t ; k++ )         /// Implementación de la rutina para el cálculo de la inversa
        {
            for ( i = 0; i < fil_t ; i++ )    /// Esta rutina inicializa los L[i][n] para ser utilizados con la matriz L
            {
                if (i == k) { L[i][fil_t] = 1; }
               else{  L[i][fil_t] = 0; }
            }

//-----------------------------------------------------------------------------------------------------------------------------------/

                                        /// Esta función implementa la sustitución hacia adelante con la matriz L y los L[i][n] que produce la rutina anterior
            D[0] = L[0][fil_t];

            for (i = 1; i < fil_t; i++)
            {
                sum = 0;
                for (j = 0; j < i; j++)
                {
                    sum = sum + L[i][j]*D[j];
                }
                D[i] = L[i][fil_t] - sum;
            }

//-----------------------------------------------------------------------------------------------------------------------------------/

            for (i = 0; i <fil_t ; i++)         /// Esta rutina asigna los D[i] que produce forward para ser utilizados con la matriz U.
            {
                a[i][fil_t] = D[i];
            }

            X[fil_t-1] = a[fil_t-1][fil_t]/a[fil_t-1][fil_t-1];     /// Rutina que aplica la sustitución hacia atras.

//-----------------------------------------------------------------------------------------------------------------------------------/

            for (i = fil_t - 2; i > -1; i--)     /// Determinación de las raíces restantes.
            {
                sum = 0;
                for (j = i+1; j < fil_t; j++)
                {
                    sum = sum + a[i][j]*X[j];
                }

                X[i] = (a[i][fil_t] - sum)/a[i][i];
            }

//-----------------------------------------------------------------------------------------------------------------------------------/

            for (i = 0; i < fil_t ; i++)     /// Esta rutina asigna los X[i] que produce Sustituir como los elementos de la matriz inversa
            {
                A_t_A_inv[i][k] = X[i];

            }

        }

///-------------------------------------------------------------------------------------------------/

        ///Muestra la Matriz Inversa
        for(i=0 ; i<fil_t ; i++)
        {
            for(j=0 ; j<fil_t ; j++)
            {
                cout << "\t" << A_t_A_inv[i][j];
                if( j==fil_t-1 ){   cout << endl;   }
            }
        }


//-----------------------------------------------------------------------------------------------------------------------------------/


///------------------------------------------------------------------------------------------------------------------------------------------------///


        cout<<"\n\t(A^t)*B:\n"<<endl;

        // Inicializamos la matriz A_t_B.
        for( f=0; f<fil ; f++ )
        {
            for( c=0 ; c<col ; c++ )
            {
                A_t_B[f][c] = 0;
            }
        }


        // Generamos la matriz A_t_A_B
        for( f=0 ; f<fil_t ; f++ )
        {
            for( c1=0 ; c1<1 ; c1++ )
            {
                for( c=0 ; c<col_t ; c++ )
                {
                    A_t_B[f][c1] += A_t[f][c] * B[c][c1];
                }
            }
        }

        //Mostramos la matriz A_t_B.
        for( f=0 ; f<fil_t ; f++ )
        {
            for( c=0 ; c<1 ; c++ )
            {
                cout << "\t" << A_t_B[f][c];
                if( c==0 )
                {   cout << endl;
                }
            }
        }

///-------------------------------------------------------------------------------------------------/

        cout<<"\n\tX:\n"<<endl;

        // Inicializamos la matriz X.
        for( f=0 ; f<4 ; f++ )
        {
            for( c=0 ; c<1 ; c++ )
            {
                X_4[f][c] = 0;
            }
        }

        // Generamos la matriz X.
        for( f=0 ; f<fil_t ; f++ )
        {
            for( c1=0 ; c1<1 ; c1++ )
            {
                for( c=0 ; c<col ; c++)
                {
                    X_4[f][c1] += A_t_A_inv[f][c] * A_t_B[c][c1];
                }
            }
        }

        //Mostramos la matriz X.
        for( f=0; f<4; f++)
        {
            for( c=0 ; c<=0 ; c++ )
            {
                cout << "\t" << X_4[f][c];
                if( c==0 )
                {   cout << endl;
                }
            }
        }



///-------------------------------------------------------------------------------------------------/

        cout<<"\n\tEc que mejor se aproxima:"<<endl;
        cout<<"\n\ty = " << X_4[0][0] << "(X)^3 + " << X_4[1][0] << "(X)^2 + " << X_4[2][0] << "(X) + " << X_4[3][0] <<endl;

        float X1 , Y1 , X2 , Y2 ;
        short r=0 ;

        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), 12);
        cout<<"\n\tManipulacion Grafica Activada."<<endl;
        cout<<"\n\tSeleccione la grafica y extiendala o maximicela a gusto."<<endl;
        cout<<"\n\tPara Desactivar su control solo presione una \n\ttecla con la grafica seleccionada y vuelva a \n\tseleccionar el programa para poder trabajar.\n"<<endl;

        SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);

        if ( graf== 0 )
        {   initwindow(800,600);
            setcolor(15);
            line ( -10000 , 500 , 10000 , 500 );
            line ( 500 , -10000 , 500 , 10000 );
        }

        graf=1;

        for ( i=0 ; (i/2)<puntos ; i=i+2 )
        {   if( (r == 1) || (r == 0) || (r>15) ) { r=2; }
            setcolor(r); r++;
            circle( (p[i])*12+500 , ((-1)*(p[i+1]))*12+500 , 2 );
        }

        for ( X1=-300 ; X1<300 ; X1 = X1+(0.5) )
        {
            X2 = X1+(0.5) ;
            Y1=(X_4[0][0])*X1*X1*X1 + (X_4[1][0])*X1*X1 + (X_4[2][0])*X1 + (X_4[3][0]);
            Y2=(X_4[0][0])*X2*X2*X2 + (X_4[1][0])*X2*X2 + (X_4[2][0])*X2 + (X_4[3][0]);
            setcolor(4);
            line( (X1)*12+500 , (-1)*Y1*12+500 , (X2)*12+500 , (-1)*Y2*12+500 );
        }

        while(!kbhit());      //Espera a que el usuario presione una tecla
        getch();
        cout<<"\n\tManipulacion Grafica Desactivada!.\n"<<endl;
        cout<<"\n\tPara volver a manipular la grafica debe activarla nuevamente!.\n"<<endl;

    }
    else
    {
        cout<<"\n\tLa determinante = 0 , por lo que no tiene inversa."<<endl;
    }
    return graf;

}







///-------------------------------------------------------------------------------------------------/

/// Funcion #5 - Determinante

int determinante( int fil , int A_t_A[MAX][MAX] )
{   short f1,c1;
    int p,q,det;
    int a,b,c,d,e,f,g,h,i;

    if( fil == 3 )
    {
        for( f1 = 0 ; f1 < fil ; f1++ )
        {
            for( c1 = 0 ; c1 < 3 ; c1++ )
            {
                if ( (f1==0) && (c1==0) ) {   a=A_t_A[f1][c1] ; }
                if ( (f1==0) && (c1==1) ) {   b=A_t_A[f1][c1] ; }
                if ( (f1==0) && (c1==2) ) {   c=A_t_A[f1][c1] ; }
                if ( (f1==1) && (c1==0) ) {   d=A_t_A[f1][c1] ; }
                if ( (f1==1) && (c1==1) ) {   e=A_t_A[f1][c1] ; }
                if ( (f1==1) && (c1==2) ) {   f=A_t_A[f1][c1] ; }
                if ( (f1==2) && (c1==0) ) {   g=A_t_A[f1][c1] ; }
                if ( (f1==2) && (c1==1) ) {   h=A_t_A[f1][c1] ; }
                if ( (f1==2) && (c1==2) ) {   i=A_t_A[f1][c1] ; }
            }
        }
        det = (a*((e*i)-(f*h))) - (b*((d*i)-(f*g)))+ (c*((d*h)-(e*g)));
        cout << endl;
        cout << "\tDeterminante de [(A^t)*A]= " << det << endl;
    }
    else
    {   p=(A_t_A)[1][1]*(A_t_A)[2][2];
        q=(A_t_A)[1][2]*(A_t_A)[2][1];
        det = p-q;
    }
    return det;
}

///-------------------------------------------------------------------------------------------------/








///--------------------------------------------------------------------------------------------------------------------------------------///

/// Funcion #6 - Systema

void systema()
{   short i , f , fil , c , col=3 , j , f1 , c1 , fil_t , col_t ;
    int A[MAX][MAX] , B[MAX][MAX] , A_t[MAX][MAX] , A_t_A[MAX][MAX];
    float A_t_A_inv[MAX][MAX] , A_t_B[MAX][MAX] , X_3[MAX][MAX] ;
    int det , k ;

    cout<<"\n\tLa estructura de los systemas es: a(X) + b(Y) + c(Z) = d"<<endl;
    cout<<"\n\tIntroduzca la cantidad de sistemas a ingresar (MIN 3 - MAX 6):";
    cin>> fil;

    if ( fil>=3 && fil<=6 ) {  }
    else
    {   i=0;
        while ( i==0 )
        {
            cout<<"\tIngrese una cantidad de sistemas admitida:";   cin>> fil ;
            if ( fil>=3 && fil<=6 ){ i=1;  }
        }
    }


/// Matris A

    //Generando matriz
    for( f = 0 ; f < MAX ; f++ )
    {   for( c = 0 ; c < MAX ; c++ )
       {    A[f][c] = 0;
       }
    }

    //Dandole datos X^2

    for( f = 0 ; f < fil ; f++ )
    {
        cout<<"\n\tPara Sistema #" << f+1 <<":"<<endl;
        for( c = 0 ; c < col+1 ; c++ )
        {
            if ( c == 0){  cout<<"\n\tIntroduzca valor de (a):";    cin>> A[f][c];  }
            if ( c == 1){  cout<<"\n\tIntroduzca valor de (b):";    cin>> A[f][c];  }
            if ( c == 2){  cout<<"\n\tIntroduzca valor de (c):";    cin>> A[f][c];  }
            /// Matris B
            if ( c == 3){   cout<<"\n\tIntroduzca valor de (d):";   cin>> B[f][0];  }
        }
        cout<<"\n\tSistema #" << f+1 <<":"<<endl;
        cout<<"\t"<< A[f][c-4] << "(X) + "<< A[f][c-3] << "(Y) + "<< A[f][c-2] << "(Z) = "<< B[f][0] <<endl;
    }

/// Ver

    cout<<"\n\tMatrices:"<<endl;

///-------------------------------------------------------------------------------------------------/

    cout<<"\n\tA:\n"<<endl;

    for( f = 0 ; f < fil ; f++ )
    {
       for( c = 0 ; c < col ; c++ )
       {
            cout << "\t" << A[f][c] ;
            if( c==col-1 )
            {   cout << endl;
            }
       }
    }

///-------------------------------------------------------------------------------------------------/

    cout<<"\n\tB:\n"<<endl;

    for( f = 0 ; f < fil ; f++ )
    {
       for( c = 0 ; c < 1 ; c++ )
       {    cout << "\t" << B[f][c] ;
            cout << endl;
       }
    }

///-------------------------------------------------------------------------------------------------/
    cout<<"\n\tA^t:\n"<<endl;

    for( f = 0 ; f < fil ; f++ )
    {
       for( c = 0 ; c < col ; c++ )
       {
            A_t[c][f] = A[f][c];
       }
    }

    fil_t = col;
    col_t = fil;

    for( f = 0 ; f < fil_t ; f++ )
    {
       for( c = 0 ; c < col_t ; c++ )
       {
            cout << "\t" << A_t[f][c] ;
            if( c==fil-1 )
            {   cout << endl;
            }
       }
    }

///-------------------------------------------------------------------------------------------------/
    cout<<"\n\t(A^t)*A:\n"<<endl;

    // Inicializamos la matriz A_t_A.
    for( f=0 ; f<fil_t ; f++)
    {
        for( c=0 ; c<col ; c++)
        {
            A_t_A[f][c] = 0;
        }
    }

    // Generamos la matriz A_t_A.
    for( f=0 ; f<fil_t ; f++ )
    {
        for( c1=0 ; c1<col ; c1++ )
        {
            for( c=0 ; c<col_t ; c++)
            {
                A_t_A[f][c1] += A_t[f][c] * A[c][c1];
            }
        }
    }

    //Mostramos la matriz A_t_A.
    for( f=0 ; f<fil_t ; f++ )
    {
        for( c=0 ; c<col ; c++ )
        {
            cout << "\t" << A_t_A[f][c];
            if( c==col-1 )
            {   cout << endl;
            }
        }
    }

///-------------------------------------------------------------------------------------------------/

    det = determinante( fil_t , A_t_A );
    if ( det!=0 )
    {

///-------------------------------------------------------------------------------------------------/

        cout<<"\n\t[(A^t)*A]^(-1):\n"<<endl;

    /// Definición de variables y asignación dinámica de memoria

        float sum , factor , *L[fil_t] , D[fil_t] , X[fil_t] ;
        float a[MAX][MAX] , ainv[MAX][MAX];

        /// Lectura de la matriz
        for(i=0; i<fil_t; i++)
        {
            for(j=0; j<fil_t; j++)
            {
                a[i][j] = A_t_A[i][j];
            }
        }

///--------------------------------------------------------------------------------------------------------------------------/

	/// Algoritmo para la eliminación simple de Gauss
//-----------------------------------------------------------------------------------------------------------------------------------/
        for ( j=0 ; j<fil_t ; j++ )
        {
            L[j] = new float [fil_t];
        }
        for (k =0 ; k<fil_t-1 ; k++)
        {
            for ( i = k+1; i<fil_t ;  i++ )
            {
                factor = a[i][k]/a[k][k];
                for ( j = k+1 ; j < fil_t + 1 ; j++ )
                {
                    a[i][j] = a[i][j] - factor * a[k][j];
                }
            }

        }
//-----------------------------------------------------------------------------------------------------------------------------------/
/// Rutina para determinar las matrices L (inferior) y U (superior) de la descomposición LU.


        for ( i = 0 ; i < fil_t ; i++ )
        {
            for ( j = 0 ; j < fil_t ; j++ )
            {
                if (i > j)
                {
                    L[i][j] = a[i][j]/a[j][j];
                    a[i][j] = 0;
                }
            }
        }
//-----------------------------------------------------------------------------------------------------------------------------------/
        for ( i = 0 ; i < fil_t ; i++ )
        {
            for ( j = 0; j < fil_t ; j++ )
            {
                L[j][j] = 1;
            }
        }

///------------------------------------------------------------------------------------------------------------------------------------------------///

        for ( k = 0; k < fil_t ; k++ )         /// Implementación de la rutina para el cálculo de la inversa
        {
            for ( i = 0; i < fil_t ; i++ )    /// Esta rutina inicializa los L[i][n] para ser utilizados con la matriz L
            {
                if (i == k) { L[i][fil_t] = 1; }
               else{  L[i][fil_t] = 0; }
            }

//-----------------------------------------------------------------------------------------------------------------------------------/

                                        /// Esta función implementa la sustitución hacia adelante con la matriz L y los L[i][n] que produce la rutina anterior
            D[0] = L[0][fil_t];

            for (i = 1; i < fil_t; i++)
            {
                sum = 0;
                for (j = 0; j < i; j++)
                {
                    sum = sum + L[i][j]*D[j];
                }
                D[i] = L[i][fil_t] - sum;
            }

//-----------------------------------------------------------------------------------------------------------------------------------/

            for (i = 0; i <fil_t ; i++)         /// Esta rutina asigna los D[i] que produce forward para ser utilizados con la matriz U.
            {
                a[i][fil_t] = D[i];
            }

            X[fil_t-1] = a[fil_t-1][fil_t]/a[fil_t-1][fil_t-1];     /// Rutina que aplica la sustitución hacia atras.

//-----------------------------------------------------------------------------------------------------------------------------------/

            for (i = fil_t - 2; i > -1; i--)     /// Determinación de las raíces restantes.
            {
                sum = 0;
                for (j = i+1; j < fil_t; j++)
                {
                    sum = sum + a[i][j]*X[j];
                }

                X[i] = (a[i][fil_t] - sum)/a[i][i];
            }

//-----------------------------------------------------------------------------------------------------------------------------------/

            for (i = 0; i < fil_t ; i++)     /// Esta rutina asigna los X[i] que produce Sustituir como los elementos de la matriz inversa
            {
                A_t_A_inv[i][k] = X[i];

            }

        }

///-------------------------------------------------------------------------------------------------/

        ///Muestra la Matriz Inversa
        for(i=0 ; i<fil_t ; i++)
        {
            for(j=0 ; j<fil_t ; j++)
            {
                cout << "\t" << A_t_A_inv[i][j];
                if( j==fil_t-1 ){   cout << endl;   }
            }
        }


//-----------------------------------------------------------------------------------------------------------------------------------/

        for ( j=0 ; j<fil_t ; j++ )
        {
            delete  L[j];
        }


///------------------------------------------------------------------------------------------------------------------------------------------------///


        cout<<"\n\t(A^t)*B:\n"<<endl;

        // Inicializamos la matriz A_t_B.
        for( f=0; f<fil ; f++ )
        {
            for( c=0 ; c<col ; c++ )
            {
                A_t_B[f][c] = 0;
            }
        }


        // Generamos la matriz A_t_A_B
        for( f=0 ; f<fil_t ; f++ )
        {
            for( c1=0 ; c1<1 ; c1++ )
            {
                for( c=0 ; c<col_t ; c++ )
                {
                    A_t_B[f][c1] += A_t[f][c] * B[c][c1];
                }
            }
        }

        //Mostramos la matriz A_t_B.
        for( f=0 ; f<fil_t ; f++ )
        {
            for( c=0 ; c<1 ; c++ )
            {
                cout << "\t" << A_t_B[f][c];
                if( c==0 )
                {   cout << endl;
                }
            }
        }

///-------------------------------------------------------------------------------------------------/

        cout<<"\n\tX:\n"<<endl;

        // Inicializamos la matriz X.
        for( f=0 ; f<3 ; f++ )
        {
            for( c=0 ; c<1 ; c++ )
            {
                X_3[f][c] = 0;
            }
        }

        // Generamos la matriz X.
        for( f=0 ; f<fil_t ; f++ )
        {
            for( c1=0 ; c1<1 ; c1++ )
            {
                for( c=0 ; c<col ; c++)
                {
                    X_3[f][c1] += A_t_A_inv[f][c] * A_t_B[c][c1];
                }
            }
        }

        //Mostramos la matriz X.
        for( f=0; f<3; f++)
        {
            for( c=0 ; c<=0 ; c++ )
            {
                cout << "\t" << X_3[f][c];
                if( c==0 )
                {   cout << endl;
                }
            }
        }



///-------------------------------------------------------------------------------------------------/

        cout<<"\n\tValores Aproximados de cada variable:"<<endl;
        cout<<"\n\tX = " << X_3[0][0] <<"\n\n\tY = " << X_3[1][0] << "\n\n\tZ = " << X_3[2][0] << endl;

    }
    else
    {
        cout<<"\n\tLa determinante = 0 , por lo que no tiene inversa."<<endl;
    }

}

