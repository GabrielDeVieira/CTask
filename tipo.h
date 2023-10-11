//Assinaturas das Funções

struct tipo_tarefa
{
    char nome[100];
};
typedef struct tipo_tarefa Tipo;

void op_tipo(void);
char menu_tipotarefa(void);
Tipo create_tipo_tarefa(void);
void update_tipo_tarefa(void);
void delete_tipo_tarefa(void);
void read_tipo_tarefa(void);
