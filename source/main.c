#include <3ds.h>
#include <citro2d.h>

int main() {

    gfxInitDefault();

    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);

    C3D_RenderTarget* top =
        C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

    float x = 120;
    float y = 100;

    while (aptMainLoop()) {

        hidScanInput();

        u32 kHeld = hidKeysHeld();

        if (kHeld & KEY_START)
            break;

        if (kHeld & KEY_LEFT)  x -= 2;
        if (kHeld & KEY_RIGHT) x += 2;
        if (kHeld & KEY_UP)    y -= 2;
        if (kHeld & KEY_DOWN)  y += 2;

        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

        C2D_TargetClear(top, C2D_Color32(0,0,80,255));
        C2D_SceneBegin(top);

        C2D_DrawRectSolid(
            x,
            y,
            0,
            20,
            20,
            C2D_Color32(255,255,255,255)
        );

        C3D_FrameEnd(0);
    }

    C2D_Fini();
    C3D_Fini();
    gfxExit();

    return 0;
}
