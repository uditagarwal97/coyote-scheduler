﻿// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#ifndef FFI_H
#define FFI_H

#if _WIN32 && defined(COYOTE_SHARED)
#if defined(COYOTE_EXPORT)
#define COYOTE_API __declspec(dllexport)
#else
#define COYOTE_API __declspec(dllimport)
#endif
#else
#define COYOTE_API
#endif

#endif // FFI_H
