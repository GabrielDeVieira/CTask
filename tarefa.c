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
            case '8': Lista_ordenada_alfa_t();
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
    printf("|--            8 - Listar em Ordem Alfabetica     --|\n");
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
FILE * fp;
fp = fopen("tipo.dat", "rb");
Tipo * ttarefa = (Tipo*) malloc(sizeof(Tipo));
if ((tf == NULL) || (tf->status == '0')) {
 printf("\n Tarefa Inexistente...");
} else {
 printf("\nId da Tarefa: %d\n", tf->id);
 printf("Nome da Tarefa: %s\n", tf->nome);
 printf("Descrição da Tarefa da Tarefa: %s\n", tf->descricao);
while(fread(ttarefa, sizeof(Tipo), 1, fp)) {
        if ((tf->id_tipo == ttarefa->id) && (ttarefa->status != '0')) {
            printf("Tipo da Tarefa: %s\n", ttarefa->nome);
            break;
        }
    }
fclose(fp);
free(ttarefa);
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
 printf("\n Tarefa Inexistente...");
} else {
  printf("| %-5d | %-40s |\n",tf->id, tf->nome);
  printf("|-------|------------------------------------------|\n");
 

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
    system("clear||cls");
    printf(" --------------------------------------------------\n");
    printf("|---              LISTA DE TAREFAS              ---|\n");
    printf(" --------------------------------------------------\n");
    printf(" --------------------------------------------------\n");
    printf("| %-5s | %-40s |\n", "ID", "Nome");
    printf("|-------|------------------------------------------|\n");
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
    tarefa = (Tarefa*) malloc(sizeof(Tarefa));
    fp = fopen("tarefa.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Criar tarefa...\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return;
    }
    system("clear||cls");
    printf(" ---------------------------------------------------\n");
    printf("|---              LISTA DE TAREFAS               ---|\n");
    printf(" --------------------------------------------------\n");
    printf(" --------------------------------------------------\n");
    printf("| %-5s | %-40s |\n", "ID", "Nome");
    printf("|-------|------------------------------------------|\n");
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
    if (tarefa->id_tipo == 0){
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Verificar Informações que Foram indicadas durante a execucao...\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }
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
void get_nometf(char * nome){
    do{
    fgets(nome, 150, stdin);
    trata_string(nome);
    
    if(!(dado_tf_exist(nome))){
        printf("|-- Nome ja cadastrado! \n");
        printf("|-- Nome: \n");
    }
    }while (!(dado_tf_exist(nome)) );
}

int dado_tf_exist( char* dado) {
    FILE * fp;
    fp = fopen("tarefa.dat", "rb");
    if(fp == NULL){
        fclose(fp);
        return 1;
    }
    Tarefa * lista = (Tarefa*) malloc(sizeof(Tarefa));
    while(fread(lista, sizeof(Tarefa), 1, fp)) {
        if (strcmp(lista->nome, dado) == 0 && lista->status=='1') {
            // Data  encontrada na lista
            free(lista);
            fclose(fp);
            return 0;
        }
    }
    // Data nao encontrada
    fclose(fp);
    free(lista);
    return 1;
}


int get_id_tipo(){
    int  ag;
    int vaux = 1;
     Tipo *tarefa = malloc(sizeof(Tipo));
     do{
        FILE* fp;
        fp = fopen("tipo.dat", "rb");
        ag = lerNumeroInteiro();
        if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Criar Tipo de Tarefa...\n");
        ag =0;
        return ag;
        }
     while(!feof(fp) && vaux) {
        fread(tarefa, sizeof(Tipo), 1, fp);
        if ((ag == tarefa->id) && (tarefa->status != '0')) {
            fclose(fp);
            vaux = 0;
            return ag;
        }
    }
    if(vaux){
            printf("Tipo de Tarefa nao encontrada, digite um id valido \n");
            fclose(fp);
        }
    }while(vaux);
    return 0;

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
    get_nometf(tarefa->nome);
    printf("|                                                   |\n");
    printf("|-- Descrição : \n");
    fgets(tarefa->descricao, sizeof(tarefa->descricao), stdin);
    printf("|                                                   |\n");
    printf("|-- Tipo do tarefa(ID) : \n");
    tarefa->id_tipo = get_id_tipo();
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
        if ((strcmp(tarefa->nome, nome_tarefa->nome) == 0) && (tarefa->status != '0')) {
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
        if (strcmp(tarefa->nome, nome_tarefa->nome) == 0 && (tarefa->status != '0')){
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
    trata_string(nome_tarefa);
    printf("|___________________________________________________|\n");
    FILE* fp;
    Tarefa* tarefa;
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
void Lista_ordenada_alfa_t(void) {
    FILE* fp;
    Tarefa* tarefa; 
    Tarefa* lista;
    fp = fopen("tarefa.dat", "rb"); 
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Criar tarefa...\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }
    
    lista = NULL;
    tarefa = (Tarefa*)malloc(sizeof(Tarefa)); 

    system("clear||cls");
    printf(" --------------------------------------------------- \n");
    printf("|---               LISTA DE TAREFAS              ---|\n");
    printf(" --------------------------------------------------- \n");

    while(fread(tarefa, sizeof(Tarefa), 1, fp) == 1) {
        tarefa->prox = NULL;
        if ((lista == NULL) || (strcmp(tarefa->nome, lista->nome) < 0)) {
            tarefa->prox = lista;  
            lista = tarefa;
        } else {  
            Tarefa *anterior = lista; 
            Tarefa *atual = lista->prox;
            while ((atual != NULL) && strcmp(atual->nome, tarefa->nome) < 0) { 
                anterior = atual;  
                atual = atual->prox;
            }
            anterior->prox = tarefa;  
            tarefa->prox = atual; 
        }
        
        tarefa = (Tarefa*)malloc(sizeof(Tarefa));
        
        
    }

    fclose(fp); 

    tarefa = lista; 
    while (tarefa != NULL) {  
        exibe_tarefa_lista(tarefa);
        tarefa = tarefa->prox; 
        }
        

    tarefa = lista; 
    while (lista != NULL) {
        lista = lista->prox;  
        free(tarefa);
        tarefa = lista; 
    }
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}