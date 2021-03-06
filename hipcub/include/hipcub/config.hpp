/******************************************************************************
 * Copyright (c) 2010-2011, Duane Merrill.  All rights reserved.
 * Copyright (c) 2011-2018, NVIDIA CORPORATION.  All rights reserved.
 * Modifications Copyright (c) 2019-2020, Advanced Micro Devices, Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the NVIDIA CORPORATION nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NVIDIA CORPORATION BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************/

#ifndef HIPCUB_CONFIG_HPP_
#define HIPCUB_CONFIG_HPP_

#include <hip/hip_runtime.h>

#define HIPCUB_NAMESPACE hipcub

#define BEGIN_HIPCUB_NAMESPACE \
    namespace hipcub {

#define END_HIPCUB_NAMESPACE \
    } /* hipcub */

#ifdef __HIP_PLATFORM_HCC__
    #define HIPCUB_ROCPRIM_API 1
    #define HIPCUB_RUNTIME_FUNCTION __host__
#elif defined(__HIP_PLATFORM_NVCC__)
    #define HIPCUB_CUB_API 1
    #define HIPCUB_RUNTIME_FUNCTION CUB_RUNTIME_FUNCTION

    #include <cub/util_arch.cuh>
    #define HIPCUB_WARP_THREADS CUB_PTX_WARP_THREADS
    #define HIPCUB_ARCH CUB_PTX_ARCH
    BEGIN_HIPCUB_NAMESPACE
    using namespace cub;
    END_HIPCUB_NAMESPACE
#endif

#define HIPCUB_HOST __host__
#define HIPCUB_DEVICE __device__
#define HIPCUB_HOST_DEVICE __host__ __device__
#define HIPCUB_SHARED_MEMORY __shared__
// TODO: This paremeters should be tuned for NAVI.
#ifndef HIPCUB_DEFAULT_MIN_WARPS_PER_EU
    #define HIPCUB_DEFAULT_MIN_WARPS_PER_EU 1
#endif

#endif // HIPCUB_CONFIG_HPP_
