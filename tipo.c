#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"
#include <unistd.h>
#include "util.h"
#include <string.h>

void op_tipo(void) {
    char opcao;
    do {
        opcao = menu_tipotarefa();
        switch(opcao) {
            case '1': 	salvar_tipo(create_tipo_tarefa());
                        break;
            case '2': 	delete_tipo_tarefa();
                        break;
            case '3': 	update_tipo_tarefa();
                        break;
            case '4': 	all_tipos();
                        break;
        } 		
    } while (opcao != '0');
}

// Estrutura das Funções baseadas na ideia professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
char menu_tipotarefa(void){
    char opcao;
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK tpENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---          DIGITE A OPÇÃO DESEJADA:           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--           1 - Adicionar Tipo tarefa           --|\n");
    printf("|--           2 - Deletar Tipo tarefa             --|\n");
    printf("|--           3 - Editar  Tipo tarefa             --|\n");
    printf("|--           4 - Relatório Tipo tarefa           --|\n");
    printf("|--           0 - Sair                            --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("Digite uma opção: \n");
    scanf("%c", &opcao);
    getchar();
    return opcao;
    
    
}

//Funções de Listagem
//Função Baseada nos Slides da aula: Semana 11
void exibe_tipo(Tipo* tp) {
char situacao[20];
if ((tp == NULL) || (tp->status == '0')) {
 printf("\n= = = tarefa Inexistente = = =\n");
} else {
 printf("\n= = = Tarefa Cadastrado = = =\n");
 printf("Nome da Tarefa: %s\n", tp->nome);


if (tp->status == '1') {
 strcpy(situacao, "Ativo");
} else {
 strcpy(situacao, "Arquivado");
}
 printf("Status: %s\n", situacao);
}
}
//Função Baseada nos Slides da aula: Semana 11
void all_tipos(){
    FILE* fp;
    Tipo* tipo;
    printf("\n = Lista de Tarefas = \n");
    tipo = (Tipo*) malloc(sizeof(Tipo));
    fp = fopen("tipo.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    while(fread(tipo, sizeof(Tipo), 1, fp)) {
        if (tipo->status == '1') {
            exibe_tipo(tipo);
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
    printf("|                     CTASK tpENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---        CADASTRO TIPO DA TAREFA              ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|-- Nome Tipo tarefa: \n");
    do{
    fgets(tipo->nome, sizeof(tipo->nome), stdin);
    if(!(valida_nome(tipo->nome))){
        printf("|-- Nome inválido! \n");
        printf("|-- Nome: \n");
    }
    }while (!(valida_nome(tipo->nome)));
    tipo->status = '1';
    
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    return tipo;
}

void update_tipo_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK tpENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---     ATUALIZAÇÃO DO TIPO DA TAREFA           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--    informe o nome do Tipo do tarefa:          --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void delete_tipo_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK tpENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---          EXCLUSÃO DO TIPO DO TAREFA         ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--      informe o nome do Tipo da tarefa:        --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void read_tipo_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK tpENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---           BUSCA DO TIPO DO TAREFA           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--       informe o nome do Tipo do tarefa:       --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}