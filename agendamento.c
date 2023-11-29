#include <stdio.h>
#include <stdlib.h>
#include "agendamento.h"
#include <unistd.h>
#include "util.h"
#include <string.h>
#include <time.h>
#include "tarefa.h"
#include "disciplina.h"

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
            case '6':   filtro_agendamentos();
                        break;
            case '7':   matriz_agendamento();
                        printf("\n");
                        printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
                        getchar();
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
    printf("|--            6 - Filtrar Agendamentos           --|\n");
    printf("|--            7 - Agendamentos da Semana         --|\n");
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
FILE* fp;
FILE* fp1;
fp = fopen("tarefa.dat", "rb");
fp1 = fopen("disciplina.dat", "rb");
Tarefa * tarefa = (Tarefa*) malloc(sizeof(Tarefa));
Disciplina * d = (Disciplina*) malloc(sizeof(Disciplina));

if ((ag == NULL) || (ag->status == '0')) {
 printf("\n= = = tarefa Inexistente = = =\n");
} else {
 printf("\n= = = Tarefa Cadastrado = = =\n");
 printf("Nome da Tarefa: %s\n", ag->nome);
 printf("Data do Agndamento: %s\n", ag->data_agendamento);
 while(fread(tarefa, sizeof(Tarefa), 1, fp)) {
        if ((ag->id_tarefa == tarefa->id) && (tarefa->status != '0')) {
            printf("Tarefa do Agendamento: %s\n", tarefa->nome);
            fclose(fp);
            break;
        }
    }
while(fread(d, sizeof(Disciplina), 1, fp1)){
        if ((ag->id_disciplina == d->id) && (d->status != '0')) {
            printf("Disciplina : %s\n", d->nome);
            fclose(fp1);
            break;
        }
    }
 
 printf("Horário do Agndamento: %d\n", ag->horario);
if (ag->status == '1') {
 strcpy(situacao, "Novo");
} else {
 strcpy(situacao, "Arquivado");
}
 printf("Situação do agendamento: %s\n", situacao);
}
free(tarefa);
free(d);
}
void exibe_agendamento_lista(Agendamento* ag) {
FILE* fp;
FILE* fp1;
fp = fopen("tarefa.dat", "rb");
fp1 = fopen("disciplina.dat", "rb");
Tarefa * tarefa = (Tarefa*) malloc(sizeof(Tarefa));
Disciplina * d = (Disciplina*) malloc(sizeof(Disciplina));
if ((ag == NULL) || (ag->status == '0')) {
 printf("\n= = = tarefa Inexistente = = =\n");
} else {
 
 printf("Nome: %s ", ag->nome);
 printf(" Data: %11s ",  ag->data_agendamento);
 printf(" Id : %d", ag->id);
 while(fread(tarefa, sizeof(Tarefa), 1, fp)) {
        if ((ag->id_tarefa == tarefa->id) && (tarefa->status != '0')) {
            printf(" Tarefa : %s", tarefa->nome);
            fclose(fp);
            break;
        }
    }
while(fread(d, sizeof(Disciplina), 1, fp1)){
        if ((ag->id_disciplina == d->id) && (d->status != '0')) {
            printf(" Disciplina : %s\n", d->nome);
            fclose(fp1);
            break;
        }
    }
printf("-----------------------------------------------------------------------------------------------------\n");
free(d);
free(tarefa);
}
}
//Função Baseada nos Slides da aula: Semana 11
void filtro_agendamentos(){
    FILE* fp;
    char data[11];
    printf("Digite a data que deseja buscar(dd/mm/aaaa): ");
    scanf("%10s", data);
    getchar();
    Agendamento* agendamento;
    printf("\n = Filtragem dos Agendamentos por Data = \n");
    printf("\n");
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));
    fp = fopen("agendamento.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    while(fread(agendamento, sizeof(Agendamento), 1, fp)) {
        if (agendamento->status == '1' && (strstr(agendamento->data_agendamento, data))!= NULL) {
            exibe_agendamento_lista(agendamento);
        }
    }
    fclose(fp);
    printf("\n");
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}
//Função Baseada nos Slides da aula: Semana 11
void all_agendamentos(){
    FILE* fp;
    Agendamento* agendamento;
    printf("\t\t\t = Lista de Agendamentos = \n");
    printf("\n");
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

void get_data(char * data){
    int dia, mes, ano;
    do
    {
      scanf("%10s", data);
      limpa_buffer();
      if (sscanf(data, "%2d/%2d/%4d", &dia, &mes, &ano) == 3) {
        if(!(valida_data(dia, mes, ano))){
            printf("|-- Data Agendamento inválida! \n");
            printf("|-- Data Agendamento(dd/mm/aaaa): \n");
        }
      }else{
        printf("|-- Data Agendamento inválida! \n");
        printf("|-- Data Agendamento(dd/mm/aaaa): \n");
      }
    } while (!(valida_data(dia, mes, ano)));
}

//Função Desenvolvida com auxilio do ChatGPT
void matriz_agendamento(){
    Agendamento *agendamento = malloc(sizeof(Agendamento));
    FILE* fp1;
    fp1 = fopen("agendamento.dat","ab");
    if (fp1 == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    fclose(fp1);
    time_t t;
    struct tm *infoTempo;
    time(&t);
    infoTempo = localtime(&t);
    // Obtendo o dia da semana (0 = Domingo, 1 = Segunda, ..., 6 = Sábado)
    int diaSemana = infoTempo->tm_wday;
    // Calculando o início da semana (domingo)
    t -= diaSemana * 24 * 60 * 60;
    infoTempo = localtime(&t);
    //infoTempo->tm_year += 1900;
    //infoTempo->tm_mon += 1;
    
    int **matriz = (int **)malloc(16 * sizeof(int *));
    for (int i = 0; i < 16; i++) {
        matriz[i] = (int *)malloc(7 * sizeof(int));
    }
    // Exibindo a semana
    printf("Agendamentos já cadastradas na semana:\n");
    printf(" ______________________________________________________________________________\n");
    printf(" | Horarios      1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10 |11 |12 |13 |14 |15 |16 |\n");
    printf(" |_________________|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|\n");
    for (int i = 0; i < 7; i++) {
        char dataString[11];
        strftime(dataString, sizeof(dataString), "%d/%m/%Y", infoTempo);
        printf(" | %s ->", dataString);
        // Avançando para o próximo dia
        t += 24 * 60 * 60;
        infoTempo = localtime(&t);
        for (int j = 0; j < 16; j++) {
            FILE* fp;
            fp = fopen("agendamento.dat", "rb");
            int vaux = 1;
            while(fread(agendamento, sizeof(Agendamento), 1, fp)) {
                if (agendamento->status == '1' && ((strstr(agendamento->data_agendamento, dataString))!= NULL)
                && agendamento->horario == (j+1)) {
                    printf(" x |");
                    vaux =0;
                    break;
                }
            
            }
            if (vaux){
                printf("   |");
            }
            fclose(fp);
        }
        printf("\n");
        printf(" -------------------------------------------------------------------------------\n");
    }
    free(matriz);
    free(agendamento);

}
void get_id_tarefa(int  ag){
    FILE* fp;
    fp = fopen("tarefa.dat", "rb");
    int vaux = 1;
     Tarefa *tarefa = malloc(sizeof(Tarefa));
     while(!feof(fp) && vaux) {
        ag = lerNumeroInteiro();
        fread(tarefa, sizeof(Tarefa), 1, fp);
        if ((ag == tarefa->id) && (tarefa->status != '0')) {
            fclose(fp);
            vaux = 0;
        }else{
            printf("Tarefa nao encontrada, digite um id valido \n");
        }

    }

}
void get_id_disciplina(int  ag){
    FILE* fp;
    fp = fopen("disciplina.dat", "rb");
    int vaux = 1;
     Disciplina *d = malloc(sizeof(Disciplina));
     ag = lerNumeroInteiro();
     while(!feof(fp) && vaux) {
        fread(d, sizeof(Disciplina), 1, fp);
        if ((ag == d->id) && (d->status != '0')) {
            fclose(fp);
            vaux = 0;
        }else{
            printf("Disciplina nao encontrada, digite um id valido \n");
        }
    }

}
Agendamento * create_agendamento(void){
    matriz_agendamento();
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    Agendamento *agendamento = malloc(sizeof(Agendamento));
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
    trata_string(agendamento->nome);
    printf("|-- Data Agendamento(dd/mm/aaaa) : \n");
    get_data(agendamento->data_agendamento);
    printf("|-- Tarefa(ID) : \n");
    get_id_tarefa(agendamento->id_tarefa);
    printf("|-- Disciplina(ID) : \n");
    get_id_disciplina(agendamento->id_disciplina);
    printf("|-- Horario da Tarefa (1 a 16): \n");
    agendamento->horario = lerNumeroInteiro();
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
            printf("|-- Nome : \n");
            fgets(agendamento->nome, sizeof(agendamento->nome), stdin);
            printf("|-- Data Agendamento(dd/mm/aaaa) : \n");
            get_data(agendamento->data_agendamento);
            printf("|-- Tarefa(ID) : \n");
            agendamento->id_tarefa = lerNumeroInteiro();
            printf("|-- Disciplina(ID) : \n");
            agendamento->id_disciplina = lerNumeroInteiro();
            printf("|-- Horario da Tarefa (1 a 16): \n");
            agendamento->horario = lerNumeroInteiro();
            agendamento->status = '1';
            printf("|___________________________________________________|\n");
                    
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
