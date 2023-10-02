#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include <string.h>

#define True 1
#define False 0

int valida_datahora_exist(){
  return True;  
}
int valida_data_exist(){
  return True;  
}
int valida_exist_nome(){
  return True;
}

//Função adaptada do código do professsor Flávius - https://replit.com/@GabrielVieira01/ValidacaoDeDados#util.c
int eh_bissexto(int aa) {
  if ((aa % 4 == 0) && (aa % 100 != 0)) {
    return True;
  } else if (aa % 400 == 0) {
    return True;
  } else {
    return False;
  }
}
//Função adaptada do código do professsor Flávius - https://replit.com/@GabrielVieira01/ValidacaoDeDados#util.c
int valida_data(int dd, int mm, int aa) {
  int maiorDia;
  if (aa < 0 || mm < 1 || mm > 12)
    return False;
  if (mm == 2) {
    if (eh_bissexto(aa)) 
      maiorDia = 29;
    else
      maiorDia = 28;
  } else if (mm == 4 || mm == 6 || 
             mm == 9 || mm == 11) {
               maiorDia = 30;
  } else
    maiorDia = 31;

  if (dd < 1 || dd > maiorDia)
    return False;

  return True;
}
//Função adaptada do código do professsor Flávius - https://replit.com/@GabrielVieira01/ValidacaoDeDados#util.c
int valida_nome(char* nome) {
  int tam;
  tam = strlen(nome);
  for (int i = 0; i < tam-1; i++) {
    if (!eh_letra(nome[i])) {
      return False;
    }
  }
  return True;  
}
//Função adaptada do código do professsor Flávius - https://replit.com/@GabrielVieira01/ValidacaoDeDados#util.c
int eh_letra(char c) {
  if (c >= 'A' && c <= 'Z') {
    return True;
  } else if (c >= 'a' && c <= 'z') {
    return True;
  } else if (c == ' ' || c == 13) {
    return True;
  } else {
    return False;
  }  
}

int eh_numero(char c){
   if (c >= '0' && c <= '9') {
        return True;
    } else {
        return False;
    }
}
int valida_CPF(char *cpf) {
    int i, j;
    int digito_v1 = 0, digito_v2 = 0;

    char numeros_cpf[12]; 
    int len = strlen(cpf);
    int pos = 0;
    for (i = 0; i < len; i++) {
        if (eh_numero(cpf[i])) {
            numeros_cpf[pos++] = cpf[i];
        }
    }
    numeros_cpf[pos] = '\0';

    if (strlen(numeros_cpf) != 11) {
        return False;
    }
    for (i = 0, j = 10; i < 9; i++, j--) {
        digito_v1 += (numeros_cpf[i] - '0') * j;
    }
    digito_v1 = 11 - (digito_v1 % 11);
    if (digito_v1 >= 10) {
        digito_v1 = 0;
    }
    for (i = 0, j = 11; i < 10; i++, j--) {
        digito_v2 += (numeros_cpf[i] - '0') * j;
    }
    digito_v2 = 11 - (digito_v2 % 11);
    if (digito_v2 >= 10) {
        digito_v2 = 0;
    }
    if (digito_v1 == (numeros_cpf[9] - '0') && digito_v2 == (numeros_cpf[10] - '0')) {
        return True;
    } else {
        return False;
    }
}