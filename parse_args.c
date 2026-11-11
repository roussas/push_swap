#include "push_swap.h"
#include "libft.h"

// possible flags
// strategy selector:
//      --simple
//      --medium
//      --complex
//      --adaptive
// bench mode: (display)
//      --bench
//
// 6-bit integer
// 0th: bench
// 1st: simple, [0000, 0001], [0, 1]
// 2nd: medium, [0000, 0010], [0, 2]
// 3rd: complex, [0000, 0100], [0, 4]
// 4th: adaptive, [0000, 1000], [0, 8]
// 0; 0000: adaptive, no bench mode
// 1; 0001: adaptive with bench
// 2; 0010: simple, no bench
// 3; 0011: simple, with bench
// 4, 0100: medium, no bench
// 5, 0101: medium, with bench
// 8, 1000: complex, no bench
// 9, 1001: complex, with bench

static int parsedata(const char *arg, t_node *a)
{
    // check if it is a single argument
    //      whitespace?, atoi, put on stack
    // check if it is a string in the correct format to split
    //      whitespace?, split, atoi, put on stack
    // include validation check --> call validator
    //      put on stack, mind direction (earliest arg is top of stack)
    (void )arg;
    (void )a;
    return (1);
}

static int parseflags(const char *arg, t_flag *f)
{
    int strat;

    strat = 0;
    if (!ft_strncmp(arg, "--bench", 8))
        f->bench = 1;
    else if (!ft_strncmp(arg, "--simple", 9))
        strat = 1;
    else if (!ft_strncmp(arg, "--medium", 9))
        strat = 2;
    else if (!ft_strncmp(arg, "--complex", 10))
        strat = 4;
    else if (!ft_strncmp(arg, "--adaptive", 11))
        strat = 8;
    strat = f->strategy | strat;
    if (!(strat == 0 || strat == 1 || strat == 2 || strat == 4 || strat == 8))
        return (0);
    f->strategy = strat;
    return (1);
}

static t_flag *flags_init()
{
    t_flag *f;
    f = malloc(sizeof(t_flag));
    if (f == NULL)
        return (NULL);
    f->bench = 0;
    f->strategy = 0;
    return (f);
}

static int checkarg(const char *arg)
{
    if (!ft_strncmp(arg, "--", 2))
        return ('f');
    else
        return ('d');
}

static int parseargs(int count, char **args, t_node *a, t_flag *f)
{
    int i;

    i = 1;
    while (i < count)
    {
        if (checkarg(args[i]) == 'f')
        {
            if (!parseflags(args[i], f))
                return (0);
        }
        else if (checkarg(args[i]) == 'd')
        {
            if(!parsedata(args[i], a))
                return (0);
        }
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_node *a;
    t_flag *f;

    if (argc < 2)
        return (0);
    a = NULL;
    f = flags_init();
    if (!parseargs(argc, argv, a, f))
    {
        write(2, "Error\n", 6);
        return (0);
    }
    return (1);
}