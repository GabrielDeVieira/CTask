#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Limpeza de terminal desenvolvido com a ajuda do ChatGPT
#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

void clearTerminal() {
    system(CLEAR_SCREEN);
}
// Utilização da boa prática de assinatura das funções, ideia código professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
void menu_principal(void);
void menu_compromisso(void);
void menu_agendamentos(void);
void menu_statuscompromisso(void);
void menu_tipocompromisso(void);
void sobre(void);
void equipe(void);
void create_compromisso(void);
void create_status_compromisso(void);
void create_tipo_compromisso(void);
void update_compromisso(void);
void update_status_compromisso(void);
void update_tipo_compromisso(void);
void delete_compromisso(void);
void delete_status_compromisso(void);
void delete_tipo_compromisso(void);
void read_compromisso(void);
void read_status_compromisso(void);
void read_tipo_compromisso(void);

//Funções de Menu
// Estrutura das Funções baseadas na ideia professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
int true = 1;
int false = 0;

//Função Principal
int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil");
    menu_principal();
    menu_compromisso();
    menu_agendamentos();
    menu_statuscompromisso();
    menu_tipocompromisso();
    sobre();
    equipe();
    create_compromisso();
    create_status_compromisso();
    create_tipo_compromisso();
    update_compromisso();
    update_status_compromisso();
    update_tipo_compromisso();
    delete_compromisso();
    delete_status_compromisso();
    delete_tipo_compromisso();
    read_compromisso();
    read_status_compromisso();
    read_tipo_compromisso();
    
    // int aux = true;
    // while (aux){
    //    menu_principal();
    //    int op;
    //    printf("Digite uma Opção: ");
    //    scanf(" %d", &op);
    //    if ( op == 1){
    //     menu_agendamentos();
    //     int op2;
    //     printf("Digite uma Opção: ");
    //     scanf(" %d", &op2);
    //    } else if (op == 2){
    //     menu_compromisso();
    //     int aux1 = true;
    //     while (aux1){
    //         int op1;
    //         printf("Digite uma Opção: ");
    //         scanf(" %d", &op1);
    //         if (op1 == 6){
    //             menu_statuscompromisso();
    //             printf("Digite uma Opção: ");
    //             scanf(" %d", &op1);
    //             aux1 = false;
    //         } else if (op1 == 7){
    //             menu_tipocompromisso();
    //             printf("Digite uma Opção: ");
    //             scanf(" %d", &op1);
    //             aux1 = false;
    //         }else{
    //             aux1 = false;
    //         }
    //     }
    //    }else if (op == 3){
    //     sobre();
    //    }else if(op == 4){
    //     equipe();
    //    } else {
    //     break;
    //    }

    // }
    
    return 0;
}

