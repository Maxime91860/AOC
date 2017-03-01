

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h> 

int main(int argc, char const *argv[])
{
	int taille = atoi(argv[1]);
	int stock;
	int i;
	struct timeval debut_calcul, fin_calcul, duree_calcul;
	FILE* output = fopen("OUTPUT/temps_execution.txt","a+");


	//Temps avant boucle
	gettimeofday(&debut_calcul, NULL);

	for(i=0; i<taille; i++){
		stock = taille*42 + 30;
	}

	//Temps après boucle
	gettimeofday(&fin_calcul, NULL);

	timersub(&fin_calcul, &debut_calcul, &duree_calcul);
	fprintf(output, "%d %f\n", taille,
			(double) (duree_calcul.tv_sec) + (duree_calcul.tv_usec / 1000000.0));
	return 0;
}