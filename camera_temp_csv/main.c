/** Programa que exibe na tela dados formatados
 * de um arquivo CSV conforme o padrÃ£o: 
 *         Series;Value;Time
 *         <int>;<float>;<string> 
 *         <int>;<float>;<string>
 */

#include <stdio.h>

int main() {

	int amostra;
	float temperatura;
	char data[64];

	FILE *fp = fopen("camera_temp.csv", "r");

	if (fp==NULL) {
		perror("Erro em main: fopen");
		exit(-1);
	}

	/* Ignora primeira linha */
	fgets(data, 63, fp);

	while (fscanf(fp, "%d,%f,%63[^\n]\n", &amostra, &temperatura, data)==3) {
			printf("%d  --  %f  --- %s\n", amostra, temperatura, data);
	}

	fclose (fp);
	return 0;
}
