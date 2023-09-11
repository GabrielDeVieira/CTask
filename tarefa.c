#include <stdio.h>
#include <stdlib.h>
#include "tarefa.h"
#include "tipo.h"
#include <unistd.h>

void op_tarefa(void) {
    char opcao;
    do {
        opcao = menu_tarefa();
        switch(opcao) {
            case '1': 	create_tarefa();
                        break;
            case '2': 	delete_tarefa();
                        break;
            case '3': 	update_tarefa();
                        break;
            case '4': 	read_tarefa();
                        break;
            case '5': 	op_tipo();
                        break;
        } 		
    } while (opcao != '0');
}

// Estrutura das Funções baseadas na ideia professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
char menu_tarefa(void){
    char opcao;
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---          DIGITE A OPÇÃO DESEJADA:           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--            1 - Adcionar Tarefa                --|\n");
    printf("|--            2 - Deletar Tarefas                --|\n");
    printf("|--            3 - Editar  Tarefas                --|\n");
    printf("|--            4 - Relatório Tarefas              --|\n");
    printf("|--            5 - Menu Tipo tarefa               --|\n");
    printf("|--            0 - Sair                           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("Digite uma opção: \n");
    scanf("%c", &opcao);
    getchar();
    return opcao;

}
void create_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---              CADASTRO DA TAREFA             ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--               Nome:                           --|\n");
    printf("|--               Descrição:                      --|\n");
    printf("|--               Tipo do tarefa(ID):             --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void update_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---            ATUALIZAÇÃO DA TAREFA            ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o nome da tarefa:             --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void delete_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---              EXCLUSÃO DA TAREFA              ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o nome da tarefa:             --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void read_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---               BUSCA DA TAREFA               ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o nome da tarefa:             --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}