// Copyright 2026 Raúl Cumplido
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "toyarrow/buffer.h"

#include <stdexcept>

namespace toyarrow {

// Allocate memory with 64-byte default alignment as per spec recommendation
constexpr int64_t kDefaultAlignment = 64;

Buffer::Buffer(int64_t size) : m_size(size) {
  if (size < 0) {
    throw std::invalid_argument("Size must be non-negative");
  }
  m_data =
      static_cast<uint8_t*>(::operator new(size, std::align_val_t{kDefaultAlignment}));
  // Use a custom deleter to ensure proper deallocation with alignment.
  owner_ = std::shared_ptr<void>(
      m_data, [](void* p) { operator delete(p, std::align_val_t{kDefaultAlignment}); });
}

const uint8_t* Buffer::data() const { return m_data; }

int64_t Buffer::size() const { return m_size; }

}  // namespace toyarrow
