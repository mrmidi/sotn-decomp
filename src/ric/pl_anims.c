#include "ric.h"

AnimationFrame* D_8015538C[] = {ric_anim_stand, ric_anim_stand};
AnimationFrame ric_anim_press_up[] = {{64, FRAME(38, 2)}, A_LOOP_AT(0)};
AnimationFrame ric_anim_stop_run[] = {
    {2, FRAME(55, 2)},  {1, FRAME(144, 2)}, {2, FRAME(145, 2)},
    {3, FRAME(144, 2)}, {4, FRAME(145, 2)}, {12, FRAME(144, 2)},
    {4, FRAME(16, 2)},  A_JUMP_AT(1)};
AnimationFrame ric_anim_stand[] = {
    {7, FRAME(1, 2)},
    {7, FRAME(2, 2)},
    {7, FRAME(3, 2)},
    {7, FRAME(2, 2)},
    {7, FRAME(1, 2)},
    {7, FRAME(2, 2)},
    {7, FRAME(3, 2)},
    {7, FRAME(2, 2)},
    {7, FRAME(1, 2)},
    {7, FRAME(2, 2)},
    {7, FRAME(3, 2)},
    {7, FRAME(2, 2)},
    {7, FRAME(1, 2)},
    {7, FRAME(2, 2)},
    {7, FRAME(3, 2)},
    {7, FRAME(2, 2)},
    {7, FRAME(1, 2)},
    {7, FRAME(2, 2)},
    {7, FRAME(3, 2)},
    {7, FRAME(2, 2)},
    {8, FRAME(1, 2)},
    {8, FRAME(2, 2)},
    {8, FRAME(3, 2)},
    {8, FRAME(2, 2)},
    {9, FRAME(1, 2)},
    {9, FRAME(2, 2)},
    {9, FRAME(3, 2)},
    {9, FRAME(2, 2)},
    {10, FRAME(1, 2)},
    {10, FRAME(2, 2)},
    {10, FRAME(3, 2)},
    {10, FRAME(2, 2)},
    {11, FRAME(1, 2)},
    {11, FRAME(2, 2)},
    {11, FRAME(3, 2)},
    {11, FRAME(2, 2)},
    {12, FRAME(1, 2)},
    {12, FRAME(2, 2)},
    {13, FRAME(3, 2)},
    {13, FRAME(2, 2)},
    {15, FRAME(1, 2)},
    {15, FRAME(2, 2)},
    {15, FRAME(3, 2)},
    {128, FRAME(2, 2)},
    {4, FRAME(4, 2)},
    {4, FRAME(5, 2)},
    {4, FRAME(6, 2)},
    {64, FRAME(7, 2)},
    A_END};
AnimationFrame ric_anim_stand_relax[] = {{64, FRAME(7, 2)}, A_LOOP_AT(0)};
AnimationFrame ric_anim_walk[] = {
    {3, FRAME(8, 2)},  {6, FRAME(9, 2)},  {5, FRAME(10, 2)}, {6, FRAME(11, 2)},
    {7, FRAME(12, 2)}, {6, FRAME(13, 2)}, {5, FRAME(14, 2)}, {6, FRAME(15, 2)},
    {4, FRAME(8, 2)},  A_LOOP_AT(0)};
AnimationFrame ric_anim_crouch_from_stand2[] = {
    0x0001, 0x0410, 0x0001, 0x0611, 0x0010, 0x0612, A_END};
AnimationFrame ric_anim_crouch[] = {{64, FRAME(18, 6)}, A_END};
AnimationFrame ric_anim_land_from_air_run[] = {{16, FRAME(152, 6)}, A_END};
AnimationFrame ric_anim_crouch_from_stand[] = {
    0x0001, 0x0410, 0x0001, 0x0611, 0x0001, 0x0612, A_END};
AnimationFrame D_801554E0[] = {
    0x0001, 0x0612, 0x0001, 0x0611, 0x0001, 0x0410, A_END};
AnimationFrame D_801554F0[] = {
    0x0008, 0x0813, 0x0003, 0x0415, 0x0005, 0x0416, 0x0003,
    0x0415, 0x0006, 0x0417, 0x0050, 0x0418, A_END};
AnimationFrame D_8015550C[] = {
    0x0008, 0x0814, 0x0003, 0x0415, 0x0005, 0x0416, 0x0003,
    0x0415, 0x0006, 0x0417, 0x0050, 0x0418, A_END};
AnimationFrame D_80155528[] = {0x0006, 0x0417, 0x0050, 0x0418, A_END};
AnimationFrame D_80155534[] = {
    0x0002, 0x0813, 0x0006, 0x0417, 0x0050, 0x0418, A_END};
AnimationFrame D_80155544[] = {0x0004, 0x0820, 0x0003, 0x0C21, 0x0002, 0x0C22,
                               0x0010, 0x0C22, 0x0001, 0x0C22, A_END};
