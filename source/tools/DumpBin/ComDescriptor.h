#pragma once

void MetaData(PVOID Address, DWORD Size);
void Resources(PVOID Address, DWORD Size);
void StrongNameSignature(PVOID Address, DWORD Size);
void CodeManagerTable(PVOID Address, DWORD Size);
void VTableFixups(PVOID Address, DWORD Size);
void ExportAddressTableJumps(PVOID Address, DWORD Size);
void ManagedNativeHeader(PVOID Address, DWORD Size);
DWORD ComDescriptor(PBYTE Data, LONGLONG Size);