void menu_principal(void){
    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---          DIGITE A OPÇÃO DESEJADA:           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--            1 - Menu Agendamentos              --|\n");
    printf("|--            2 - Menu Compromissos              --|\n");
    printf("|--            3 - Sobre                          --|\n");
    printf("|--            4 - Equipe                         --|\n");
    printf("|--            0 - Sair                           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
    

}

void menu_compromisso(void){

    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---          DIGITE A OPÇÃO DESEJADA:           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--            1 - Adcionar Compromisso           --|\n");
    printf("|--            2 - Deletar Compromissos           --|\n");
    printf("|--            3 - Editar  Compromissos           --|\n");
    printf("|--            4 - Relatório Compromissos         --|\n");
    printf("|--            5 - Procurar Compromisso           --|\n");
    printf("|--            6 - Menu Tipo Compromisso          --|\n");
    printf("|--            0 - Sair                           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
//Creates
void create_compromisso(void){
    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---          CADASTRO DO COMPROMISSO            ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--               Nome:                           --|\n");
    printf("|--               Descrição:                      --|\n");
    printf("|--               Tipo do Compromisso(ID):        --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void create_status_compromisso(void){
    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---       CADASTRO STATUS DO COMPROMISSO        ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--            Nome Status Compromisso:           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void create_tipo_compromisso(void){
    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---        CADASTRO TIPO DO COMPROMISSO         ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--             Nome Tipo Compromisso:            --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
//Updates
void update_compromisso(void){
    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---         ATUALIZAÇÃO DO COMPROMISSO          ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o nome do compromisso:        --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void update_status_compromisso(void){
    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---    ATUALIZAÇÃO DO STATUS DO COMPROMISSO     ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--   informe o nome do Status do compromisso:    --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void update_tipo_compromisso(void){
    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---     ATUALIZAÇÃO DO TIPO DO COMPROMISSO      ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--    informe o nome do Tipo do compromisso:     --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
//Deletes
void delete_compromisso(void){
    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---           EXCLUSÃO DO COMPROMISSO           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o nome do compromisso:        --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void delete_status_compromisso(void){
    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---      EXCLUSÃO DO STATUS DO COMPROMISSO      ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--   informe o nome do Status do compromisso:    --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void delete_tipo_compromisso(void){
    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---       EXCLUSÃO DO TIPO DO COMPROMISSO       ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--    informe o nome do Tipo do compromisso:     --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
//Read
void read_compromisso(void){
    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---             BUSCA DO COMPROMISSO            ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o nome do compromisso:        --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void read_status_compromisso(void){
    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---        BUSCA DO STATUS DO COMPROMISSO       ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--   informe o nome do Status do compromisso:    --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void read_tipo_compromisso(void){
    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---         BUSCA DO TIPO DO COMPROMISSO        ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--    informe o nome do Tipo do compromisso:     --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
//Menus Principais
void menu_agendamentos(void){
    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---          DIGITE A OPÇÃO DESEJADA:           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--            1 - Adicionar Agendamento          --|\n");
    printf("|--            2 - Deletar Agendamento            --|\n");
    printf("|--            3 - Editar  Agendamento            --|\n");
    printf("|--            4 - Relatório Agendamentos         --|\n");
    printf("|--            5 - Procurar Agendamento           --|\n");
    printf("|--            6 - Menu Status Compromisso        --|\n");
    printf("|--            0 - Sair                           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
   

}
void menu_statuscompromisso(void){
    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---          DIGITE A OPÇÃO DESEJADA:           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--           1 - Adicionar Status Compromisso    --|\n");
    printf("|--           2 - Deletar Status Compromisso      --|\n");
    printf("|--           3 - Editar  Status Compromisso      --|\n");
    printf("|--           4 - Relatório Status Compromisso    --|\n");
    printf("|--           5 - Procurar Status Compromisso     --|\n");
    printf("|--           0 - Sair                            --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
   
    
}
void menu_tipocompromisso(void){
    clearTerminal();
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---          DIGITE A OPÇÃO DESEJADA:           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--           1 - Adicionar Tipo Compromisso      --|\n");
    printf("|--           2 - Deletar Tipo Compromisso        --|\n");
    printf("|--           3 - Editar  Tipo Compromisso        --|\n");
    printf("|--           4 - Relatório Tipo Compromisso      --|\n");
    printf("|--           5 - Procurar Tipo Compromisso       --|\n");
    printf("|--           0 - Sair                            --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
    
}

// menu baseado no codigo do professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
void sobre(void){
    clearTerminal();
    printf(" ________________________________________________________________________\n");
    printf("|                               CTASK AGENDA                             |\n");
    printf("|________________________________________________________________________|\n");
    printf("|---                             CERES UFRN                           ---|\n");
    printf("|---             Projeto da Disciplina DCT1106 - Programação          ---|\n");
    printf("|---             CTASK: Uma Agenda de Tarefas e Compromissos          ---|\n");
    printf("|---              Desenvolvido por Gabriel de Araújo Vieira           ---|\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("|                                                                        |\n");
    printf("|---                           Descrição CTASK                        ---|\n");
    printf("|                                                                        |\n");
    printf("|-   O projeto é o método principal de avaliação da disciplina DCT1106  -|\n");
    printf("|-   Programação. Como o próprio nome sugere o projeto diz respeito ao  -|\n");
    printf("|-   Desenvolvimento de uma Agenda de Compromissos, onde o seu usuário  -|\n");
    printf("|-   vai poder tipificar esses determinados compromissos (Tendo a li-   -|\n");
    printf("|-   berdade de nomer o tipo da atividade), enxergar o status do mesmo  -|\n");
    printf("|-   (com a mesma liberdade de excolher o status, por exemplo: 'novo'   -|\n");
    printf("|-   e 'concluído'). Além de todas as funcionalidades de uma agenda,    -|\n");
    printf("|-   como: criar um compromisso e poder agenda-lo.                      -|\n");
    printf("|________________________________________________________________________|\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

// menu baseado no codigo do professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
void equipe(void){
    clearTerminal();
    printf(" ________________________________________________________________________\n");
    printf("|                               CTASK AGENDA                             |\n");
    printf("|________________________________________________________________________|\n");
    printf("|---                             CERES UFRN                           ---|\n");
    printf("|---             Projeto da Disciplina DCT1106 - Programação          ---|\n");
    printf("|---             CTASK: Uma Agenda de Tarefas e Compromissos          ---|\n");
    printf("|---              Desenvolvido por Gabriel de Araújo Vieira           ---|\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("|                                                                        |\n");
    printf("|---                           Desenvolvedor:                         ---|\n");
    printf("|                                                                        |\n");
    printf("|           Nome: Gabriel de Araújo Vieira                               |\n");
    printf("|           Redes Sociais: @araujovieiragabriel                          |\n");
    printf("|           Email: gabrieldeviei@gmail.com                               |\n");
    printf("|           git: https://github.com/GabrielDeVieira/CTask.git            |\n");
    printf("|________________________________________________________________________|\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
}
