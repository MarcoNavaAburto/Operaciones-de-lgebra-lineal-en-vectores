#include<stdio.h>
#include<math.h>

int vector1[5] = {1, 2, 3, 4, 5};
int vector2[5] = {6, 7, 8, 9, 10};
int vector3[5] = {11, 12, 13, 14, 15};

int vectorResultante[5];
int vectorResultante2[5];


void calcularDistanciaEntreDosPuntos()
{
	int suma = 0, i, distancia;
	
	for(i=0;i<5;i++)
		suma += pow((vector2[i] - vector1[i]), 2);
	
	distancia = sqrt(suma);
	
	printf("La distancia entre los 2 puntos es : %d", distancia);
}


void calcularSumaEntreDosVectores()
{
	int i = 0;
	
	for(i=0;i<5;i++)
		vectorResultante[i] = vector1[i] + vector2[i];
	
	printf("\nEl vector resultante que sale de la suma de los vectores anteriores es el siguiente: ");
	
	printf("\n(");
	
	for(i=0;i<5;i++)
		printf("%d, ", vectorResultante[i]);

	printf(")");
}


void calcularProductoEscalarPorVector()
{
	int escalar, opcion, i;
	
	printf("\nIngrese un escalar: ");
	scanf("%d", &escalar);
	
	printf("\nIngrese el numero 1 si quiere hacer la operacion sobre el primer vector o el 2 en caso de hacer la operacion en el segundo vector: ");	
	scanf("%d", &opcion);
	
	if(opcion == 1)
	{
		for(i=0;i<5;i++)
			vectorResultante[i] = vector1[i] * escalar;
	}
	else if(opcion == 2)
	{
		for(i=0;i<5;i++)
			vectorResultante[i] = vector2[i] * escalar;
	}
	else
	{
		printf("\nLa opcion que se ingreso es incorrecta. Sere regresado al menu principal");
		return;	
	}
	
	printf("\nEl vector resultante queda de la siguiente manera: ");
		
	printf("\n(");
		
	for(i=0;i<5;i++)
		printf("%d, ", vectorResultante[i]);
		
	printf(")");
	
}


int calcularProductoPuntoEntreDosVectores()
{
	int productoPunto = 0, i;
	
	for(i=0;i<5;i++)
		productoPunto += vector1[i] * vector2[i];	
	
	return productoPunto;
}


void calcularNormaVector()
{
	int opcion, i;
	int norma, suma = 0;
	
	printf("\nIngrese el numero 1 si quiere calcular la norma del primer vector o el numero 2 en caso de querer calcular la norma del segundo vector: ");
	scanf("%d", &opcion);
	
	if(opcion == 1)
	{
		for(i=0;i<5;i++)
			suma += pow(vector1[i], 2);		
	}
	
	else if(opcion == 2)
	{
		for(i=0;i<5;i++)
			suma += pow(vector2[i], 2);
	}
	
	else
	{
		printf("\nTiene que ingresar una opcion que sea valida. Se le regresara al menu principal\n");	
		return;		
	}
	
	norma = sqrt(suma);	
	printf("\nLa norma del vector es: %d", norma);
}


float calcularNormaVector1()
{
	int i, suma = 0;
	
	for(i=0;i<5;i++)
		suma += pow(vector1[i], 2);		
	
	return sqrt(suma);
}


float calcularNormaVector2()
{
	int i, suma = 0;
	
	for(i=0;i<5;i++)
		suma += pow(vector2[i], 2);		
	
	return sqrt(suma);	
}


void calcularAnguloEntreDosVectores()
{
	int productoPunto;
	
	float norma1, norma2, division, anguloRadianes, anguloGrados;
	
	productoPunto = calcularProductoPuntoEntreDosVectores();
	
	norma1 = calcularNormaVector1();
	
	norma2 = calcularNormaVector2();
	
	division = productoPunto / (norma1 * norma2);
	
	anguloRadianes = acos(division);
	
	anguloGrados = anguloRadianes * (180.0 / M_PI);
	
	printf("\nEl angulo entre los dos vectores es %.2f grados\n", anguloGrados);
	
}


int calcularNormaVector1SinRaiz()
{
	int i, suma = 0;
	
	for(i=0;i<5;i++)
		suma += pow(vector1[i], 2);
		
	return suma;
}


int calcularNormaVector2SinRaiz()
{
	int i, suma = 0;
	
	for(i=0;i<5;i++)
		suma += pow(vector2[i], 2);
		
	return suma;
}


void calcularVectorUnitario()
{
	int opcion, i, norma;
	
	printf("\nIngrese el numero 1 si quiere hacer la operacion en el primer vector, ingrese el numero 2 si lo quiere hacer en el segundo vector: ");
	scanf("%d", &opcion);
	
	if(opcion == 1)
	{
		norma = calcularNormaVector1SinRaiz();
		
		printf("\nEl vector unitario es el siguiente: \n(\n");
		
		for(i=0;i<5;i++)
			printf("%d / v%d, ", vector1[i], norma);
			
		printf(")\n");
	}
	else if(opcion == 2)
	{
		norma = calcularNormaVector2SinRaiz();	
		
		printf("\nEl vector unitario es el siguiente: \n(\n");
		
		for(i=0;i<5;i++)
			printf("%d / v%d, ", vector2[i], norma);
			
		printf(")\n");
	}
	else
	{
		printf("\nSe debe de ingresar una opcion que sea valida, sera regresado al menu de opciones de operaciones\n");	
		return;
	}
	
}


