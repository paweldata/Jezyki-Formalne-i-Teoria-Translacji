#include <cstdint>
#include <string>

namespace utf8
{
    bool isFirstByteInUtf8(const uint8_t& bits) { return (bits <= 127 || bits >= 192); }

    void increaseIndexIfNecessary(uint64_t& index, const uint8_t currChar) {
        if (isFirstByteInUtf8(currChar))
            index++;
    }

    uint32_t getSizeInUtf8(const std::string& pattern) {
        int size = 0;

        for (uint8_t currChar : pattern) {
            if (isFirstByteInUtf8(currChar))
                size++;
        }

        return size;
    }
}
