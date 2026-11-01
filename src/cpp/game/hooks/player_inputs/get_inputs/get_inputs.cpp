#include "get_inputs.hpp"

#include "game/features/ragebot/ragebot.hpp"

#include "game/sdk/axlebolt/player_inputs/player_inputs.hpp"

#include "globals.hpp"

#include "memory_manager/memory_manager.hpp"

void hk::player_inputs::get_inputs::hook( )
{
    // Standarling 0.20.2: WeaponryController.ICGKEKHBKNA(CINHFKGPEMA) RVA 0x1ACA798
    memory_manager::hook( 0x1ACA798, reinterpret_cast< void* >( hk_get ), reinterpret_cast< void** >( &og_get ) );
}

void hk::player_inputs::get_inputs::hk_get( uintptr_t instance, uintptr_t input_packet )
{
    if ( input_packet && g_ctx->features.ragebot->m_fire )
    {
        // Standarling: CINHFKGPEMA.HGCMJFIGCHG (int @ 0x14) = fire state bitmask
        // set bit 0 = fire
        *reinterpret_cast< int* >( input_packet + 0x14 ) |= 1;
        g_ctx->features.ragebot->m_fire = false;
    }

    og_get( instance, input_packet );
}