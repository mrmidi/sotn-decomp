
#include "dra.h"
#include "sfx.h"

void func_80112BB0(void) {
    char pad[12];
    s32 temp_v0;
    s32 temp_v1;
    s32 var_s2;

    if (PLAYER.step_s != 0x58) {
        DecelerateX(0x1000);
        if (PLAYER.velocityY < -0x10000) {
            if (!(g_Player.unk44 & 0x40) &&
                !(g_Player.padPressed & PAD_CROSS)) {
                PLAYER.velocityY = -0x10000;
            }
            if (g_Player.pl_vram_flag & 2) {
                PLAYER.velocityY = -0x4000;
                g_Player.unk44 |= 0x20;
            }
        }
        if (func_8010FDF8(0x11029) != 0) {
            return;
        }
    }
    switch (PLAYER.step_s) {
    case 0x0:
        var_s2 = func_8010E27C();
        if (var_s2 != 0) {
            if ((PLAYER.ext.player.unkAC == 0x16) ||
                (PLAYER.ext.player.unkAC == 0x19)) {
                func_8010DA48(0x18U);
            }
            SetSpeedX(0x18000);
        } else if ((PLAYER.ext.player.unkAC == 0x1A) ||
                   (PLAYER.ext.player.unkAC == 0x18)) {
            func_8010DA48(0x19U);
        }
        if (var_s2 <= 0) {
            g_Player.unk44 &= 0xFFEF;
        }
        if (PLAYER.velocityY > 0) {
            if (PLAYER.ext.player.unkAC != 0x1B) {
                func_8010DA48(0x1BU);
            }
            PLAYER.step_s = 1;
        }
        break;
    case 0x1:
        var_s2 = func_8010E27C();
        if ((var_s2 == 0) || (SetSpeedX(0x18000), (var_s2 <= 0))) {
            g_Player.unk44 &= 0xFFEF;
        }
        break;
    case 0x58:
        func_8010DFF0(1, 1);
        if (D_80139824 > 0) {
            D_80139824--;
        }
        if ((PLAYER.animFrameIdx == 3) && (PLAYER.animFrameDuration == 1) &&
            (D_80139824 != 0)) {
            PLAYER.animFrameIdx = 1;
        }
        if ((PLAYER.animFrameIdx == 4) ||
            (g_Player.padTapped & (PAD_DOWN | PAD_UP))) {
            PLAYER.step_s = 0x40;
        }
        break;
    case 0x57:
    case 0x5B:
        func_8010DFF0(1, 1);
        DecelerateX(0x1000);
        if (PLAYER.ext.player.unkAC == 0x6C) {
            if (PLAYER.animFrameDuration < 0) {
                temp_v0 = (PLAYER.velocityY > 0x10000) ^ 1;
                PLAYER.step_s = D_800ACF7C[temp_v0].unk0;
                func_8010DA48(D_800ACF7C[temp_v0].unk2);
                func_8010FAF4();
                g_Player.unk44 = 1;
                D_80138FC8 = 0xFE;
                D_80138FCA = 0x10;
            }
        } else if (
            (PLAYER.animFrameIdx == 4) && (PLAYER.animFrameDuration == 1)) {
            PLAYER.animFrameIdx = 5;
            PLAYER.ext.player.unkAC = 0x6C;
        }
        break;
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4A:
    case 0x4B:
    case 0x4C:
    case 0x4D:
    case 0x4E:
    case 0x4F:
    case 0x50:
    case 0x51:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x5A:
    case 0x5C:
    case 0x5D:
        func_8010DFF0(1, 1);
    case 0x40:
    case 0x59:
        func_8010DFF0(1, 1);
        if (g_Player.padPressed & PAD_LEFT) {
            PLAYER.velocityX = -0x18000;
        }
        if (g_Player.padPressed & PAD_RIGHT) {
            PLAYER.velocityX = 0x18000;
        }
        if (PLAYER.animFrameDuration < 0) {
            temp_v1 = (PLAYER.velocityY > 0x10000) ^ 1;
            PLAYER.step_s = D_800ACF7C[temp_v1].unk0;
            func_8010DA48(D_800ACF7C[temp_v1].unk2);
            func_8010FAF4();
        }
        break;
    case 0x70:
        if (g_Player.unk44 & 0x80) {
            func_8010E83C(1);
            if (!(g_Player.padPressed & PAD_CROSS)) {
                PLAYER.velocityY = -0x44000;
            }
            g_Player.unk44 |= 0x40;
        }
        break;
    }

    if (PLAYER.step_s < 2) {
        if (g_Player.unk44 & 1) {
            if ((g_Player.padPressed & PAD_DOWN) &&
                (g_Player.padTapped & PAD_CROSS)) {
                func_8010DA48(0x22U);
                PLAYER.step_s = 0x70;
                CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0, 5), 0);
                PLAYER.velocityY = 0x60000;
                g_Player.unk44 &= 0xFF7F;
                if (var_s2 != 0) {
                    SetSpeedX(0x48000);
                }
                PlaySfx(0x6F0);
            }
            if (g_Player.unk44 & 0x100) {
                PLAYER.velocityX = 0;
            }
        }
    } else {
        if (g_Player.unk44 & 0x100) {
            PLAYER.velocityX = 0;
        }
    }
}

