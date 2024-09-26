// This file is part of the FidelityFX SDK.
//
// Copyright (C) 2024 Advanced Micro Devices, Inc.
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#pragma once

#include "ffx_api_dx12.h"
#include <windows.h>

namespace dx12
{

typedef struct ffxFunctions {
    PfnFfxCreateContextDX12  CreateContextDX12;
    PfnFfxDestroyContextDX12 DestroyContextDX12;
    PfnFfxConfigureDX12      ConfigureDX12;
    PfnFfxQueryDX12          QueryDX12;
    PfnFfxDispatchDX12       DispatchDX12;
} ffxFunctions;

static inline void ffxLoadFunctions(ffxFunctions* pOutFunctions, HMODULE module)
{
    pOutFunctions->CreateContextDX12 = (PfnFfxCreateContextDX12)GetProcAddress(module, "ffxCreateContextDX12");
    pOutFunctions->DestroyContextDX12 = (PfnFfxDestroyContextDX12)GetProcAddress(module, "ffxDestroyContextDX12");
    pOutFunctions->ConfigureDX12      = (PfnFfxConfigureDX12)GetProcAddress(module, "ffxConfigureDX12");
    pOutFunctions->QueryDX12          = (PfnFfxQueryDX12)GetProcAddress(module, "ffxQueryDX12");
    pOutFunctions->DispatchDX12       = (PfnFfxDispatchDX12)GetProcAddress(module, "ffxDispatchDX12");
}

}  // namespace dx12
