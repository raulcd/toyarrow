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

#include "toyarrow/bitmap.h"

#include <stdexcept>

namespace toyarrow {

Bitmap::Bitmap(std::shared_ptr<Buffer> buffer, int64_t length)
    : buffer_(std::move(buffer)), length_(length) {
  if (length < 0) {
    throw std::invalid_argument("Length must be non-negative");
  }
  if (length > buffer_->size()) {
    throw std::invalid_argument("Length cannot exceed buffer size");
  }
}

int64_t Bitmap::length() const { return length_; }

}  // namespace toyarrow
