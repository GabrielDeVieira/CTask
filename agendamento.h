//Assinaturas das Funções

struct agendamento
{
    int id;
    char nome[100];
    char data_agendamento[11];
    char horaria_agendamento[9];
    int id_tarefa;
    int id_disciplina;
    int duracao_hora;
    char status;
    struct agendamento *next;
};

typedef struct agendamento Agendamento;

void op_agendamento(void);
char menu_agendamentos(void);
Agendamento * create_agendamento(void);
void salvar_agendamento (Agendamento *);
void update_agendamento(void);
void delete_agendamento(void);
void read_agendamento(void);
void all_agendamentos();
void exibe_agendamento(Agendamento *);
void exibe_agendamento(Agendamento *);
void exibe_agendamento_lista(Agendamento *);
void editar_agendamento(Agendamento *);
void excluir_agendamento(Agendamento *);
int new_id_agendamento();
void filtro_agendamentos();