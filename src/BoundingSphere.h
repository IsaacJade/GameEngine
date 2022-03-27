#ifndef BOUNDING_SPHERE_H
#define BOUNDING_SPHERE_H

#include "MathEngine.h"
#include "BoundingSphere.pb.h"

namespace Azul
{
	class Sphere : public Align16
	{
	public:
		Sphere();
		Sphere(const Sphere &) = default;
		Sphere &operator = (const Sphere &);
		~Sphere();

		void RitterSphere(Vect *pt, unsigned int numPts);

		// Data: ---------------------------------
		Vect cntr;
		float rad;
		float pad[3];  // love and hate this new compiler
		float poData[4];

		// Serialization 
		void Serialize(BoundingSphere_proto& out) const;
		void Deserialize(const BoundingSphere_proto& in);
		void FindBoundingVolume(Vect* pVerts, unsigned int count);
	private:

		void privMostSeparatedPointsOnAABB(int &min, int &max, Vect *pt, int numPts);
		void privSphereFromDistantPoints(Vect *pt, int numPts);
		void privSphereOfSphereAndPt(Vect &p);

	};
}

#endif
