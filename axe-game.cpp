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

  int score{0};
  bool reachedLeftEdge{false};
  bool reachedRightEdge{false};
  const int buttonWidth{140};
  const int buttonHeight{40};
  const int buttonMargin{20};

  SetTargetFPS(60);
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);

    Rectangle resetButton{static_cast<float>(width - buttonMargin - buttonWidth),
                          static_cast<float>(buttonMargin),
                          static_cast<float>(buttonWidth),
                          static_cast<float>(buttonHeight)};
    Vector2 mousePosition = GetMousePosition();
    bool isHoveringButton = CheckCollisionPointRec(mousePosition, resetButton);
    Color buttonColor = isHoveringButton ? LIGHTGRAY : GRAY;
    DrawRectangleRec(resetButton, buttonColor);
    DrawRectangleLinesEx(resetButton, 2, DARKGRAY);
    const char *buttonLabel = "Reset";
    int textWidth = MeasureText(buttonLabel, 20);
    DrawText(buttonLabel,
             resetButton.x + (resetButton.width - textWidth) / 2,
             resetButton.y + (resetButton.height - 20) / 2,
             20,
             BLACK);

    if (isHoveringButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
      score = 0;
      reachedLeftEdge = false;
      reachedRightEdge = false;
    }

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

      bool atLeftEdge = circleLeft <= 0;
      bool atRightEdge = circleRight >= width;

      if (atLeftEdge && !reachedLeftEdge)
      {
        score++;
        reachedLeftEdge = true;
      }
      else if (!atLeftEdge)
      {
        reachedLeftEdge = false;
      }

      if (atRightEdge && !reachedRightEdge)
      {
        score++;
        reachedRightEdge = true;
      }
      else if (!atRightEdge)
      {
        reachedRightEdge = false;
      }

      printf("rectY: %i\n", rectY);
      printf(" circleTop: %i\n", circleTop);
      printf(" circleBottom: %i\n", circleBottom);
    }

    const char *scoreText = TextFormat("Score: %i", score);
    DrawText(scoreText, buttonMargin, buttonMargin, 30, BLACK);

    EndDrawing();
  }
}