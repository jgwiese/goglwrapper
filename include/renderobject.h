#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

class t_renderobject {
public:
  virtual ~t_renderobject() = default;
  virtual void draw() = 0;
};

#endif // RENDEROBJECT_H
