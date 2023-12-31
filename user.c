#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "user.h"
#include <unistd.h>
#include <string.h>

#define True 1
#define False 0

void op_users(void) {
    char opcao[256];
    do {
        opcao[0] = menu_users();
        switch(opcao[0]) {
            case '1': 	salvar_user(create_users());
                        break;
            case '2': 	delete_users();
                        break;
            case '3': 	update_users();
                        break;
            case '4': 	all_users();
                        break;
            case '5':   read_users();
                        break;
            case '6':   filtro_nome_users();
                        break;
            case '7':   Lista_ordenada_alfa();
                        break;
        } 		
    } while (opcao[0] != '0');
}


// Estrutura das Funções baseadas na ideia professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
char menu_users(void){
    char opcao;
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---           DIGITE A OPÇÃO DESEJADA:          ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--           1 - Adicionar User                  --|\n");
    printf("|--           2 - Deletar User                    --|\n");
    printf("|--           3 - Editar  User                    --|\n");
    printf("|--           4 - Relatório User                  --|\n");
    printf("|--           5 - Buscar User                     --|\n");
    printf("|--           6 - Buscar Com Filtro               --|\n");
    printf("|--           7 - Listar em Ordem Alfabetica      --|\n");
    printf("|--           0 - Sair                            --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("Digite uma opção: \n");
    scanf("%c", &opcao);
    getchar();
    return opcao;
    
   
    
}
void salvar_user(User * user){
    FILE* fp1;
    User* usuario;
    User *user1 = (User*) malloc(sizeof(User));
    fp1 = fopen("user.dat", "rb");
    if (fp1 == NULL) {
        usuario = NULL;
    }else{
        while(fread(user1, sizeof(User), 1, fp1)) {
            usuario = user1->prox;
        }
        free(user1);
    }
    FILE* fp;
    fp = fopen("user.dat","ab");
    if (fp == NULL) {
    printf("Erro na criacao do arquivo\n!");
    exit(1);
    }
    user->prox = usuario;
    fwrite(user, sizeof(User), 1, fp);
    fclose(fp);
    free(user);
}
void get_nome(char * nome){
    do{
    fgets(nome, 150, stdin);
    trata_string(nome);
    if(!(valida_nome(nome))){
        printf("|-- Nome inválido! \n");
        printf("|-- Nome: \n");
    }
    }while (!(valida_nome(nome)));
}
void get_username(char * nome){
    do{
    printf("|-- Username: \n");
    scanf("%s", nome);
    limpa_buffer();
    if(!(dado_use_exist(nome,4))){
        printf("Username ja existe... \n");
    }
    }while (!(dado_use_exist(nome,4)));
}

void get_data_nascimento(char * data){
    int dia, mes, ano;
    do
    {
      scanf("%10s", data);
      limpa_buffer();
      if (sscanf(data, "%2d/%2d/%4d", &dia, &mes, &ano) == 3) {
        if(!(valida_data(dia, mes, ano))){
            printf("|-- Data user inválida! \n");
            printf("|-- Data user(dd/mm/aaaa): \n");
        }
      }else{
        printf("|-- Data user inválida! \n");
        printf("|-- Data user(dd/mm/aaaa): \n");
      }
    } while (!(valida_data(dia, mes, ano)));
}
void get_email(char * email){
    do{
    printf("|-- Email: \n");
    do
    {
    scanf("%s", email);
    limpa_buffer();
    if (!(valida_email(email))){ 
       printf("|-- Email Inválido ! \n");
       printf("|-- Email: \n");
    } 
    
    } while (!(valida_email(email))); 
    if(!(dado_use_exist(email,3))){
        printf("Email ja existe... \n");
    }
    }while (!(dado_use_exist(email,3)) );
    
}
void get_numero(char * numero){
    do{
    printf("|-- DDD + Numero do Celular(apenas os numeros):  \n");
    do
    {
     fgets(numero, 14, stdin);
     trata_string(numero);
     if (!(valida_numero(numero))){
       printf("|-- Numero Inválido ! \n");
       printf("|-- Numero (apenas os numeros): \n");
     }
    } while (!(valida_numero(numero)));
    if(!(dado_use_exist(numero,1))){
        printf("Numero ja existe... \n");
    }
    }while (!(dado_use_exist(numero,1)) );
   
}
void get_cpf(char * cpf){
    do{
    printf("|-- CPF: \n");
    do{
    
    fgets(cpf, 14, stdin);
    trata_string(cpf);

    if (!(valida_CPF(cpf))){
        printf("|-- CPF inválido! \n");
        printf("|-- CPF: \n");
    }
    }while(!(valida_CPF(cpf)));
    if(!(dado_use_exist(cpf,2))){
        printf("CPF ja existe... \n");
    }
    }while (!(dado_use_exist(cpf,2)) );
}

//Funcao que verifica a existencia de dados na tabela de usuarios
int dado_use_exist( char* dado, int op) {
    FILE * fp;
    fp = fopen("user.dat", "rb");
    if(fp == NULL){
        fclose(fp);
        return 1;
    }
    User * lista = (User*) malloc(sizeof(User));
    if (op==1){
    while(fread(lista, sizeof(User), 1, fp)) {
        if (strcmp(lista->numero, dado) == 0 && lista->status=='1') {
            // Data  encontrada na lista
            free(lista);
            fclose(fp);
            return 0;
        }
    }
    }else if(op==2){
    while(fread(lista, sizeof(User), 1, fp)) {
        if (strcmp(lista->cpf, dado) == 0 && lista->status=='1') {
            // Data  encontrada na lista
            free(lista);
            fclose(fp);
            return 0;
        }
    }
    }else if(op ==3){
       while(fread(lista, sizeof(User), 1, fp)) {
        if (strcmp(lista->email, dado) == 0 && lista->status=='1') {
            // Data  encontrada na lista
            free(lista);
            fclose(fp);
            return 0;
        }
    } 
    }else if(op ==4){
       while(fread(lista, sizeof(User), 1, fp)) {
        if (strcmp(lista->username, dado) == 0 && lista->status=='1' ) {
            // Data  encontrada na lista
            free(lista);
            fclose(fp);
            return 0;
        }
    } 
    }
    // Data nao encontrada
    fclose(fp);
    free(lista);
    return 1;
}

User * create_users(void){
   
    User *usuario = (User*) malloc(sizeof(User));
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---            CADASTRO NOVO USUÁRIO            ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    usuario->id = new_id_user();
    printf("|-- Nome: \n");
    get_nome(usuario->nome);
    printf("|-- Data de Nascimento(dd/mm/aaaa): \n");
    get_data_nascimento(usuario->data_nascimento);
    printf("|                                                   |\n");
    get_email(usuario->email);
    printf("|                                                   |\n");
    get_numero(usuario->numero);    
    printf("|                                                   |\n");
    get_username(usuario->username);
    printf("|                                                   |\n");
    printf("|-- Senha: \n");
    scanf("%s", usuario->senha);
    limpa_buffer();
    printf("|                                                   |\n");
    get_cpf(usuario->cpf);
    usuario->status = '1';
    printf("|                                                   |\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    return usuario;

}
void exibe_user(User* tf) {
char situacao[20];
if ((tf == NULL) || (tf->status == '0')) {
 printf("\n= = = Usuário Inexistente = = =\n");
} else {
 printf("Id do Usuário: %d\n", tf->id);
 
 printf("Nome do Usuário: %s\n", tf->nome);
 printf("Data de Nascimento: %s\n", tf->data_nascimento);
 printf("Email: %s\n", tf->email);
 printf("Username: %s\n", tf->username);
 printf("Número: %s\n", tf->numero);
 

if (tf->status == '1') {
 strcpy(situacao, "Cadastrado");
} else {
 strcpy(situacao, "Não Cadastrado");
}
 printf("Situação do Usuário: %s\n", situacao);
}
}
void exibe_user_lista(User* tf) {
if ((tf == NULL)) {
 printf("\n= = = Usuário Inexistente = = =\n");
} else {
 printf("| %-5d | %-40s | %-25s | \n",tf->id, tf->nome, tf->username);
 printf("|-------|------------------------------------------|---------------------------|\n");

}
}
//FUnção desenvolvida a partir do ChatGPT
int new_id_user(){
    FILE *file = fopen("user.dat", "rb+");
    if (file == NULL) {
        // Se o arquivo não existir, crie um novo
        file = fopen("user.dat", "wb+");
        if (file == NULL) {
            perror("Erro ao criar o arquivo");
            return 1;
        }
    }
    int lastId = 0;

    // Encontre o último ID
    fseek(file, 0, SEEK_SET);
    while (1) {
        User record;
        size_t read_bytes = fread(&record, sizeof(User), 1, file);
        if (read_bytes == 0) {
            break;
        }
        if (record.id > lastId) {
            lastId = record.id;
        }
    }
    return lastId+1;
}

//Função Baseada nos Slides da aula: Semana 11
void all_users(){
    FILE* fp;
    User* user;
    
    user = (User*) malloc(sizeof(User));
    fp = fopen("user.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    return;

    }
    system("clear||cls");
    printf(" ------------------------------------------------------------------------------ \n");
    printf("|---                             LISTA DE USUARIOS                          ---|\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("| %-5s | %-40s | %-25s |\n", "ID", "Nome", "Username");
    printf("|-------|------------------------------------------|---------------------------|\n");
    while(fread(user, sizeof(User), 1, fp)) {
        if (user->status == '1') {
            exibe_user_lista(user);
        }
    }
    fclose(fp);
    free(user);
    printf("\n");
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}
//Função Baseada nos Slides da aula: Semana 11
void filtro_nome_users(){
    FILE* fp;
    char nome[150];
    printf("Digite o nome que deseja Buscar: \n");
    scanf("%[^\n\t]",nome);
    limpa_buffer();
    User* user;
    printf("\n = Lista de Usuário = \n");
    user = (User*) malloc(sizeof(User));
    fp = fopen("user.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    return;
    }
    while(fread(user, sizeof(User), 1, fp)) {
        if ((user->status == '1') && (strstr(user->nome, nome))!= NULL) {
            exibe_user_lista(user);
        }
    }
    fclose(fp);
    free(user);
    printf("\n");
    printf("\t\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();

}
//Função retirada do material de aula
void editar_user(User* nome_user) {
    
    FILE* fp;
    User* usuario;
    int achou = 0;
    if (nome_user == NULL) {
    printf("O Usuário informado não existe!\n");
    }
    else {
    usuario = (User*) malloc(sizeof(User));
    fp = fopen("user.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Erro abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    int aux =0;
    while(!aux) {
        fread(usuario, sizeof(User), 1, fp);
        if ((usuario->id == nome_user->id) && (usuario->status != '0')) {
            achou = 1;
            printf("|-- Nome: \n");
            get_nome(usuario->nome);
            printf("|-- Data de Nascimento(dd/mm/aaaa): \n");
            get_data_nascimento(usuario->data_nascimento);
            printf("|                                                   |\n");
            printf("|-- Email: \n");
            get_email(usuario->email);
            printf("|                                                   |\n");
            printf("|-- DDD + Numero do Celular(apenas os numeros):  \n");
            get_numero(usuario->numero);    
            printf("|                                                   |\n");
            printf("|-- Username: \n");
            scanf("%s", usuario->username);
            limpa_buffer();
            printf("|                                                   |\n");
            printf("|-- Senha: \n");
            scanf("%s", usuario->senha);
            limpa_buffer();
            printf("|                                                   |\n");
            printf("|-- CPF: \n");
            get_cpf(usuario->cpf);
            usuario->status = '1';
            printf("|                                                   |\n");
            printf("|___________________________________________________|\n");
            printf("\n");
            fseek(fp, -1*sizeof(User), SEEK_CUR);
            fwrite(usuario, sizeof(User), 1, fp);
            printf("\nUsuário editado!\n");
            aux = 1;
        }
    }
    if (!achou) {
    printf("\nUsuário não encontrado!\n");
    }
    fclose(fp);
    free(usuario);
}
}

void update_users(void){
    User * user;
    user = (User*) malloc(sizeof(User));
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---            ATUALIZAÇÃO DO USUÁRIO           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--           informe o id do usuário:            --|\n");
    printf("|___________________________________________________|\n");
    user->id = lerNumeroInteiro();
    printf("\n");
    editar_user(user);
    free(user);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
//Função retirada do material de aula
void excluir_user(User* id_usuario) {
   
    FILE* fp;
    User* user;
    int achou = 0;
    if (id_usuario == NULL) {
    printf("O disciplina informado não existe!\n");
    }
    else {
    user = (User*) malloc(sizeof(User));
    fp = fopen("user.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Erro abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    return;
    }
    while(!feof(fp)) {
        fread(user, sizeof(User), 1, fp);
        if ((user->id ==id_usuario->id) && (user->status != '0')) {
            achou = 1;
            user->status = '0';
            fseek(fp, -1*sizeof(User), SEEK_CUR);
            fwrite(user, sizeof(User), 1, fp);
            printf("\nUsuário excluído!\n");
        }
    }
    if (!achou) {
    printf("\nUsuário não encontrada!\n");
    }
    fclose(fp);
    free(user);
    }
    }
void delete_users(void){
    User * user;
    user = (User*) malloc(sizeof(User));
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---            EXCLUSÃO DO DO USUÁRIO           ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--            informe o id do usuário:           --|\n");
    printf("|___________________________________________________|\n");
    user->id = lerNumeroInteiro();
    excluir_user(user);
    free(user);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void read_users(void){
    int user_id;
    FILE * fp;
    User * user;
    user = (User*) malloc(sizeof(User));
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|___________________________________________________|\n");
    printf("|---              BUSCA DO DO USUÁRIO            ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--            informe o id do usuário:           --|\n");
    printf("|___________________________________________________|\n");
    user_id = lerNumeroInteiro();
    printf("\n");
    fp = fopen("user.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    while(fread(user, sizeof(User), 1, fp)) {
        if ((user->status == '1') && user_id == user->id) {
            exibe_user(user);
        }
    }
    fclose(fp);
    free(user);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
//Função desenvolvida a partir do ChatGPT e auxilio dos materiais de aula https://replit.com/@flaviusgorgonio/ExemploDeListaInvertidac#main.c
void Lista_ordenada_alfa(void) {
    FILE* fp;
    User* usuario; 
    User* lista;
    fp = fopen("user.dat", "rb"); 
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Criar Usuario...\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }
    
    lista = NULL;
    usuario = (User*)malloc(sizeof(User)); 

    system("clear||cls");
    printf(" ------------------------------------------------------------------------------ \n");
    printf("|---                             LISTA DE USUARIOS                          ---|\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("| %-5s | %-40s | %-25s |\n", "ID", "Nome", "Username");
    printf("|-------|------------------------------------------|---------------------------|\n");

    while(fread(usuario, sizeof(User), 1, fp) == 1) {
        usuario->prox = NULL;
        if ((lista == NULL) || (strcmp(usuario->nome, lista->nome) < 0)) {
            usuario->prox = lista;  
            lista = usuario;
        } else {  
            User *anterior = lista; 
            User *atual = lista->prox;
            while ((atual != NULL) && strcmp(atual->nome, usuario->nome) < 0) { 
                anterior = atual;  
                atual = atual->prox;
            }
            anterior->prox = usuario;  
            usuario->prox = atual; 
        }
        
        usuario = (User*)malloc(sizeof(User));
        
        
    }

    fclose(fp); 

    usuario = lista; 
    while (usuario != NULL) {  
        exibe_user_lista(usuario);
        usuario = usuario->prox; 
        }
        

    usuario = lista; 
    while (lista != NULL) {
        lista = lista->prox;  
        free(usuario);
        usuario = lista; 
    }
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}