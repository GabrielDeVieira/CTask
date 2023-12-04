//Assinaturas das Funnções
struct disciplina
{
    int id;
    char nome[100];
    char docente[150];
    char carga_horaria[10];
    char status;
    struct disciplina *prox;
};
typedef struct disciplina Disciplina;

void op_disciplina(void);
char menu_disciplina(void);
Disciplina * create_disciplina(void);
void update_disciplina(void);
void delete_disciplina(void);
void read_disciplina(void);
void salvar_disciplina(Disciplina * );
void all_disciplinas();
void exibe_disciplina(Disciplina *);
void exibe_disciplina_lista(Disciplina *);
void editar_disciplina(Disciplina *);
void excluir_disciplina(Disciplina *);
int new_id_disciplina();
void filtro_disciplinas();
void get_nomed(char *);
void Lista_ordenada_alfa_d(void);