AnimationFrame D_8015555C[] = {
    0x0004, 0x0820, 0x0003, 0x0C21, 0x0003, 0x0C22, 0x0003,
    0x0C23, 0x0002, 0x0C24, 0x0001, 0x0A1C, 0x0001, 0x0A1B,
    0x0020, 0x0425, 0x0012, 0x0819, 0x0030, 0x0418, A_END};
AnimationFrame D_80155588[] = {
    0x0002, 0x0226, 0x0002, 0x0227, 0x0002, 0x0228, 0x0002, 0x0229,
    0x0002, 0x022A, 0x0002, 0x022B, 0x0010, 0x022C, A_END};
AnimationFrame D_801555A8[] = {
    0x0002, 0x062F, 0x0002, 0x0630, 0x0002, 0x0631, 0x0002, 0x0632,
    0x0002, 0x0633, 0x0002, 0x0634, 0x0010, 0x0635, A_END};
AnimationFrame D_801555C8[] = {
    0x0002, 0x0836, 0x0002, 0x0837, 0x0002, 0x0428, 0x0002, 0x0429,
    0x0002, 0x042A, 0x0002, 0x042B, 0x0010, 0x042C, A_END};
AnimationFrame D_801555E8[] = {
    0x0002, 0x0226, 0x0002, 0x0227, 0x0002, 0x0228, 0x0002, 0x0229,
    0x0003, 0x022A, 0x0010, 0x022D, 0x0006, 0x022E, A_END};
AnimationFrame ric_anim_throw_daggers[] = {
    0x0002, 0x0226, 0x0002, 0x0227, 0x0002, 0x0228, 0x0002,      0x0229,
    0x0002, 0x022A, 0x0006, 0x022D, 0x0002, 0x022E, 0x0002,      0x0228,
    0x0002, 0x0229, 0x0003, 0x022A, 0x0002, 0x022D, A_LOOP_AT(7)};
AnimationFrame D_80155638[] = {
    0x0002, 0x0836, 0x0002, 0x0837, 0x0002, 0x0428, 0x0002, 0x0429,
    0x0003, 0x042A, 0x0010, 0x042D, 0x0006, 0x042E, A_END};
AnimationFrame ric_ric_anim_stand_in_air[] = {
    {5, FRAME(19, 0)},  {1, FRAME(26, 0)},   {1, FRAME(25, 0)},
    {6, FRAME(125, 0)}, {32, FRAME(126, 0)}, A_LOOP_AT(4)};
AnimationFrame ric_anim_run[] = {
    0x0003, 0x1281, 0x0003, 0x1282, 0x0003, 0x1283, 0x0003, 0x1284,      0x0003,
    0x1285, 0x0003, 0x1286, 0x0003, 0x127F, 0x0003, 0x1280, A_LOOP_AT(0)};
AnimationFrame ric_anim_stun[] = {{64, FRAME(32, 8)}, A_END};
AnimationFrame D_8015569C[] = {
    0x0001, 0x02CE, 0x0001, 0x02CF, 0x0001, 0x02CE, 0x0003,
    0x02CF, 0x0003, 0x02CE, 0x0005, 0x02CF, 0x0001, 0x0226,
    0x0001, 0x022E, 0x0020, 0x0202, A_END};
AnimationFrame D_801556C4[] = {
    0x0001, 0x08B7, 0x0002, 0x08B8, 0x0001, 0x08B6, 0x0001, 0x08B7,
    0x0001, 0x08B9, 0x0001, 0x08B6, 0x0001, 0x08B7, 0x0001, 0x08BA,
    0x0001, 0x08B6, 0x0001, 0x08B7, 0x0001, 0x08BC, 0x0001, 0x08B7,
    0x0001, 0x08BB, 0x0001, 0x08B7, 0x0020, 0x08B6, A_END};
AnimationFrame D_80155704[] = {
    0x0001, 0x06C8, 0x0001, 0x06C9, 0x0001, 0x06C8, 0x0002,
    0x06C9, 0x0002, 0x06C8, 0x0003, 0x06C9, 0x0003, 0x06C8,
    0x0005, 0x06C9, 0x0001, 0x062F, 0x0001, 0x0611, A_END};
AnimationFrame D_80155730[] = {0x0080, 0x02D0, A_END};
AnimationFrame D_80155738[] = {0x0080, 0x06D1, A_END};
AnimationFrame D_80155740[] = {0x0080, 0x08D2, A_END};
AnimationFrame D_80155748[] = {0x0080, 0x0011, A_END};
AnimationFrame D_80155750[] = {
    0x0002, 0x0218, 0x0002, 0x0487, 0x0002, 0x0488, 0x0001,
    0x0642, 0x0008, 0x1489, 0x0010, 0x148A, 0x0008, 0x1489,
    0x0002, 0x0642, 0x0002, 0x0641, 0x0002, 0x0611, A_END};
AnimationFrame D_8015577C[] = {0x0016, 0x228C, 0x0080, 0x228D, A_END};
AnimationFrame D_80155788[] = {
    0x0003, 0x081B, 0x0003, 0x081A, 0x0003, 0x0819, 0x0030, 0x0418, A_END};
