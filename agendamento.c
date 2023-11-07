#include <stdio.h>
#include <stdlib.h>
#include "agendamento.h"
#include <unistd.h>
#include "util.h"
#include <string.h>

// Estrutura das Funções baseadas na ideia professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
void op_agendamento(void) {
    char opcao[256];
    do {
        opcao[0] = menu_agendamentos();
        switch(opcao[0]) {
            case '1':   salvar_agendamento(create_agendamento());
                        break;
            case '2': 	delete_agendamento();
                        break;
            case '3': 	update_agendamento();
                        break;
            case '4': 	all_agendamentos();
                        break;
            case '5':   read_agendamento();
                        break;

        } 		
    } while (opcao[0] != '0');
}
char menu_agendamentos(void){
    char opcao1;

    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---           DIGITE A OPÇÃO DESEJADA:          ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--            1 - Adicionar Agendamento          --|\n");
    printf("|--            2 - Deletar Agendamento            --|\n");
    printf("|--            3 - Editar  Agendamento            --|\n");
    printf("|--            4 - Relatório Agendamentos         --|\n");
    printf("|--            5 - Buscar Agendamentos            --|\n");
    printf("|--            0 - Sair                           --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("Digite uma opção: \n");
    scanf("%c", &opcao1);
    getchar();
    return opcao1;
   

}
int new_id_agendamento(){
    FILE *file = fopen("agendamento.dat", "rb+");
    if (file == NULL) {
        // Se o arquivo não existir, crie um novo
        file = fopen("agendamento.dat", "wb+");
        if (file == NULL) {
            perror("Erro ao criar o arquivo");
            return 1;
        }
    }
    int lastId = 0;

    // Encontre o último ID
    fseek(file, 0, SEEK_SET);
    while (1) {
        Agendamento record;
        size_t read_bytes = fread(&record, sizeof(Agendamento), 1, file);
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
void exibe_agendamento(Agendamento* ag) {
char situacao[20];
if ((ag == NULL) || (ag->status == '0')) {
 printf("\n= = = tarefa Inexistente = = =\n");
} else {
 printf("\n= = = Tarefa Cadastrado = = =\n");
 printf("Nome da Tarefa: %s\n", ag->nome);
 printf("Data do Agndamento: %s\n", ag->data_agendamento);
 printf("Horário do Agndamento: %s\n", ag->horaria_agendamento);
 printf("Tarefa do Agendamento: %d\n", ag->id_tarefa);
 printf("Duração do Agendamento: %d horas\n", ag->duracao_hora);

if (ag->status == '1') {
 strcpy(situacao, "Novo");
} else {
 strcpy(situacao, "Arquivado");
}
 printf("Situação do agendamento: %s\n", situacao);
}
}
void exibe_agendamento_lista(Agendamento* ag) {
if ((ag == NULL) || (ag->status == '0')) {
 printf("\n= = = tarefa Inexistente = = =\n");
} else {
 
 printf("Nome da Tarefa: %s Data: %s Id agendamento: %d\n", ag->nome, ag->data_agendamento, ag->id);
 
}
}
//Função Baseada nos Slides da aula: Semana 11
void all_agendamentos(){
    FILE* fp;
    Agendamento* agendamento;
    printf("\n = Lista de Tarefas = \n");
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));
    fp = fopen("agendamento.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    while(fread(agendamento, sizeof(Agendamento), 1, fp)) {
        if (agendamento->status == '1') {
            exibe_agendamento_lista(agendamento);
        }
    }
    fclose(fp);
    printf("\n");
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}

//Função de gravação em arquivo
//Função Baseada nos Slides da aula: Semana 11
void salvar_agendamento(Agendamento * agendamento){
    FILE* fp;
    fp = fopen("agendamento.dat","ab");
    if (fp == NULL) {
    printf("Erro na criacao do arquivo\n!");
    exit(1);
    }
    fwrite(agendamento, sizeof(Agendamento), 1, fp);
    fclose(fp);
    free(agendamento);
}

Agendamento * create_agendamento(void){
    Agendamento *agendamento = malloc(sizeof(Agendamento));
    int dia, mes, ano, hora, minuto, segundo;
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---           CADASTRO DO AGENDAMENTO           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    agendamento->id = new_id_agendamento();
    printf("|-- Nome : \n");
    fgets(agendamento->nome, sizeof(agendamento->nome), stdin);
    printf("|-- Data Agendamento(dd/mm/aaaa) : \n");
    do
    {
      //scanf("%d/%d/%d", &agendamento->dia, &agendamento->mes, &agendamento->ano);
      scanf("%10s", agendamento->data_agendamento);
      getchar();
      if (sscanf(agendamento->data_agendamento, "%2d/%2d/%4d", &dia, &mes, &ano) == 3) {
        if(!(valida_data(dia, mes, ano))){
            printf("|-- Data Agendamento inválida! \n");
            printf("|-- Data Agendamento(dd/mm/aaaa): \n");
        }
      }else{
        printf("|-- Data Agendamento inválida! \n");
        printf("|-- Data Agendamento(dd/mm/aaaa): \n");
      }
    } while (!(valida_data(dia, mes, ano)));

    printf("|-- Horario Agendamento(hh:mm:ss): \n");
    do
    {
      scanf("%8s", agendamento->horaria_agendamento);
      getchar();
      if(sscanf(agendamento->horaria_agendamento,"%2d:%2d:%2d", &hora, &minuto, &segundo) == 3){
        if(!(valida_hora(hora, minuto, segundo))){
            printf("|-- Horario Agendamento inválida! \n");
            printf("|-- Horario Agendamento(hh:mm:ss): \n");
        }
      }else{
        printf("|-- Horario Agendamento inválida! \n");
        printf("|-- Horario Agendamento(hh:mm:ss): \n");
      }
    } while (!(valida_hora(hora, minuto, segundo)));

    printf("|-- Tarefa(ID) : \n");
    agendamento->id_tarefa = lerNumeroInteiro();
    printf("|-- Disciplina(ID) : \n");
    agendamento->id_disciplina = lerNumeroInteiro();
    printf("|-- Duracao Compromisso(Hora): \n");
    agendamento->duracao_hora = lerNumeroInteiro();
    agendamento->status = '1';
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    return agendamento;

}

//Função retirada do material de aula
void editar_agendamento(Agendamento* nome_agendamento) {
    
    FILE* fp;
    Agendamento* agendamento;
    int achou = 0;
    if (nome_agendamento == NULL) {
    printf("O agendamento da tarefa informado não existe!\n");
    }
    else {
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));
    fp = fopen("agendamento.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Erro abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    int aux =0;
    while(!aux) {
        fread(agendamento, sizeof(Agendamento), 1, fp);
        if ((agendamento->id == nome_agendamento->id) && (agendamento->status != '0')) {
            achou = 1;
            int dia, mes, ano, hora, minuto, segundo;
            printf("|-- Nome : \n");
            fgets(agendamento->nome, sizeof(agendamento->nome), stdin);
            printf("|-- Data Agendamento(dd/mm/aaaa) : \n");
            do
            {
            //scanf("%d/%d/%d", &agendamento->dia, &agendamento->mes, &agendamento->ano);
            scanf("%10s", agendamento->data_agendamento);
            getchar();
            if (sscanf(agendamento->data_agendamento, "%2d/%2d/%4d", &dia, &mes, &ano) == 3) {
                if(!(valida_data(dia, mes, ano))){
                    printf("|-- Data Agendamento inválida! \n");
                    printf("|-- Data Agendamento(dd/mm/aaaa): \n");
                }
            }else{
                printf("|-- Data Agendamento inválida! \n");
                printf("|-- Data Agendamento(dd/mm/aaaa): \n");
            }
            } while (!(valida_data(dia, mes, ano)));

            printf("|-- Horario Agendamento(hh:mm:ss): \n");
            do
            {
            scanf("%8s", agendamento->horaria_agendamento);
            getchar();
            if(sscanf(agendamento->horaria_agendamento,"%2d:%2d:%2d", &hora, &minuto, &segundo) == 3){
                if(!(valida_hora(hora, minuto, segundo))){
                    printf("|-- Horario Agendamento inválida! \n");
                    printf("|-- Horario Agendamento(hh:mm:ss): \n");
                }
            }else{
                printf("|-- Horario Agendamento inválida! \n");
                printf("|-- Horario Agendamento(hh:mm:ss): \n");
            }
            } while (!(valida_hora(hora, minuto, segundo)));

            printf("|-- Tarefa(ID) : \n");
            agendamento->id_tarefa = lerNumeroInteiro();
            printf("|-- Disciplina(ID) : \n");
            agendamento->id_disciplina = lerNumeroInteiro();
            printf("|-- Duracao Compromisso(Hora): \n");
            agendamento->duracao_hora = lerNumeroInteiro();
            
            fseek(fp, -1*sizeof(Agendamento), SEEK_CUR);
            fwrite(agendamento, sizeof(Agendamento), 1, fp);
            printf("\nTarefa editada!\n");
            aux = 1;
        }
    }
    if (!achou) {
    printf("\nagendamento da tarefa não encontrada!\n");
    }
    fclose(fp);
    free(agendamento);
}
}


