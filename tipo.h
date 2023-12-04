//Assinaturas das Funções

struct tipo_tarefa
{
    int id;
    char nome[100];
    char status;
    struct tipo_tarefa *prox;
};
typedef struct tipo_tarefa Tipo;

void op_tipo(void);
char menu_tipotarefa(void);
Tipo * create_tipo_tarefa(void);
void update_tipo_tarefa(void);
void delete_tipo_tarefa(void);
void read_tipo_tarefa(void);
void salvar_tipo(Tipo * );
void all_tipos();
void exibe_tipo(Tipo *);
void exibe_tipo_lista(Tipo *);
void editar_tipo(Tipo *);
void excluir_tipo(Tipo *);
int new_id_tipo();
void filtro_tipos();
void Lista_ordenada_alfa_tp(void);

