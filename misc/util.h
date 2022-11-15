#pragma once
#include <cstdint>
#include <vector>
#include <Windows.h>

namespace Globals
{
	static bool Open = true;
	static uintptr_t Base = NULL;

}

uintptr_t sig_scan(const char* module, const char* pattern);
