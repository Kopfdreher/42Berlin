#include "vbc.h"

node	*parse_addition(char **s);
node	*parse_multiplication(char **s);
node	*parse_factor(char **s);

node	*parse_expr(char *s)
{
// 1. Parse to Add
	node *ret = parse_addition(&s);

// 2. Check Output for Null or unexpected
	if (!ret)
		return (NULL);
	if (*s != '\0')
	{
		unexpected(*s);
		destroy_tree(ret);
		return (NULL);
	}
	return (ret);
}

node	*parse_addition(char **s)
{
	node *left;
	node *right;
	node tmp;

	// 3. Add: give left to MULT
	left = parse_multiplication(s);
	if (!left)
		return (NULL);
	// 4. Add: while accept(s, '+') give right to MULT
	while (accept(s, '+'))
	{
		right = parse_multiplication(s);
		if (!right)
		{
			destroy_tree(left);
			return (NULL);
		}
	// 5. Add: fill node + return
		tmp.type = ADD;
		tmp.val = 0;
		tmp.l = left;
		tmp.r = right;
		left = new_node(tmp);
	}
	return (left);
}

node	*parse_multiplication(char **s)
{
	node *left;
	node *right;
	node tmp;

	// 6. Mult: give left to FACT
	left = parse_factor(s);
	if (!left)
		return (NULL);
	// 7. Mult: while accept(s, '*') give right to FACT
	while (accept(s, '*'))
	{
		right = parse_factor(s);
		if (!right)
		{
			destroy_tree(left);
			return (NULL);
		}
	// 8. Mult: fild node + return
		tmp.type = MULTI;
		tmp.val = 0;
		tmp.l = left;
		tmp.r = right;
		left = new_node(tmp);
	}
	return (left);
}

node	*parse_factor(char **s)
{
	node *n;
	node tmp;

	// 9. Fact: if accept(s, '('), parse_addition(s)
	if (accept(s, '('))
	{
		n = parse_addition(s);
		if (!n)
			return (NULL);
	// 9. Fact: if !expect(s,')', destroy
		if (!expect(s, ')'))
		{
			destroy_tree(n);
			return (NULL);
		}
		return (n);
	}
	// 10. Fact: if digit, fill node
	if (isdigit(**s))
	{
		tmp.type = VAL;
		tmp.val = **s - '0';
		tmp.l = NULL;
		tmp.r = NULL;

		(*s)++;
		return (new_node(tmp));
	}
	// 11. Fact: unexpected(**s)
	unexpected(**s);
	return (NULL);
}
