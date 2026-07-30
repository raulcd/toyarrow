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

#pragma once

#include <cstdint>
#include <memory>

namespace toyarrow {
class Buffer {
    public:
        explicit Buffer(int64_t size);

        const uint8_t* data() const;

        int64_t size() const;
    private:
        uint8_t* m_data;
        int64_t m_size;
        std::shared_ptr<void> owner_;
};
}  // namespace toyarrow
