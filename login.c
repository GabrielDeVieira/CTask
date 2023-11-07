#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "login.h"
#include <unistd.h>

#define True 1
#define False 0

void op_login(void) {
    char opcao;
    do {
        opcao = menu_login();
        switch(opcao) {
            case '1': 	login();
                        opcao = '0';
                        break;
            case '2': 	create_users();
                        break;

        } 		
    } while (opcao != '0');
}

// Estrutura das Funções baseadas na ideia professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
char menu_login(void){
    char opcao;
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---                     LOGIN                   ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--           1 - Login                           --|\n");
    printf("|--           2 - Registro                        --|\n");
    printf("|___________________________________________________|\n");
    printf("Login em Desenvolvimento, selecione 1 e digite qualquer\n");
    printf("valor na username e senha!\n");
    printf("Crud completo de 4 módulos- Agendamento, Tarefa, Disciplina\n");
    printf("e tipo da tarefa.\n");
    printf("\n");
    printf("Digite uma opção: \n");
    scanf("%c", &opcao);
    getchar();
    return opcao;
    
}
int login(){
    char username[100];
    char senha[20];

    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---                     LOGIN                   ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--  Username: ");
    fgets(username, sizeof(username), stdin);
    printf("|                                                   |\n");
    printf("|-- Senha: ");
    fgets(senha, sizeof(senha), stdin);
    printf("|                                                   |\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    if (valida_login(username[100], senha[20])){
        return True;
    }else{
        return False;
    }

}
int valida_login(char username[100], char senha[20]){
    return True;
}