void func_80113148(void) {
    if (g_Player.D_80072F00[5] != 0 && g_Player.padTapped & PAD_CROSS) {
        func_8010E83C(1);
    } else if (func_8010FDF8(0x9029) == 0) {
        DecelerateX(0x1000);
        if (func_8010E27C() != 0) {
            SetSpeedX(0xC000);
        }
    }
}

void func_801131C4(void) {
    s32 i;
    s32 x_offset;
    u16 local_flags;
    bool condition = false;

    local_flags = 0;
    condition = ((g_Player.pl_vram_flag & 0x20) != condition);

    if ((g_Player.padTapped & PAD_CROSS) && !(g_Player.unk46 & PAD_LEFT)) {
        if (g_Player.padPressed & PAD_DOWN) {
            for (i = 0; i < 4; i++) {
                if ((g_Player.colliders[i].effects & EFFECT_SOLID_FROM_ABOVE)) {
                    g_Player.D_80072F00[7] = 8;
                    return;
                }
            }
        }
        if (g_Player.unk72 == 0) {
            func_8010E83C(1);
            return;
        }
    }
    if (func_8010FDF8(0x100C) != 0) {
        return;
    }
    DecelerateX(0x2000);
    if (g_Player.unk48 != 0) {
        if (PLAYER.ext.player.unkAC == 0x11) {
            PLAYER.ext.player.unkAC = 0x65;
            PLAYER.animFrameDuration = 2;
            PLAYER.animFrameIdx = 3;
        }
    } else if (PLAYER.ext.player.unkAC == 0x65) {
        func_8010DA48(0x11);
    }
    switch (PLAYER.step_s) {
    case 0x0:
        if (D_800ACF74 != 0) {
            D_800ACF74--;
        } else if (D_80097448[0] >= 0x19) {
            if (g_Player.unk48 == 0) {
                x_offset = 0xC;
                if (PLAYER.facingLeft) {
                    x_offset = -0xC;
                }
                PLAYER.posX.i.hi = x_offset + PLAYER.posX.i.hi;
                PLAYER.posY.i.hi += 2;
                CreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(0xd00, 4), 0);
                D_800ACF74 = 0x60;
                PLAYER.posY.i.hi -= 2;
                PLAYER.posX.i.hi -= x_offset;
            }
        }
        local_flags = 6;
        break;
    case 0x1:
        if (!(g_Player.padPressed & PAD_DOWN)) {
            local_flags = 1;
            if ((PLAYER.animFrameIdx >= 4) || PLAYER.ext.player.unkAC == 0x65) {
                func_8010DA48(0x13);
                PLAYER.step_s = 2;
                PLAYER.animFrameIdx = 2;
                if (g_Player.unk72 == 1) {
                    PLAYER.animFrameIdx = 0;
                }
                if (g_Player.unk72 == 2) {
                    PLAYER.animFrameIdx = 1;
                }
                return;
            }
        } else if (PLAYER.ext.player.unkAC == 0x65) {
            PLAYER.step_s = 0;
        } else {
            if (PLAYER.animFrameDuration < 0) {
                local_flags = 0x20;
            }
        }
        break;
    case 0x5:
        func_8010DFF0(1, 1);
        if (g_Player.unk72 == PLAYER.animFrameIdx ||
            PLAYER.animFrameDuration < 0) {
            local_flags = 0x20;
        }
        break;
    case 0x3:
    case 0x4:
        func_8010DFF0(1, 1);
        if (PLAYER.animFrameDuration < 0) {
            local_flags = 0x20;
        }
        break;
    case 0x2:
        local_flags = 1;
        if (g_Player.padPressed & PAD_DOWN) {
            func_8010E470(0, PLAYER.velocityX);
            break;
        }
        if (g_Player.unk72 != 0) {
            func_8010DFF0(1, 1);
            if (g_Player.unk72 == 1) {
                PLAYER.animFrameIdx = 0;
                PLAYER.animFrameDuration = 3;
                break;
            } else if (g_Player.unk72 == 2) {
                if (PLAYER.animFrameIdx != 0) {
                    PLAYER.animFrameIdx = 1;
                    PLAYER.animFrameDuration = 3;
                }
                break;
            } else if (g_Player.unk72 == 3) {
                if (PLAYER.animFrameIdx >= 2) {
                    PLAYER.animFrameIdx = 2;
                    PLAYER.animFrameDuration = 3;
                }
                break;
            } else if (g_Player.unk72 == 4) {
                if (PLAYER.animFrameIdx >= 3) {
                    PLAYER.animFrameIdx = 3;
                    PLAYER.animFrameDuration = 3;
                }
                break;
            }
        }
        if (PLAYER.animFrameDuration < 0) {
            func_8010E570(0);
        }

        break;
    case 0x40:
    case 0x59:
        func_8010DFF0(1, 1);
        if (PLAYER.animFrameIdx < g_Player.unk54) {
            if (PLAYER.animFrameIdx < 2) {
                func_8010E27C();
                if (!(g_Player.padPressed & PAD_DOWN)) {
                    if (g_Player.unk72 == 0) {
                        PLAYER.step = 0;
                        PLAYER.ext.player.unkAC = 0x24;
                    }
                }
            }
        } else {
            g_Player.unk46 &= 0x7FFF;
            local_flags = 0xE;
            if (PLAYER.animFrameIdx == 7) {
                if (g_Player.padPressed & g_Player.D_80072EF8) {
                    PLAYER.animFrameDuration = 2;
                    local_flags = 0xE;
                } else {
                    local_flags = 0x2E;
                }
            }
        }
        break;
    case 0x47:
    case 0x49:
        if ((PLAYER.animFrameIdx == 6) &&
            (g_Player.padPressed & g_Player.D_80072EF8)) {
            PLAYER.animFrameDuration = 2;
        }
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x48:
    case 0x4A:
    case 0x4B:
    case 0x4C:
    case 0x4D:
    case 0x4E:
    case 0x4F:
    case 0x50:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x5A:
    case 0x5B:
    case 0x5C:
    case 0x5D:
        func_8010DFF0(1, 1);
        if (PLAYER.animFrameIdx < g_Player.unk54) {
            if (PLAYER.animFrameIdx < 3) {
                func_8010E27C();
                if (!(g_Player.padPressed & PAD_DOWN)) {
                    if (g_Player.unk72 == 0) {
                        PLAYER.ext.player.unkAC =
                            D_800B0608[PLAYER.step_s - 0x41] + condition;
                        PLAYER.step = 0;
                    }
                }
            }
        } else {
            g_Player.unk46 &= 0x7FFF;
            local_flags = 0xE;
            if (PLAYER.animFrameDuration < 0) {
                local_flags = 0x2E;
            }
        }
        break;
    case 0x51:
        func_8010DFF0(1, 1);
        if (PLAYER.animFrameDuration < 0) {
            local_flags = 0x2E;
        }
        break;
    }

    if (local_flags & 0x20) {
        func_8010E470(0, 0);
        local_flags |= 0x8000;
    }
    if (local_flags & 2) {
        if (g_Player.unk4C != 0) {
            func_8010DA48(0x14);
            PLAYER.step_s = 0;
            local_flags |= 0x8000;
        }
    }
    if (local_flags & 4) {
        if (!(g_Player.padPressed & PAD_DOWN)) {
            func_8010DA48(0x13);
            PLAYER.step_s = 2;
            local_flags |= 0x8000;
        }
    }
    if (local_flags & 1) {
        if (func_8010E27C()) {
            switch ((u8)g_Player.unk72) {
            case 0:
            case 3:
            case 4:
                func_8010E6AC(0);
                local_flags |= 0x8000;
                break;
            case 1:
            case 2:
                if (g_Player.padTapped & (PAD_RIGHT | PAD_LEFT)) {
                    PLAYER.step_s = 5;
                    func_8010DA48(0xF6);
                    SetSpeedX(FIX(0.75));
                    local_flags |= 0x8000;
                }
                break;
            }
        }
    }
    if ((local_flags & 0x8000) && (local_flags & 8)) {
        func_8010FAF4();
    }
}

