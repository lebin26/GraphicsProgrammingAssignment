#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")
#define WINDOW_TITLE L"OpenGL Window"

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg){
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;
	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	int n = ChoosePixelFormat(hdc, &pfd);
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//===================
// Draw parts of body
//===================

void drawBladeHalf(float sign)
{
    // =====================================
    // 1. BLADE FACETS (Dense Triangulated Facets)
    // =====================================
    glBegin(GL_TRIANGLES);

    // ----------------------------------------------------
    // Section A: Sharp Pointy Tip (y = 3.45 down to y = 2.7)
    // ----------------------------------------------------
    // Tip Left Outer Tri
    glColor3f(sign > 0 ? 0.94f : 0.72f, sign > 0 ? 0.96f : 0.74f, sign > 0 ? 0.99f : 0.78f);
    glVertex3f(0.0f, 3.45f, 0.0f);
    glVertex3f(-0.35f, 2.7f, 0.0f);
    glVertex3f(-0.12f, 2.7f, 0.05f * sign);

    // Tip Left Inner Tri
    glColor3f(sign > 0 ? 0.90f : 0.69f, sign > 0 ? 0.93f : 0.71f, sign > 0 ? 0.97f : 0.75f);
    glVertex3f(0.0f, 3.45f, 0.0f);
    glVertex3f(-0.12f, 2.7f, 0.05f * sign);
    glVertex3f(0.0f, 3.0f, 0.08f * sign);

    // Tip Center Ridge Cap Tri (Connecting tip down to ridge vertex)
    glColor3f(sign > 0 ? 0.86f : 0.65f, sign > 0 ? 0.89f : 0.68f, sign > 0 ? 0.94f : 0.72f);
    glVertex3f(0.0f, 3.45f, 0.0f);
    glVertex3f(0.0f, 3.0f, 0.08f * sign);
    glVertex3f(0.12f, 2.7f, 0.05f * sign);

    // Tip Right Outer Tri
    glColor3f(sign > 0 ? 0.78f : 0.58f, sign > 0 ? 0.82f : 0.62f, sign > 0 ? 0.88f : 0.68f);
    glVertex3f(0.0f, 3.45f, 0.0f);
    glVertex3f(0.12f, 2.7f, 0.05f * sign);
    glVertex3f(0.35f, 2.7f, 0.0f);

    // ----------------------------------------------------
    // Section B: Upper Blade Top Tier (y = 2.7 down to y = 1.6)
    // ----------------------------------------------------
    // Inner ridge Left Top Tri 1
    glColor3f(sign > 0 ? 0.90f : 0.68f, sign > 0 ? 0.92f : 0.70f, sign > 0 ? 0.97f : 0.75f);
    glVertex3f(0.0f, 3.0f, 0.08f * sign);
    glVertex3f(-0.12f, 2.7f, 0.05f * sign);
    glVertex3f(0.0f, 1.6f, 0.085f * sign);

    // Inner ridge Left Top Tri 2
    glColor3f(sign > 0 ? 0.87f : 0.65f, sign > 0 ? 0.90f : 0.68f, sign > 0 ? 0.95f : 0.73f);
    glVertex3f(-0.12f, 2.7f, 0.05f * sign);
    glVertex3f(-0.13f, 1.6f, 0.052f * sign);
    glVertex3f(0.0f, 1.6f, 0.085f * sign);

    // Outer Bevel Left Top Tri 1
    glColor3f(sign > 0 ? 0.83f : 0.62f, sign > 0 ? 0.86f : 0.65f, sign > 0 ? 0.92f : 0.70f);
    glVertex3f(-0.12f, 2.7f, 0.05f * sign);
    glVertex3f(-0.35f, 2.7f, 0.0f);
    glVertex3f(-0.35f, 1.6f, 0.0f);

    // Outer Bevel Left Top Tri 2
    glColor3f(sign > 0 ? 0.81f : 0.60f, sign > 0 ? 0.84f : 0.63f, sign > 0 ? 0.90f : 0.68f);
    glVertex3f(-0.12f, 2.7f, 0.05f * sign);
    glVertex3f(-0.35f, 1.6f, 0.0f);
    glVertex3f(-0.13f, 1.6f, 0.052f * sign);

    // Inner ridge Right Top Tri 1
    glColor3f(sign > 0 ? 0.76f : 0.57f, sign > 0 ? 0.80f : 0.61f, sign > 0 ? 0.86f : 0.67f);
    glVertex3f(0.0f, 3.0f, 0.08f * sign);
    glVertex3f(0.0f, 1.6f, 0.085f * sign);
    glVertex3f(0.12f, 2.7f, 0.05f * sign);

    // Inner ridge Right Top Tri 2
    glColor3f(sign > 0 ? 0.73f : 0.54f, sign > 0 ? 0.77f : 0.58f, sign > 0 ? 0.83f : 0.64f);
    glVertex3f(0.12f, 2.7f, 0.05f * sign);
    glVertex3f(0.0f, 1.6f, 0.085f * sign);
    glVertex3f(0.13f, 1.6f, 0.052f * sign);

    // Outer Bevel Right Top Tri 1
    glColor3f(sign > 0 ? 0.68f : 0.51f, sign > 0 ? 0.72f : 0.55f, sign > 0 ? 0.78f : 0.61f);
    glVertex3f(0.12f, 2.7f, 0.05f * sign);
    glVertex3f(0.35f, 1.6f, 0.0f);
    glVertex3f(0.35f, 2.7f, 0.0f);

    // Outer Bevel Right Top Tri 2
    glColor3f(sign > 0 ? 0.65f : 0.48f, sign > 0 ? 0.69f : 0.52f, sign > 0 ? 0.75f : 0.58f);
    glVertex3f(0.12f, 2.7f, 0.05f * sign);
    glVertex3f(0.13f, 1.6f, 0.052f * sign);
    glVertex3f(0.35f, 1.6f, 0.0f);

    // ----------------------------------------------------
    // Section C: Upper Blade Bottom Tier (y = 1.6 down to y = 0.5)
    // ----------------------------------------------------
    // Inner ridge Left Bottom Tri 1
    glColor3f(sign > 0 ? 0.88f : 0.66f, sign > 0 ? 0.91f : 0.69f, sign > 0 ? 0.96f : 0.74f);
    glVertex3f(0.0f, 1.6f, 0.085f * sign);
    glVertex3f(-0.13f, 1.6f, 0.052f * sign);
    glVertex3f(0.0f, 0.5f, 0.09f * sign);

    // Inner ridge Left Bottom Tri 2
    glColor3f(sign > 0 ? 0.85f : 0.64f, sign > 0 ? 0.88f : 0.66f, sign > 0 ? 0.94f : 0.72f);
    glVertex3f(-0.13f, 1.6f, 0.052f * sign);
    glVertex3f(-0.14f, 0.5f, 0.055f * sign);
    glVertex3f(0.0f, 0.5f, 0.09f * sign);

    // Outer Bevel Left Bottom Tri 1
    glColor3f(sign > 0 ? 0.80f : 0.60f, sign > 0 ? 0.84f : 0.63f, sign > 0 ? 0.90f : 0.69f);
    glVertex3f(-0.13f, 1.6f, 0.052f * sign);
    glVertex3f(-0.35f, 1.6f, 0.0f);
    glVertex3f(-0.35f, 0.5f, 0.0f);

    // Outer Bevel Left Bottom Tri 2
    glColor3f(sign > 0 ? 0.78f : 0.58f, sign > 0 ? 0.82f : 0.61f, sign > 0 ? 0.88f : 0.67f);
    glVertex3f(-0.13f, 1.6f, 0.052f * sign);
    glVertex3f(-0.35f, 0.5f, 0.0f);
    glVertex3f(-0.14f, 0.5f, 0.055f * sign);

    // Inner ridge Right Bottom Tri 1
    glColor3f(sign > 0 ? 0.74f : 0.55f, sign > 0 ? 0.78f : 0.59f, sign > 0 ? 0.84f : 0.65f);
    glVertex3f(0.0f, 1.6f, 0.085f * sign);
    glVertex3f(0.0f, 0.5f, 0.09f * sign);
    glVertex3f(0.13f, 1.6f, 0.052f * sign);

    // Inner ridge Right Bottom Tri 2
    glColor3f(sign > 0 ? 0.71f : 0.52f, sign > 0 ? 0.75f : 0.56f, sign > 0 ? 0.81f : 0.62f);
    glVertex3f(0.13f, 1.6f, 0.052f * sign);
    glVertex3f(0.0f, 0.5f, 0.09f * sign);
    glVertex3f(0.14f, 0.5f, 0.055f * sign);

    // Outer Bevel Right Bottom Tri 1
    glColor3f(sign > 0 ? 0.66f : 0.49f, sign > 0 ? 0.70f : 0.53f, sign > 0 ? 0.76f : 0.59f);
    glVertex3f(0.13f, 1.6f, 0.052f * sign);
    glVertex3f(0.35f, 0.5f, 0.0f);
    glVertex3f(0.35f, 1.6f, 0.0f);

    // Outer Bevel Right Bottom Tri 2
    glColor3f(sign > 0 ? 0.63f : 0.46f, sign > 0 ? 0.67f : 0.50f, sign > 0 ? 0.73f : 0.56f);
    glVertex3f(0.13f, 1.6f, 0.052f * sign);
    glVertex3f(0.14f, 0.5f, 0.055f * sign);
    glVertex3f(0.35f, 0.5f, 0.0f);

    // ----------------------------------------------------
    // Section D: Lower Blade Upper Half (y = 0.5 down to y = -0.25)
    // ----------------------------------------------------
    // Inner ridge Left Mid Tri 1
    glColor3f(sign > 0 ? 0.85f : 0.65f, sign > 0 ? 0.89f : 0.68f, sign > 0 ? 0.94f : 0.74f);
    glVertex3f(0.0f, 0.5f, 0.09f * sign);
    glVertex3f(-0.14f, 0.5f, 0.055f * sign);
    glVertex3f(0.0f, -0.25f, 0.085f * sign);

    // Inner ridge Left Mid Tri 2
    glColor3f(sign > 0 ? 0.83f : 0.63f, sign > 0 ? 0.87f : 0.66f, sign > 0 ? 0.92f : 0.72f);
    glVertex3f(-0.14f, 0.5f, 0.055f * sign);
    glVertex3f(-0.14f, -0.25f, 0.05f * sign);
    glVertex3f(0.0f, -0.25f, 0.085f * sign);

    // Outer Bevel Left Mid Tri 1
    glColor3f(sign > 0 ? 0.79f : 0.59f, sign > 0 ? 0.83f : 0.63f, sign > 0 ? 0.89f : 0.69f);
    glVertex3f(-0.14f, 0.5f, 0.055f * sign);
    glVertex3f(-0.35f, 0.5f, 0.0f);
    glVertex3f(-0.35f, -0.25f, 0.0f);

    // Outer Bevel Left Mid Tri 2
    glColor3f(sign > 0 ? 0.77f : 0.57f, sign > 0 ? 0.81f : 0.61f, sign > 0 ? 0.87f : 0.67f);
    glVertex3f(-0.14f, 0.5f, 0.055f * sign);
    glVertex3f(-0.35f, -0.25f, 0.0f);
    glVertex3f(-0.14f, -0.25f, 0.05f * sign);

    // Inner ridge Right Mid Tri 1
    glColor3f(sign > 0 ? 0.72f : 0.54f, sign > 0 ? 0.76f : 0.58f, sign > 0 ? 0.82f : 0.64f);
    glVertex3f(0.0f, 0.5f, 0.09f * sign);
    glVertex3f(0.0f, -0.25f, 0.085f * sign);
    glVertex3f(0.14f, 0.5f, 0.055f * sign);

    // Inner ridge Right Mid Tri 2
    glColor3f(sign > 0 ? 0.69f : 0.51f, sign > 0 ? 0.73f : 0.55f, sign > 0 ? 0.79f : 0.61f);
    glVertex3f(0.14f, 0.5f, 0.055f * sign);
    glVertex3f(0.0f, -0.25f, 0.085f * sign);
    glVertex3f(0.14f, -0.25f, 0.05f * sign);

    // Outer Bevel Right Mid Tri 1
    glColor3f(sign > 0 ? 0.64f : 0.47f, sign > 0 ? 0.68f : 0.51f, sign > 0 ? 0.75f : 0.58f);
    glVertex3f(0.14f, 0.5f, 0.055f * sign);
    glVertex3f(0.35f, -0.25f, 0.0f);
    glVertex3f(0.35f, 0.5f, 0.0f);

    // Outer Bevel Right Mid Tri 2
    glColor3f(sign > 0 ? 0.62f : 0.45f, sign > 0 ? 0.66f : 0.49f, sign > 0 ? 0.73f : 0.56f);
    glVertex3f(0.14f, 0.5f, 0.055f * sign);
    glVertex3f(0.14f, -0.25f, 0.05f * sign);
    glVertex3f(0.35f, -0.25f, 0.0f);

    // ----------------------------------------------------
    // Section E: Lower Blade Bottom Half (y = -0.25 down to y = -1.0)
    // ----------------------------------------------------
    // Inner ridge Left Base Tri 1
    glColor3f(sign > 0 ? 0.83f : 0.63f, sign > 0 ? 0.87f : 0.66f, sign > 0 ? 0.92f : 0.72f);
    glVertex3f(0.0f, -0.25f, 0.085f * sign);
    glVertex3f(-0.14f, -0.25f, 0.05f * sign);
    glVertex3f(0.0f, -1.0f, 0.08f * sign);

    // Inner ridge Left Base Tri 2
    glColor3f(sign > 0 ? 0.81f : 0.61f, sign > 0 ? 0.85f : 0.64f, sign > 0 ? 0.90f : 0.70f);
    glVertex3f(-0.14f, -0.25f, 0.05f * sign);
    glVertex3f(-0.14f, -1.0f, 0.045f * sign);
    glVertex3f(0.0f, -1.0f, 0.08f * sign);

    // Diagonal Bevel Left Base Tri 1 (Folded inward according to reference)
    glColor3f(sign > 0 ? 0.78f : 0.58f, sign > 0 ? 0.82f : 0.61f, sign > 0 ? 0.88f : 0.67f);
    glVertex3f(-0.14f, -0.25f, 0.05f * sign);
    glVertex3f(-0.35f, -0.25f, 0.0f);
    glVertex3f(-0.35f, -1.0f, 0.0f);

    // Diagonal Bevel Left Base Tri 2
    glColor3f(sign > 0 ? 0.75f : 0.55f, sign > 0 ? 0.79f : 0.58f, sign > 0 ? 0.85f : 0.64f);
    glVertex3f(-0.14f, -0.25f, 0.05f * sign);
    glVertex3f(-0.35f, -1.0f, 0.0f);
    glVertex3f(-0.14f, -1.0f, 0.045f * sign);

    // Inner ridge Right Base Tri 1
    glColor3f(sign > 0 ? 0.70f : 0.52f, sign > 0 ? 0.74f : 0.56f, sign > 0 ? 0.80f : 0.62f);
    glVertex3f(0.0f, -0.25f, 0.085f * sign);
    glVertex3f(0.0f, -1.0f, 0.08f * sign);
    glVertex3f(0.14f, -0.25f, 0.05f * sign);

    // Inner ridge Right Base Tri 2
    glColor3f(sign > 0 ? 0.67f : 0.49f, sign > 0 ? 0.71f : 0.53f, sign > 0 ? 0.77f : 0.59f);
    glVertex3f(0.14f, -0.25f, 0.05f * sign);
    glVertex3f(0.0f, -1.0f, 0.08f * sign);
    glVertex3f(0.14f, -1.0f, 0.045f * sign);

    // Diagonal Bevel Right Base Tri 1
    glColor3f(sign > 0 ? 0.62f : 0.45f, sign > 0 ? 0.66f : 0.49f, sign > 0 ? 0.73f : 0.56f);
    glVertex3f(0.14f, -0.25f, 0.05f * sign);
    glVertex3f(0.35f, -1.0f, 0.0f);
    glVertex3f(0.35f, -0.25f, 0.0f);

    // Diagonal Bevel Right Base Tri 2
    glColor3f(sign > 0 ? 0.59f : 0.42f, sign > 0 ? 0.63f : 0.46f, sign > 0 ? 0.70f : 0.53f);
    glVertex3f(0.14f, -0.25f, 0.05f * sign);
    glVertex3f(0.14f, -1.0f, 0.045f * sign);
    glVertex3f(0.35f, -1.0f, 0.0f);

    glEnd();

    // =====================================
    // 2. CROSSGUARD (Faceted Triangle Mesh)
    // =====================================
    glBegin(GL_TRIANGLES);

    // Center boss - Split into 2 triangles
    glColor3f(sign > 0 ? 0.50f : 0.38f, sign > 0 ? 0.52f : 0.40f, sign > 0 ? 0.56f : 0.44f);
    glVertex3f(-0.18f, -1.0f, 0.09f * sign);
    glVertex3f(0.18f, -1.0f, 0.09f * sign);
    glVertex3f(0.18f, -1.22f, 0.09f * sign);

    glVertex3f(-0.18f, -1.0f, 0.09f * sign);
    glVertex3f(0.18f, -1.22f, 0.09f * sign);
    glVertex3f(-0.18f, -1.22f, 0.09f * sign);

    // Left wing upper - Split into 2 triangles
    glColor3f(sign > 0 ? 0.58f : 0.44f, sign > 0 ? 0.61f : 0.47f, sign > 0 ? 0.66f : 0.52f);
    glVertex3f(-0.18f, -1.0f, 0.07f * sign);
    glVertex3f(-0.35f, -1.0f, 0.07f * sign);
    glVertex3f(-0.35f, -1.08f, 0.08f * sign);

    glVertex3f(-0.35f, -1.0f, 0.07f * sign);
    glVertex3f(-0.50f, -0.92f, 0.05f * sign);
    glVertex3f(-0.35f, -1.08f, 0.08f * sign);

    // Left wing lower - Split into 4 triangles
    glColor3f(sign > 0 ? 0.48f : 0.36f, sign > 0 ? 0.51f : 0.39f, sign > 0 ? 0.56f : 0.43f);
    glVertex3f(-0.35f, -1.08f, 0.08f * sign);
    glVertex3f(-0.50f, -0.92f, 0.05f * sign);
    glVertex3f(-0.50f, -1.05f, 0.05f * sign);

    glVertex3f(-0.35f, -1.08f, 0.08f * sign);
    glVertex3f(-0.50f, -1.05f, 0.05f * sign);
    glVertex3f(-0.32f, -1.22f, 0.06f * sign);

    glVertex3f(-0.18f, -1.0f, 0.07f * sign);
    glVertex3f(-0.35f, -1.08f, 0.08f * sign);
    glVertex3f(-0.32f, -1.22f, 0.06f * sign);

    glVertex3f(-0.18f, -1.0f, 0.07f * sign);
    glVertex3f(-0.32f, -1.22f, 0.06f * sign);
    glVertex3f(-0.18f, -1.22f, 0.07f * sign);

    // Right wing upper - Split into 2 triangles
    glColor3f(sign > 0 ? 0.44f : 0.33f, sign > 0 ? 0.47f : 0.36f, sign > 0 ? 0.52f : 0.41f);
    glVertex3f(0.18f, -1.0f, 0.07f * sign);
    glVertex3f(0.35f, -1.08f, 0.08f * sign);
    glVertex3f(0.35f, -1.0f, 0.07f * sign);

    glVertex3f(0.35f, -1.0f, 0.07f * sign);
    glVertex3f(0.35f, -1.08f, 0.08f * sign);
    glVertex3f(0.50f, -0.92f, 0.05f * sign);

    // Right wing lower - Split into 4 triangles
    glColor3f(sign > 0 ? 0.38f : 0.28f, sign > 0 ? 0.41f : 0.31f, sign > 0 ? 0.46f : 0.35f);
    glVertex3f(0.35f, -1.08f, 0.08f * sign);
    glVertex3f(0.50f, -0.92f, 0.05f * sign);
    glVertex3f(0.50f, -1.05f, 0.05f * sign);

    glVertex3f(0.35f, -1.08f, 0.08f * sign);
    glVertex3f(0.50f, -1.05f, 0.05f * sign);
    glVertex3f(0.32f, -1.22f, 0.06f * sign);

    glVertex3f(0.18f, -1.0f, 0.07f * sign);
    glVertex3f(0.32f, -1.22f, 0.06f * sign);
    glVertex3f(0.18f, -1.22f, 0.07f * sign);

    glVertex3f(0.18f, -1.0f, 0.07f * sign);
    glVertex3f(0.35f, -1.08f, 0.08f * sign);
    glVertex3f(0.32f, -1.22f, 0.06f * sign);

    glEnd();

    // =====================================
    // 3. HANDLE CHEVRONS (3D Faceted V-Plates)
    // =====================================
    float chevronTops[4] = { -1.22f, -1.445f, -1.67f, -1.895f };
    float chevronH = 0.225f;

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 4; i++)
    {
        float top = chevronTops[i];
        float bot = top - chevronH;

        // Left faceted V-triangle
        glColor3f(sign > 0 ? 0.70f : 0.54f, sign > 0 ? 0.72f : 0.56f, sign > 0 ? 0.76f : 0.60f);
        glVertex3f(-0.11f, top, 0.065f * sign);
        glVertex3f(0.0f, bot, 0.075f * sign);
        glVertex3f(-0.11f, bot, 0.065f * sign);

        // Right faceted V-triangle
        glColor3f(sign > 0 ? 0.52f : 0.40f, sign > 0 ? 0.54f : 0.42f, sign > 0 ? 0.58f : 0.46f);
        glVertex3f(0.11f, top, 0.065f * sign);
        glVertex3f(0.11f, bot, 0.065f * sign);
        glVertex3f(0.0f, bot, 0.075f * sign);
    }
    glEnd();

    // =====================================
    // 4. WIREFRAME OVERLAY FOR THIS SIDE (MATCHING REFERENCE EXACTLY)
    // =====================================
    // Enable polygon offset so wireframe lines never Z-fight (flicker/clip) with faces
    glEnable(GL_POLYGON_OFFSET_LINE);
    glPolygonOffset(-1.0f, -1.0f);

    glColor3f(0.05f, 0.05f, 0.05f);
    glLineWidth(1.8f);

    glBegin(GL_LINES);
    // Blade Outer Borders
    glVertex3f(0.0f, 3.45f, 0.0f);   glVertex3f(-0.35f, 2.7f, 0.0f);
    glVertex3f(0.0f, 3.45f, 0.0f);   glVertex3f(0.35f, 2.7f, 0.0f);
    glVertex3f(-0.35f, 2.7f, 0.0f);  glVertex3f(-0.35f, -1.0f, 0.0f);
    glVertex3f(0.35f, 2.7f, 0.0f);   glVertex3f(0.35f, -1.0f, 0.0f);

    // Tip facet lines
    glVertex3f(0.0f, 3.45f, 0.0f);   glVertex3f(0.0f, 3.0f, 0.08f * sign);
    glVertex3f(-0.35f, 2.7f, 0.0f);  glVertex3f(0.0f, 3.0f, 0.08f * sign);
    glVertex3f(0.35f, 2.7f, 0.0f);   glVertex3f(0.0f, 3.0f, 0.08f * sign);

    // Tip to longitudinal ridges
    glVertex3f(0.0f, 3.45f, 0.0f);   glVertex3f(-0.12f, 2.7f, 0.05f * sign);
    glVertex3f(0.0f, 3.45f, 0.0f);   glVertex3f(0.12f, 2.7f, 0.05f * sign);

    // Upper blade central ridge
    glVertex3f(0.0f, 3.0f, 0.08f * sign);    glVertex3f(0.0f, 0.5f, 0.09f * sign);

    // Upper blade longitudinal subdivision facets
    glVertex3f(-0.12f, 2.7f, 0.05f * sign);  glVertex3f(-0.14f, 0.5f, 0.055f * sign);
    glVertex3f(0.12f, 2.7f, 0.05f * sign);   glVertex3f(0.14f, 0.5f, 0.055f * sign);

    // Horizontal cross-seam on upper blade
    glVertex3f(-0.35f, 1.6f, 0.0f);          glVertex3f(0.35f, 1.6f, 0.0f);

    // Middle horizontal seam / facet transition
    glVertex3f(-0.35f, 0.5f, 0.0f);  glVertex3f(0.35f, 0.5f, 0.0f);

    // Lower blade internal facet lines
    glVertex3f(0.0f, 0.5f, 0.09f * sign);    glVertex3f(0.0f, -1.0f, 0.08f * sign);
    glVertex3f(-0.14f, 0.5f, 0.055f * sign); glVertex3f(-0.14f, -1.0f, 0.045f * sign);
    glVertex3f(0.14f, 0.5f, 0.055f * sign);  glVertex3f(0.14f, -1.0f, 0.045f * sign);

    // Horizontal cross-seam on lower blade
    glVertex3f(-0.35f, -0.25f, 0.0f);        glVertex3f(0.35f, -0.25f, 0.0f);

    // Diagonal bevel lines across lower blade
    glVertex3f(-0.14f, 0.5f, 0.055f * sign); glVertex3f(-0.35f, -1.0f, 0.0f);
    glVertex3f(0.14f, 0.5f, 0.055f * sign);  glVertex3f(0.35f, -1.0f, 0.0f);

    glVertex3f(-0.35f, -1.0f, 0.0f); glVertex3f(0.35f, -1.0f, 0.0f);

    // Crossguard Outer Perimeter
    glVertex3f(-0.18f, -1.0f, 0.07f * sign);  glVertex3f(-0.35f, -1.0f, 0.07f * sign);
    glVertex3f(-0.35f, -1.0f, 0.07f * sign);  glVertex3f(-0.50f, -0.92f, 0.05f * sign);
    glVertex3f(-0.50f, -0.92f, 0.05f * sign); glVertex3f(-0.50f, -1.05f, 0.05f * sign);
    glVertex3f(-0.50f, -1.05f, 0.05f * sign); glVertex3f(-0.32f, -1.22f, 0.06f * sign);
    glVertex3f(-0.32f, -1.22f, 0.06f * sign); glVertex3f(-0.18f, -1.22f, 0.07f * sign);

    glVertex3f(0.18f, -1.0f, 0.07f * sign);   glVertex3f(0.35f, -1.0f, 0.07f * sign);
    glVertex3f(0.35f, -1.0f, 0.07f * sign);   glVertex3f(0.50f, -0.92f, 0.05f * sign);
    glVertex3f(0.50f, -0.92f, 0.05f * sign);  glVertex3f(0.50f, -1.05f, 0.05f * sign);
    glVertex3f(0.50f, -1.05f, 0.05f * sign);  glVertex3f(0.32f, -1.22f, 0.06f * sign);
    glVertex3f(0.32f, -1.22f, 0.06f * sign);  glVertex3f(0.18f, -1.22f, 0.07f * sign);

    // Crossguard Central Box
    glVertex3f(-0.18f, -1.0f, 0.09f * sign);  glVertex3f(0.18f, -1.0f, 0.09f * sign);
    glVertex3f(-0.18f, -1.22f, 0.09f * sign); glVertex3f(0.18f, -1.22f, 0.09f * sign);
    glVertex3f(-0.18f, -1.0f, 0.09f * sign);  glVertex3f(-0.18f, -1.22f, 0.09f * sign);
    glVertex3f(0.18f, -1.0f, 0.09f * sign);   glVertex3f(0.18f, -1.22f, 0.09f * sign);

    // Crossguard Wing internal ridge lines
    glVertex3f(-0.18f, -1.0f, 0.07f * sign);  glVertex3f(-0.35f, -1.08f, 0.08f * sign);
    glVertex3f(-0.35f, -1.08f, 0.08f * sign); glVertex3f(-0.50f, -1.05f, 0.05f * sign);

    glVertex3f(0.18f, -1.0f, 0.07f * sign);   glVertex3f(0.35f, -1.08f, 0.08f * sign);
    glVertex3f(0.35f, -1.08f, 0.08f * sign);  glVertex3f(0.50f, -1.05f, 0.05f * sign);

    // Hilt Outer Rails
    glVertex3f(-0.11f, -1.22f, 0.065f * sign); glVertex3f(-0.11f, -2.12f, 0.065f * sign);
    glVertex3f(0.11f, -1.22f, 0.065f * sign);  glVertex3f(0.11f, -2.12f, 0.065f * sign);

    // Chevron V-lines
    for (int i = 0; i < 4; i++)
    {
        float top = chevronTops[i];
        float bot = top - chevronH;

        glVertex3f(-0.11f, top, 0.065f * sign); glVertex3f(0.0f, bot, 0.075f * sign);
        glVertex3f(0.11f, top, 0.065f * sign);  glVertex3f(0.0f, bot, 0.075f * sign);
    }
    glVertex3f(-0.11f, -2.12f, 0.065f * sign); glVertex3f(0.11f, -2.12f, 0.065f * sign);
    glEnd();

    glDisable(GL_POLYGON_OFFSET_LINE);
}

