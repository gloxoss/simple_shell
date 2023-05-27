#include "shell.h"

/**
 * change_cd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *constant function prototype.
 *  Return: Always 0
 */
int change_cd(info_t *info)
{
    char *s, *dir, buffer[1024];
    int chdir_ret;

    s = getcwd(buffer, 1024);
    if (!s)
        _puts("TODO: >>getcwd failure emsg here<<\n");
    if (!info->argv[1])
    {
        dir = get_env(info, "HOME=");
        if (!dir)
            chdir_ret = chdir((dir = get_env(info, "PWD=")) ? dir : "/");
        else
            chdir_ret = chdir(dir);
    }
    else if (_strcmp(info->argv[1], "-") == 0)
    {
        if (!get_env(info, "OLDPWD="))
        {
            _puts(s);
            _putchar('\n');
            return (1);
        }
        _puts(get_env(info, "OLDPWD=")), _putchar('\n');
        chdir_ret = chdir((dir = get_env(info, "OLDPWD=")) ? dir : "/");
    }
    else
        chdir_ret = chdir(info->argv[1]);
    if (chdir_ret == -1)
    {
        print_error(info, "can't cd to ");
        print_instr(info->argv[1]), write_chatrr('\n');
    }
    else
    {
        set_env(info, "OLDPWD", get_env(info, "PWD="));
        set_env(info, "PWD", getcwd(buffer, 1024));
    }
    return (0);
}

/**
 * help_call - help function
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int help_call(info_t *info)
{
    char **arg_array;

    arg_array = info->argv;
    _puts("help call works. Function not yet implemented \n");
    if (0)
        _puts(*arg_array);
    return (0);
}

/**
 * exit_shell - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int exit_shell(info_t *info)
{
    int exitcheck;

    if (info->argv[1])
    {
        exitcheck = error_atoi(info->argv[1]);
        if (exitcheck == -1)
        {
            info->status = 2;
            print_error(info, "Illegal number: ");
            print_instr(info->argv[1]);
            write_chatrr('\n');
            return (1);
        }
        info->err_num = error_atoi(info->argv[1]);
        return (-2);
    }
    info->err_num = -1;
    return (-2);
}