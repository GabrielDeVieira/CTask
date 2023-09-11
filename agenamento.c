#include <stdio.h>
#include <stdlib.h>
#include "agendamento.h"
#include "status.h"
#include <unistd.h>

// Estrutura das Funções baseadas na ideia professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
void op_agendamento(void) {
    char opcao;
    do {
        opcao = menu_agendamentos();
        switch(opcao) {
            case '1': 	create_agendamento();
                        break;
            case '2': 	delete_agendamento();
                        break;
            case '3': 	update_agendamento();
                        break;
            case '4': 	read_agendamento();
                        break;
            case '5': 	op_status_tarefa();
                        break;
        } 		
    } while (opcao != '0');
}
char menu_agendamentos(void){
    char opcao1;

    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---           DIGITE A OPÇÃO DESEJADA:          ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--            1 - Adicionar Agendamento          --|\n");
    printf("|--            2 - Deletar Agendamento            --|\n");
    printf("|--            3 - Editar  Agendamento            --|\n");
    printf("|--            4 - Relatório Agendamentos         --|\n");
    printf("|--            5 - Menu Status Tarefa             --|\n");
    printf("|--            0 - Sair                           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("Digite uma opção: \n");
    scanf("%c", &opcao1);
    getchar();
    return opcao1;
   

}
void create_agendamento(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---           CADASTRO DO AGENDAMENTO           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--               Nome:                           --|\n");
    printf("|--               Data Agendamento:               --|\n");
    printf("|--               Status Tarefa(ID):              --|\n");
    printf("|--               Horario Agendamento:            --|\n");
    printf("|--               Tarefa(ID):                     --|\n");
    printf("|--               Duracao Compromisso(Hora):      --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void update_agendamento(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---          ATUALIZAÇÃO DO AGENDAMENTO         ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o id do Agendamento:          --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
}
void delete_agendamento(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---           EXCLUSÃO DO AGENDAMENTO           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o id do Agendamento:          --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();


}

void read_agendamento(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---             BUSCA DO AGENDAMENTO            ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o id do Agndamento:           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
