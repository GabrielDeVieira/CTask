#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include "agendamento.h"
#include "tarefa.h"
#include "tipo.h"
#include "login.h"
#include "user.h"
#include "disciplina.h"

#define True 1
#define False 0

// Utilização da boa prática de assinatura das funções, ideia código professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
char menu_principal(void);
void sobre(void);
void equipe(void);

//Função Principal
int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    char opcao[256];
    int log = 0;
    do {
        if (!log){
            op_login();
            log = 1;
        }else{
            opcao[0] = menu_principal();
            switch(opcao[0]) {
                case '1': 	op_agendamento();
                            break;
                case '2': 	op_tarefa();
                            break;
                case '3': 	op_disciplina();
                            break;
                case '4':   op_users();
                            break;
                case '5': 	sobre();
                            break;
                case '6': 	equipe();
                            break;
            } 
        }
        		
    } while (opcao[0] != '0');
    
    return 0;
}

char menu_principal(void){
    char opcao1;
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---          DIGITE A OPÇÃO DESEJADA:           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--            1 - Menu Agendamentos              --|\n");
    printf("|--            2 - Menu Tarefas                   --|\n");
    printf("|--            3 - Menu Disciplina                --|\n");
    printf("|--            4 - Menu Usuários                  --|\n");
    printf("|--            5 - Sobre                          --|\n");
    printf("|--            6 - Equipe                         --|\n");
    printf("|--            0 - Sair                           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("Digite uma opção: \n");
    scanf("%c", &opcao1);
    getchar();
    return opcao1;
    
    

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
    printf("|-   Desenvolvimento de uma Agenda de Compromissos para estudantes,     -|\n");
    printf("|-   mais especificamente estudantes da universidade onde se tem 16     -|\n");
    printf("|-   horários da manhâ até a noite.                                     -|\n");
    printf("|-    o seu usuário vai poder tipificar esses determinados Compromissos -|\n");
    printf("|-   (Tendo a liberdade de nomer o tipo da atividade). Além de todas as -|\n");
    printf("|-   funcionalidades de uma agenda, como: criar um Compromisso e poder  -|\n");
    printf("|-   agenda-lo.                                                         -|\n");
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

