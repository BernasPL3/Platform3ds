#include <3ds.h>
#include <citro2d.h>

int main() {
    gfxInitDefault();
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);

    C3D_RenderTarget* top =
        C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

    float playerX = 120;
    float playerY = 100;

    while (aptMainLoop()) {

        hidScanInput();

        u32 kDown = hidKeysHeld();

        if (kDown & KEY_START)
            break;

        if (kDown & KEY_LEFT)
            playerX -= 2;

        if (kDown & KEY_RIGHT)
            playerX += 2;

        if (kDown & KEY_UP)
            playerY -= 2;

        if (kDown & KEY_DOWN)
            playerY += 2;

        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

        C2D_TargetClear(top, C2D_Color32(0,0,50,255));
        C2D_SceneBegin(top);

        C2D_DrawRectangle(
            playerX,
            playerY,
            0,
            20,
            20,
            C2D_Color32(255,255,255,255),
            C2D_Color32(255,255,255,255),
            C2D_Color32(255,255,255,255),
            C2D_Color32(255,255,255,255)
        );

        C3D_FrameEnd(0);
    }

    C2D_Fini();
    gfxExit();

    return 0;
}