void func_801139CC(s32 arg0) {
    s32 move = PLAYER.facingLeft != 0 ? -3 : 3;

    PLAYER.posY.i.hi -= 22;
    PLAYER.posX.i.hi = move + PLAYER.posX.i.hi;
    CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0x100, 4), 0);
    PLAYER.posY.i.hi = PLAYER.posY.i.hi + 22;
    PLAYER.posX.i.hi = PLAYER.posX.i.hi - move;

    if (arg0 & 1) {
        func_80102CD8(3);
        PlaySfx(NA_SE_SECRET_STAIRS);
    }
    if (arg0 & 2) {
        PLAYER.velocityX = 0;
        PLAYER.velocityY = 0;
    }
}
void func_80113AAC(void) {
    s32 var_s1 = 0;
    s32 temp;

    g_Player.unk4A++;
    if (func_8010FDF8(2) != 0) {
        return;
    }

    switch (PLAYER.step_s) {
    case 0:
        if (g_Player.pl_vram_flag & 2) {
            func_801139CC(3);
            if (g_Player.unk4A >= 5) {
                PLAYER.step_s = 2;
                PLAYER.rotZ = 0x800;
                PLAYER.rotPivotY = 2;
                PLAYER.rotPivotX = 0;
                PLAYER.drawFlags |= 4;
                PLAYER.facingLeft = (PLAYER.facingLeft + 1) & 1;
                func_8010DA48(0x2B);
            } else {
                PLAYER.step_s = 3;
            }
        } else if (g_Player.unk4A > 28) {
            PLAYER.step_s = 1;
            PLAYER.velocityY = -0x60000;
            func_8010DA48(0x1B);
        }
        break;

    case 1:
        if (g_Player.pl_vram_flag & 2) {
            PLAYER.step_s = 2;
            func_801139CC(3);
        } else {
            PLAYER.velocityY += 0x6000;
            if (PLAYER.velocityY > 0x8000) {
                var_s1 = 1;
            }
        }
        break;

    case 2:
        PLAYER.drawFlags |= 4;
        PLAYER.rotPivotX = 0;
        PLAYER.rotPivotY = 2;
        if (g_Player.unk4A >= 0x39) {
            func_8010DA48(0x2D);
            PLAYER.rotZ = 0;
            PLAYER.step_s = 4;
            PLAYER.drawFlags &= 0xFB;
            PLAYER.facingLeft = (PLAYER.facingLeft + 1) & 1;
        }
        break;

    case 3:
        if (g_Player.unk4A > 20) {
            var_s1 = 1;
        }
        break;

    case 4:
        PLAYER.velocityY += 0x1000;
        if (PLAYER.animFrameDuration < 0) {
            var_s1 = 2;
        }
        break;
    }

    if (var_s1 != 0) {
        temp = 0; // TODO: !FAKE
        if ((var_s1 - 1) != temp) {
            func_8010DA48(0x1C);
        }
        PLAYER.palette = 0x8100;
        PLAYER.step_s = 1;
        PLAYER.step = Player_Jump;
    }
}

