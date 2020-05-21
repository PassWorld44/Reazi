#pragma once

#ifdef RZ_PLATFORM_WINDOWS

#include "Application.h"

extern Reazi::Application* Reazi::CreateApplication();

void windmain(int argc, char** argv);

#endif

