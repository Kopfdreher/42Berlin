#ifndef VBC_H
# define VBC_H

# include <stdlib.h>
# include <ctype.h>

// 1. The AST Node structure
typedef struct node
{
    enum {
        ADD,
        MULTI,
        VAL
    } type;
    int val;
    struct node *l;
    struct node *r;
} node;

// 2. Helper functions provided by given.c
node    *new_node(node n);
void    destroy_tree(node *n);
void    unexpected(char c);
int     accept(char **s, char c);
int     expect(char **s, char c);

// 3. The main function you are required to write
node    *parse_expr(char *s);

#endif