void drawSwordSides()
{
    // =====================================
    // CROSSGUARD SIDEWALLS (Full Triangulated Solid)
    // =====================================
    glBegin(GL_TRIANGLES);
    glColor3f(0.35f, 0.38f, 0.42f);

    // Left Wing Perimeter Walls
    glVertex3f(-0.35f, -1.0f, 0.06f);   glVertex3f(-0.50f, -0.92f, 0.06f);  glVertex3f(-0.50f, -0.92f, -0.06f);
    glVertex3f(-0.35f, -1.0f, 0.06f);   glVertex3f(-0.50f, -0.92f, -0.06f); glVertex3f(-0.35f, -1.0f, -0.06f);

    glVertex3f(-0.50f, -0.92f, 0.06f);  glVertex3f(-0.50f, -1.05f, 0.06f);  glVertex3f(-0.50f, -1.05f, -0.06f);
    glVertex3f(-0.50f, -0.92f, 0.06f);  glVertex3f(-0.50f, -1.05f, -0.06f); glVertex3f(-0.50f, -0.92f, -0.06f);

    glVertex3f(-0.50f, -1.05f, 0.06f);  glVertex3f(-0.32f, -1.22f, 0.06f);  glVertex3f(-0.32f, -1.22f, -0.06f);
    glVertex3f(-0.50f, -1.05f, 0.06f);  glVertex3f(-0.32f, -1.22f, -0.06f); glVertex3f(-0.50f, -1.05f, -0.06f);

    // Right Wing Perimeter Walls
    glVertex3f(0.35f, -1.0f, 0.06f);    glVertex3f(0.50f, -0.92f, 0.06f);   glVertex3f(0.50f, -0.92f, -0.06f);
    glVertex3f(0.35f, -1.0f, 0.06f);    glVertex3f(0.50f, -0.92f, -0.06f);  glVertex3f(0.35f, -1.0f, -0.06f);

    glVertex3f(0.50f, -0.92f, 0.06f);   glVertex3f(0.50f, -1.05f, 0.06f);   glVertex3f(0.50f, -1.05f, -0.06f);
    glVertex3f(0.50f, -0.92f, 0.06f);   glVertex3f(0.50f, -1.05f, -0.06f);  glVertex3f(0.50f, -0.92f, -0.06f);

    glVertex3f(0.50f, -1.05f, 0.06f);   glVertex3f(0.32f, -1.22f, 0.06f);   glVertex3f(0.32f, -1.22f, -0.06f);
    glVertex3f(0.50f, -1.05f, 0.06f);   glVertex3f(0.32f, -1.22f, -0.06f);  glVertex3f(0.50f, -1.05f, -0.06f);

    // Central Guard Top & Bottom
    glVertex3f(-0.18f, -1.0f, 0.09f);   glVertex3f(0.18f, -1.0f, 0.09f);    glVertex3f(0.18f, -1.0f, -0.09f);
    glVertex3f(-0.18f, -1.0f, 0.09f);   glVertex3f(0.18f, -1.0f, -0.09f);   glVertex3f(-0.18f, -1.0f, -0.09f);

    glVertex3f(-0.18f, -1.22f, -0.09f); glVertex3f(0.18f, -1.22f, -0.09f);  glVertex3f(0.18f, -1.22f, 0.09f);
    glVertex3f(-0.18f, -1.22f, -0.09f); glVertex3f(0.18f, -1.22f, 0.09f);   glVertex3f(-0.18f, -1.22f, 0.09f);

    // Left Wing Bottom Return
    glVertex3f(-0.32f, -1.22f, 0.06f);  glVertex3f(-0.18f, -1.22f, 0.06f);  glVertex3f(-0.18f, -1.22f, -0.06f);
    glVertex3f(-0.32f, -1.22f, 0.06f);  glVertex3f(-0.18f, -1.22f, -0.06f); glVertex3f(-0.32f, -1.22f, -0.06f);

    // Right Wing Bottom Return
    glVertex3f(0.18f, -1.22f, 0.06f);   glVertex3f(0.32f, -1.22f, 0.06f);   glVertex3f(0.32f, -1.22f, -0.06f);
    glVertex3f(0.18f, -1.22f, 0.06f);   glVertex3f(0.32f, -1.22f, -0.06f);  glVertex3f(0.18f, -1.22f, -0.06f);
    glEnd();

    // Side edge outlines
    glColor3f(0.05f, 0.05f, 0.05f);
    glLineWidth(1.8f);
    glBegin(GL_LINES);
    glVertex3f(-0.50f, -0.92f, 0.06f); glVertex3f(-0.50f, -0.92f, -0.06f);
    glVertex3f(-0.50f, -1.05f, 0.06f); glVertex3f(-0.50f, -1.05f, -0.06f);
    glVertex3f(0.50f, -0.92f, 0.06f);  glVertex3f(0.50f, -0.92f, -0.06f);
    glVertex3f(0.50f, -1.05f, 0.06f);  glVertex3f(0.50f, -1.05f, -0.06f);
    glEnd();
}

