//Assinaturas das Funnções
struct disciplina
{
    char nome[100];
    char docente[150];
    char carga_horaria[10];
    struct disciplina *next;
};
typedef struct disciplina Disciplina;

void op_disciplina(void);
char menu_disciplina(void);
Disciplina create_disciplina(void);
void update_disciplina(void);
void delete_disciplina(void);
void read_disciplina(void);
