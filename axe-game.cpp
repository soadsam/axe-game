#include "raylib.h"
#include <cstdio>
int main()
{
  int width = 800;
  int height = 600;
  InitWindow(width, height, "Axe Game");

  // Circle position
  int circleX{200};
  int circleY{200};
  int radius{50};
  int circleRight{circleX + radius};
  int circleLeft{circleX - radius};
  int circleTop{circleY - radius};
  int circleBottom{circleY + radius};

  // Rectangle position
  int rectX{400};
  int rectY{0};
  int direction{10};
  int rectRight{rectX + 50};
  int rectLeft{rectX};
  int rectTop{rectY};
  int rectBottom{rectY + 50};
  Color circleColor{RED};
  Color rectColor{RED};

  SetTargetFPS(60);
  while (!WindowShouldClose())
  {
    BeginDrawing();

    if ((circleRight >= rectLeft && circleLeft <= rectRight) && (circleTop <= rectBottom && circleBottom >= rectTop))
    {
      DrawText("GAME OVER", 400, 200, 20, RED);
    }
    else
    {
      circleColor = GREEN;
      rectColor = GREEN;
      DrawCircle(circleX, circleY, radius, circleColor);
      DrawRectangle(rectX, rectY, 50, 50, rectColor);

      rectY += direction;
      rectTop = rectY;
      rectBottom = rectY + 50;

      if (rectY > height - 50 || rectY < 0)
      {
        direction = direction * -1;
      }

      if (IsKeyDown(KEY_D) && circleX < width - 50)
      {
        circleX += 5;
      }

      if (IsKeyDown(KEY_W) && circleY > 50)
      {
        circleY -= 5;
      }

      if (IsKeyDown(KEY_S) && circleY < height - 50)
      {
        circleY += 5;
      }

      if (IsKeyDown(KEY_A) && circleX > 50)
      {
        circleX -= 5;
      }

      circleRight = circleX + radius;
      circleLeft = circleX - radius;
      circleTop = circleY - radius;
      circleBottom = circleY + radius;

      printf("rectY: %i\n", rectY);
      printf(" circleTop: %i\n", circleTop);
      printf(" circleBottom: %i\n", circleBottom);
    }
    ClearBackground(WHITE);
    EndDrawing();
  }
}