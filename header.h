
struct data_t 
{
    unsigned int id_;
    char name_ [50];
};

struct node_t
{
    node_t * next_;
    data_t data_;
};

void initialize(node_t **, const char **, const unsigned int);
void print(node_t *);
void clear(node_t *);
void swap(node_t *, node_t *);
data_t find(node_t *, const char *, const unsigned int);
node_t * find_ref(node_t *, const char *, const unsigned int);
void edit(node_t *, const char *);
