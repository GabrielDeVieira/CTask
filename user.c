#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "user.h"
#include <unistd.h>

#define True 1
#define False 0

void op_users(void) {
    char opcao;
    do {
        opcao = menu_users();
        switch(opcao) {
            case '1': 	create_users();
                        break;
            case '2': 	delete_users();
                        break;
            case '3': 	update_users();
                        break;
            case '4': 	read_users();
                        break;
        } 		
    } while (opcao != '0');
}


// Estrutura das Funções baseadas na ideia professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
char menu_users(void){
    char opcao;
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---           DIGITE A OPÇÃO DESEJADA:          ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--           1 - Adicionar User                  --|\n");
    printf("|--           2 - Deletar User                    --|\n");
    printf("|--           3 - Editar  User                    --|\n");
    printf("|--           4 - Relatório User                  --|\n");
    printf("|--           0 - Sair                            --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("Digite uma opção: \n");
    scanf("%c", &opcao);
    getchar();
    return opcao;
    
   
    
}
User create_users(void){

    User *usuario = malloc(sizeof(User));


    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---            CADASTRO NOVO USUÁRIO            ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|-- Nome: \n");
    do{
    fgets(usuario->nome, sizeof(usuario->nome), stdin);
    if(!(valida_nome(usuario->nome))){
        printf("|-- Nome inválido! \n");
        printf("|-- Nome: \n");
    }
    }while (!(valida_nome(usuario->nome)));
    printf("|-- Data de Nascimento(dd/mm/aaaa): \n");
    do
    {
      scanf("%d/%d/%d", &usuario->dia, &usuario->mes, &usuario->ano);
      getchar();
      if(!(valida_data(usuario->dia, usuario->mes, usuario->ano))){
        printf("|-- Data de NAscimento inválida! \n");
        printf("|-- Data de Nascimento(dd/mm/aaaa): \n");
      }
    } while (!(valida_data(usuario->dia, usuario->mes, usuario->ano)));

    printf("|                                                   |\n");
    printf("|-- Email: \n");
    do{
    fgets(usuario->email, sizeof(usuario->email), stdin);

    if (!(valida_email(usuario->email))){
       printf("|-- Email Inválido ! \n");
       printf("|-- Email: \n");
    }
    
    } while (!(valida_email(usuario->email)));
    
    
    printf("|                                                   |\n");
    printf("|-- Numero (apenas os numeros): \n");
    do
    {
    fgets(usuario->numero, sizeof(usuario->numero), stdin);
    
     if (!(valida_numero(usuario->numero))){
       printf("|-- Numero Inválido ! \n");
       printf("|-- Numero (apenas os numeros): \n");
     }
    } while (!(valida_numero(usuario->numero)));
    
    
    printf("|                                                   |\n");
    printf("|-- Username: \n");
    fgets(usuario->username, sizeof(usuario->username), stdin);
    printf("|                                                   |\n");
    printf("|-- CPF: \n");
    do{
    fgets(usuario->username, sizeof(usuario->username), stdin);
    if (!(valida_CPF(usuario->username))){
        printf("|-- CPF inválido! \n");
        printf("|-- CPF: \n");
    }
    }while(!(valida_CPF(usuario->username)));
    printf("|                                                   |\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    return *usuario;

}


void update_users(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---            ATUALIZAÇÃO DO USUÁRIO           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--           informe o cpf do usuário:           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void delete_users(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---            EXCLUSÃO DO DO USUÁRIO           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--            informe o cpf do usuário:          --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void read_users(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---              BUSCA DO DO USUÁRIO            ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--            informe o cpf do usuário:          --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}