#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "user.h"
#include <unistd.h>

void op_user(void) {
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

    User usuario;

    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---            CADASTRO NOVO USUÁRIO            ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|-- Nome: \n");
    fgets(usuario.nome, sizeof(usuario.nome), stdin);
    printf("|-- Data de Nascimento: \n");
    fgets(usuario.data_nascimento, sizeof(usuario.data_nascimento), stdin);
    printf("|                                                   |\n");
    printf("|-- Email: \n");
    fgets(usuario.email, sizeof(usuario.email), stdin);
    printf("|                                                   |\n");
    printf("|-- Numero: \n");
    fgets(usuario.numero, sizeof(usuario.numero), stdin);
    printf("|                                                   |\n");
    printf("|-- Username: \n");
    fgets(usuario.username, sizeof(usuario.username), stdin);
    printf("|                                                   |\n");
    printf("|-- CPF: \n");
    fgets(usuario.cpf, sizeof(usuario.cpf), stdin);
    printf("|                                                   |\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    return usuario;

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