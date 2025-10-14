#include "jasm.h"

using namespace std;

void (*yasm_internal_error_)(const char* file, unsigned int line, const char* message);
void (*yasm_fatal) (const char* message, va_list va);
const char* (*yasm_gettext_hook) (const char* msgid);

FILE* errfile;
static unsigned long warn_class_enabled;

static void handle_yasm_int_error(const char* file, unsigned int line, const char* message)
{
	fprintf(stderr, "INTERNAL ERROR at %s, line %u: %s\n", file, line, message);
	exit(EXIT_FAILURE);
}

static void handle_yasm_fatal(const char* fmt, va_list va)
{
	fprintf(errfile, "yasm: %s: ", "FATAL");
	vfprintf(errfile, fmt, va);
	fputc('\n', errfile);
	exit(EXIT_FAILURE);
}

static const char* handle_yasm_gettext(const char* msgid)
{
	return msgid;
}

static void print_error(const char* fmt, ...)
{
	va_list va;
	fprintf(errfile, "yasm: ");
	va_start(va, fmt);
	vfprintf(errfile, fmt, va);
	va_end(va);
	fputc('\n', errfile);
}

int main(int argc, char* argv[])
{
	errfile = stderr;
	yasm_internal_error_ = handle_yasm_int_error;
	yasm_fatal = handle_yasm_fatal;
	yasm_gettext_hook = handle_yasm_gettext;
	yasm_errwarn_initialize();
	/* Initialize BitVector (needed for intnum/floatnum). */
	if (BitVector_Boot() != ErrCode_Ok) {
		print_error("%s: could not initialize BitVector", "FATAL");
		return EXIT_FAILURE;
	}
	/* Initialize intnum and floatnum */
	yasm_intnum_initialize();
	yasm_floatnum_initialize();
	return 0;
}