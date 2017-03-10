#include <Carbon/Carbon.h>
#include <stdio.h>
#include <getopt.h>

int KrpMajor = 0;
int KrpMinor = 0;
int KrpPatch = 2;

void ChangeKeyRepeatDelay(char *Arg)
{
    int16_t Rate;
    if(sscanf(Arg, "%hd", &Rate) != 1)
    {
        fprintf(stderr, "invalid keyrepeat delay '%s'\n", Arg);
        return;
    }

    int16_t OldRate = LMGetKeyRepThresh();
    LMSetKeyRepThresh(Rate);

    char Command[256];
    snprintf(Command, sizeof(Command), "defaults write NSGlobalDomain KeyRepeat -int %hd", Rate);
    system(Command);

    printf("delay until repeat: %hd -> %hd\n", OldRate, Rate);
}

void ChangeKeyRepeatRate(char *Arg)
{
    int16_t Rate;
    if(sscanf(Arg, "%hd", &Rate) != 1)
    {
        fprintf(stderr, "invalid keyrepeat rate '%s'\n", Arg);
        return;
    }

    int16_t OldRate = LMGetKeyThresh();
    LMSetKeyThresh(Rate);

    char Command[256];
    snprintf(Command, sizeof(Command), "defaults write NSGlobalDomain InitialKeyRepeat -int %hd", Rate);
    system(Command);

    printf("keyrepeat rate: %hd -> %hd\n", OldRate, Rate);
}

int ParseArguments(int Count, char **Args)
{
    int Option;
    const char *Short = "r:d:v";
    struct option Long[] =
    {
        { "repeat-rate", required_argument, NULL, 'r' },
        { "delay-until-repeat", required_argument, NULL, 'd' },
        { "version", no_argument, NULL, 'v' },
        { NULL, 0, NULL, 0 }
    };

    while((Option = getopt_long(Count, Args, Short, Long, NULL)) != -1)
    {
        switch(Option)
        {
            case 'r':
            {
                ChangeKeyRepeatRate(optarg);
            } break;
            case 'd':
            {
                ChangeKeyRepeatDelay(optarg);
            } break;
            case 'v':
            {
                printf("krp version %d.%d.%d\n",
                        KrpMajor, KrpMinor, KrpPatch);
            } break;
        }
    }

    return 0;
}

int main(int Count, char **Args)
{
    if(Count < 2)
    {
        fprintf(stderr, "Usage: krp -r | --repeat-rate <level>\n"
                        "       krp -d | --delay-until-repeat <level>\n\n"
                        "<level>: 1 = 15ms, 2 = 30ms etc..\n");
        exit(1);
    }

    ParseArguments(Count, Args);
    return 0;
}