s32 func_80113D7C(s16 damageAmount) {
    DamageParam damage;
    s32 sfx;
    s32 temp_s0;
    s16 step;
    u16 temp_s1;

    temp_s0 = HandleDamage(&damage, 2, damageAmount / 2, 1);
    func_80118C84(damage.damageTaken, 0);
    func_800FE8F0();
    if (temp_s0 != 4) {
        g_Player.D_80072F00[2] = 4;
        g_Player.unk40 = 0x8166;
        sfx = D_800ACF84[(rand() & 1) + 3];
        PlaySfx(sfx);
        if (step && step) // TODO: !FAKE
            ;
        return 0;
    }
    step = PLAYER.step;
    temp_s1 = PLAYER.step_s;
    damage.effects = 0;
    damage.damageKind = 0;
    SetPlayerStep(Player_Kill);
    func_80115394(&damage, step, temp_s1);
    return -1;
}

s32 func_80113E68(void) {
    s16 rnd = rand();
    PLAYER.ext.player.unkAC = 0x2E + (rnd % 3);
    return rnd % 16;
}

void func_80113EE0(void) {
    PLAYER.animSet = ANIMSET_DRA(1);
    PLAYER.drawFlags &= 0xF3;
    PLAYER.animFrameDuration = 0;
    PLAYER.animFrameIdx = 0;
    PLAYER.entityId = 0;
    PLAYER.drawMode = DRAW_DEFAULT;
    g_Player.unk44 = 0;
    g_Player.unk46 = 0;
    PLAYER.rotZ = 0;
    PLAYER.zPriority = g_unkGraphicsStruct.g_zEntityCenter.S16.unk0;
    if (g_Entities[E_WEAPON].entityId == E_UNK_22) {
        func_8010FAF4();
    }
}

void func_80113F7C(void) {
    Entity* entity = PLAYER.ext.generic.unkB8.entityPtr;
    s16 posX;
    s32 var_a0;
    s32 var_a2;

    if (entity->facingLeft != 0) {
        var_a2 = -entity->hitboxOffX;
    } else {
        var_a2 = entity->hitboxOffX;
    }

    if (PLAYER.facingLeft != 0) {
        var_a0 = -PLAYER.hitboxOffX;
    } else {
        var_a0 = PLAYER.hitboxOffX;
    }

    posX = var_a0 + PLAYER.posX.i.hi - entity->posX.i.hi - var_a2;

    if (ABS(posX) < 16) {
        if (entity->velocityX != 0) {
            if (entity->velocityX >= 0) {
                PLAYER.entityRoomIndex = 1;
                return;
            }
            goto block_14;
        }
        goto block_13;
    }
    // TODO: labels are !FAKE
block_13:
    if (posX < 0) {
    block_14:
        PLAYER.entityRoomIndex = 0;
        return;
    }

    PLAYER.entityRoomIndex = 1;
}

