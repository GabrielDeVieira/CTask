//Assinatura Funções
struct tarefa
{
    int id;
    char nome[150];
    char descricao[200];
    int id_tipo;
    char status;
    struct tarefa *prox;
    
};
typedef struct tarefa Tarefa;
void op_tarefa(void);
char menu_tarefa(void);
Tarefa * create_tarefa(void);
void salvar_tarefa(Tarefa *);
void update_tarefa(void);
void delete_tarefa(void);
void read_tarefa(void);
void all_tarefas(void);
void exibe_tarefa(Tarefa *);
void exibe_tarefa_lista(Tarefa *);
void excluir_tarefa(Tarefa *);
void editar_tarefa(Tarefa *);
int new_id_tarefa();
void filtro_tarefas();
void Lista_ordenada_alfa_t(void);
void get_nometf(char *);
int dado_tf_exist( char* );