void calcularComponenteDeUnVectorSobreOtro()
{
	int productoPunto; 
	float normaVector1, componente;
	
	productoPunto = calcularProductoPuntoEntreDosVectores();
	
	normaVector1 = calcularNormaVector1();
	
	componente = productoPunto / normaVector1;
	
	printf("\nLa componente del vector 2 sobre el vector 1 es %.2f", componente);
}


void calcularVectorProyeccionSobreOtroVector()
{
	int productoPunto, i, suma = 0;
	float division;
	
	productoPunto = calcularProductoPuntoEntreDosVectores();
	
	for(i=0;i<5;i++)
		suma += pow(vector1[i], 2);
	
	division = productoPunto / suma;
	
	for(i=0;i<5;i++)
	{
		vectorResultante[i] = division * vector1[i];
	}
	
	printf("\nLa proyeccion del vector 2 en el vector 1 da el siguiente vector resultante: ");
	
	printf("(");
	
	for(i=0;i<5;i++)
		printf("%d, ", vectorResultante[i]);
		
	printf(")");
}

void calcularRestaVectores()
{
	int i;
	
	for(i=0;i<5;i++)
		vectorResultante[i] = vector2[i] - vector1[i];	
}


void calcularEcuacionDeLaRectaPorDosPuntos()
{
	int i;
	
	calcularRestaVectores();
	
	printf("\nLa ecuacion es la siguiente: ");
	
	printf("(");
	
	for(i=0;i<5;i++)
	{
		printf("%dt + %d, ", vectorResultante[i], vector1[i]);	
	}
	
	printf(")");
}


void vector1MenosVector3()
{
	int i;
	
	for(i=0;i<5;i++)
	{
		vectorResultante[i] = vector1[i] - vector3[i];
		vectorResultante2[i] = vector2[i] - vector3[i];
	}	
	
}


void calcularEcuacionVectorialDelPlanoTresPuntos()
{
	int i;
	
	vector1MenosVector3();
	
	printf("(");
	
	for(i=0;i<5;i++)
	{
		printf("%d %dt1 %dt2, ", vector3[i], vectorResultante[i], vectorResultante2[i]);	
	}
	
	printf(")");			
}


void imprimirVectores()
{
	int i;
	
	printf("\nVector 1: \n(");
		
	for(i=0;i<5;i++)
	{
		printf("%d, ", vector1[i]);
	}
		
	printf(")");
		
	printf("\nVector 2: \n(");
		
	for(i=0;i<5;i++)
	{
		printf("%d, ", vector2[i]);
	}
		
	printf(")\n");
}


int main()
{
	int otro = 1;
	int opcion, i;
	int productoPunto;
	
	while(otro == 1)
	{
		imprimirVectores();
		
		printf("\nMenu de opciones");
		printf("\nOpcion\tAccion\n1\tCalcular la distancia entre 2 puntos\n2\tCalcular la suma entre 2 vectores\n3\tCalcular el producto por un escalar de un vector\n4\tCalcular el producto punto entre 2 vectores");
		printf("\n5\tCalcular la norma de un vector\n6\tCalcular el angulo entre 2 vectores\n7\tCalcular el vector unitario en la direccion de un vector\n8\tCalcular la componente de un vector y sobre un vector x");
		printf("\n9\tCalcular el vector proyeccion de un vector y sobre un vector x\n10\tCalcular la ecuacion vectorial de la recta que pasa por 2 puntos\n11\tCalcular la ecuacion vectorial del plano que pasa por tres puntos\n12\tSalir del programa");
		
		printf("\n\nIngrese la opcion de la accion que desea realizar: ");
		scanf("%d", &opcion);
	
		switch(opcion)
		{
			case 1:
				calcularDistanciaEntreDosPuntos();
				break;
				
			case 2:
				calcularSumaEntreDosVectores();
				break;
				
			case 3:
				calcularProductoEscalarPorVector();
				break;
				
			case 4:
							
				productoPunto = calcularProductoPuntoEntreDosVectores();
				
				printf("\nEl producto punto de los vectores es %d \n", productoPunto);
				
				break;
				
			case 5:
				calcularNormaVector();
				break;
				
			case 6:
				calcularAnguloEntreDosVectores();
				break;
				
			case 7:
				calcularVectorUnitario();
				break;
				
			case 8:
				calcularComponenteDeUnVectorSobreOtro();
				break;
				
			case 9:
				calcularVectorProyeccionSobreOtroVector();
				break;
				
			case 10:
				calcularEcuacionDeLaRectaPorDosPuntos();
				break;
				
			case 11:
				calcularEcuacionVectorialDelPlanoTresPuntos();
				break;
				
			case 12:
				otro = 2;
				break;
				
			default:
				printf("\nLa opcion que ingreso es incorrecta. Favor de ingresar una opcion que sea valida");
		}
		
	printf("\n");
	}
	
	return 0;
}
