#include "pch.h"
#include "cmdline.h"

struct global_options Options = {
    /* quiet            */          FALSE,
    /* line_numbers     */          FALSE,
    /* debug_symbols    */          0,
    /* debug_ext        */          0, /* v2.10 */
    /* floating_point   */          FPO_NO_EMULATION,

    /* error_limit      */          50,
    /* no error display */          FALSE,
    /* warning_level    */          2,
    /* warning_error    */          FALSE,
#ifdef DEBUG_OUT
    /* debug            */          FALSE,
    /* nobackpatch      */          FALSE,
#if FASTPASS
    /* nofastpass       */          FALSE,
    /* print_linestore  */          FALSE,
#endif
    /* max_passes       */          0,
    /* skip_preprocessor */         0,
    /* log_all_files    */          0,
    /* dump_reswords    */          FALSE,
    /* dump_reswords_hash */        FALSE,
    /* dump_symbols     */          FALSE,
    /* dump_symbols_hash */         FALSE,
#endif
    /* names            */          {
        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
#if BUILD_TARGET
        NULL,
#endif
#if MANGLERSUPP
        NULL
#endif
    },
    /* queues           */          { NULL, NULL, NULL },
#if COCTALS
    /* allow_c_octals        */     FALSE,
#endif
    /* no_comment_data_in_code_records */   FALSE,
    /* no_opt_farcall        */     FALSE,
    /* no_dependencies       */ //    FALSE,
#if COFF_SUPPORT
    /* no_file_entry         */     FALSE,
    /* no_static_procs       */     FALSE,
    /* no_section_aux_entry  */     FALSE,
#endif
    /* no_cdecl_decoration   */     FALSE,
    /* stdcall_decoration    */     STDCALL_FULL,
    /* no_export_decoration  */     FALSE,
    /* entry_decorated       */     FALSE,
    /* write_listing         */     FALSE,
    /* write_impdef          */     FALSE,
    /* case_sensitive        */     FALSE,
    /* convert_uppercase     */     FALSE,
    /* preprocessor_stdout   */     FALSE,
    /* masm51_compat         */     FALSE,
    /* strict_masm_compat    */     FALSE,
    /* masm_compat_gencode   */     FALSE,
    /* masm8_proc_visibility */     FALSE,

    /* listif                */     FALSE,
    /* list_generated_code   */     FALSE,
    /* list_macro            */     LM_LISTMACRO,
    /* no_symbol_listing     */     FALSE,
    /* first_pass_listing    */     FALSE,

    /* all_symbols_public    */     FALSE,
    /* safeseh               */     FALSE,
    /* ignore_include        */     FALSE,
    /* output_format         */     OFORMAT_OMF,
    /* sub_format            */     SFORMAT_NONE,
    /* alignment_default     */     0,
    /* langtype              */     LANG_NONE,
    /* model                 */     MODEL_NONE,
    /* cpu                   */     P_86,
    /* fastcall type         */     FCT_MSC,
    /* syntax check only     */     FALSE,
#if MANGLERSUPP
    /* naming_convention*/          NC_DO_NOTHING,
#endif
}; 
char* EXPQUAL ParseCmdline(const char** cmdline, int*)
{
	return NULL;
}

void EXPQUAL CmdlineFini(void)
{
}