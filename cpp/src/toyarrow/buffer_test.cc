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
#include <gtest/gtest.h>

TEST(BufferTest, ConstructorAndAccessors) {
  std::vector<int64_t> sizes = {0, 1, 5, 8, 1024, 2047, 4096};
  for (int64_t size : sizes) {
    toyarrow::Buffer buffer(size);

    EXPECT_EQ(buffer.size(), size);
    // Check for 64-byte alignment, address should be divisible by 64
    EXPECT_EQ(reinterpret_cast<uintptr_t>(buffer.data()) % 64, 0);
    EXPECT_NE(buffer.data(), nullptr);
  }
}
