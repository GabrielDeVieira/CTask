#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefa.h"
#include "tipo.h"
#include "util.h"
#include <unistd.h>


void op_tarefa(void) {
    char opcao;
    do {
        opcao = menu_tarefa();
        switch(opcao) {
            case '1': 	salvar_tarefa(create_tarefa());
                        break;
            case '2': 	delete_tarefa();
                        break;
            case '3': 	update_tarefa();
                        break;
            case '4': 	all_tarefas();
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
void exibe_tarefa(Tarefa* tf) {
char situacao[20];
if ((tf == NULL) || (tf->status == '0')) {
 printf("\n= = = tarefa Inexistente = = =\n");
} else {
 printf("\n= = = Tarefa Cadastrado = = =\n");
 printf("Nome da Tarefa: %s\n", tf->nome);
 printf("Descrição da Tarefa da Tarefa: %s\n", tf->descricao);

if (tf->status == '1') {
 strcpy(situacao, "Cadastrada");
} else {
 strcpy(situacao, "Não Cadastrada");
}
 printf("Situação do aluno: %s\n", situacao);
}
}

void all_tarefas(){
    FILE* fp;
    Tarefa* tarefa;
    printf("\n = Lista de Tarefas = \n");
    tarefa = (Tarefa*) malloc(sizeof(Tarefa));
    fp = fopen("tarefa.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    while(fread(tarefa, sizeof(Tarefa), 1, fp)) {
        if (tarefa->status == '1') {
            exibe_tarefa(tarefa);
        }
    }
    fclose(fp);
    printf("\n");
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}
void salvar_tarefa(Tarefa * tarefa){
    FILE* fp;
    fp = fopen("tarefa.dat","ab");
    if (fp == NULL) {
    printf("Erro na criacao do arquivo\n!");
    exit(1);
    }
    fwrite(tarefa, sizeof(Tarefa), 1, fp);
    fclose(fp);
    free(tarefa);
}

Tarefa * create_tarefa(void){

     Tarefa* tarefa;
    tarefa = (Tarefa*) malloc(sizeof(Tarefa));
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---              CADASTRO DA TAREFA             ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|-- Nome Da Tarefa : \n");
    fgets(tarefa->nome, sizeof(tarefa->nome), stdin);
    printf("|                                                   |\n");
    printf("|-- Descrição : \n");
    fgets(tarefa->descricao, sizeof(tarefa->descricao), stdin);
    printf("|                                                   |\n");
    printf("|-- Tipo do tarefa(ID) : \n");
    scanf("%d", &tarefa->id_tipo);
    tarefa->status = '1';
    printf("|                                                   |\n");
    printf("|___________________________________________________|\n");
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

    return tarefa;

}
void update_tarefa(void){
    char nome_tarefa [150];
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---            ATUALIZAÇÃO DA TAREFA            ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|-- informe o nome da tarefa: \n");
    fgets(nome_tarefa,150,stdin);
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}
void delete_tarefa(void){
    char nome_tarefa [150];
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---              EXCLUSÃO DA TAREFA              ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|-- informe o nome da tarefa: \n");
    fgets(nome_tarefa,150,stdin);
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}
void read_tarefa(void){
    char nome_tarefa [150];
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---               BUSCA DA TAREFA               ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|-- informe o nome da tarefa: \n");
    fgets(nome_tarefa,150,stdin);
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}