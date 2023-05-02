typedef enum { typeCon, typeId, typeOpr } nodeEnum;

/* constants */
typedef struct {
 double value; /* value of constant */
} conNodeType;

/* identifiers */
typedef struct {
char* i; /* subscript to sym array */
} idNodeType;
/* operators */
typedef struct {
 int oper; /* operator */
 int nops; /* number of operands */
 struct nodeTypeTag **op; /* operands */
} oprNodeType;
typedef struct nodeTypeTag {
 nodeEnum type; /* type of node */
 union {
 conNodeType con; /* constants */
 idNodeType id; /* identifiers */
 oprNodeType opr; /* operators */
 };
} nodeType;
typedef struct dataType {
    char *id_name;
    double value;
} sym;
typedef struct stl{
    int symbol_table_itr;
    sym symbol_table[20];
} symtab;
typedef struct func {
    char* func_name;
    int num_parem;
    char* parem_list[10];
    nodeType *root;
} functab;
typedef struct obj_node {
    char* obj_name;
    int data_index;
    sym obj_data[20];
    int func_index;
    functab obj_func[20];
} object_node;
typedef struct c {
    char* cls_name;
    int obj_cnt;
    object_node objtab[10]; 
} cls;