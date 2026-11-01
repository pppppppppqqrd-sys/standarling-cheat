#pragma once

#include <cstdint>

class c_player_inputs;

namespace hk::player_inputs::get_inputs
{
    // Standarling: hook signature changed to void(uintptr_t instance, uintptr_t input_packet)
    inline void ( *og_get )( uintptr_t, uintptr_t );
    extern void hk_get( uintptr_t instance, uintptr_t input_packet );

    extern void hook( );
} // namespace hk::player_inputs::get_inputs