//Assinaturas das Funções
struct agendamento
{
    char nome[100];
    char data_agendamento[12];
    char horaria_agendamento[10];
    int id_tarefa;
    int id_disciplina;
    char duracao_hora[10];
    struct agendamento *next;
};
typedef struct agendamento Agendamento;

void op_agendamento(void);
char menu_agendamentos(void);
Agendamento create_agendamento(void);
void update_agendamento(void);
void delete_agendamento(void);
void read_agendamento(void);
