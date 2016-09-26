/*
 ============================================================================
 Name        : substituicao.c
 Author      : Pablo Curty
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* pega_string() {
	char* str = malloc(sizeof(char));
	printf("\nDigite o texto e '#' no final do texto");
	scanf("\n %[-,.;:A-Za-z #]s", str);
	getchar();
	return str;
}

int pega_chave() {
	int ch;
	printf("\nDigite o valor da chave ");
	scanf("%d", &ch);
	if (ch > 26) {
		ch = ch % 26;
	}

	return ch;
}

void encripter(char* frase, int chave) {
	int chave2 = chave;
	int contador = 0; //variável de controle do loop
	char i = '#';
	int c = (int) i;
	char vazio = ' ';
	int v = (int) vazio;
	while ((int) frase[contador] != c) {
		int enc = (int) frase[contador++];
		if (enc > 64 && enc < 91 && (int) frase[contador] != v) {
			enc = enc + chave2;
			if (enc > 90) {
				enc = (enc % 90) + 64;
			}
		}
		printf("%c", (char) enc);
		chave2 = ((chave2 + (enc % 64)) % 26);
	}
}

void decripter(char* frase, int chave) {
	int chave2 = chave;
	int contador = 0; //variável de controle do loop
	char i = '#';
	int c = (int) i;
	char vazio = ' ';
	int v = (int) vazio;
	while ((int) frase[contador] != c) {
		int enc1 = (int) frase[contador++];
		int enc = enc1;
		if (enc > 64 && enc < 91 && (int) frase[contador] != v) {
			enc = enc - chave2;
			if (enc < 65) {
				enc = 64 - enc;
				enc = 90 - enc;
			}
		}
		printf("%c", (char) enc);
		chave2 = ((chave2 + (enc1 % 64)) % 26);
	}
}

int main(void) {
	char teste;
	// string para decriptar ou encriptar
	char* frase;
	//boolean para saber se já pode sair 0 = false   1 = true
	int sair = 0;
	// chave default é 1
	int chave;

	while (sair != 1) {
		printf("\nDigite D para decriptar e E para decriptar ");
		scanf("%c", &teste);
		if (teste == 'E') {
			printf("\nEntrou no E");
			//metodo para pegar o valor da chave
			chave = pega_chave();
			printf("\nA chave é %d", chave);
			// método para pegar a string para decriptar ou encriptar
			frase = pega_string();
			printf("\nO texto é %s", frase);
			// metodo para encriptar
			printf("\nO texto encriptado é:");
			encripter(frase, chave);
			sair = 1;
		}
		if (teste == 'D') {
			printf("\nEntrou no D");
			//metodo para pegar o valor da chave
			chave = pega_chave();
			printf("\nA chave é %d", chave);
			// método para pegar a string para decriptar ou encriptar
			frase = pega_string();
			printf("\nO texto é %s", frase);
			// metodo para decriptar
			printf("\nO texto decriptado é:");
			decripter(frase, chave);
			sair = 1;
		}
	}
	return EXIT_SUCCESS;
}
