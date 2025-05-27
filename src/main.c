/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Example complexity rating: [★☆☆☆] 1/4
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute 'raylib_compile_execute' script
*   Note that compiled executable is placed in the same folder as .c file
*
*   To test the examples on Web, press F6 and execute 'raylib_compile_execute_web' script
*   Web version of the program is generated in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#include "stdio.h"
#include "raylib.h"

struct enemyStruct {
	Vector2 pos;
	bool dead;
	Texture2D texture;
	int aggression;
	int speed;
	int health;
};

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 300;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	
	Vector2 ship_pos = { screenWidth / 2,  screenHeight * 8 / 10};
	Image greengan = LoadImage("/home/ryan/Developer/c/raylib-test/assets/greengan.png");     // Loaded in CPU memory (RAM)
    Texture2D greengan_texture = LoadTextureFromImage(greengan);          // Image converted to texture, GPU memory (VRAM)
    UnloadImage(greengan);   // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM
	Image ship = LoadImage("/home/ryan/Developer/c/raylib-test/assets/ship.png");
	Texture2D ship_texture = LoadTextureFromImage(ship);
	UnloadImage(ship);
	
	//Level Setup
	const int enemyPadding = 10;
	const int enemyWidth = 30;
	const int enemyHeight = 30;
	struct enemyStruct level1[10];
	int level1_len = 10;
	for (int i = 0; i < level1_len; i++){
		int abs_pos = enemyPadding * (i +1) + i * enemyWidth;
		printf("%d\n", abs_pos);
		struct enemyStruct guy = level1[i];
		int temp_x = enemyPadding * (i + 1) + i * enemyWidth;
		//while (guy.pos.x > screenWidth) guy.pos.x -= screenWidth;
		guy.pos.x = temp_x;
		guy.pos.y = enemyPadding * (i + 1) + abs_pos / screenWidth * enemyHeight; 
		printf("X and Y: %d %d\n", guy.pos.x, guy.pos.y);
		guy.dead = false;
		guy.texture = greengan_texture;		
	}
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
		if (IsKeyDown(KEY_RIGHT)) ship_pos.x += 2;
		if (IsKeyDown(KEY_LEFT)) ship_pos.x -= 2;
		//if (IsKeyDown(SPACE)) ship_pos.y += 0;
		if (ship_pos.x < 0) ship_pos.x = 0;
		if (ship_pos.x + 25 > screenWidth) ship_pos.x = screenWidth - 25; 
		
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
			DrawTexture(greengan_texture, 50, 50, WHITE);
			DrawTexture(ship_texture, ship_pos.x, ship_pos.y, WHITE);
            for (int i = 0; i < level1_len; i++) {
				struct enemyStruct guy = level1[i];
				DrawTexture(greengan_texture, guy.pos.x, guy.pos.y, WHITE);
			}
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