AnimationFrame ric_anim_high_jump[] = {
    0x0001, 0x089B, 0x0001, 0x089C, 0x0010, 0x089B, A_END};
AnimationFrame ric_anim_point_finger_up[] = {
    0x0002, 0x00A4, 0x0002, 0x00A5, 0x0001, 0x00A4, 0x0001,
    0x00A5, 0x000D, 0x00A4, 0x0002, 0x00A6, 0x0003, 0x00A7,
    0x0002, 0x00A6, 0x0080, 0x00A6, 0x0002, 0x0026, A_END};
AnimationFrame ric_anim_blade_dash[] = {
    0x0001, 0x0008, 0x0001, 0x0038, 0x0001, 0x0092, 0x0001, 0x0093, 0x0001,
    0x0094, 0x0001, 0x0095, 0x0001, 0x0096, 0x0001, 0x0097, 0x0001, 0x0094,
    0x0001, 0x0095, 0x0001, 0x0096, 0x0001, 0x0097, 0x0001, 0x0093, 0x0001,
    0x0094, 0x0001, 0x0095, 0x0001, 0x0096, 0x0001, 0x0097, 0x0010, 0x0092,
    0x0002, 0x0037, 0x0001, 0x0090, 0x0002, 0x0091, 0x0003, 0x0090, 0x0004,
    0x0091, 0x000C, 0x0090, 0x0004, 0x0010, A_END};
AnimationFrame ric_anim_flame_whip[] = {
    0x0004, 0x02A2, 0x0001, 0x02A8, 0x0002, 0x02A9, 0x0018, 0x02A8, 0x0004,
    0x02AC, 0x0001, 0x02AA, 0x0002, 0x02AB, 0x0018, 0x02AA, 0x0008, 0x02AC,
    0x0005, 0x02AD, 0x0004, 0x02AC, 0x0003, 0x02AD, 0x0002, 0x02AE, 0x0002,
    0x02AD, 0x0001, 0x02AE, 0x0001, 0x02AF, 0x0001, 0x02AE, 0x000C, 0x02AF,
    0x0001, 0x02B0, 0x0002, 0x02B1, 0x0001, 0x02B2, 0x0001, 0x02B3, 0x0001,
    0x02B4, 0x0001, 0x02B5, 0x0001, 0x02B4, 0x0001, 0x02B3, 0x0001, 0x02B2,
    0x0030, 0x02B0, A_END};
AnimationFrame D_801558B4[] = {
    0x0005, 0x0013, 0x0001, 0x001A, 0x0001, 0x0019, 0x0006, 0x007D,
    0x0083, 0x007E, 0x0080, 0x007E, 0x0080, 0x0019, A_END};
AnimationFrame D_801558D4[] = {0x000C, 0x0019, A_END};
AnimationFrame D_801558DC[] = {0x0006, 0x001A, A_END};
AnimationFrame D_801558E4[] = {
    0x0002, 0x0237, 0x0001, 0x0290, 0x0002, 0x0291, 0x0003, 0x0290, 0x0004,
    0x0291, 0x0005, 0x0291, 0x0005, 0x0290, 0x0005, 0x0291, 0x0005, 0x0291,
    0x0005, 0x0290, 0x0005, 0x0291, 0x000C, 0x0290, 0x0010, 0x0226, A_END};
AnimationFrame D_8015591C[] = {
    0x0002, 0x00A4, 0x0002, 0x00A5, 0x0001, 0x00A4, 0x0001, 0x00A5, 0x000D,
    0x00A4, 0x0002, 0x00A6, 0x0003, 0x00A7, 0x0002, 0x00A6, 0x0080, 0x00A6,
    0x0080, 0x00A6, 0x0080, 0x00A6, 0x0080, 0x00A6, A_END};
AnimationFrame D_80155950[] = {
    0x0080, 0x00A6, 0x0080, 0x00A6, 0x0080, 0x00A6, 0x0002, 0x0026, A_END};

FrameProperty D_80155964[] = {
    0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x14, 0x02, 0x05, 0x07, 0x0C,
    0x03, 0x0C, 0x08, 0x0C, 0x00, 0xFF, 0x06, 0x10, 0x00, 0x01, 0x08, 0x08,
    0x00, 0xFB, 0x07, 0x05, 0xC0, 0xA8, 0x00, 0x00, 0xFC, 0x00, 0x06, 0x11,
    0x00, 0x00, 0x09, 0x10, 0xFF, 0x11, 0x0C, 0x07, 0xF9, 0x0A, 0x08, 0x05,
    0xFE, 0x06, 0x08, 0x08, 0xFA, 0x06, 0x07, 0x11, 0x04, 0x06, 0x0A, 0x09,
    0xFD, 0x03, 0x09, 0x14, 0x00, 0x08, 0x08, 0x08, 0xFF, 0x0A, 0x0C, 0x07,
};
