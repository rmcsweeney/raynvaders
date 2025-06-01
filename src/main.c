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
    const int screenWidth = 360;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Space Raynvaders");
	
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
		struct enemyStruct *guy = &level1[i];
		float temp_x = enemyPadding * (i + 1) + i * enemyWidth;
		while (temp_x + enemyWidth > screenWidth) temp_x -= screenWidth + enemyWidth;
		guy->pos.x = temp_x;
		guy->pos.y = abs_pos / (screenWidth + enemyWidth) * enemyHeight; 
		printf("X and Y: %f %f\n", guy->pos.x, guy->pos.y);
		guy->dead = false;
		guy->texture = greengan_texture;		
	}

    const float xes[6] = {60, 100, 140, 180, 220, 260};
    const float yes[2] = {20, 70};
    struct enemyStruct level2[12];
    for (int i = 0; i < 12; i++){ 
        struct enemyStruct *guy = &level2[i];
        guy->pos.x = xes[i % 6];
        if (i > 5) guy->pos.y = yes[1];
        else guy->pos.y = yes[0];
        guy->dead = false;
        guy->texture = greengan_texture;
    }

    int level = 2;
    float enemy_speed = 1;
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
	    
        //check collision
        bool will_collide = false;
        for (int i = 0; i < 12; i++) {
           struct enemyStruct *guy = &level2[i];
           if (guy->alive==true && (guy->pos.x + enemy_speed < 0 ||
                guy->pos.x + enemy_speed + enemyWidth > screenWidth){
                willCollide = true;
                break;
           }
        }
        if (willCollide) {
            
        }
        else {
            
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
			DrawTexture(ship_texture, ship_pos.x, ship_pos.y, WHITE);
            switch (level) {
                case 1:
                    for (int i = 0; i < level1_len; i++) {
				        struct enemyStruct guy = level1[i];
				        DrawTexture(greengan_texture, guy.pos.x, guy.pos.y, WHITE);
			        }
                    break;
                case 2:
                    for (int i = 0; i < 12; i++) {
                        struct enemyStruct guy = level2[i];
                        DrawTexture(greengan_texture, guy.pos.x, guy.pos.y, WHITE);
                    }
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
