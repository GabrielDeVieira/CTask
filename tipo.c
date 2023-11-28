#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"
#include <unistd.h>
#include "util.h"
#include <string.h>

void op_tipo(void) {
    char opcao[256];
    do {
        opcao[0] = menu_tipotarefa();
        switch(opcao[0]) {
            case '1': 	salvar_tipo(create_tipo_tarefa());
                        break;
            case '2': 	delete_tipo_tarefa();
                        break;
            case '3': 	update_tipo_tarefa();
                        break;
            case '4': 	all_tipos();
                        break;
            case '5':   read_tipo_tarefa();
                        break;
            case '6':  filtro_tipos();
                        break;
        } 		
    } while (opcao[0] != '0');
}
//Função desenvolvida a partir do ChatCPT
int new_id_tipo(){
    FILE *file = fopen("tipo.dat", "rb+");
    if (file == NULL) {
        // Se o arquivo não existir, crie um novo
        file = fopen("tipo.dat", "wb+");
        if (file == NULL) {
            perror("Erro ao criar o arquivo");
            return 1;
        }
    }
    int lastId = 0;

    // Encontre o último ID
    fseek(file, 0, SEEK_SET);
    while (1) {
        Tipo record;
        size_t read_bytes = fread(&record, sizeof(Tipo), 1, file);
        if (read_bytes == 0) {
            break;
        }
        if (record.id > lastId) {
            lastId = record.id;
        }
    }
    return lastId+1;
}
// Estrutura das Funções baseadas na ideia professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
char menu_tipotarefa(void){
    char opcao;
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---          DIGITE A OPÇÃO DESEJADA:           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--           1 - Adicionar Tipo tarefa           --|\n");
    printf("|--           2 - Deletar Tipo tarefa             --|\n");
    printf("|--           3 - Editar  Tipo tarefa             --|\n");
    printf("|--           4 - Relatório Tipo tarefa           --|\n");
    printf("|--           5 - Busca Tipo tarefa               --|\n");
    printf("|--           6 - Filtrar Tipo tarefa             --|\n");
    printf("|--           0 - Sair                            --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("Digite uma opção: \n");
    scanf("%c", &opcao);
    getchar();
    return opcao;
    
    
}
//Função retirada do material de aula
void excluir_tipo(Tipo* nome_tipo) {   
    FILE* fp;
    Tipo* tarefa;
    int achou = 0;
    if (nome_tipo == NULL) {
    printf("O Tarefa informado não existe!\n");
    }
    else {
    tarefa = (Tipo*) malloc(sizeof(Tipo));
    fp = fopen("tipo.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Erro abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    while(!feof(fp)) {
        fread(tarefa, sizeof(Tipo), 1, fp);
        if ((tarefa->id == nome_tipo->id) && (tarefa->status != '0')) {
            achou = 1;
            tarefa->status = '0';
            fseek(fp, -1*sizeof(Tipo), SEEK_CUR);
            fwrite(tarefa, sizeof(Tipo), 1, fp);
            printf("\nTipo da tarefa excluída!\n");
        }
    }
    if (!achou) {
    printf("\nTipo da tarefa não encontrada!\n");
    }
    fclose(fp);
    free(tarefa);
    }
    }

//Função retirada do material de aula
void editar_tipo(Tipo* nome_tipo) {
    
    FILE* fp;
    Tipo* tarefa;
    int achou = 0;
    if (nome_tipo == NULL) {
    printf("O Tipo da tarefa informado não existe!\n");
    }
    else {
    tarefa = (Tipo*) malloc(sizeof(Tipo));
    fp = fopen("tipo.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Erro abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    while(!feof(fp)) {
        fread(tarefa, sizeof(Tipo), 1, fp);
        if ((tarefa->id == nome_tipo->id) && (tarefa->status != '0')) {
            achou = 1;
            printf("Nome:\n");
            fgets(tarefa->nome, sizeof(tarefa->nome), stdin);
            trata_string(tarefa->nome);
            fseek(fp, -1*sizeof(Tipo), SEEK_CUR);
            fwrite(tarefa, sizeof(Tipo), 1, fp);
            printf("\nTarefa editada!\n");
        }
    }
    if (!achou) {
    printf("\nTipo da tarefa não encontrada!\n");
    }
    fclose(fp);
    free(tarefa);
}
}
    


//Funções de Listagem
//Função Baseada nos Slides da aula: Semana 11
void exibe_tipo(Tipo* tp) {
char situacao[20];
if ((tp == NULL) || (tp->status == '0')) {
 printf("\n= = = |Tipo da tarefa Inexistente = = =\n");
} else {
 printf("\n= = = Tipo da tarefa Cadastrado = = =\n");
 printf("Nome da Tarefa: %s\n", tp->nome);
 printf("Id do Tipo da tarefa: %d\n", tp->id);

if (tp->status == '1') {
 strcpy(situacao, "Ativo");
} else {
 strcpy(situacao, "Arquivado");
}
 printf("Status: %s\n", situacao);
}
}
void exibe_tipo_lista(Tipo* tp) {
if ((tp == NULL) || (tp->status == '0')) {
 printf("\n= = = |Tipo da tarefa Inexistente = = =\n");
} else {
 printf("Nome da Tarefa: %s Id do Tipo da tarefa: %d\n", tp->nome,tp->id);

}
}
//Função Baseada nos Slides da aula: Semana 11
void filtro_tipos(){
    FILE* fp;
    char nome[100];
    printf("Digite o nome que deseja Buscar: \n");
    scanf("%[^\n\t]",nome);
    limpa_buffer();
    Tipo* tipo;
    printf("\n = Lista Filtarda de Tipos de Tarefas por nome = \n");
    tipo = (Tipo*) malloc(sizeof(Tipo));
    fp = fopen("tipo.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    while(fread(tipo, sizeof(Tipo), 1, fp)) {
        if (tipo->status == '1' && (strstr(tipo->nome, nome))!= NULL) {
            exibe_tipo_lista(tipo);
        }
    }
    fclose(fp);
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}
//Função Baseada nos Slides da aula: Semana 11
void all_tipos(){
    FILE* fp;
    Tipo* tipo;
    printf("\n = Lista de Tipos de Tarefas = \n");
    tipo = (Tipo*) malloc(sizeof(Tipo));
    fp = fopen("tipo.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    while(fread(tipo, sizeof(Tipo), 1, fp)) {
        if (tipo->status == '1') {
            exibe_tipo_lista(tipo);
        }
    }
    fclose(fp);
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}

//Função de gravação em arquivo
//Função Baseada nos Slides da aula: Semana 11
void salvar_tipo(Tipo * tipo){
    FILE* fp;
    fp = fopen("tipo.dat","ab");
    if (fp == NULL) {
    printf("Erro na criacao do arquivo\n!");
    exit(1);
    }
    fwrite(tipo, sizeof(Tipo), 1, fp);
    fclose(fp);
    free(tipo);
}

Tipo * create_tipo_tarefa(void){

    Tipo *tipo = malloc(sizeof(Tipo));
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---        CADASTRO TIPO DA TAREFA              ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    tipo->id = new_id_tipo();
    printf("|-- Nome Tipo tarefa: \n");
    fgets(tipo->nome, sizeof(tipo->nome), stdin);
    trata_string(tipo->nome); 
    tipo->status = '1';   
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    return tipo;
}

void update_tipo_tarefa(void){
    Tipo * tipo;
    tipo = (Tipo*) malloc(sizeof(Tipo));
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---     ATUALIZAÇÃO DO TIPO DA TAREFA           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--    informe o id do Tipo do tarefa:            --|\n");
    tipo->id = lerNumeroInteiro();
    printf("|___________________________________________________|\n");
    printf("\n");
    editar_tipo(tipo);
    free(tipo);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void delete_tipo_tarefa(void){
    Tipo * tipo;
    tipo = (Tipo*) malloc(sizeof(Tipo));
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---          EXCLUSÃO DO TIPO DO TAREFA         ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--      informe o id do Tipo da tarefa:          --|\n");
    tipo->id = lerNumeroInteiro();
    printf("|___________________________________________________|\n");
    excluir_tipo(tipo);
    free(tipo);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void read_tipo_tarefa(void){
    FILE * fp;
    Tipo * tipo;
    tipo = (Tipo*) malloc(sizeof(Tipo));
    int tipo_id;
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---           BUSCA DO TIPO DO TAREFA           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--       informe o id do Tipo do tarefa:         --|\n");
    printf("|___________________________________________________|\n");
    tipo_id = lerNumeroInteiro();
    printf("\n");
    fp = fopen("tipo.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    while(fread(tipo, sizeof(Tipo), 1, fp)) {
        if ((tipo->status == '1') && tipo_id == tipo->id) {
            exibe_tipo(tipo);
        }
    }
    fclose(fp);
    free(tipo);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}