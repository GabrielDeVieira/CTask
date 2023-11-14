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

//Funções de Listagem
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
if ((tp == NULL) || (tp->status == '0')) {
 printf("\n= = = Disciplina Inexistente = = =\n");
} else {
 printf("Nome da Disciplina: %s Id da disciplina: %d \n", tp->nome, tp->id);
 
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
    printf("Não é possível continuar...\n");
    exit(1);
    }
    while(fread(disciplina, sizeof(Disciplina), 1, fp)) {
        if (disciplina->status == '1') {
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
    fgets(disciplina->nome, sizeof(disciplina->nome), stdin);
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
    printf("Ops! Erro abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    int aux = 0;
    while(!aux) {
        fread(disciplina, sizeof(Disciplina), 1, fp);
        if ((disciplina->id == nome_disciplina->id) && (disciplina->status != '0')) {
            achou = 1;
            printf("|-- Nome Da Disciplina: \n");
            fgets(disciplina->nome, sizeof(disciplina->nome), stdin);
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
    printf("Ops! Erro abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
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