#include "Transform.h"

Transform::Transform()
{
    position = new Vector();
}

void Transform::End()
{
    Component::End();

    delete position;
}
