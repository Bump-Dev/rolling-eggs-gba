#ifndef BN_SPRITE_ITEMS_EGG_H
#define BN_SPRITE_ITEMS_EGG_H

#include "bn_sprite_item.h"

//{{BLOCK(egg_bn_gfx)

//======================================================================
//
//	egg_bn_gfx, 32x32@8, 
//	+ palette 32 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 64 + 1024 = 1088
//
//	Time-stamp: 2024-08-06, 20:26:51
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_EGG_BN_GFX_H
#define GRIT_EGG_BN_GFX_H

#define egg_bn_gfxTilesLen 1024
extern const bn::tile egg_bn_gfxTiles[32];

#define egg_bn_gfxPalLen 64
extern const bn::color egg_bn_gfxPal[32];

#endif // GRIT_EGG_BN_GFX_H

//}}BLOCK(egg_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item egg(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(egg_bn_gfxTiles, 32), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(egg_bn_gfxPal, 32), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

