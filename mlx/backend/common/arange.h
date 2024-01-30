// Copyright © 2023 Apple Inc.

#pragma once

#include "mlx/allocator.h"
#include "mlx/array.h"

namespace mlx::core {

namespace {

template <typename T>
void arange(T start, T next, array& out, size_t size) {
  auto ptr = out.data<T>();
  auto step_size = next - start;
  for (int i = 0; i < size; ++i) {
    ptr[i] = start;
    start += step_size;
  }
}

} // namespace

void arange(
    const std::vector<array>& inputs,
    array& out,
    double start,
    double step) {
  assert(inputs.size() == 0);
  out.set_data(allocator::malloc_or_wait(out.nbytes()));
  if (std::isinf(step)) {
    // handle the infinite step case
    switch (out.dtype()) {
      case bool_:
        throw std::runtime_error("Bool type unsupported for arange.");
        break;
      case uint8:
        out.data<uint8_t>()[0] = start; // set the first element to the start value
        break;
      case uint16:
        out.data<uint16_t>()[0] = start;
        break;
      case uint32:
        out.data<uint32_t>()[0] = start;
        break;
      case uint64:
        out.data<uint64_t>()[0] = start;
        break;
      case int8:
        out.data<int8_t>()[0] = start;
        break;
      case int16:
        out.data<int16_t>()[0] = start;
        break;
      case int32:
        out.data<int32_t>()[0] = start;
        break;
      case int64:
        out.data<int64_t>()[0] = start;
        break;
      case float16:
        out.data<float16_t>()[0] = start;
        break;
      case float32:
        out.data<float>()[0] = start;
        break;
      case bfloat16:
        out.data<bfloat16_t>()[0] = start;
        break;
      case complex64:
        out.data<complex64_t>()[0] = start;
        break;
    }
  } else {
    // handle the normal case
    switch (out.dtype()) {
      case bool_:
        throw std::runtime_error("Bool type unsupported for arange.");
        break;
      case uint8:
        arange<uint8_t>(start, start + step, out, out.size());
        break;
      case uint16:
        arange<uint16_t>(start, start + step, out, out.size());
        break;
      case uint32:
        arange<uint32_t>(start, start + step, out, out.size());
        break;
      case uint64:
        arange<uint64_t>(start, start + step, out, out.size());
        break;
      case int8:
        arange<int8_t>(start, start + step, out, out.size());
        break;
      case int16:
        arange<int16_t>(start, start + step, out, out.size());
        break;
      case int32:
        arange<int32_t>(start, start + step, out, out.size());
        break;
      case int64:
        arange<int64_t>(start, start + step, out, out.size());
        break;
      case float16:
        arange<float16_t>(start, start + step, out, out.size());
        break;
      case float32:
        arange<float>(start, start + step, out, out.size());
        break;
      case bfloat16:
        arange<bfloat16_t>(start, start + step, out, out.size());
        break;
      case complex64:
        arange<complex64_t>(start, start + step, out, out.size());
        break;
    }
  }
}


} // namespace mlx::core
