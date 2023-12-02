#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefa.h"
#include "tipo.h"
#include "util.h"
#include <unistd.h>


void op_tarefa(void) {
    char opcao[256];
    do {
        opcao[0] = menu_tarefa();
        switch(opcao[0]) {
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
            case '6': read_tarefa();
                        break;
            case '7': filtro_tarefas();
                        break;
        } 		
    } while (opcao[0] != '0');
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
    printf("|--            6 - Busca Tarefas                  --|\n");
    printf("|--            7 - Filtrar Tarefas                --|\n");
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
 printf("Id da Tarefa: %d", tf->id);
 printf("Nome da Tarefa: %s\n", tf->nome);
 printf("Descrição da Tarefa da Tarefa: %s\n", tf->descricao);

if (tf->status == '1') {
 strcpy(situacao, "Cadastrada");
} else {
 strcpy(situacao, "Não Cadastrada");
}
 printf("Situação do Tarefa: %s\n", situacao);
}
}
void exibe_tarefa_lista(Tarefa* tf) {
if ((tf == NULL) || (tf->status == '0')) {
 printf("\n= = = Tarefa Inexistente = = =\n");
} else {
 printf("\nNome da Tarefa: %sId da Tarefa: %d\n", tf->nome,tf->id);

}
}

//Função Baseada nos Slides da aula: Semana 11
void all_tarefas(){
    FILE* fp;
    Tarefa* tarefa;
    printf("\n = Lista de Tarefas = \n");
    tarefa = (Tarefa*) malloc(sizeof(Tarefa));
    fp = fopen("tarefa.dat", "rb");
    if (fp == NULL) {
     printf("Ops! Erro na abertura do arquivo!\n");
    printf("Criar tarefa...\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return;
    }
    while(fread(tarefa, sizeof(Tarefa), 1, fp)) {
        if (tarefa->status == '1') {
            exibe_tarefa_lista(tarefa);
        }
    }
    fclose(fp);
    free(tarefa);
    printf("\n");
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}
//Função Baseada nos Slides da aula: Semana 11
void filtro_tarefas(){
    FILE* fp;
    char nome[150];
    printf("Digite o nome que deseja Buscar: \n");
    scanf("%[^\n\t]",nome);
    limpa_buffer();
    Tarefa* tarefa;
    printf("\n = Lista de tarefas filtradas por nome = \n");
    printf("\n");
    tarefa = (Tarefa*) malloc(sizeof(Tarefa));
    fp = fopen("tarefa.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Criar tarefa...\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return;
    }
    while(fread(tarefa, sizeof(Tarefa), 1, fp)) {
        if (tarefa->status == '1'  && (strstr(tarefa->nome, nome))!= NULL) {
            exibe_tarefa_lista(tarefa);
        }
    }
    fclose(fp);
    free(tarefa);
    printf("\n");
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}
//Função Baseada nos Slides da aula: Semana 11
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
//FUnção desenvolvida a partir do ChatGPT
int new_id_tarefa(){
    FILE *file = fopen("tarefa.dat", "rb+");
    if (file == NULL) {
        // Se o arquivo não existir, crie um novo
        file = fopen("tarefa.dat", "wb+");
        if (file == NULL) {
            perror("Erro ao criar o arquivo");
            return 1;
        }
    }
    int lastId = 0;

    // Encontre o último ID
    fseek(file, 0, SEEK_SET);
    while (1) {
        Tarefa record;
        size_t read_bytes = fread(&record, sizeof(Tarefa), 1, file);
        if (read_bytes == 0) {
            break;
        }
        if (record.id > lastId) {
            lastId = record.id;
        }
    }
    return lastId+1;
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
    tarefa->id = new_id_tarefa();
    printf("|-- Nome Da Tarefa : \n");
    fgets(tarefa->nome, sizeof(tarefa->nome), stdin);
    trata_string(tarefa->nome);
    printf("|                                                   |\n");
    printf("|-- Descrição : \n");
    fgets(tarefa->descricao, sizeof(tarefa->descricao), stdin);
    printf("|                                                   |\n");
    printf("|-- Tipo do tarefa(ID) : \n");
    tarefa->id_tipo = lerNumeroInteiro();
    tarefa->status = '1';
    printf("|                                                   |\n");
    printf("|___________________________________________________|\n");
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

    return tarefa;

}
void update_tarefa(void){
    Tarefa * tarefa;
    tarefa = (Tarefa*) malloc(sizeof(Tarefa));
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---            ATUALIZAÇÃO DA TAREFA            ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|-- informe o nome da tarefa: \n");
    fgets(tarefa->nome, sizeof(tarefa->nome), stdin);
    trata_string(tarefa->nome);
    printf("|___________________________________________________|\n");
    editar_tarefa(tarefa);
    printf("\n");
    free(tarefa);
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}
//Função retirada do material de aula
void excluir_tarefa(Tarefa* nome_tarefa) {
    printf("Nome1: %s\n",nome_tarefa->nome);
    
    FILE* fp;
    Tarefa* tarefa;
    int achou = 0;
    if (nome_tarefa == NULL) {
    printf("O Tarefa informado não existe!\n");
    }
    else {
    tarefa = (Tarefa*) malloc(sizeof(Tarefa));
    fp = fopen("tarefa.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Criar tarefa...\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }
    while(!feof(fp)) {
        fread(tarefa, sizeof(Tarefa), 1, fp);
        if ((*tarefa->nome == *nome_tarefa->nome) && (tarefa->status != '0')) {
            achou = 1;
            tarefa->status = '0';
            fseek(fp, -1*sizeof(Tarefa), SEEK_CUR);
            fwrite(tarefa, sizeof(Tarefa), 1, fp);
            printf("\nTarefa excluída!\n");
        }
    }
    if (!achou) {
    printf("\nTarefa não encontrada!\n");
    }
    fclose(fp);
    free(tarefa);
    }
    }

//Função retirada do material de aula
void editar_tarefa(Tarefa* nome_tarefa) {
    
    FILE* fp;
    Tarefa* tarefa;
    int achou = 0;
    if (nome_tarefa == NULL) {
    printf("O Tarefa informado não existe!\n");
    }
    else {
    tarefa = (Tarefa*) malloc(sizeof(Tarefa));
    fp = fopen("tarefa.dat", "r+b");
    if (fp == NULL) {
     printf("Ops! Erro na abertura do arquivo!\n");
    printf("Criar tarefa...\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return;
    }
    while(!feof(fp)) {
        fread(tarefa, sizeof(Tarefa), 1, fp);
        if ((*tarefa->nome == *nome_tarefa->nome) && (tarefa->status != '0')) {
            achou = 1;
            printf("Nome:\n");
            fgets(tarefa->nome, sizeof(tarefa->nome), stdin);
            trata_string(tarefa->nome);
            printf("|                                                   |\n");
            printf("|-- Descrição : \n");
            fgets(tarefa->descricao, sizeof(tarefa->descricao), stdin);
            printf("|                                                   |\n");
            printf("|-- Tipo do tarefa(ID) : \n");
            tarefa->id_tipo = lerNumeroInteiro();
            fseek(fp, -1*sizeof(Tarefa), SEEK_CUR);
            fwrite(tarefa, sizeof(Tarefa), 1, fp);
            printf("\nTarefa editada!\n");
        }
    }
    if (!achou) {
    printf("\nTarefa não encontrada!\n");
    }
    fclose(fp);
    free(tarefa);
    }
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();
    }
//replit.com/@flaviusgorgonio/AplicacaoComS
void delete_tarefa(void){
    //char nome_tarefa [150];
    Tarefa * tarefa;
    tarefa = (Tarefa*) malloc(sizeof(Tarefa));
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---              EXCLUSÃO DA TAREFA              ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|-- informe o nome da tarefa: \n");
    fgets(tarefa->nome, sizeof(tarefa->nome), stdin);
    trata_string(tarefa->nome);
    printf("|___________________________________________________|\n");
    printf("\n");
    excluir_tarefa(tarefa);
    printf("\n");
    free(tarefa);
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
    FILE* fp;
    Tarefa* tarefa;
    printf("\n = Lista de Tarefas = \n");
    tarefa = (Tarefa*) malloc(sizeof(Tarefa));
    fp = fopen("tarefa.dat", "rb");
    if (fp == NULL) {
     printf("Ops! Erro na abertura do arquivo!\n");
    printf("Criar tarefa...\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return;
    }
    while(fread(tarefa, sizeof(Tarefa), 1, fp)) {
        if ((tarefa->status == '1') && strcmp(nome_tarefa,tarefa->nome)==0) {
            exibe_tarefa(tarefa);
        }
    }
    fclose(fp);
    free(tarefa);
    printf("\n");
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}

//fseek
//ftell
//prox_id = (tamanho arq/tamanho reg)2 + 1
//prtbcc -site manipulação de arquivo