void AlucardHandleDamage(DamageParam* damage, s16 arg1) {
    s32 randbit;
    u8 unkAC_offset;
    s32 var_s0;
    s32 sfxIndex;
    bool step_sIsZero = false;

    switch (PLAYER.step_s) {
    case 0:
        step_sIsZero = true;
        func_80113EE0();
        if (damage->damageKind < 16) {
            func_80113F7C();
        } else {
            if (damage->damageKind == 16) {
                func_80113F7C();
            }
            if (damage->damageKind == 17) {
                PLAYER.entityRoomIndex = 1;
            }
            if (damage->damageKind == 18) {
                PLAYER.entityRoomIndex = 0;
            }
        }
        if (g_Player.unk0C & PLAYER_STATUS_AXEARMOR) {
            PLAYER.velocityY = FIX(-3);
            func_8010E3B8(FIX(-1.25));
            PLAYER.step = Player_AxearmorHit;
            PLAYER.step_s = 0;
            PLAYER.ext.player.unkAC = 0xD1;
            PlaySfx(0x6ED);
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0, 85), 0);
            D_8017A000.func_ptr_80170010();
            if (g_Player.unk72 != 0) {
                PLAYER.velocityY = 0;
            }
            return;
        }
        // Unfortunate reuse of var_s0 here. case 4 and 5 treat it as a step_s
        // offset, while others treat it as a velocity.
        var_s0 = 0;
        func_80111CC0();
        sfxIndex = 0;
        switch (damage->damageKind) {
        case 5:
            var_s0 = 13;
            g_Player.damageTaken = damage->damageTaken;
        case 4:
            PLAYER.posY.val -= 1;
            PLAYER.velocityY = FIX(-0.5);
            func_8010E3B8(FIX(-8));
            PLAYER.step_s = var_s0 + 2;
            PLAYER.ext.player.unkAC = 0x2E;
            g_Player.D_80072F00[2] = 0x200;
            PLAYER.facingLeft = PLAYER.entityRoomIndex;
            if (damage->damageKind == 4) {
                sfxIndex = (rand() & 1) + 1;
            }
            break;
        case 16:
        case 17:
        case 18:
            sfxIndex = (rand() & 1) + 3;
            switch (arg1) {
            case 0:
            case 1:
                break;
            case 3:
            case 4:
                var_s0 = FIX(1);
                break;
            }
            PLAYER.velocityY = var_s0 + FIX(-4);
            func_8010E3B8(FIX(-1.66666));
            PLAYER.step_s = 1;
            if (func_80113E68() == 0) {
                PLAYER.ext.player.unkAC = 0x40;
            }
            break;
        case 3:
        case 7:
            sfxIndex = (rand() & 1) + 3;
            switch (arg1) {
            case 3:
            case 4:
                var_s0 = FIX(1);
            case 0:
            default:
                PLAYER.velocityY = var_s0 + FIX(-4);
                func_8010E3B8(FIX(-1.66666));
                PLAYER.step_s = 1;
                if (func_80113E68() == 0) {
                    PLAYER.ext.player.unkAC = 0x40;
                }
                break;
            case 2:
            case 6:
                PLAYER.velocityY = 0;
                func_8010E3B8(FIX(-2.5));
                PLAYER.step_s = 7;
                PLAYER.ext.player.unkAC = 0x23;
                CreateEntFactoryFromEntity(g_CurrentEntity, 0, 0);
            }
            break;
        case 2:
            sfxIndex = (rand() & 1) + 5;
            switch (arg1) {
            case 0:
            case 1:
                PLAYER.velocityY = 0;
                func_8010E3B8(FIX(-2.5));
                PLAYER.step_s = 6;
                randbit = (rand() & 1);
                // Weird test, I  think PLAYER.entityRoomIndex is a wrong name.
                // But if they don't match, we add 2 to the offset.
                unkAC_offset =
                    randbit |
                    ((PLAYER.entityRoomIndex != PLAYER.facingLeft) ? 2 : 0);
                PLAYER.ext.player.unkAC = unkAC_offset + 0x31;
                CreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(0x600, 0), 0);
                break;
            case 2:
            case 6:
                PLAYER.velocityY = 0;
                func_8010E3B8(FIX(-2.5));
                PLAYER.step_s = 7;
                PLAYER.ext.player.unkAC = 0x23;
                CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0, 0), 0);
                break;
            case 3:
            case 4:
            case 5:
            default:
                PLAYER.velocityY = FIX(-2);
                func_8010E3B8(FIX(-1.25));
                PLAYER.step_s = 1;
                func_80113E68();
                break;
            }
            break;
        default:
            FntPrint("dam_kind:%04x\n", damage->damageKind);
            break;
        }
        g_Player.unk40 = 0x8166;
        g_Player.D_80072F00[2] = 6;
        PlaySfx(D_800ACF84[sfxIndex]);
        if (damage->effects & 0x100) {
            g_Player.D_80072F00[1] =
                GetStatusAilmentTimer(STATUS_AILMENT_CURSE, 0x400);
            g_Player.unk40 = 0x8165;
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0x200, 47), 0);
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0x1700, 44), 0);
            PlaySfx(NA_SE_VO_AL_WHAT);
        } else if (damage->effects & 0x80) {
            g_Player.D_80072F00[0] =
                GetStatusAilmentTimer(STATUS_AILMENT_POISON, 0xFFF);
            g_Player.unk40 = 0x8164;
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0x1600, 44), 0);
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0x100, 47), 0);
            PlaySfx(NA_SE_VO_AL_WHAT);
        } else if (damage->effects & 0x8000) {
            PlaySfx(0x690);
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0x4500, 44), 0);
            g_Player.unk40 = 0x8160;
            if (damage->effects & 0x10000) {
                CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0, 19), 0);
                g_Player.D_80072F00[2] = 10;
            } else {
                CreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(0x100, 17), 0);
                CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0, 18), 0);
                g_Player.D_80072F00[2] = 16;
            }
        } else if (damage->effects & 0x4000) {
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0, 45), 0);
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0x4600, 44), 0);
            g_Player.D_80072F00[2] = 24;
            g_Player.unk40 = 0x8102;
        } else if (damage->effects & 0x2000) {
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0, 46), 0);
            g_Player.D_80072F00[2] = 12;
            g_Player.unk40 = 0x8169;
            PLAYER.ext.player.unkAC = 0x2E;
        } else {
            if (damage->effects & 0x1000) {
                CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0, 119), 0);
                CreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(0x6800, 44), 0);
                g_Player.D_80072F00[2] = 8;
                g_Player.unk40 = 0x8168;
            }
            if (damage->effects & 0x800) {
                CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0, 113), 0);
                CreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(0x6200, 44), 0);
                g_Player.D_80072F00[2] = 16;
                g_Player.unk40 = 0x8164;
            }
            if (damage->effects & 0x40) {
                PlaySfx(0x62E);
                g_Player.unk40 = 0x8166;
                CreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(0x4200, 44), 0);
                if (damage->effects & 0x10000) {
                    CreateEntFactoryFromEntity(
                        g_CurrentEntity, FACTORY(0x500, 21), 0);
                    g_Player.D_80072F00[2] = 10;
                } else {
                    CreateEntFactoryFromEntity(
                        g_CurrentEntity, FACTORY(0x500, 20), 0);
                    g_Player.D_80072F00[2] = 16;
                }
            } else if (!(damage->effects & 0xFAC0)) {
                CreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(0x5800, 44), 0);
            }
        }

        break;
    case 1:
        if (func_8010FDF8(0x20280) != 0) {
            return;
        }
        if (PLAYER.animFrameDuration < 0) {
            func_8010DA48(0x1C);
            PLAYER.facingLeft = (PLAYER.facingLeft + 1) & 1;
        }
        break;
    case 2:
    case 15:
        if ((g_Player.unk04 & 0x8000) && !(g_Player.pl_vram_flag & 0x8000)) {
            goto deepcond;
        }
        if ((g_Player.pl_vram_flag & 0x8000) && !(g_GameTimer & 1)) {
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0xA00, 69), 0);
        }
        if (!(g_Player.pl_vram_flag & 0xE)) {
            break;
        }
        if (g_Player.pl_vram_flag & 2) {
            func_801139CC(1);
            PLAYER.velocityX /= 2;
            PLAYER.velocityY = 0;
            g_Player.D_80072F00[8] = 24;
            PLAYER.step_s = 5;
            if (g_Player.unk52 == 0xF &&
                (func_80113D7C(g_Player.damageTaken) != 0)) {
                return;
            }
            break;
        }
        if ((g_StageId != STAGE_BO6) && (g_StageId != STAGE_RBO6) &&
            (g_StageId != STAGE_DRE)) {
            for (var_s0 = 2; var_s0 < 7; var_s0++) {
                if ((g_Player.colliders3[var_s0].effects & 2)) {
                    break;
                }
            }
            if (var_s0 == 7) {
                for (var_s0 = 9; var_s0 < 14; var_s0++) {
                    if ((g_Player.colliders3[var_s0].effects & 2)) {
                        break;
                    }
                }
            }
            if (var_s0 == 14) {
            // Not a very good label name, but it's deep in a bunch of
            // conditionals.
            deepcond:
                PLAYER.velocityY = FIX(-4);
                func_8010E3B8(FIX(-1.25));
                PLAYER.ext.player.unkAC = 0x2F;
                var_s0 = -3;
                if (PLAYER.velocityX != 0) {
                    var_s0 = 3;
                }
                PLAYER.posY.i.hi += 0x15;
                PLAYER.posX.i.hi = var_s0 + PLAYER.posX.i.hi;
                CreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(0x900, 4), 0);
                PLAYER.posY.i.hi -= 0x15;
                PLAYER.posX.i.hi -= var_s0;
                PlaySfx(0x644);
                func_80102CD8(2);
                PLAYER.step_s = 1;
                if (g_Player.unk52 == 0xF &&
                    (func_80113D7C(g_Player.damageTaken) != 0)) {
                    return;
                }
                break;
            }
        }

        if (PLAYER.step_s == 0xF) {
            g_Player.D_80072F00[8] = 8;
            func_8010DA48(0x3F);
            PlaySfx(0x644);
            PLAYER.velocityY = FIX(-2.5);
            func_80102CD8(2);
            PLAYER.step_s = 3;
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0x800, 31), 0);
            if (func_80113D7C(g_Player.damageTaken) != 0) {
                return;
            }
            break;
        }
        PLAYER.velocityY = 0;
        g_Player.D_80072F00[8] = 48;
        PLAYER.velocityX /= 2;
        PlaySfx(0x647);
        PLAYER.rotZ = 0x400;
        PLAYER.rotPivotX = 0x10;
        PLAYER.rotPivotY = 4;
        PLAYER.drawFlags |= 4;
        func_8010DA48(0x2C);
        PLAYER.step_s = 0xE;
        CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0x800, 31), 0);
        break;
    case 3:
        if (g_Player.D_80072F00[8] == 0) {
            SetSpeedX(FIX(0.75));
            if (func_8010FDF8(0x20280) != 0) {
                return;
            }
        }
        break;
    case 5:
        DecelerateX(FIX(1.0 / 8));
        if (g_Player.D_80072F00[8] != 0) {
            if ((g_Player.pl_vram_flag & 2) && !(g_GameTimer & 3)) {
                func_801139CC(0);
            }
            break;
        } else if (g_Player.pl_vram_flag & 0xC) {
            if (!(g_Player.pl_vram_flag & 0xFF03)) {
                PLAYER.velocityY += FIX(12.0 / 128);
                if (PLAYER.velocityY > FIX(7)) {
                    PLAYER.velocityY = FIX(7);
                }
                if (!(g_GameTimer & 3)) {
                    CreateEntFactoryFromEntity(
                        g_CurrentEntity, FACTORY(0x400, 12), 0);
                }
                break;
            }
        }
        PLAYER.step_s = 1;
        func_80113E68();
        PLAYER.animFrameIdx = 0;
        PLAYER.animFrameDuration = 0;
        break;
    case 14:
        PLAYER.drawFlags |= 4;
        if (g_Player.D_80072F00[8] <= 0) {
            PLAYER.drawFlags &= ~4;
            PLAYER.rotZ = 0x800;
            PLAYER.velocityY = 0;
            PLAYER.velocityX /= -2;
            func_8010DA48(0x1C);
            PLAYER.step_s = 1;
            PLAYER.step = 4;
            g_Player.unk44 = 0;
        }
        break;
    case 6:
    case 7:
        DecelerateX(FIX(1.0 / 8));
        if (!(g_Player.pl_vram_flag & 1)) {
            func_8010E7AC();
        }
        if (PLAYER.animFrameDuration < 0) {
            if (PLAYER.step_s == 6) {
                func_8010E570(0);
            } else {
                func_8010E470(0, PLAYER.velocityX);
            }
        }
        break;
    }
    if (step_sIsZero && (g_Player.unk72 != 0)) {
        PLAYER.velocityY = 0;
    }
}

