#include <iostream>
using namespace std;
#include <malloc.h>

void cabecalho()
{
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
	cout << "|      Calculadora de Determinantes     |\n";
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
}

void lerDimensao(int *tamMatriz)
{
	cout << endl << "Insira a ordem da matriz: "; 
	cin >> *tamMatriz;
}

void lerMatriz(int *tamMatriz, double **matriz)
{
	cout << endl << endl << "Entre com o conteudo da matriz:" << endl;
    int i, j;
    
	for(i = 0; i < *tamMatriz; i++)
    {
        for(j = 0; j < *tamMatriz; j++)
        {
            cout << "A[" << i+1 << " ; " << j+1 << "] => ";
            cin >> matriz[i][j];
        }
    }
}

void mostraMatriz(int *tamMatriz, double **matriz)
{
	int i,j;
	
	cout << endl << "Matriz digitada: " << endl;
    for(i = 0; i < *tamMatriz; i++)
    {
        for(j = 0; j < *tamMatriz ; j++)
        {
        	cout << "| " <<  matriz[i][j] << " |";
        }
        cout << endl;
    }
}

double calculaDet(int *dimMatriz, double **matriz)
{
	int i,j,k;
	double variante = 0;
	int count = 0;
	double fator;
	
	   for(i = 0; i < *dimMatriz - 1; i++)
    {
        if(matriz[i][i] == 0)
        {
            for(k = i; k < *dimMatriz; k++)
            {
                if(matriz[k][i] != 0)
                {
                    for(j = 0; j < *dimMatriz; j++)
                    {
                        variante = matriz[i][j];
                        matriz[i][j] = matriz[k][j];
                        matriz[k][j] = variante;
                    }
                    k = *dimMatriz;
                }
            }
            count++;
        }
           
	    if(matriz[i][i] != 0)
        {
            for(k = i + 1; k < *dimMatriz; k++)
            {
                fator = -1.0 * matriz[k][i] /  matriz[i][i];
                for(j = i; j < *dimMatriz; j++)
                {
                    matriz[k][j] = matriz[k][j] + (fator * matriz[i][j]);
                }
            }
        }
    }
    
    variante = 1.0;

    for(i = 0; i < *dimMatriz; i++)
    	variante *= matriz[i][i];

    cout << endl << "Determinante: " << endl;
    if(count % 2 == 0)
        cout << variante << endl;
    else
        cout << -1.0 * variante << endl;

	return variante;
}

void tipoDet(double *valorDet)
{
	if(*valorDet == 0)
		cout << endl << "Sistema possivel indeterminado ou impossível." << endl;
	else
		cout << endl << "Sistema possivel determindo." << endl;
}

int main()
{
	int dimMatriz, i;
	double **matriz;
	double determinante;
	
	cabecalho();
	
	lerDimensao(&dimMatriz);
	cout<< endl << "Tamanho da matriz: " << dimMatriz << "x" << dimMatriz;

    matriz = (double **) malloc(dimMatriz * sizeof(double *));
    for(i = 0; i < dimMatriz; i++)
    {
        matriz[i] = (double *) malloc(dimMatriz * sizeof(double));
    }
    
    lerMatriz(&dimMatriz, matriz);
    mostraMatriz(&dimMatriz, matriz);
    determinante = calculaDet(&dimMatriz, matriz);
    tipoDet(&determinante);
}
