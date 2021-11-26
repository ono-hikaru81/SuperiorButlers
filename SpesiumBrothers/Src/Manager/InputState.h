
#ifndef INPUT_STATE_H
#define INPUT_STATE_H

#include <cstdint>

namespace spesium {
    namespace input {
        static constexpr int8_t ON { 1 };
        static constexpr int8_t OFF { 0 };

        enum class InputState {
            none,
            push,
            hold,
            release
        };

        static constexpr InputState ConvertState( const bool& current, const bool& previous ) {
            if ( !previous && current ) {
                return InputState::push;
            }
            else if ( previous && current ) {
                return InputState::hold;
            }
            else if ( previous && !current ) {
                return InputState::release;
            }
            return InputState::none;
        }
    }  // namespace input
}  // namespace spesium

#endif  // !INPUT_STATE_H