void func_80114DF4(s32 arg0) {
    s16 randvar;
    s32 newlyPetrified;
    s32 yShift;

    newlyPetrified = 0;
    switch (PLAYER.step_s) {
    case 0:
        newlyPetrified = 1;
        func_80113EE0();
        func_80113F7C();
        PLAYER.velocityY = FIX(-4);
        if (!(g_Player.pl_vram_flag & 1)) {
            PLAYER.velocityY = FIX(-2);
        }
        func_8010E3B8(FIX(-1.25));
        func_80113E68();
        PLAYER.palette = 0x8161;
        PlaySfx(0x6EC);
        g_Player.D_80072F00[2] = 0;
        g_Player.D_80072F00[0] = 0;
        g_Player.D_80072F00[1] = 0;
        g_Player.unk5E = GetStatusAilmentTimer(STATUS_AILMENT_PETRIFIED, 8);
        CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0x300, 47), 0);
        func_8010E168(1, 4);
        PLAYER.step_s = 1;
        break;
    case 1:
        func_8010E168(1, 4);
        PLAYER.palette = 0x8161;
        if (func_8010FDF8(0x20280) != 0) {
            PLAYER.step = Player_StatusStone;
            PLAYER.velocityY = 0;
            PLAYER.velocityX = 0;
            func_80102CD8(1);
            PlaySfx(0x644);
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0, 39), 0);

            randvar = rand() % 64;

            if (g_Status.hp == 0) {
                D_80137FE0 = 0x20;
                randvar = 2;
            }
            if (randvar << 0x10) {
                PLAYER.palette = (randvar & 1) - 0x7E62;
                func_8010DA48(randvar & 1 | 0x38);
                CreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(0x300, 16), 0);
            } else {
                PLAYER.palette = 0x819E;
                func_8010DA48(0x3A);
                CreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(0x700, 29), 0);
            }
            PLAYER.step_s = 2;
        }
        break;
    case 2:
        if (D_80097448[0] >= 0x29) {
            yShift = FIX(11.0 / 256);
        } else {
            yShift = FIX(44.0 / 256);
        }

        // I don't know man
        do {
        } while (0);

        if (!(g_Player.pl_vram_flag & 1)) {
            PLAYER.velocityY += yShift;
            if (PLAYER.velocityY > FIX(7)) {
                PLAYER.velocityY = FIX(7);
            }
            func_8010E168(1, 4);
            break;
        }

        if (!(g_Player.unk04 & 1)) {
            func_80102CD8(1);
            PlaySfx(0x644);
        }

        PLAYER.velocityY = 0;
        if (g_Status.hp == 0) {
            if (--D_80137FE0 == 0) {
                PLAYER.step = Player_Kill;
                PlaySfx(0x6F6);
                PLAYER.step_s = 16;
            }
            func_8010E168(1, 4);
            break;
        }
        // Handles wiggling out of being petrified.
        if (g_Player.padTapped & (PAD_UP | PAD_RIGHT | PAD_DOWN | PAD_LEFT) ||
            arg0 != 0 || D_800ACE44 != 0) {
            PLAYER.animFrameDuration = 0x10;
            g_Player.padTapped |= (PAD_UP | PAD_RIGHT | PAD_DOWN | PAD_LEFT);
            // Counter for how many wiggles left until we're out
            g_Player.unk5E--;
            PlaySfx(0x608);
            if (g_Player.unk5E == 0) {
                func_8010DA48(0x3B);
                if (PLAYER.ext.player.unkAC != 0x3A) {
                    CreateEntFactoryFromEntity(
                        g_CurrentEntity, FACTORY(0x300, 16), 0);
                } else {
                    CreateEntFactoryFromEntity(
                        g_CurrentEntity, FACTORY(0, 32), 0);
                }
                PlaySfx(0x6E7);
                PLAYER.step = Player_Hit;
                PLAYER.step_s = 6;
                PLAYER.palette = 0x8100;
                break;
            }
            func_8010E168(1, 0x1C);
            PLAYER.step_s = 3;
            if (PLAYER.ext.player.unkAC != 0x3A) {
                CreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(0x300, 13), 0);
                CreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(0x300, 31), 0);
            } else {
                CreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(0x800, 13), 0);
                CreateEntFactoryFromEntity(
                    g_CurrentEntity, FACTORY(0x700, 30), 0);
            }
        }
        PLAYER.palette = ((PLAYER.ext.player.unkAC + 0xFFC8) & 1) - 0x7E62;
        break;
    case 3:
        if (PLAYER.animFrameDuration < 0) {
            PLAYER.step_s = 2;
            PLAYER.drawFlags &= 0xFB;
        } else {
            PLAYER.rotPivotX = 0;
            PLAYER.drawFlags |= 4;
            PLAYER.rotZ = D_800ACF94[PLAYER.animFrameDuration] >> 4;
            if (PLAYER.rotZ == 0) {
                PLAYER.rotPivotY = 0x18;
            } else {
                PLAYER.rotPivotY = 0x14;
            }
        }
        break;
    }
    if (PLAYER.ext.player.unkAC == 0x3A) {
        func_8010E168(1, 4);
    }
    if (newlyPetrified && (g_Player.unk72 != 0)) {
        PLAYER.velocityY = 0;
    }
}

