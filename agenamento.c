#include <stdio.h>
#include <stdlib.h>
#include "agendamento.h"
#include <unistd.h>
#include "util.h"

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
    printf("|--            0 - Sair                           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("Digite uma opção: \n");
    scanf("%c", &opcao1);
    getchar();
    return opcao1;
   

}
Agendamento create_agendamento(void){

    Agendamento *agendamento = malloc(sizeof(Agendamento));

    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---           CADASTRO DO AGENDAMENTO           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|-- Nome : \n");
    fgets(agendamento->nome, sizeof(agendamento->nome), stdin);
    printf("|-- Data Agendamento(dd/mm/aaaa) : \n");
    do
    {
      scanf("%d/%d/%d", &agendamento->dia, &agendamento->mes, &agendamento->ano);
      getchar();
      if(!(valida_data(agendamento->dia, agendamento->mes, agendamento->ano))){
        printf("|-- Data Agendamento inválida! \n");
        printf("|-- Data Agendamento(dd/mm/aaaa): \n");
      }
    } while (!(valida_data(agendamento->dia, agendamento->mes, agendamento->ano)));

    printf("|-- Horario Agendamento(hh:mm:ss):: \n");
    do
    {
      scanf("%d:%d:%d", &agendamento->hora, &agendamento->minuto, &agendamento->segundo);
      getchar();
      if(!(valida_hora(agendamento->hora, agendamento->minuto, agendamento->segundo))){
        printf("|-- Horario Agendamento inválida! \n");
        printf("|-- Horario Agendamento(hh:mm:ss): \n");
      }
    } while (!(valida_data(agendamento->hora, agendamento->minuto, agendamento->segundo)));

    printf("|-- Tarefa(ID) : \n");
    scanf("%d", &agendamento->id_tarefa);
    getchar();
    printf("|-- Duracao Compromisso(Hora): \n");
    fgets(agendamento->duracao_hora, sizeof(agendamento->duracao_hora), stdin);
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    return *agendamento;

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
    getchar();
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
