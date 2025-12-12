#include <cstring>
#include "MessagingSubsystem.h"

static const char* const msgtexts[] = {
    "",
    "",
#undef pick
#define pick( code, string )  string,
#include "lnkerror.msg"
#include "wlink.msg"
#include "rc.msg"
#undef pick

}; 

MessagingSubsystem::MessagingSubsystem()
{
}	

MessagingSubsystem::~MessagingSubsystem()
{
}			

void MessagingSubsystem::ResetMsg( void )
{
}

int MessagingSubsystem::Msg_Get( int resourceid, char buffer[] )
{
    strcpy(buffer, msgtexts[resourceid]);
    return(0);
} 

void MessagingSubsystem::Msg_Do_Put_Args(char rc_buff[], MSG_ARG_LIST* arg_info, char* types, ...)
{
    va_list     args;

    va_start(args, types);
    Msg_Put_Args(rc_buff, arg_info, types, &args);
    va_end(args);
}

static void Msg_Add_Arg(MSG_ARG* arginfo, char typech, va_list* args)
{
    switch (typech) {
        case 's':
            arginfo->string = va_arg(*args, char*);
            break;
        case 'x':
        case 'd':
            arginfo->int_16 = va_arg(*args, unsigned int);
            break;
        case 'l':
            arginfo->int_32 = va_arg(*args, unsigned long);
            break;
        case 'A':
        case 'a':
            arginfo->address = va_arg(*args, targ_addr*);
            break;
        case 'S':
            arginfo->symb = va_arg(*args, symbol*);
            break;
    }
}

void MessagingSubsystem::Msg_Put_Args(char message[],MSG_ARG_LIST* arg_info,char* types,va_list* args)
{
    int         argnum = 0;             // Index of argument found
    int         j;                      // General purpose loop index
    int         order[3];               // Mapping of args to arg_info->arg
    char* percent;               // Position of '%' in message
    char        types_buff[1 + 3];      // readwrite copy of types
    char        specifier;              // Character following '%'

    if (types != NULL) {
        strcpy(types_buff, types);
        // conversions set order[]; digits->s
        percent = message - 2;          // So strchr below can work
        while ((percent = strchr(percent + 2, '%')) != NULL) {
            specifier = percent[1];
            for (j = 0; types_buff[j] != '\0'; j++) {  // Match with types
                if (types_buff[j] == specifier) {
                    order[j] = argnum;
                    argnum++;
                    if (isdigit(specifier))          // Digit becomes s
                        types_buff[j] = percent[1] = 's';
                    break;
                }
            }
        }
        // Re-order sequential arguments
        for (j = 0; j < argnum; j++) {
            Msg_Add_Arg(arg_info->arg + order[j], types_buff[j], args);
        }
    }
    arg_info->index = 0;
}