void update_agendamento(void){
    Agendamento * agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---          ATUALIZAÇÃO DO AGENDAMENTO         ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|-- informe o id do Agendamento: \n");
    agendamento->id = lerNumeroInteiro();
    printf("|___________________________________________________|\n");
    printf("\n");
    editar_agendamento(agendamento);
    free(agendamento);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

//Função retirada do material de aula
void excluir_agendamento(Agendamento* nome_agendamento) {
   
    FILE* fp;
    Agendamento* agendamento;
    int achou = 0;
    if (nome_agendamento == NULL) {
    printf("O disciplina informado não existe!\n");
    }
    else {
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));
    fp = fopen("agendamento.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Erro abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    while(!feof(fp)) {
        fread(agendamento, sizeof(Agendamento), 1, fp);
        if ((agendamento->id ==nome_agendamento->id) && (agendamento->status != '0')) {
            achou = 1;
            agendamento->status = '0';
            fseek(fp, -1*sizeof(Agendamento), SEEK_CUR);
            fwrite(agendamento, sizeof(Agendamento), 1, fp);
            printf("\nAgendamento excluído!\n");
        }
    }
    if (!achou) {
    printf("\nAgendamento não encontrada!\n");
    }
    fclose(fp);
    free(agendamento);
    }
    }

void delete_agendamento(void){
    Agendamento* agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---           EXCLUSÃO DO AGENDAMENTO           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|-- informe o id do Agendamento: \n");
    agendamento->id = lerNumeroInteiro();
    printf("|___________________________________________________|\n");
    excluir_agendamento(agendamento);
    free(agendamento);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();


}

void read_agendamento(void){
    FILE * fp;
    Agendamento * agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));
    int id_agendamento;
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---             BUSCA DO AGENDAMENTO            ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|-- informe o id do Agendamento: \n");
    id_agendamento= lerNumeroInteiro();
    printf("|___________________________________________________|\n");
    fp = fopen("agendamento.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    while(fread(agendamento, sizeof(Agendamento), 1, fp)) {
        if ((agendamento->status == '1') && id_agendamento == agendamento->id) {
            exibe_agendamento(agendamento);
        }
    }
    fclose(fp);
    free(agendamento);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
