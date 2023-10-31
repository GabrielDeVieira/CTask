#include <stdio.h>
#include <stdlib.h>
#include "agendamento.h"
#include <unistd.h>
#include "util.h"
#include <string.h>

// Estrutura das Funções baseadas na ideia professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
void op_agendamento(void) {
    char opcao;
    do {
        opcao = menu_agendamentos();
        switch(opcao) {
            case '1':   salvar_agendamento(create_agendamento());
                        break;
            case '2': 	delete_agendamento();
                        break;
            case '3': 	update_agendamento();
                        break;
            case '4': 	all_agendamentos();
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
//Funções de Listagem
void exibe_agendamento(Agendamento* ag) {
char situacao[20];
if ((ag == NULL) || (ag->status == '0')) {
 printf("\n= = = tarefa Inexistente = = =\n");
} else {
 printf("\n= = = Tarefa Cadastrado = = =\n");
 printf("Nome da Tarefa: %s\n", ag->nome);
 printf("Data do Agndamento: %s\n", ag->data_agendamento);
 printf("Horário do Agndamento: %d:%d:%d\n", ag->hora, ag->minuto, ag->segundo);
 printf("Tarefa do Agendamento: %d\n", ag->id_tarefa);
 printf("Duração do Agendamento: %d horas\n", ag->duracao_hora);

if (ag->status == '1') {
 strcpy(situacao, "Novo");
} else {
 strcpy(situacao, "Arquivado");
}
 printf("Situação do aluno: %s\n", situacao);
}
}

void all_agendamentos(){
    FILE* fp;
    Agendamento* agendamento;
    printf("\n = Lista de Tarefas = \n");
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));
    fp = fopen("agendamento.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    while(fread(agendamento, sizeof(Agendamento), 1, fp)) {
        if (agendamento->status == '1') {
            exibe_agendamento(agendamento);
        }
    }
    fclose(fp);
    printf("\n");
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}

//Função de gravação em arquivo
void salvar_agendamento(Agendamento * agendamento){
    FILE* fp;
    fp = fopen("agendamento.dat","ab");
    if (fp == NULL) {
    printf("Erro na criacao do arquivo\n!");
    exit(1);
    }
    fwrite(agendamento, sizeof(Agendamento), 1, fp);
    fclose(fp);
    free(agendamento);
}

Agendamento * create_agendamento(void){
    Agendamento *agendamento = malloc(sizeof(Agendamento));
    int dia, mes, ano;
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
      //scanf("%d/%d/%d", &agendamento->dia, &agendamento->mes, &agendamento->ano);
      scanf("%10s", agendamento->data_agendamento);
      getchar();
      if (sscanf(agendamento->data_agendamento, "%2d/%2d/%4d", &dia, &mes, &ano) == 3) {
        if(!(valida_data(dia, mes, ano))){
            printf("|-- Data Agendamento inválida! \n");
            printf("|-- Data Agendamento(dd/mm/aaaa): \n");
        }
      }else{
        printf("|-- Data Agendamento inválida! \n");
        printf("|-- Data Agendamento(dd/mm/aaaa): \n");
      }
    } while (!(valida_data(dia, mes, ano)));

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
    scanf("%d", &agendamento->duracao_hora);
    getchar();
    agendamento->status = '1';
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    return agendamento;

}

void update_agendamento(void){
    int id_agendamento;
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---          ATUALIZAÇÃO DO AGENDAMENTO         ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|-- informe o id do Agendamento: \n");
    scanf("%d", &id_agendamento);
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
void delete_agendamento(void){
    int id_agendamento;
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---           EXCLUSÃO DO AGENDAMENTO           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|-- informe o id do Agendamento: \n");
    scanf("%d", &id_agendamento);
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();


}

void read_agendamento(void){
    int id_agendamento;
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---             BUSCA DO AGENDAMENTO            ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|-- informe o id do Agendamento: \n");
    scanf("%d", &id_agendamento);
    printf("|___________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
