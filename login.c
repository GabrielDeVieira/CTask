#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "login.h"
#include <unistd.h>
#include <string.h>
#include "util.h"

#define True 1
#define False 0

int op_login(void) {
    char opcao[256];
    int aux = 0;
    do {
        opcao[0] = menu_login();
        if( opcao[0] == '0'){
            exit(1);
        }
        switch(opcao[0]) {
            case '1': 	if(login()){
                aux =1;
                opcao[0] = '0';
            }
                        break;
            case '2': 	salvar_user(create_users());
                        break;

        } 		
    } while (opcao[0] != '0');
    if (aux){
        return True;
    }
    return False;
}

// Estrutura das Funções baseadas na ideia professor Flávius https://github.com/FlaviusGorgonio/LinguaSolta/blob/main/ls.c
char menu_login(void){
    char opcao;
    system("clear||cls");
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---                     LOGIN                   ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--           1 - Login                           --|\n");
    printf("|--           2 - Registro                        --|\n");
    printf("|--           0 - Sair                            --|\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("Digite uma opção: \n");
    scanf("%c", &opcao);
    getchar();
    return opcao;
    
}
int login(){
    User * user;
    user = (User*) malloc(sizeof(User));
    printf(" ___________________________________________________\n");
    printf("|                     CTASK AGENDA                  |\n");
    printf("|___________________________________________________|\n");
    printf("|---                     LOGIN                   ---|\n");
    printf("|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("|--  Username: ");
    scanf("%s", user->username);
    limpa_buffer();
    printf("|                                                   |\n");
    printf("|-- Senha: ");
    scanf("%s", user->senha);
    limpa_buffer();
    printf("|                                                   |\n");
    printf("|___________________________________________________|\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    if (valida_login(user)){
        free(user);
        return True;
    }else{
        free(user);
        return False;
    }

}
int valida_login(User * usuario){
    FILE* fp;
    User* user;
    int achou = 0;
    if (usuario == NULL) {
    printf("Usuário ou senha informados estao incorretos!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return False;
    }else {
    user = (User*) malloc(sizeof(User));
    fp = fopen("user.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Erro abertura do arquivo!\n");
    printf("Não é possível continuar...\n");
    exit(1);
    }
    while(!feof(fp)) {
        fread(user, sizeof(User), 1, fp);
        if ( strcmp(user->username,usuario->username)==0 && (user->status != '0') && strcmp(user->senha,usuario->senha)==0 ) {
            achou = 1;
            free(user);
            fclose(fp);
            return True;
        }
    }
    if (!achou) {
    printf("\nUsuário ou senha informados estao incorretos!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    free(user);
    fclose(fp);
    return False;
    }
    }
    fclose(fp);
    return True;
}