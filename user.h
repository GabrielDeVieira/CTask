// Assinatura Funções
struct user
{
    char nome[150];
    char data_nascimento[11];
    int dia;
    int mes;
    int ano;
    char email[100];
    char numero[14];
    char username[100];
    char cpf[15];
    struct user *next;
};
typedef struct user User;

void op_users(void);
char menu_users(void);
User create_users(void);
void update_users(void);
void delete_users(void);
void read_users(void);
int ler_cpf(char*);