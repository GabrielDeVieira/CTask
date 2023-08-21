#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Utilização da boa prática de assinatura das funÃ§Ãµes, ideia código professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
void menu_principal(void);
void menu_compromisso(void);
void menu_agendamentos(void);
void menu_statuscompromisso(void);
void menu_tipocompromisso(void);
void sobre(void);
void equipe(void);

//FunÃ§Ãµes de Menu
// Estrutura das FunÃ§Ãµes baseadas na ideia professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
int true = 1;
int false = 0;

//Função Principal
int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    int aux = true;
    while (aux){
       menu_principal();
       int op;
       printf("Digite uma Opção: ");
       scanf(" %d", &op);
       if ( op == 1){
        menu_agendamentos();
       } else if (op == 2){
        menu_compromisso();
        int aux1 = true;
        while (aux1){
            int op1;
            printf("Digite uma Opção: ");
            scanf(" %d", &op1);
            if (op1 == 6){
                menu_statuscompromisso();
                printf("Digite uma Opção: ");
                scanf(" %d", &op1);
                aux1 = false;
            } else if (op1 == 7){
                menu_tipocompromisso();
                printf("Digite uma Opção: ");
                scanf(" %d", &op1);
                aux1 = false;
            }else{
                aux1 = false;
            }
        }
       }else if (op == 3){
        sobre();
       }else if(op == 4){
        equipe();
       } else {
        break;
       }

    }
    
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
    printf("|--            2 - Menu Compromissos              --|\n");
    printf("|--            3 - Sobre                          --|\n");
    printf("|--            4 - Equipe                         --|\n");
    printf("|--            0 - Sair                           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    
    

}

void menu_compromisso(void){

    system("clear||cls");
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
    printf("|--            6 - Menu Status Compromisso        --|\n");
    printf("|--            7 - Menu Tipo Compromisso          --|\n");
    printf("|--            0 - Sair                           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");

}
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
    printf("|--            0 - Sair                           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    

}
void menu_statuscompromisso(void){
    system("clear||cls");
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
    system("clear||cls");
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
