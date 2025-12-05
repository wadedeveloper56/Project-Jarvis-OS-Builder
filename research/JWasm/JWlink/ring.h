#pragma once

#define RINGNAME( name ) Ring##name

void* RINGNAME(Pop)(void* hdr);
void RINGNAME(Free)(void* hdr);
