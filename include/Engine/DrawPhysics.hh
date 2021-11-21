#pragma once
#include<box2d/box2d.h>
#include<SFML/Graphics.hpp>

class DrawPhysics : public b2Draw
{
private:
  sf::RenderWindow* window;
public:

  DrawPhysics(sf::RenderWindow*& window);
  ~DrawPhysics();

  sf::Color GLColorToSFML(const b2Color &color, sf::Uint8 alpha = 255);
  sf::Vector2f B2VecToSFVec(const b2Vec2 &vector);

  void DrawPolygon (const b2Vec2 *vertices, int32 vertexCount, const b2Color &color);
  void DrawSolidPolygon (const b2Vec2 *vertices, int32 vertexCount, const b2Color &color);
  void DrawCircle (const b2Vec2 &center, float radius, const b2Color &color);
  void DrawSolidCircle (const b2Vec2 &center, float radius, const b2Vec2 &axis, const b2Color &color);
  void DrawSegment (const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color);
  void DrawTransform (const b2Transform &xf);
  void DrawPoint (const b2Vec2 &p, float size, const b2Color &color);
};