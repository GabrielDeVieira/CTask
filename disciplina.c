#include <stdio.h>
#include <stdlib.h>
#include "disciplina.h"
#include <unistd.h>
#include "util.h"

void op_disciplina(void) {
    char opcao;
    do {
        opcao = menu_disciplina();
        switch(opcao) {
            case '1': 	create_disciplina();
                        break;
            case '2': 	delete_disciplina();
                        break;
            case '3': 	update_disciplina();
                        break;
            case '4': 	read_disciplina();
                        break;
        } 		
    } while (opcao != '0');
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
    printf("|--           0 - Sair                            --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("Digite uma opção: \n");
    scanf("%c", &opcao);
    getchar();
    return opcao;
    
   
    
}
Disciplina create_disciplina(void){

    Disciplina *disciplina = malloc(sizeof(disciplina));
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---            CADASTRO DA DISCIPLINA           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
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
    printf("|                                                   |\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    

    return *disciplina;


}
void update_disciplina(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---           ATUALIZAÇÃO DA DISCIPLINA         ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o nome da disciplina:         --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void delete_disciplina(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---            EXCLUSÃO DA DISCIPLINA           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--          informe o nome da disciplina:        --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void read_disciplina(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---              BUSCA DA DISCIPLINA            ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o nome da disciplina:         --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}