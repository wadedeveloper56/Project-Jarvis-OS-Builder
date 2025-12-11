#pragma once

void ResetOvlSupp(void);
void FreeOvlStruct(void);
void WalkAreas(OVL_AREA* ovl, void (*rtn)(section*));
