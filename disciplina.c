#include <stdio.h>
#include <stdlib.h>
#include "disciplina.h"
#include <unistd.h>
#include "util.h"
#include <string.h>

void op_disciplina(void) {
    char opcao[256];
    do {
        opcao[0] = menu_disciplina();
        switch(opcao[0]) {
            case '1': 	salvar_disciplina(create_disciplina());
                        break;
            case '2': 	delete_disciplina();
                        break;
            case '3': 	update_disciplina();
                        break;
            case '4': 	all_disciplinas();
                        break;
            case '5':   read_disciplina();
                        break;
            case '6':   filtro_disciplinas();
                        break;
            case '7':   Lista_ordenada_alfa_d();
                        break;
        } 		
    } while (opcao[0] != '0');
}

// Estrutura das Funções baseadas na ideia professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
char menu_disciplina(void){
    char opcao;
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---           DIGITE A OPÇÃO DESEJADA:          ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--           1 - Adicionar Disciplina            --|\n");
    printf("|--           2 - Deletar Disciplina              --|\n");
    printf("|--           3 - Editar  Disciplina              --|\n");
    printf("|--           4 - Relatório Disciplina            --|\n");
    printf("|--           5 - Buscar Disciplina               --|\n");
    printf("|--           6 - Filtrar Disciplina              --|\n");
    printf("|--           7 - Listar em Ordem Alfabetica      --|\n");
    printf("|--           0 - Sair                            --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("Digite uma opção: \n");
    scanf("%c", &opcao);
    getchar();
    return opcao;
    
   
    
}

//Função desenvolvida a partir do ChatGPT
int new_id_disciplina(){
    FILE *file = fopen("disciplina.dat", "rb+");
    if (file == NULL) {
        // Se o arquivo não existir, crie um novo
        file = fopen("disciplina.dat", "wb+");
        if (file == NULL) {
            perror("Erro ao criar o arquivo");
            return 1;
        }
    }
    int lastId = 0;

    // Encontre o último ID
    fseek(file, 0, SEEK_SET);
    while (1) {
        Disciplina record;
        size_t read_bytes = fread(&record, sizeof(Disciplina), 1, file);
        if (read_bytes == 0) {
            break;
        }
        if (record.id > lastId) {
            lastId = record.id;
        }
    }
    return lastId+1;
}

//Funções de exibicao de um determinado arquivo,  mostrando todos os dados existentes do mesmo.
//Função Baseada nos Slides da aula: Semana 11
void exibe_disciplina(Disciplina* tp) {
char situacao[20];
if ((tp == NULL) || (tp->status == '0')) {
 printf("\n= = = Disciplina Inexistente = = =\n");
} else {
 printf("Nome da Disciplina: %s\n", tp->nome);
 printf("Docente: %s\n", tp->docente );
 printf("Carga Horária: %s\n", tp->carga_horaria );
if (tp->status == '1') {
 strcpy(situacao, "Ativa");
} else {
 strcpy(situacao, "Arquivada");
}
 printf("Status: %s\n", situacao);
}
}
void exibe_disciplina_lista(Disciplina* tp) {
if ((tp == NULL)) {
 printf("\n= = = Disciplina Inexistente = = =\n");
} else {

 printf("| %-5d | %-40s |\n",tp->id, tp->nome);
 printf("|-------|------------------------------------------|\n");
 
}
}
//Função Baseada nos Slides da aula: Semana 11
void all_disciplinas(){
    FILE* fp;
    Disciplina* disciplina;
    printf("\n = Lista de Disciplinas = \n");
    disciplina = (Disciplina*) malloc(sizeof(Disciplina));
    fp = fopen("disciplina.dat", "rb");
    if (fp == NULL) {
     printf("Ops! Erro na abertura do arquivo!\n");
    printf("Criar disciplina...\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return;
    }
    system("clear||cls");
    printf(" ---------------------------------------------------\n");
    printf("|---          LISTA DE DISCIPLINAS              ---|\n");
    printf(" --------------------------------------------------\n");
    printf(" --------------------------------------------------\n");
    printf("| %-5s | %-40s |", "ID", "Nome");
    printf("|-------|------------------------------------------|\n");
    while(fread(disciplina, sizeof(Disciplina), 1, fp)) {
        if (disciplina->status == '1') {
            exibe_disciplina_lista(disciplina);
        }
    }
    fclose(fp);
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}
//Função Baseada nos Slides da aula: Semana 11
void filtro_disciplinas(){
    FILE* fp;
    char nome[100];
    printf("Digite o nome que deseja Buscar: \n");
    scanf("%[^\n\t]",nome);
    limpa_buffer();
    Disciplina* disciplina;
    printf("\n = Lista de Disciplinas = \n");
    disciplina = (Disciplina*) malloc(sizeof(Disciplina));
    fp = fopen("disciplina.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Criar disciplina...\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return;
    }
    while(fread(disciplina, sizeof(Disciplina), 1, fp)) {
        if (disciplina->status == '1' && (strstr(disciplina->nome, nome))!= NULL) {
            exibe_disciplina_lista(disciplina);
        }
    }
    fclose(fp);
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}
//Função de gravação em arquivo
//Função Baseada nos Slides da aula: Semana 11
void salvar_disciplina(Disciplina * disciplina){
    FILE* fp;
    fp = fopen("disciplina.dat","ab");
    if (fp == NULL) {
    printf("Erro na criacao do arquivo\n!");
    exit(1);
    }
    fwrite(disciplina, sizeof(Disciplina), 1, fp);
    fclose(fp);
    free(disciplina);
}

void get_nomed(char * nome){
    do{
    fgets(nome, 150, stdin);
    trata_string(nome);
    if(!(valida_nome(nome))){
        printf("|-- Nome inválido! \n");
        printf("|-- Nome: \n");
    }
    }while (!(valida_nome(nome)) );
}

void get_nomedc(char * nome){
    do{
    fgets(nome, 100, stdin);
    trata_string(nome);
    if(!(dado_dic_exist(nome))){
        printf("|-- Nome ja cadastrado! \n");
        printf("|-- Nome: \n");
    }
    }while (!(dado_dic_exist(nome)) );
}
//Função desenvolvida a partir do ChatGPT
int dado_dic_exist( char* dado) {
    FILE * fp;
    fp = fopen("disciplina.dat", "rb");
    if(fp == NULL){
        fclose(fp);
        return 1;
    }
    Disciplina * lista = (Disciplina*) malloc(sizeof(Disciplina));
    while(fread(lista, sizeof(Disciplina), 1, fp)) {
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

Disciplina * create_disciplina(void){

    Disciplina *disciplina = malloc(sizeof(Disciplina));
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---            CADASTRO DA DISCIPLINA           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    disciplina->id = new_id_disciplina();
    printf("|-- Nome Da Disciplina: \n");
    get_nomedc(disciplina->nome);
    printf("|                                                   |\n");
    printf("|-- Nome do Docente : \n");
    get_nomed(disciplina->docente);
    printf("|                                                   |\n");
    printf("|-- Carga Horária : \n");
    fgets(disciplina->carga_horaria, sizeof(disciplina->carga_horaria), stdin);
    disciplina->status = '1';
    printf("|                                                   |\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    

    return disciplina;


}
//Função retirada do material de aula
void editar_disciplina(Disciplina* nome_disciplina) {
    
    FILE* fp;
    Disciplina* disciplina;
    int achou = 0;
    if (nome_disciplina == NULL) {
    printf("O disciplina informado não existe!\n");
    }
    else {
    disciplina = (Disciplina*) malloc(sizeof(Disciplina));
    fp = fopen("disciplina.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Criar agendamento...\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return;
    }
    int aux = 0;
    while(!aux) {
        fread(disciplina, sizeof(Disciplina), 1, fp);
        if ((disciplina->id == nome_disciplina->id) && (disciplina->status != '0')) {
            achou = 1;
            printf("|-- Nome Da Disciplina: \n");
            fgets(disciplina->nome, sizeof(disciplina->nome), stdin);
            trata_string(disciplina->nome);
            printf("|                                                   |\n");
            printf("|-- Nome do Doscente : \n");
            do{
            fgets(disciplina->docente, sizeof(disciplina->docente), stdin);
            if(!(valida_nome(disciplina->docente))){
                printf("|-- Nome inválido! \n");
                printf("|-- Nome: \n");
            }
            }while (!(valida_nome(disciplina->docente)));
            printf("|                                                   |\n");
            printf("|-- Carga Horária : \n");
            fgets(disciplina->carga_horaria, sizeof(disciplina->carga_horaria), stdin);
            
            fseek(fp, -1*sizeof(Disciplina), SEEK_CUR);
            fwrite(disciplina, sizeof(Disciplina), 1, fp);
            printf("\nDisciplina editada!\n");
            aux = 1;
        }
    }
    if (!achou) {
    printf("\ndisciplina não encontrada!\n");
    }
    fclose(fp);
    free(disciplina);
    }
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();
    }
void update_disciplina(void){
    Disciplina * disciplina;
    disciplina = (Disciplina*) malloc(sizeof(Disciplina));
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---           ATUALIZAÇÃO DA DISCIPLINA         ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o id da disciplina:           --|\n");
    disciplina->id = lerNumeroInteiro();
    printf("|___________________________________________________|\n");
    printf("\n");
    editar_disciplina(disciplina);
    free(disciplina);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
//Função retirada do material de aula
void excluir_disciplina(Disciplina* nome_disciplina) {
   
    FILE* fp;
    Disciplina* disciplina;
    int achou = 0;
    if (nome_disciplina == NULL) {
    printf("O disciplina informado não existe!\n");
    }
    else {
    disciplina = (Disciplina*) malloc(sizeof(Disciplina));
    fp = fopen("disciplina.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Criar agendamento...\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return;
    }
    while(!feof(fp)) {
        fread(disciplina, sizeof(Disciplina), 1, fp);
        if ((disciplina->id ==nome_disciplina->id) && (disciplina->status != '0')) {
            achou = 1;
            disciplina->status = '0';
            fseek(fp, -1*sizeof(Disciplina), SEEK_CUR);
            fwrite(disciplina, sizeof(Disciplina), 1, fp);
            printf("\ndisciplina excluída!\n");
        }
    }
    if (!achou) {
    printf("\ndisciplina não encontrada!\n");
    }
    fclose(fp);
    free(disciplina);
    }
    }


void delete_disciplina(void){
    Disciplina * disciplina;
    disciplina = (Disciplina*) malloc(sizeof(Disciplina));
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---            EXCLUSÃO DA DISCIPLINA           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--          informe o id da disciplina:          --|\n");
    disciplina->id = lerNumeroInteiro();
    printf("|___________________________________________________|\n");
    excluir_disciplina(disciplina);
    free(disciplina);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void read_disciplina(void){
    FILE * fp;
    Disciplina * disciplina;
    disciplina = (Disciplina*) malloc(sizeof(Disciplina));
    int disp_id;
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---              BUSCA DA DISCIPLINA            ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o id da disciplina:           --|\n");
    printf("|___________________________________________________|\n");
    disp_id = lerNumeroInteiro();
    printf("\n");
    fp = fopen("disciplina.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    while(fread(disciplina, sizeof(Disciplina), 1, fp)) {
        if ((disciplina->status == '1') && disp_id == disciplina->id) {
            exibe_disciplina(disciplina);
        }
    }
    fclose(fp);
    free(disciplina);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void Lista_ordenada_alfa_d(void) {
    FILE* fp;
    Disciplina* disciplina; 
    Disciplina* lista;
    fp = fopen("disciplina.dat", "rb"); 
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Criar Disciplina...\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }
    
    lista = NULL;
    disciplina = (Disciplina*)malloc(sizeof(Disciplina)); 
    system("clear||cls");
    printf(" ---------------------------------------------------\n");
    printf("|---          LISTA DE DISCIPLINAS              ---|\n");
    printf(" --------------------------------------------------\n");
    printf(" --------------------------------------------------\n");
    printf("| %-5s | %-40s |\n", "ID", "Nome");
    printf("|-------|------------------------------------------|\n");

    while(fread(disciplina, sizeof(Disciplina), 1, fp) == 1) {
        disciplina->prox = NULL;
        if ((lista == NULL) || (strcmp(disciplina->nome, lista->nome) < 0)) {
            disciplina->prox = lista;  
            lista = disciplina;
        } else {  
            Disciplina *anterior = lista; 
            Disciplina *atual = lista->prox;
            while ((atual != NULL) && strcmp(atual->nome, disciplina->nome) < 0) { 
                anterior = atual;  
                atual = atual->prox;
            }
            anterior->prox = disciplina;  
            disciplina->prox = atual; 
        }
        
        disciplina = (Disciplina*)malloc(sizeof(Disciplina));
        
        
    }

    fclose(fp); 

    disciplina = lista; 
    while (disciplina != NULL) {  
        exibe_disciplina_lista(disciplina);
        disciplina = disciplina->prox; 
        }
        

    disciplina = lista; 
    while (lista != NULL) {
        lista = lista->prox;  
        free(disciplina);
        disciplina = lista; 
    }
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}