// Assinatura Funções
struct user
{
    int id;
    char nome[150];
    char data_nascimento[11];
    int dia;
    int mes;
    int ano;
    char email[100];
    char numero[12];
    char senha[20];
    char username[100];
    char cpf[15];
    char status;
    struct user *next;
};
typedef struct user User;

void op_users(void);
char menu_users(void);
User * create_users(void);
void update_users(void);
void delete_users(void);
void read_users(void);
void salvar_user(User * );
int ler_cpf(char*);
void all_users(void);
void filtro_nome_users(void);
void exibe_user(User *);
void exibe_user_lista(User *);
void excluir_user(User *);
void editar_user(User *);
int new_id_user();
void get_nome(char *);
void get_data_nascimento(char *);
void get_email(char *);
void get_numero(char *);
void  get_cpf(char * );
