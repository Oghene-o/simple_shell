#include "shell.h"
/**
 * _myenv - to print the recent environ
 * @info: Struct containing potential arguments. Used to maintain
 *          constant prototype function.
 * Return: 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - always get the value of an environment variable
 * @info: Struct containing potential arguments.
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Init a new environ variable,
 *             or modify an existing one
 * @info: Struct containing potential arguments. Used to maintain
 *        constant prototype function.
 *  Return: 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect num of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
/**
 * _myunsetenv - Remove an environ variable
 * @info: Struct containing potential arguments. Used to maintain
 *        constant prototype function.
 * Return: 0
 */
int _myunsetenv(info_t *info)
{
	int z;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (z = 1; z <= info->argc; z++)
		_unsetenv(info, info->argv[z]);

	return (0);
}
/**
 * populate_env_list - populates environ linked list
 * @info: Struct containing potential arguments. Used to maintain
 *          constant prototype function.
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t z;

	for (z = 0; environ[z]; z++)
		add_node_end(&node, environ[z], 0);
	info->env = node;
	return (0);
}
