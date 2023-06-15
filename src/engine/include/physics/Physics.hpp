// no need for a class, at least right now
// nice to finally get some code going again
#ifndef PHYSICS
#define PHYSICS

#include "btBulletDynamicsCommon.h"
#include <stdio.h>

namespace lei3d
{
    struct PhysicsObjects
    {
        btDefaultCollisionConfiguration* collisionConfiguration = nullptr;
        btCollisionDispatcher* dispatcher = nullptr;
        btBroadphaseInterface* overlappingPairCache = nullptr;
        btSequentialImpulseConstraintSolver* solver = nullptr;
        btDiscreteDynamicsWorld* dynamicsWorld = nullptr;
        btAlignedObjectArray<btCollisionShape*> collisionShapes;
    };

    PhysicsObjects CreatePhysicsWorld();
    void PhysicsStep(PhysicsObjects physicsObjects);

}

#endif // PHYSICS