INCLUDE_ASM("dra/nonmatchings/72BB0", func_80115394);

void func_80115BB0(void) {
    PLAYER.drawFlags = FLAG_DRAW_ROTZ;
    PLAYER.velocityY = 0;
    PLAYER.velocityX = 0;
    PLAYER.animFrameDuration = 4;

    if (D_80097420[0] == 0) {
        if (g_Player.pl_vram_flag & 1) {
            func_8010E570(0);
        } else {
            func_8010E7AC();
        }
        CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0x4a00, 44), 0);
        g_PlayerDraw->enableColorBlend = 0;
    }
}

// same as RIC/func_8015BB80
void func_80115C50(void) {
    s32 dist;

    if (g_StageId == STAGE_TOP) {
        dist = g_Tilemap.left * 256 + playerX;
        dist = ABS(dist);

        if (dist - 8000 > 0) {
            PLAYER.posX.i.hi--;
        }

        dist = g_Tilemap.left * 256 + playerX;
        dist = ABS(dist);

        if (dist - 8000 < 0) {
            PLAYER.posX.i.hi++;
        }
    }

    if (g_StageId == (STAGE_TOP | STAGE_INVERTEDCASTLE_FLAG)) {
        dist = g_Tilemap.left * 256 + playerX;
        dist = ABS(dist);

        if (dist - 8384 > 0) {
            PLAYER.posX.i.hi--;
        }

        dist = g_Tilemap.left * 256 + playerX;
        dist = ABS(dist);

        if (dist - 8384 < 0) {
            PLAYER.posX.i.hi++;
        }
    }
}

