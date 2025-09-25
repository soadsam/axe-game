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

    if ((circleRight >= rectLeft && circleLeft <= rectRight) && (circleY + radius >= rectY && circleY - radius <= rectY + 50))
    {
      circleColor = GREEN;
      rectColor = GREEN;
    }
    else
    {
      circleColor = RED;
      rectColor = RED;
    }

    DrawCircle(circleX, circleY, radius, circleColor);
    DrawRectangle(rectX, rectY, 50, 50, rectColor);

    rectY += direction;

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

    printf("rectX: %i", rectX);
    printf(" circleRight: %i\n", circleRight);

    ClearBackground(WHITE);
    EndDrawing();
  }
}