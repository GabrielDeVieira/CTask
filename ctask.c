#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Utilização da boa prática de assinatura das funções, ideia código professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
void menu_principal(void);
void menu_tarefa(void);
void menu_agendamentos(void);
void menu_statustarefa(void);
void menu_tipotarefa(void);
void sobre(void);
void equipe(void);
void create_tarefa(void);
void create_status_tarefa(void);
void create_tipo_tarefa(void);
void create_agendamento(void);
void update_tarefa(void);
void update_agendamento(void);
void update_status_tarefa(void);
void update_tipo_tarefa(void);
void delete_tarefa(void);
void delete_status_tarefa(void);
void delete_tipo_tarefa(void);
void delete_agendamento(void);
void read_tarefa(void);
void read_status_tarefa(void);
void read_tipo_tarefa(void);
void read_agendamento(void);

//Funções de Menu
// Estrutura das Funções baseadas na ideia professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c

//Função Principal
int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil");
    menu_principal();
    menu_tarefa();
    menu_agendamentos();
    menu_statustarefa();
    menu_tipotarefa();
    sobre();
    equipe();

    create_agendamento();
    create_tarefa();
    create_status_tarefa();
    create_tipo_tarefa();

    update_agendamento();
    update_tarefa();
    update_status_tarefa();
    update_tipo_tarefa();

    delete_agendamento();
    delete_tarefa();
    delete_status_tarefa();
    delete_tipo_tarefa();

    read_agendamento();
    read_tarefa();
    read_status_tarefa();
    read_tipo_tarefa();
    
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
    //     menu_tarefa();
    //     int aux1 = true;
    //     while (aux1){
    //         int op1;
    //         printf("Digite uma Opção: ");
    //         scanf(" %d", &op1);
    //         if (op1 == 6){
    //             menu_statustarefa();
    //             printf("Digite uma Opção: ");
    //             scanf(" %d", &op1);
    //             aux1 = false;
    //         } else if (op1 == 7){
    //             menu_tipotarefa();
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
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---          DIGITE A OPÇÃO DESEJADA:           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--            1 - Menu Agendamentos              --|\n");
    printf("|--            2 - Menu Tarefas                   --|\n");
    printf("|--            3 - Sobre                          --|\n");
    printf("|--            4 - Equipe                         --|\n");
    printf("|--            0 - Sair                           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
    

}

void menu_tarefa(void){

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
    printf("|--            5 - Procurar tarefa                --|\n");
    printf("|--            6 - Menu Tipo tarefa               --|\n");
    printf("|--            0 - Sair                           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
//Creates
void create_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---          CADASTRO DA TAREFA                 ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--               Nome:                           --|\n");
    printf("|--               Descrição:                      --|\n");
    printf("|--               Tipo do tarefa(ID):             --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void create_status_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---       CADASTRO STATUS DA TAREFA             ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--            Nome Status tarefa:                --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void create_tipo_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---        CADASTRO TIPO DA TAREFA              ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--             Nome Tipo tarefa:                 --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void create_agendamento(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---          CADASTRO DO AGENDAMENTO            ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--               Nome:                           --|\n");
    printf("|--               Data Agendamento:               --|\n");
    printf("|--               Status Tarefa(ID):              --|\n");
    printf("|--               Horario Agendamento:            --|\n");
    printf("|--               Tarefa(ID):                     --|\n");
    printf("|--               Duracao Compromisso(Hora):      --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
//Updates
void update_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---         ATUALIZAÇÃO DA TAREFA               ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o nome do tarefa:             --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void update_agendamento(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---         ATUALIZAÇÃO DA AGENDAMENTO          ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o id do Agendamento:          --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
}
void update_status_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---    ATUALIZAÇÃO DO STATUS DA TAREFA          ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--   informe o nome do Status do tarefa:         --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void update_tipo_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
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
//Deletes
void delete_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---           EXCLUSÃO DOA TAREFA               ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o nome do tarefa:             --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void delete_agendamento(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---           EXCLUSÃO DO AGENDAMENTO           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o id do Agendamento:          --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void delete_status_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---          EXCLUSÃO DO STATUS DA TAREFA       ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--      informe o nome do Status do tarefa:      --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void delete_tipo_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
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
//Read
void read_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---                BUSCA DA TAREFA              ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o nome dA tarefa:             --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void read_agendamento(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---                BUSCA DO AGENDAMENTO         ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--         informe o id do Agndamento:           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void read_status_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---           BUSCA DO STATUS DA TAREFA         ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--    informe o nome do Status do tarefa:        --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void read_tipo_tarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
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
//Menus Principais
void menu_agendamentos(void){
    system("clear||cls");
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
    printf("|--            6 - Menu Status Tarefa             --|\n");
    printf("|--            0 - Sair                           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
   

}
void menu_statustarefa(void){
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---          DIGITE A OPÇÃO DESEJADA:           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--           1 - Adicionar Status tarefa         --|\n");
    printf("|--           2 - Deletar Status tarefa           --|\n");
    printf("|--           3 - Editar  Status tarefa           --|\n");
    printf("|--           4 - Relatório Status tarefa         --|\n");
    printf("|--           5 - Procurar Status tarefa          --|\n");
    printf("|--           0 - Sair                            --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
   
    
}
void menu_tipotarefa(void){
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
    printf("|--           5 - Procurar Tipo tarefa            --|\n");
    printf("|--           0 - Sair                            --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
    
}

// menu baseado no codigo do professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
void sobre(void){
    system("clear||cls");
    printf(" ________________________________________________________________________\n");
    printf("|                               CTASK AGENDA                             |\n");
    printf("|________________________________________________________________________|\n");
    printf("|---                             CERES UFRN                           ---|\n");
    printf("|---             Projeto da Disciplina DCT1106 - Programação          ---|\n");
    printf("|---             CTASK: Uma Agenda de Compromissos e Tarefas          ---|\n");
    printf("|---              Desenvolvido por Gabriel de Araújo Vieira           ---|\n");
    printf("|------------------------------------------------------------------------|\n");
    printf("|                                                                        |\n");
    printf("|---                           Descrição CTASK                        ---|\n");
    printf("|                                                                        |\n");
    printf("|-   O projeto é o método principal de avaliação da disciplina DCT1106  -|\n");
    printf("|-   Programação. Como o próprio nome sugere o projeto diz respeito ao  -|\n");
    printf("|-   Desenvolvimento de uma Agenda de Compromissos, onde o seu usuário  -|\n");
    printf("|-   vai poder tipificar esses determinados Compromissos (Tendo a li-   -|\n");
    printf("|-   berdade de nomer o tipo da atividade), enxergar o status do mesmo  -|\n");
    printf("|-   (com a mesma liberdade de excolher o status, por exemplo: 'novo'   -|\n");
    printf("|-   e 'concluído'). Além de todas as funcionalidades de uma agenda,    -|\n");
    printf("|-   como: criar um Compromisso e poder agenda-lo.                      -|\n");
    printf("|________________________________________________________________________|\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

// menu baseado no codigo do professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
void equipe(void){
    system("clear||cls");
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

