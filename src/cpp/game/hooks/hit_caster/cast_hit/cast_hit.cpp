#include "cast_hit.hpp"

#include "globals.hpp"

#include "game/features/ragebot/ragebot.hpp"
#include "game/features/misc/peek_assist/peek_assist.hpp"
#include "game/features/visual/bullet_tracers/bullet_tracers.hpp"

#include "memory_manager/memory_manager.hpp"

void hk::hit_caster::cast_hit::hook( )
{
    // Standarling 0.20.2: HitCaster.MFLCMHMAMKG (3-arg overload) RVA 0x1917ECC
    memory_manager::hook( 0x1917ECC, reinterpret_cast< void* >( hk_cast ), reinterpret_cast< void** >( &og_cast ) );
}

uintptr_t hk::hit_caster::cast_hit::hk_cast( vec3_t start, vec3_t target, uintptr_t param )
{
    g_ctx->features.ragebot->cast_hit( start, target, param );

    if ( g_ctx->features.peek_assist->m_peeking )
        g_ctx->features.peek_assist->m_peeking = false;

    uintptr_t const ret = og_cast( start, target, param );

    if ( c::get< bool >( g_ctx->cfg.visual_bullet_tracers ) && ret )
    {
        vec3_t const end_position = *reinterpret_cast< vec3_t* >( ret + 0x2C );

        g_ctx->features.bullet_tracers->push_tracer(
            { .start = start,
              .end = end_position } );
    }

    return ret;
}