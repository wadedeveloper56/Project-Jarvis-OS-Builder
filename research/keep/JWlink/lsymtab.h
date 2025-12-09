#pragma once

#define STATIC_TABSIZE  241  /* should be prime */
#define GLOBAL_TABSIZE  1789  /* should be prime */

#define STATIC_TABALLOC (256 * sizeof(symbol *))  // 1st power of 128 > TABSIZE
#define GLOBAL_TABALLOC (1792 * sizeof(symbol *)) // 1st power of 128 > TABSIZE

void InitSym(void);
void FiniSym(void);