// Corresponding RIC function is func_8015BCD0
void func_80115DA0(void) {
    PLAYER.velocityY = 0;
    PLAYER.velocityX = 0;
    g_Player.D_80072EF4 = 0;
    g_Player.D_80072EFC = 4;

    switch (PLAYER.step_s) {
    case 0:
        if (PLAYER.animFrameIdx == 8 && PLAYER.animFrameDuration == 1 &&
            CreateEntFactoryFromEntity(g_CurrentEntity, FACTORY(0, 121), 0) ==
                NULL) {
            PLAYER.animFrameDuration = 2;
        }
        if (PLAYER.animFrameDuration < 0) {
            func_8010E570(0);
        }
        break;

    case 2:
        func_80115C50();
        if (PLAYER.animFrameIdx == 8 && PLAYER.animFrameDuration == 1 &&
            CreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(0x200, 121), 0) == NULL) {
            PLAYER.animFrameDuration = 2;
        }
        if (PLAYER.animFrameDuration < 0) {
            func_8010E570(0);
        }
        break;

    case 4:
        func_80115C50();
        if (PLAYER.animFrameIdx == 8 && PLAYER.animFrameDuration == 1 &&
            CreateEntFactoryFromEntity(
                g_CurrentEntity, FACTORY(0x400, 121), 0) == NULL) {
            PLAYER.animFrameDuration = 2;
        }
        if (PLAYER.animFrameDuration < 0) {
            func_8010E570(0);
        }
        break;

    case 1:
    case 3:
    case 5:
        if (PLAYER.animFrameDuration < 0) {
            func_8010E570(0);
        }
        if (g_Player.unk1C != 0) {
            func_8010E570(0);
        }
        break;
    }
}
