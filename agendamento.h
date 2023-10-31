//Assinaturas das Funções

struct agendamento
{
    char nome[100];
    char data_agendamento[11];
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int segundo;
    char horaria_agendamento[10];
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
void exibir_agendamento(Agendamento *);