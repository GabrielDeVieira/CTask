//Assinatura Funções
struct tarefa
{
    char nome[150];
    char descricao[200];
    int id_tipo;
    char status;
    
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