void drawHiltAndPommelGLU()
{
    GLUquadricObj* q = gluNewQuadric();

    // 1. Handle Core: GLU Cylinder (3D Round/Oval Core)
    glPushMatrix();
    glTranslatef(0.0f, -1.22f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(0.24f, 0.24f, 0.26f);
    gluCylinder(q, 0.08, 0.075, 0.90, 32, 1);
    glPopMatrix();

    // 2. Pommel: GLU High-Poly Spherical Gem
    // Upper connection collar (tapers down smoothly to spherical gem)
    glPushMatrix();
    glTranslatef(0.0f, -2.12f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(0.50f, 0.54f, 0.60f);
    gluCylinder(q, 0.075, 0.12, 0.08, 32, 1);
    glPopMatrix();

    // Main Round Spherical Pommel Orb (High subdivision: 32 slices, 24 stacks)
    glPushMatrix();
    glTranslatef(0.0f, -2.36f, 0.0f);
    glScalef(1.0f, 1.0f, 0.75f); // Natural solid depth
    glColor3f(0.55f, 0.58f, 0.65f);
    gluQuadricDrawStyle(q, GLU_FILL);
    gluSphere(q, 0.20, 32, 24);

    // High-poly wireframe lines overlay for smooth, detailed spherical facets
    glEnable(GL_POLYGON_OFFSET_LINE);
    glPolygonOffset(-1.0f, -1.0f);
    gluQuadricDrawStyle(q, GLU_LINE);
    glColor3f(0.05f, 0.05f, 0.05f);
    glLineWidth(1.2f);
    gluSphere(q, 0.20, 24, 16);
    glDisable(GL_POLYGON_OFFSET_LINE);
    glPopMatrix();

    // Bottom Decorative Ring & Button
    glPushMatrix();
    glTranslatef(0.0f, -2.52f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(0.35f, 0.38f, 0.44f);
    gluQuadricDrawStyle(q, GLU_FILL);
    gluCylinder(q, 0.08, 0.05, 0.08, 32, 1);

    // End disk cap
    glTranslatef(0.0f, 0.0f, 0.08f);
    glColor3f(0.28f, 0.30f, 0.35f);
    gluDisk(q, 0.0, 0.05, 32, 1);

    // Outline for bottom button
    glEnable(GL_POLYGON_OFFSET_LINE);
    glPolygonOffset(-1.0f, -1.0f);
    gluQuadricDrawStyle(q, GLU_LINE);
    glColor3f(0.05f, 0.05f, 0.05f);
    glLineWidth(1.2f);
    glTranslatef(0.0f, 0.0f, -0.08f);
    gluCylinder(q, 0.08, 0.05, 0.08, 16, 1);
    glTranslatef(0.0f, 0.0f, 0.08f);
    gluDisk(q, 0.0, 0.05, 16, 1);
    glDisable(GL_POLYGON_OFFSET_LINE);

    glPopMatrix();

    gluDeleteQuadric(q);
}

void drawSword()
{
    glPushMatrix();

    // Scale and center the sword
    glTranslatef(0.0f, -0.05f, 0.0f);
    glScalef(0.24f, 0.24f, 0.24f);

    // 1. Draw Front Face (+Z) with thin, sharp blade
    drawBladeHalf(1.0f);

    // 2. Draw Back Face (-Z) (3D back)
    drawBladeHalf(-1.0f);

    // 3. Draw Side Walls (connecting crossguard edges)
    drawSwordSides();

    // 4. Draw Handle Core & Pommel using GLU Quadrics
    drawHiltAndPommelGLU();

    glPopMatrix();
}

void drawHead()
{

}

void drawBody()
{

}

void drawArms()
{

}

void drawLegs()
{

}

void drawDetails()
{

}
// Combine the entire character
void drawCharacter()
{

}
//=====================
// Draw the environment
//=====================
void drawBackground()
{

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);

    glRotatef(0.08, 0, 1, 0);
    drawSword();
}
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	if (!RegisterClassEx(&wc)) return false;
	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 800, NULL, NULL, wc.hInstance, NULL);
	HDC hdc = GetDC(hWnd);
	initPixelFormat(hdc);
	HGLRC hglrc = wglCreateContext(hdc);
	if (!wglMakeCurrent(hdc, hglrc)) return false;
	ShowWindow(hWnd, nCmdShow);
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		display();
		SwapBuffers(hdc);
	}
	UnregisterClass(WINDOW_TITLE, wc.hInstance);
	return true;
}